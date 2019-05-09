#include <stdio.h>

int main(){
  FILE* fp;
  int n, i, num;
  int max = -999;
  if ((fp = fopen("num.txt", "w")) != NULL){
    printf("Enter how many numbers do you want: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
      scanf("%d", &num);
      putw(num, fp);
    }
    fclose(fp);
  }
  else
    printf("Error opening file for writing\n");
  fp = fopen("num.txt", "r");
  while ((num = getw(fp)) != EOF){
    if (num > max)
      max = num;
  }
  printf("the highest number is: %d\n", max);
  return 0;
}
