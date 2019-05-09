#include<stdio.h>
#include<string.h>
int main(){
	FILE *fp;
	int n, roll, marks, i, m;
	char name[20], nm[20];
	fp=fopen("student.txt","w");
	printf("\nthe number of students: ");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("\nenter the roll:");
		scanf("%d",&roll);
		printf("\nenter the name: ");
		scanf("%s",name);
		printf("\nthe the marks: ");
		scanf("%d",&marks);
		fprintf(fp,"%d\t%s\t%d\n", roll, name, marks);
	}
	fclose(fp);
	printf("\nreading the file:\n");
	fp=fopen("student.txt","r");
	printf("\nroll\tname\tmarks\n");
	fscanf(fp,"%d%s%d",&roll, name, &marks);
	printf("\n%d\t%s\t%d", roll, name, marks);
	strcpy(nm, name);
	m=marks;
	for(i=1;i<n;i++){
		fscanf(fp,"%d%s%d",&roll,name,&marks);
		if(m<marks){
			m=marks;
			strcpy(nm,name);
		}
		printf("\n%d\t%s\t%d",roll,name,marks);
	}
	printf("\n");
	printf("\n%s got highest marks.", nm);
	fclose(fp);
}
