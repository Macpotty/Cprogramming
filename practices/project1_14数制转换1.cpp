#include"stdio.h"
void translation(int a[],int i);
void main()
{
	int i,a[100],j;
	for(j=0;j<100;j++)
		a[j]=8;
	for(;;)
	{
		printf("请输入需要转换10进制数：0x");
		scanf("%d",&i);
		translation(a,i);
		printf("这是你需要的8进制数：");
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