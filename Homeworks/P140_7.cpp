#include "stdio.h"
int main()
{
	int i,j,done,temp,a[7];
	for(i=0;i<7;i++)
		scanf("%d",&a[i]);
	for(i=0;i<7;i++)
	{
		for(j=6;j>=0;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	printf("排序后成绩为：\n");
	for(i=0;i<7;i++)
		printf("%4d\n",a[i]);
	return 0;
}