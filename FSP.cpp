#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int win = 0;

int Generate_Password();
{
	char pass;
	int x;
	x=rand()%12;
	if(x == 10)
		pass = '#';
	else {
		if(x == 11)
			pass = '*';
		else
			pass = '0' + x;
	}
	return pass;
}

int Guess()
{
	int x;
	char guess_pass;
	x=rand()%12;
	if(x == 10)
		guess_pass = '#';
	else {
		if(x == 11)
			guess_pass = '*';
		else
			guess_pass = '0' + x;
	}
	return guess_pass;
	
}

int Check(int Status[])
{
	int i;
	for(i=0;i<4;i++)
	{
		if(Status[i]!=2)
			return 0;
	}
	win = 1;
	return 1;
}

int WrongStatus(int status[], int status1[]){
	int i;
	for(i=0; i<4; i++)
		if(status[i] == 2 && status[i] != status1[i])
			return 1;
	return 0;		
}

int main()
{
	srand(time(NULL));
	char G_Pass[4],temp;
	int i,j;
	int status[4]={0},status1[4]={0};
	for(i=0;i<4;i++)
	{
		
		printf("%c ",Generate_Password());
	}
	printf("\n");
	printf("GUESS1:");
	for(i=0;i<4;i++)
	{
		G_Pass[i]=Guess();
		printf("%c ",G_Pass[i]);
	}
	printf("\n");
	for(i=0;i<4;i++)
		scanf("%d",&status[i]);
	for(i=0;!Check(status) && i<9;i++)
	{
		for(j=0;j<4;j++)
		{
			if(status[j]==0)
				G_Pass[j]=Guess();
		}
		for(j=0;j<4;j++)
		{
			if(status[j]==1)
			{
				while(1)
				{
					int x=rand()%4;
					if(status[x]!=2)
					{
						temp=G_Pass[j];
						G_Pass[j]=G_Pass[x];
						G_Pass[x]=temp;
						break;
					}	
				}		
			}
		}
		printf("GUESS %d:",i+2);
		for(j=0;j<4;j++)
			printf("%c",G_Pass[j]);
		printf("\n");
		for(j=0;j<4;j++)
			scanf("%d",&status1[j]);
			
		if(WrongStatus(status, status1)){
			printf("The guidance was wrong. Be more careful and helpful.\n");
			--i;
			continue;
		}
		for(j=0;j<4;j++)
			status[j] = status1[j];	
	}
	if (win == 0)
		printf("Ruuuuun!!!!");
	else
		printf("Congrats!! You Cracked The Password");
}
