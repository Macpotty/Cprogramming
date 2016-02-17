#include"stdio.h"
void main()
{
	int i,j,k,temp,a[8];
	printf("hello,captain!\n");
	for(i=0;i<8;i++)
		scanf("%d",&a[i]);
	for(i=0;i<8;i++)
	{
		k=i;
		for(j=i+1;j<8;j++)
			if(a[j]<a[k])k=j;
		if(k!=i)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	for(i=0;i<8;i++)
		printf("%-4d",a[i]);
}