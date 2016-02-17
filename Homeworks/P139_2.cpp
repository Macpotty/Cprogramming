#include"stdio.h"
void main()
{
	int a[12]={15,95,48,32,45,96,71,54,37,19,32};
	int i,j,k,done,temp;
	for(i=0;i<11;i++)
	{
		done=1;
		for(j=10;j>=0;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				done=0;
			}
		}
		if(done==1)break;
	}
	for(i=0;i<11;i++)
		printf("%d ",a[i]);
	printf("\nplease input your number:");
	scanf("%d",&k);
	for(i=0;i<11;i++)
		if(k<a[i])break;
	for(j=12;j>i;j++)
		a[j]=a[j-1];
	a[i]=k;
	for(i=0;i<12;i++)
		printf("%d ",a[i]);
}