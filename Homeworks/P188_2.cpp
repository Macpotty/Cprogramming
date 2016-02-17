#include"stdio.h"
void sort(int a[10]);
void main()
{
	int a[10],i;
	printf("please input your numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	sort(a);
	for(i=0;i<10;i++)
	{
		if(a[i]==a[i+1])
		{
			continue;
		}
		printf("%-4d",a[i]);
	}
}
void sort(int a[])
{
	int *pa,i,done,temp;
	for(i=0;i<10;i++)
	{
		done=1;
		pa=&a[0];
		do
		{
			if(*pa<*(pa+1))
			{
				done=0;
				temp=*pa;
				*pa=*(pa+1);
				*(pa+1)=temp;
			}
			pa++;
		}
		while(pa<=&a[9]);
		if(done==1)break;
	}
}