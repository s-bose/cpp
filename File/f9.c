#include <stdio.h>

int main(){
  int i, n, num, n1, n2;
  FILE* f1 = fopen("file1", "w");
  FILE* f2 = fopen("file2", "w");
  FILE *f3 = fopen("file3", "w");
  if (!f1 || !f2 || !f3)
    printf("Error opening files\n");
  else {
    printf("Enter the number of data for file1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
      scanf("%d", &num);
      putw(num, f1);
    }
    printf("Enter the number of data for file2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
      scanf("%d", &num);
      putw(num, f2);
    }
    fclose(f1);
    fclose(f2);
    f1 = fopen("file1", "r");
    f2 = fopen("file2", "r");
    n1 = getw(f1);
    n2 = getw(f2);
    while ((n1 != EOF) && (n2 != EOF)){
      if (n1 < n2){
        putw(n1, f3);
        n1 = getw(f1);
      }
      else {
        putw(n2, f3);
        n2 = getw(f2);
      }
    }
    while (!feof(f1)){
      putw(n1, f3);
      n1 = getw(f1);
    }

    while (!feof(f2)){
      putw(n2, f3);
      n2 = getw(f2);
    }

    fclose(f3);
    fclose(f1);
    fclose(f2);
    f3 = fopen("file3", "r");
    printf("The content of the merged file is:\n");
    while ((num = getw(f3)) != EOF)
      printf("%d\n", num);
  }
  return 0;
}
