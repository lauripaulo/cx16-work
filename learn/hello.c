#include <conio.h>
#include "second.h"

const unsigned int addr = 0x1000;

// cl65 -t cx16 -O -m helloc.map -o HELLOC.PRG hello.c

// pointer to a memory address
unsigned int *p_start = (unsigned int *) 0x2000;
unsigned int *p_end = (unsigned int *) 0x2002;

int main() {
  unsigned int indx;
  unsigned short int level[] = {1, 2, 3, 4, 5, 6};
  int sum_value = add_test(5, 5);

  // set memory addres value
  *p_start = (unsigned short int) 9;  // 9
  *p_end = (unsigned int) 0x0FEF;     // 4079

  clrscr();
  for (indx = 0; indx < 10; ++indx)
  {
    cputsxy(indx, indx, "*");
  }
  gotoxy(1, 12);
  cprintf("ADDRESS INDX: %p / VALUE: %d\n", &indx, indx);

  // pointer address and pointer value example
  gotoxy(1, 13);
  cprintf("P_START ADDR: %4p / VALUE: %d\n", p_start, *p_start);

  // pointer address and pointer value example
  gotoxy(1, 14);
  cprintf("P_END ADDR: %4p / VALUE: %d\n", p_end, (unsigned int) *p_end);

  // test call function
  gotoxy(1, 15);
  cprintf("SUM VALUE: %i", sum_value);

  // end
  gotoxy(1, 16);
  cprintf("HELLO FROM C! PRESS ANY KEY TO EXIT...");
  cgetc();
  return 0;
}
