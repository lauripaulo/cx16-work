#include <cbm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hello.h"

extern const char text[];       /* In text.s */
extern const char head[];       /* In text.s */

int main() {

    cbm_k_bsout(0x8E); // fix emulator font problem

    printf("%s\n", head);
    say_hello_alot();
    printf("%s\n", text);

    return EXIT_SUCCESS;
}

void say_hello_alot() {
  unsigned char i;
  for (i = 0; i<33; ++i) {
    printf("=- hello world! x%d -=\n", i);
  }
}
