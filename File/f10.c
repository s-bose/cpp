#include<stdio.h>
#include<stdlib.h>
struct stnd
{
	int roll,marks;
	char name[50],stream[30],session[20];
};
typedef struct stnd stnd;

void insert();
void Delete();
void display();
void modify();

//main
int main(){
	int ch;
	while(1)
	{
		printf("\n\tEnter 1 to Insert a row.");
		printf("\n\tEnter 2 to Delete a row.");
		printf("\n\tEnter 3 to Display the database.");
		printf("\n\tEnter 4 to Modify a row.");
		printf("\n\t\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				display();
				break;
			case 4:
				modify();
				break;

			case 5:
				exit(0);
			default:
				printf("Wrong input .\nplease try again......\n");
				break;
		}
	}
	return 0;
}


void insert(){
	FILE *fp;
	stnd s;
	fp=fopen("students.txt","a");
	//fprintf(fp,"Roll_No.\tName\tStream\tSession\tMarks\n");
	printf("\nenter the roll:");
	scanf("%d",&s.roll);
	printf("\nenter the name: ");
	scanf("%s",s.name);
	printf("\nEnter the stream: ");
	scanf("%s",s.stream);
	printf("\nEnter the session: ");
	scanf("%s",s.session);
	printf("\n the the marks: ");
	scanf("%d",&s.marks);
	fprintf(fp,"%d\t%s\t%s\t%s\t%d\n",s.roll,s.name,s.stream,s.session,s.marks);
	fclose(fp);
}

//Display()
void display()
{
	FILE *fp;
	stnd s;
	printf("\n now it's time to read:\n");
	fp=fopen("students.txt","r");
	if(fp==NULL)
	{
		printf("\nFILE NOT FOUND\n");
		return;
	}
	else
	{
		printf("\nRoll_No.\t\tName\t\tStream\t\tSession\t\tMarks\n");
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%s\t%s\t%s\t%d\n",&s.roll,s.name,s.stream,s.session,&s.marks);
			printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\n",s.roll,s.name,s.stream,s.session,s.marks);
		}
	fclose(fp);
	}
}

//Delete
void Delete()
{
	FILE *fp,*fp1;
	stnd s;
	int rll,st;
	printf("\n enter the roll no. of the student: ");
	scanf("%d",&rll);
	fp=fopen("students.txt","r");
	fp1=fopen("temp.txt","w");
	//printf("Roll_No.\tName\tStream\tSession\tMarks\n");
	while(!feof(fp))
	{
		fscanf(fp,"%d\t%s\t%s\t%s\t%d\n",&s.roll,s.name,s.stream,s.session,&s.marks);
		if(s.roll!=rll)
			fprintf(fp1,"%d\t%s\t%s\t%s\t%d\n",s.roll,s.name,s.stream,s.session,s.marks);
		/*else
			continue;*/
	}
	fclose(fp);
	fclose(fp1);
	remove("students.txt");
	fp=fopen("students.txt","w");
	fp1=fopen("temp.txt","r");
	//printf("Roll_No.\tName\tStream\tSession\tMarks\n");
	while(!feof(fp1))
	{
		fscanf(fp1,"%d\t%s\t%s\t%s\t%d\n",&s.roll,s.name,s.stream,s.session,&s.marks);
		fprintf(fp,"%d\t%s\t%s\t%s\t%d\n",s.roll,s.name,s.stream,s.session,s.marks);
	}
	fclose(fp);
	fclose(fp1);
	//st=remove("temp.txt");

}

//Modify()
void modify()
{
	FILE *fp,*fp1;
	stnd s;
	int rll,st,ch;
	printf("\n enter the roll no. of the student: ");
	scanf("%d",&rll);
	fp=fopen("students.txt","r");
	fp1=fopen("temp.txt","w");

	while(!feof(fp))
	{
		fscanf(fp,"%d\t%s\t%s\t%s\t%d\n",&s.roll,s.name,s.stream,s.session,&s.marks);
		if(s.roll==rll)
		{
			printf("\n\tEnter 1 to modify name.\n\tEnter 2 to modify stream.\n\tEnter 3 to modify session.\n\tEnter 4 to modify marks.\n");
			printf("\n\tEnter your choice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\nEnter the name: ");
					scanf("%d",s.name);
					break;
				case 2:
					printf("\nEnter the stream: ");
					scanf("%d",s.stream);
					break;
				case 3:
					printf("\nEnter the name: ");
					scanf("%d",s.session);
					break;
				case 4:
					printf("\nEnter the marks: ");
					scanf("%d",&s.marks);
					break;
				default:
					printf("\n\tPlease try again..............");
					break;
			}
		}
		fprintf(fp1,"%d\t%s\t%s\t%s\t%d\n",s.roll,s.name,s.stream,s.session,s.marks);
	}
	fclose(fp);
	fclose(fp1);
	fp=fopen("students.txt","w");
	fp1=fopen("temp.txt","r");
	//printf("Roll_No.\tName\tStream\tSession\tMarks\n");
	while(!feof(fp1))
	{
		fscanf(fp1,"%d\t%s\t%s\t%s\t%d\n",&s.roll,s.name,s.stream,s.session,&s.marks);
		fprintf(fp,"%d\t%s\t%s\t%s\t%d\n",s.roll,s.name,s.stream,s.session,s.marks);
	}
	fclose(fp);
	fclose(fp1);
	st=remove("temp.txt");
}
