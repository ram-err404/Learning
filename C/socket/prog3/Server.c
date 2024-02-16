/* socket server example, handles multiple clients using threads */

#include	<stdio.h>
#include	<string.h>    	//strlen
#include	<stdlib.h>    	//strlen
#include	<sys/socket.h>
#include	<arpa/inet.h> 	//inet_addr
#include	<unistd.h>    	//write
#include 	<netdb.h>
#include	<pthread.h> 	//for threading , link with lpthread

//the thread function
void *connection_handler(void *);

int main(int argc , char *args[])
{
    int 				socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in 	server , client;
	pthread_t 			sniffer_thread;

	if(3 > argc) {
		perror("Usage: ./binary_name server_ip server_port");
		exit(EXIT_FAILURE);
	}

    //Create socket
    if (0 > (socket_desc = socket(AF_INET , SOCK_STREAM , 0)))
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family 		= AF_INET;
    server.sin_addr.s_addr 	= inet_addr( args[1] );
    server.sin_port 		= htons( atoi(args[2]) );

    //Bind
    if( 0 > bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) )
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	while( -1 != (client_sock = accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&c)) )
	{
			puts("Connection accepted");

			if(0 > (pthread_create( &sniffer_thread , NULL ,  connection_handler , &client_sock)) )
			{
					perror("could not create thread");
					return 1;
			}
			puts("Handler assigned");
	}
	perror("accept failed");
    return 0;
}
/*
  This will handle connection for each client
  */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
	int n;

	char    sendBuff[100], client_message[2000];

	while((n=recv(sock,client_message,2000,0))>0)
	{

			send(sock,client_message,n,0);
	}
	close(sock);

	if(n==0)
	{
			puts("Client Disconnected");
	}
	else
	{
			perror("recv failed");
	}
	return 0;
}
