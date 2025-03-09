#include <stdio.h>
#include <stdlib.h>

int main() {
  int board[3][3] = {0}; // -1 = circle, 1 = x

  int continue_game = 1;
  while (continue_game) {
    system("clear");
    printf("\t0\t1\t2\n");
    for (int i = 0; i < 3; i++) {
      printf("%d\t", i);
      for (int j = 0; j < 3; j++) {
        switch (board[i][j]) {
        case -1:
          printf("o\t");
          break;
        case 1:
          printf("x\t");
          break;
        default:
          printf("\t");
        }
      }
      printf("\n");
    }
    if (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    } else if (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1) {
      printf("Circles won\n");
      continue_game = 0;
      break;
    } else if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
      printf("Crosses won\n");
      continue_game = 0;
      break;
    }
    int row = 0, column = 0;
    printf("Circles row: ");
    scanf("%d", &row);
    printf("Circles column: ");
    scanf("%d", &column);
    board[row][column] = -1;

    printf("Crosses row: ");
    scanf("%d", &row);
    printf("Crosses column: ");
    scanf("%d", &column);
    board[row][column] = 1;
  }
}
