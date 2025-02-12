#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#define BUFFER_SIZE 65507

int main() {
  int s = socket(AF_INET, SOCK_DGRAM, 0);
  if (s < 0) {
    perror("socket failed");
    return 1;
  }

  struct sockaddr_in sa;
  inet_pton(AF_INET, "127.0.0.1", &(sa.sin_addr));
  socklen_t sender_len = sizeof(sa);

  int b = bind(s, (struct sockaddr *)&sa, sender_len);
  if (b < 0) {
    perror("bind failed");
    return 1;
  }

  while (1) {
    char buffer[BUFFER_SIZE];
    recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr *)&sa, &sender_len);
    printf("%s\n", buffer);
  }
}
