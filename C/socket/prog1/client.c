/*Usage: ./binary_name server_ip_addr server_port */
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<unistd.h>
#include	<netdb.h>

void error(const char *msg)
{
	perror(msg);
}

int main(int argc, char *args[])
{
	int 					fd, port;
	char					buffer[1024];
	struct 	sockaddr_in 	serv_addr;
	struct 	hostent 		*server;
	if(3 > argc) {
		printf("Usage: ./binary_name server_ip_addr server_port");
	}

	port = atol(args[2]);
	if(0 > (fd = socket(AF_INET, SOCK_STREAM, 0))) {
		error("Socket creation failed");
	}

	if(NULL == (server = gethostbyname(args[1]))) {
		error("Error no such host");
	}
	bzero((char*)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(port);
	
	if(0 > connect(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) {
		error("Connection failed");
	}
	
	while(1) {
		bzero(buffer, 1024);
		fgets(buffer, 1024, stdin);
		
		if(0 > write(fd, buffer, strlen(buffer))) {
			error("Error in writing");
		}

		bzero(buffer, 1024);
		if(0 > read(fd, buffer, 1024)) {
			error("Error in reading");
		}

		printf("Server: %s", buffer);
		if(0 == strcmp("BYE", buffer))
			break;
	}
	close(fd);
	return 0;
}
