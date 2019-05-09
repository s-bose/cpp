#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
  char ch;
	fp=fopen("f5.c","r");
	while((ch = getc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
  return 0;
}
