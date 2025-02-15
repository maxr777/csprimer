#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#define BUFFER_SIZE 65507

int main() {
  int sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sfd < 0) {
    perror("socket failed");
    return 1;
  }

  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  sa.sin_port = htons(8888);
  sa.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(sa.sin_zero, '\0', sizeof(sa.sin_zero));

  socklen_t sender_len = sizeof(sa);

  if (bind(sfd, (struct sockaddr *)&sa, sender_len) < 0) {
    perror("bind failed");
    return 1;
  }

  while (1) {
    char buffer[BUFFER_SIZE];
    recvfrom(sfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sa, &sender_len);
    sendto(sfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sa, sender_len);
  }
}
