#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	<pthread.h>

#define		MAX_NUMBER_OF_THREAD	4

pthread_mutex_t 	lock = PTHREAD_MUTEX_INITIALIZER;
void connection_handler(void *sock);

int main(int argc, char *args[])
{
	int 				fd, newfd, addr_len, i=0;
	int 				*psock;
	struct sockaddr_in 	serv_addr;
	pthread_t			tid[4];

	if(3 > argc) {
		printf("Usage: ./binary SERVER_ADDR PORT");
	}

	if(-1 == (fd = socket(AF_INET, SOCK_STREAM, 0))) {
		perror("Socket creation failed");
		return -1;
	}
	serv_addr.sin_family 		= AF_INET;
	serv_addr.sin_addr.s_addr 	= inet_addr( args[1] );
	serv_addr.sin_port			= htons( atoi(args[2]) );

	if( -1 == bind(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ) {
		perror("bind failure");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if(-1 == listen(fd, 0) ) {
		perror("Listen failure");
		close(fd);
		exit(EXIT_FAILURE);
	}
	addr_len = sizeof(addr_len);

	while(i < MAX_NUMBER_OF_THREAD) {
		if ( -1 == (newfd = accept(fd, (struct sockaddr*)&serv_addr, (socklen_t*)&addr_len)) ) {
			perror("accept failed");
			close(fd);
			exit(EXIT_FAILURE);
		}
		psock 	= (int*) malloc(sizeof(newfd));
		*psock 	= newfd;

		if( 0 != pthread_create(&tid[i], NULL, (void*) &connection_handler, psock) ) {
			perror("Thread creation failed");
			close(fd);
			close(newfd);
			free(psock);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return 0;
}
void connection_handler(void *sock) 
{
	int 	i = 0;
	int		recv_bytes;
	int		write_bytes;
	int		fd = *(int*)sock;
	char 	buffer[1000];
	bzero(buffer, 1000);
	free(sock);

	recv_bytes = recv(fd, buffer, 1000, 0);
	pthread_mutex_lock(&lock);
	printf("Client: %s", buffer);

	if(0 == strncmp("Bye", buffer, 3)) {
			close(fd);
			pthread_exit(NULL);
	}
	pthread_mutex_unlock(&lock);

	bzero(buffer, 1000);
	fgets(buffer, 1000, stdin);
	
	pthread_mutex_lock(&lock);
	if (0 > (write_bytes = write(fd, buffer, strlen(buffer))) ) {
			pthread_mutex_unlock(&lock);
			perror("failed to write on the socket for thread");
			close(fd);
			pthread_exit(NULL);
	}

	if(0 == strncmp("Bye", buffer, 3)) {
			pthread_mutex_unlock(&lock);
			close(fd);
			pthread_exit(NULL);
	}
	pthread_mutex_unlock(&lock);
}
