#include <stdio.h>
#include <stdint.h>

int16_t hexToBinary(int c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    case 'A':
      return 10;
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D':
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
    }
}


int main(int argc, char *argv[]) {
  uint8_t memory [65536];
  int16_t SP; // stack pointer
  int16_t PC = 0; // program counter
  uint8_t B;
  uint8_t C;
  uint8_t D;
  uint8_t E;
  uint8_t H;
  uint8_t L;
  uint8_t A;
  uint8_t F = 0;

  while ((SP = getchar()) != EOF) {
    if (SP == '\n' || SP == ':' || SP == '$' || SP == ' ') {
      PC++;
      F = 0;
      memory[PC] = (uint8_t)SP;
      printf("line, %c\n", (char)memory[PC]);
    } else {
      F++;
      PC++;
      // printf("%d", PC);
      if (F % 2 == 1) {
        B = hexToBinary(SP) << 4;
        printf("odd: %c, %d\n", (char)SP, B);
      }
      else {
        // printf("incrementing...\n");
        C = hexToBinary(SP);
        printf("even: %c, %d\n", (char)SP, C);
        D = B + C;
        memory[PC] = D;
        printf("mementry: %d\n", memory[PC]);
        C = 0;
        D = 0;
        B = 0;
      }
    }
  }

  return 0;
}


