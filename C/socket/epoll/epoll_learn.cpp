#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

using namespace std;

#define PORT 8888
enum {
  SUCCESS = 0,
  FAIL
};

enum {
  FALSE=0,
  TRUE
};


int main() {
  uint32_t epoll_fd = epoll_create1(0);

  if(epoll_fd == -1) {
    cout<<"Failed to create epoll file descriptor"<<endl;
    return -1;
  }
  cout<<"epoll file descriptor created successfully: "<< epoll_fd << endl;

  if(close(epoll_fd)) {
    cout<<"Failed to close epoll file descriptor"<<endl;
    return -1;
  }

  return 0;
}
