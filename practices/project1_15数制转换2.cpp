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
		printf("��������Ҫת����2��������");
		scanf("%ld",&n);
		printf("��������Ҫ��16��������0x%x\n",translation(a,n));
		printf("��������Ҫ��10��������%d\n",translation(a,n));
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