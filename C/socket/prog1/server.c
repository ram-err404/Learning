#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
//#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	<netdb.h>

void error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *args[]) 	/*Usage: ./server IP_address PortNo */
{
	int                 fd, newfd;
	struct sockaddr_in 	ser_addr;
	int 		            ser_len 	    = sizeof(ser_addr);
	char 		            buffer[1024]  = {0};
	struct hostent 		  *server       = NULL;
	
	if(argc < 3) {
		error("Usage: ./server IP_address PortNo \n");
	}
	
	if(0 == (fd = socket(AF_INET, SOCK_STREAM, 0))) {
		error("Unable to create fd !!! \n");
	}

	ser_addr.sin_family		 = AF_INET;
	ser_addr.sin_port 		 = htons(atoi(args[2]));
	/* if(NULL == (server = gethostbyname(args[1]))) {
		error("Error no such host");
	}
	bcopy((char*)server->h_addr, (char*)&ser_addr.sin_addr.s_addr, server->h_length); */
	ser_addr.sin_addr.s_addr = inet_addr( args[1] );

	if(0 > bind(fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr))) {
		error("Bind failure \n");
	}
	if(0 > listen(fd, 5)) {
		close(fd);
		error("Listen failure \n");
	}
	if(0 > (newfd = accept(fd, (struct sockaddr*)&ser_addr, (socklen_t*)&ser_len))) {
		close(fd);
		error("Accept failure");
	}

	while(1) {
		bzero(buffer, 1024);
		if(0 > read(newfd, buffer, 1024)) {
			close(fd);
			close(newfd);
			printf("Error in reading");
			exit(1);
		}
		printf("Client: %s", buffer);
		if(0 == strcmp(buffer, "Bye")) {
			break;
		}
		bzero(buffer, 1024);
		fgets(buffer, 1024, stdin);
		if(0 == write(newfd, buffer, strlen(buffer))) {
			close(fd);
			close(newfd);
			error("Error in writing");
		}
		if(0 == strcmp(buffer, "Bye")) {
			break;
		}
	}
	close(fd);
	close(newfd);
	return 0;
}
