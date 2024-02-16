#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<unistd.h>
#include	<netdb.h>
#include	<pthread.h>

#define 	MAX_NUM_OF_THREAD	4

int main(int argc, int args[])
{
	int fd, newfd, port, socklen;
	struct sockaddr_in serv_addr;
	pthread_t tid[MAX_NUM_OF_THREAD];
	

	//Prepare the sockaddr_in structure
	
	return 0;
}
