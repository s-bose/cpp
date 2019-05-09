#include <stdio.h>

int main(){
  FILE* fp, *feven, *fodd;
  int i, n, num;
  if ((fp = fopen("abc.txt", "w")) != NULL){
      printf("How many data do you want to enter: ");
      scanf("%d", &n);
      for (i = 0; i < n; i++){
        scanf("%d", &num);
        putw(num, fp);
      }
      fclose(fp);
      feven = fopen("even.txt", "w");
      fodd = fopen("odd.txt", "w");
      fp = fopen("abc.txt", "r");
      if (feven == NULL || fodd == NULL || fp == NULL)
        printf("error opening files\n");
      else {
        while ((num = getw(fp)) != EOF){
          if (num % 2)
            putw(num, fodd);
          else
            putw(num, feven);
        }
      }
      fclose(fp);
      fclose(fodd);
      fclose(feven);
      fodd = fopen("odd.txt", "r");
      feven = fopen("even.txt", "r");
      printf("\ncontents of odd.txt:\n");
      while ((num = getw(fodd)) != EOF)
        printf("%d ", num);
      printf("\ncontents of even.txt:\n");
      while ((num = getw(feven)) != EOF)
        printf("%d ", num);

      fclose(feven);
      fclose(fodd);
  }
  else
    printf("error opening files\n");
  return 0;
}
