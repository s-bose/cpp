#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
  char ch;
  FILE* dest, *src;
  dest = fopen(argv[1], "w");
  src = fopen(argv[2], "r");
  if (dest == NULL || src == NULL)
    printf("error opening files\n");
  else {
    while (!feof(src)){
      if ((ch = getc(src)) != EOF)
        putc(ch, dest);
    }
  }
  fclose(src);
  fclose(dest);
  return 0;
}
