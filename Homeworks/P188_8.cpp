#include"stdio.h"
#include"math.h"
int digit(int n,int k);
int length(int n);
void main()
{
	int n,num,k;
	printf("please input your number:");
	scanf("%d",&n);
	printf("input the key:");
	scanf("%d",&k);
	num=digit(n,k);
	printf("the key-number:%d",num);
}
int digit(int n,int k)
{
	int i,a[100],m;
	m=length(n);
	for(i=0;i<m;i++)
		a[i]=n/(int)pow(10.0,i)%10;
	if(k-1>=m)
		return 0;
	else
		return a[k-1];
}
int length(int n)
{
	int i=0;
	do 
	{
		i++;
	}while(n/(int)pow(10.0,i)!=0);
	return i;
}