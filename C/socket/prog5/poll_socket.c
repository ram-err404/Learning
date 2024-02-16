/*
 * poll_socket.c
 * This program demonstrates how to use the poll function.
 * Note that although we did not cover sockets in this book, 
 * the code will remain the same for file descriptors. To use 
 * this program, open several xterms, run the program, and then
 * telnet to any of the ports. Once the telnet session is connected
 * type anything and it will echo back. For example:
 *
 * From xterm 1:
 *
 * bash$ ./poll_socket
 *
 * From xterm 2:
 *
 * bash$ telnet localhost 8888
 *
 * From xterm 3:
 *
 * bash$ telnet localhost 8889
 *
 * to compile: gcc -O -pipe  poll_socket.c  -o poll_socket
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <poll.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>


/* our defines */
#define PORT             (8888)
#define MAXBUFF          (1024)
#define MAX_CONN         (16)
#define TIMEOUT          (1024 * 1024)
#define MY_MAX(a,b)      (a = (a > b) ? a : b )
#define POLL_ERR         (-1)
#define POLL_EXPIRE      (0)

int main(int argc, char **argv)
{
	int i, j, max = 0, sfds[MAX_CONN], afd;
	size_t len;
	fd_set list;
	char buff[MAXBUFF];
	struct sockaddr_in sock[MAX_CONN];
	struct pollfd pfds[MAX_CONN];

	/* initialize our buffer */
	memset(buff, 0, MAXBUFF);

	/*
	 * We will loop through each file descriptor. First,
	 * we will create a socket bind to it and then call 
	 * listen. If we get and error we simply exit, 
	 * which is fine for demo code, but not good in the
	 * real world where errors should be handled properly. 
	 */
	for( i = 0; i < MAX_CONN; i++ )
	{
		/* check to see that we can create them */
		if( (sfds[i] = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
		{
			perror("Cannot create socket");
			exit(1);
		}

		/* now fill out the socket stuctures */
		memset(&sock[i], 0, sizeof(struct sockaddr_in));
		sock[i].sin_family = AF_INET;
		sock[i].sin_port = htons(PORT + i);
		len = INADDR_ANY;
		memset(&sock[i].sin_addr, len, sizeof(struct in_addr));

		/* Now bind to the socket	*/
		if( bind(sfds[i], (struct sockaddr *) &sock[i], sizeof(struct sockaddr_in)) < 0 )
		{
			perror("Cannot bind to the socket");
			exit(1);
		}

		/* set our options */
		if( setsockopt(sfds[i], SOL_SOCKET, SO_REUSEADDR, &j, sizeof(int)) < 0 )
		{
			perror("Cannot set socket options \n");
		}

		/* set the socket to the listen state */
		if( listen(sfds[i], 5) < 0 )
		{
			perror("Failed to listen on the socket \n");
		}

		/* now set our pollfd struct */
		pfds[i].fd = sfds[i];
		pfds[i].events = POLLIN ;

	}/* for */

	/*
	 * Our main loop. Note, with the poll function we do 
	 * not need to modify our structure before we call 
	 * poll again. Also note that the overall function
	 * is much easier to implement over select.   
	 */
	while( 1 )
	{

		/*
		 * Now call poll. When poll returns, one of 
		 * the three conditions will be true:
		 * I)   The timeout has expired
		 * II)  The poll call had an error
		 * III) We have a socket ready to accept
		 */
		j = poll(pfds, (unsigned int)MAX_CONN, TIMEOUT);
		switch( j )
		{
			case POLL_EXPIRE:
				printf("Timeout has expired !\n");
				break;                                                    

			case POLL_ERR:
				perror("Error on poll");

			default:   
				/* 
				 * Now we have to loop through each descriptor to
				 * see which is ready to accept. We will know if 
				 * the POLLIN bit is set on this descriptor that this
				 * descriptor is ready to use. 
				 */
				for( i =0; i < MAX_CONN; i++ )
				{
					if( pfds[i].revents & POLLIN )
					{
						/*
						 * We now have to accept the connection and then
						 * echo back what is written.
						 */
						printf("We have a connection \n");
						len = sizeof(struct sockaddr_in);
						afd = accept(sfds[i], (struct sockaddr *)&sock[i], (socklen_t *)&len);
						len = read(afd, buff, MAXBUFF);
						write(afd, buff, len +1);
						printf("Echoing back:\n %s \n", buff);
						close(afd);
					}

				} /* for */

		} /* switch */

	}/* while(1) */

	/* FIN */
	return(0);

} /* main */
