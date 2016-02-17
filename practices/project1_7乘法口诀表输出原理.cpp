#include"stdio.h"
void delay(int xms);
int main()
{
	int i,j,k;
	delay(5000);
	printf("%15d",1);
	for(i=2;i<10;i++)
	{
		delay(5000);
		printf("%4d",i);
	}
	printf("\n\n\n");
	for(i=1;i<10;i++)
	{
		printf("%7d%4c",i,' ');
		for(j=1;j<10;j++)
		{
			delay(5000);
			k=i*j;
			printf("%4d",k);
		}
		printf("\n\n");
	}
}

void delay(int xms)
{
	int i,j;
	for(i=0;i<xms;i++)
		for(j=0;j<10000;j++);
}