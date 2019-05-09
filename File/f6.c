#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
  FILE *f1, *f2;
  char ch;
  f1 = fopen(argv[1], "a");
  f2 = fopen(argv[2], "r");
  if (f1 == NULL || f2 == NULL)
    printf("Error opening file\n");
  else {
    while ((ch = getc(f2)) != EOF)
      putc(ch, f1);
  }
  return 0;
}
