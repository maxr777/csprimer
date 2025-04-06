#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT "8814"
#define BACKLOG 5
#define BUFFER_SIZE 65507

int main() {
  struct addrinfo hints, *res;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if (getaddrinfo(NULL, PORT, &hints, &res) < 0) {
    perror("getaddrinfo() error:");
    return 1;
  }

  int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  if (bind(s, res->ai_addr, res->ai_addrlen) < 0) {
    perror("bind() error:");
    return 1;
  }

  if (listen(s, BACKLOG) < 0) {
    perror("listen() error:");
    return 1;
  }

  struct sockaddr_storage their_addr;
  socklen_t their_addr_size = sizeof(their_addr);
  int new_socket = accept(s, (struct sockaddr *)&their_addr, &their_addr_size);

  char buf[BUFFER_SIZE];
  if (recv(new_socket, buf, BUFFER_SIZE, 0) < 0) {
    perror("recv() error:");
    return 1;
  }

  printf("%s\n", buf);
}
