#include"stdio.h"
void translation(int a[],int i);
void main()
{
	int i,a[100],j;
	for(j=0;j<100;j++)
		a[j]=8;
	for(;;)
	{
		printf("��������Ҫת��10��������0x");
		scanf("%d",&i);
		translation(a,i);
		printf("��������Ҫ��8��������");
		for(j=0;j<100;j++)
		{
			if(a[j]==8)
				continue;
			else printf("%d\n",a[j]);
		}
	}
}
void translation(int a[],int i)
{
	int j;
	for(j=99;j>=0;j--)
	{
		a[j]=i%8;
		i/=8;
		j--;
		if(i<8)break;
	}
	a[j]=i;
}