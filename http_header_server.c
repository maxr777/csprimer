#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT "8814"
#define BACKLOG 5
#define BUFFER_SIZE 65507

int main() {
  struct sockaddr_storage their_addr;
  socklen_t their_addr_len;
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

  accept(s, (struct sockaddr *)&their_addr, &their_addr_len);

  while (1) {
    char buffer[BUFFER_SIZE];
    int n = recv(s, &buffer, BUFFER_SIZE, 0);

    if (n == 0)
      break;
    else if (n < 0) {
      perror("recv() error:");
      return 1;
    }

    printf("%s\n", buffer);
  }
}
