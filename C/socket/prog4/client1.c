#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	<pthread.h>

#define 	MAX_NUMBER_OF_THREADS	4
#define		MAX_SIZE_OF_BUFFER 		1024

int main(int argc, char *args[]) 
{
	int 			i;
	int 			fd = 0;
	char 			buffer[MAX_SIZE_OF_BUFFER];
	pthread_t 		tid[MAX_NUMBER_OF_THREADS];
	struct sockaddr_in 	serv_addr;

	if(-1 == (fd = socket(AF_INET, SOCK_STREAM, 0)) ) {
		printf("socket creatio failed");
	}

	serv_addr.sin_family 		= AF_INET;
	serv_addr.sin_addr.s_addr 	= inet_addr(args[1]);
	serv_addr.sin_port 			= htons( atoi(args[2]) );
	
	if( -1 == connect(fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) ) {
		printf("failed to connect");
	}

	while(1) {
		bzero(buffer, MAX_SIZE_OF_BUFFER);
		fgets(buffer, MAX_SIZE_OF_BUFFER, stdin);
		
		if(0 > write(fd, buffer, strlen(buffer))) {
			perror("Error in writing");
		}

		bzero(buffer, MAX_SIZE_OF_BUFFER);
		if(0 > read(fd, buffer, MAX_SIZE_OF_BUFFER)) {
			perror("Error in reading");
		}

		printf("Server: %s", buffer);
		if(0 == strcmp("BYE", buffer))
			break;
	}
	close(fd);
	
	return 0;
}
