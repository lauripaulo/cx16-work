#include <cbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hello.h"

extern const char text[];       /* In text.s */
extern const char head[];       /* In text.s */

int main() {

    unsigned int start_time = 0;
    unsigned int end_time = 0;
    unsigned int total_time = 0;

    start_time = get_current_time();
    cbm_k_bsout(0x8E); // fix emulator font problem

    printf("%s\n", head);
    say_hello_alot();
    printf("%s\n", text);

    end_time = get_current_time();

    total_time = end_time - start_time;
    printf("time -> start: %u / end: %u / total: %u", start_time, end_time, \
      total_time);

    return EXIT_SUCCESS;
}

void say_hello_alot() {
  unsigned char i;
  for (i = 0; i<33; ++i) {
    printf("=- hello world! x%d -=\n", i);
  }
}

unsigned int get_current_time() {
  struct timespec now;
  clock_gettime(clock(), &now);
  return (unsigned int) now.tv_sec;
}
