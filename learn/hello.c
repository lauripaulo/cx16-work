#include <conio.h>

const unsigned int addr = 0x1000;

// cl65 -t cx16 -O -m helloc.map -o HELLOC.PRG hello.c

int main() {
  unsigned int indx;
  unsigned short int level[] = {1, 2, 3, 4, 5, 6};

  // pointer to a memory address
  unsigned int *var = (unsigned int*)0x1000;
  unsigned int *var2 = (unsigned int*)0x1002;

  // set memory addres value
  *var = (unsigned short int) 9;
  *var2 = (unsigned int) 0xFEFE;

  cprintf("HELLO FROM C!");
  for (indx = 0; indx < 10; ++indx)
  {
    cputsxy(indx, indx, "*");
  }
  cprintf("Address indx: %4p / Level array: %4p / Var:%4p\n", &indx, &level, var);
  return 0;
}
