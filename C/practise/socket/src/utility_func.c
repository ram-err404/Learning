#include <mysocket.h>

void error(const char *msg) {
  perror(msg);
  exit(0);
}
