#include <stdio.h>

int main(){
  char ch;
  FILE* f1 = fopen("blanks.txt", "w");
  FILE* f2 = fopen("copy.txt", "w");
  printf("Enter the text\n");
  while ((ch = getchar()) != '\n')
    fputc(ch, f1);
  fclose(f1);
  f1 = fopen("blanks.txt", "r");
  while ((ch = getc(f1)) != EOF){
    fputc(ch, f2);
    if (ch == 32){
      while ((ch = getc(f1)) == 32);
      fputc(ch, f2);
    }
    fclose(f1);
    fclose(f2);

  }
  return 0;
}
