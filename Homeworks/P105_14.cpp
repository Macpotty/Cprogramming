#include"stdio.h"
void main()
{
	char a[5]={'A','B','C','D','E'},temp;
	int i,j;
	for(i=0;i<5;i++)
		printf("%c   ",a[i]);
	printf("\n");
	for(i=0;i<4;i++)
	{
		temp=a[0];
		for(j=0;j<4;j++)
			a[j]=a[j+1];
		a[4]=temp;
		for(j=0;j<5;j++)
			printf("%c   ",a[j]);
		printf("\n");
	}
}