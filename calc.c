#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(void) {
  long int value[4];
  int height = 0;
  char w[32 + 1];
  while (scanf("%32s", w) == 1) {
    char *p;
    errno = 0;
    long int x = strtol(w, &p, 10);
    if (*p == '\0' && errno == 0) {
      if (height >= 4) {
        printf("error stack\n");
        exit(EXIT_FAILURE);
      }
      value[height++] = x;
    } else if (strcmp(s, "ADD") == 0
            || strcmp(s, "SUB") == 0
            || strcmp(s, "QUO") == 0
            || strcmp(s, "REM") == 0
            || strcmp(s, "MUL") == 0
            || strcmp(s, "END") == 0) {
      if (strcmp(w, "END") == 0) {
        if (height != 1) {
          printf("error\n");
          exit(EXIT_FAILURE);
        } else {
          printf("%ld\n", value[0]);
          break;
        }
      } if (height < 2) {
        printf("error\n");
        exit(EXIT_FAILURE);
      } if (strcmp(w, "ADD") == 0) {
        --height;
        value[height - 1] += value[height];
      } else if (strcmp(w, "SUB") == 0) {
        --height;
        value[height - 1] -= value[height];
      } else if (strcmp(w, "QUO") == 0) {
        --height;
        value[height - 1] /= value[height];
      } else if (strcmp(w, "REM") == 0) {
        --height;
        value[height - 1] %= value[height];
      } else if (strcmp(w, "MUL") == 0) {
        --height;
        value[height - 1] *= value[height];
      } else {
        printf("error\n");
        exit(EXIT_FAILURE);
      }
    } else {
      printf("error\n");
      exit(EXIT_FAILURE);
    }
  }
  return EXIT_SUCCESS;
}
