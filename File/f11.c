#include <stdio.h>

int main(int argc, char** argv){
  FILE* dest, *src;
  char ch;
  if (argc == 1)
    printf("Too few arguments\n");
  if (argc == 2)
    printf("Source and destination files needed\n");
  else if (argc == 3){
    dest = fopen(argv[1], "w");
    src = fopen(argv[2], "r");
    if (!dest || !src)
      printf("Error opening file\n");
    else {
      while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);
    }
    printf("Files copied successfully\n");
  }
  else if (argc > 3)
    printf("Error, too many arguments\n");
  return 0;
}
