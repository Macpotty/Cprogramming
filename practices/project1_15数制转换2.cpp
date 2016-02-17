#include"stdio.h"
#include"math.h"
int translation(int a[],int n);
int length(int n);
void main()
{
	
	int i,a[10];
	long int n;
	for(;;)
	{
		printf("请输入需要转换的2进制数：");
		scanf("%ld",&n);
		printf("这是你需要的16进制数：0x%x\n",translation(a,n));
		printf("这是你需要的10进制数：%d\n",translation(a,n));
	}
}
int translation(int a[],int n)
{
	int i=0,sum=0,length;
	while(n/(int)pow(10.0,i)!=0)
	{
		a[i]=n/(int)pow(10.0,i)%10;
		length=++i;
	}
	for(i=0;i<length;i++)
		sum+=a[i]*(int)pow(2.0,i);
	return sum;
}