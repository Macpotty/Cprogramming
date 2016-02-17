#include"stdio.h"
#define M 20
void main()
{
	int i,j,k=0,n,a[M];
	scanf("%d",&n);
	for(i=0;i<M;i++)
		a[i]=i+1;
	i=-1;
	do
	{
		for(j=0;j!=n;j++)
		{
			i++;	
			if(i==M)i=0;
			if(a[i]==0)
				j--;
		}
			printf("%-4d",a[i]);
			a[i]=0;
		k++;
	}while(k<M);
}