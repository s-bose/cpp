#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	char ch;
	if ((fp=fopen("one.txt","w")) != NULL){
		printf("Enter the characters: \n");
		fflush(stdin);
		while ((ch = getchar()) != '\n')
			putc(ch, fp);
		fclose(fp);
	}
	else
		printf("Error opening file for writing.\n");
	fp = fopen("one.txt", "r");
	printf("Reading the file\n");
	while ((ch = getc(fp)) != EOF)
			putchar(ch);
	fclose(fp);
	return 0;
}
