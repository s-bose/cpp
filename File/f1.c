#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	int i, n, num;
	if ((fp = fopen("number.txt", "w")) != NULL){
		printf("Enter how many numbers do you want: ");
		scanf("%d", &n);
		printf("Enter the numbers: \n");
		for (i = 0; i < n; i++){
			scanf("%d", &num);
			putw(num, fp);
		}
		fclose(fp);
		fp = fopen("number.txt", "r");
		printf("Reading from the file: \n");
		while ((num = getw(fp)) != EOF){
			printf("%d ", num);
		}
		printf("\n");
		fclose(fp);

	}

  else{
    printf("unable to open file for write: \n");
  }
  return 0;
}
