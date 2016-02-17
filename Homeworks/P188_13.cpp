#include"stdio.h"
void yang(int n);
int facl(int a);
void main()
{
	int n;
	printf("ÇëÊäÈëÑî»ÔÈı½Ç½×Êı£º");
	scanf_s("%d", &n);
	yang(n);
}
void yang(int n)
{
	int i,j,k;
	for(k=0;k<=n;k++)
	{
		if(k==0)
		{
			for(i=0;i<n-k;i++)
				printf("  ");
			printf("%4d",1);
		}
		else
		{
			for(i=0;i<n-k;i++)
				printf("  ");
			for(j=0;j<=k;j++)
			{
				if(j==0)
					printf("%4d",1);
				else if(k-j==0)
					printf("%4d",1);
				else
					printf("%4d",facl(k)/(facl(j)*facl(k-j)));
			}
		}
		printf("\n");
	}
}
int facl(int a)
{
	int i;
	if(a==1)
		i=1;
	else
		i=a*facl(a-1);
	return i;
}