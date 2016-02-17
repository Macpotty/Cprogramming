#include"stdio.h"
void delay(int xms);
int main()
{
	int a;
	for(a=0;a<5;a++)
	{
		delay(50000);
		switch(a)
		{
			case 0:printf("this is a text\n");break;
			case 1:printf("so there gonna be five\n");break;
			case 2:printf("but I don't know how to say\n");break;
			case 3:printf("I just don't know\n");break;
			case 4:printf("but the good thing is this is over\n");break;
		}
	}
}

void delay(int xms)
{
	int i,j;
	for(i=0;i<xms;i++)
		for(j=0;j<10000;j++);
}