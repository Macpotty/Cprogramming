#include"stdio.h"
void main()
{
	int a[10][10],i,j,n;
	printf("n=");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{	
		for(i=0;i<n;i++)
			scanf("%d",&a[i][j]);
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
	printf("\n\n\n");
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
			printf("%4d",a[j][i]);
		printf("\n");
	}
}