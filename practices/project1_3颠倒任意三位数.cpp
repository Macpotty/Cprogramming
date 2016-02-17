#include"stdio.h"
int main()
{
	int a,b,c,d;
	printf("please input your number \n");
	scanf("%d",&a);
	b=a/100;c=a%100/10;d=a%10;
	printf("your number is: %1d%1d%1d \n",d,c,b);
}