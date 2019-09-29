#include <cbm.h>
#include <stdio.h>
#include <stdlib.h>

extern const char text[];       /* In text.s */

int main() {
    cbm_k_bsout(0x8E); // fix emulator font problem

    printf("%s\n", text);
    return EXIT_SUCCESS;
}