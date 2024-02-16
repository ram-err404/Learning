#include <mysocket.h>

int main(int argc, char *args[]) {
  char                buffer[1024];
  int                 fd    = 0;
  int                 port  = 0;
  struct sockaddr_in  saddr;
  struct hostent      *server = NULL;

  if(3 > argc) {
    printf("Usage: ./binary_name server_ip_addr server_port");
  }
  port = atol(args[2]);
  if(0 > (fd = socket(AF_INET, SOCK_STREAM, 0))) {
    error("Socket creation failed");
  }

  if(NULL == (server = gethostbyname(args[1]))) {
    error("Error: no such host");
  }
  bzero((char*)&saddr, sizeof(saddr));
  saddr.sin_family  = AF_INET;
  saddr.sin_port        = htons(port);
  bcopy((char*)server->h_addr, (char*)&saddr.sin_addr.s_addr, server->h_length);

  if(0 > connect(fd, (struct sockaddr*)&saddr, sizeof(saddr))) {
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
