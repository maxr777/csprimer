#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT "8814"
#define BACKLOG 5

int main() {
  struct addrinfo hints, *res;
  int s;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if (getaddrinfo(NULL, PORT, &hints, &res) < 0) {
    perror("getaddrinfo() error:");
    return 1;
  }

  s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  if (bind(s, res->ai_addr, res->ai_addrlen) < 0) {
    perror("bind() error:");
    return 1;
  }

  listen(s, BACKLOG);
}
