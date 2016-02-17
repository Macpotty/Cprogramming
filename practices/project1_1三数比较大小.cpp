#include"stdio.h"
void main()
{
	int a,b,c;
	printf("please input a,b,c \n");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
		if(b>c)
			printf("order is:%d,%d,%d \n",a,b,c);
		else if(a>c)
			printf("order is:%d,%d,%d \n",a,c,b);
		else
			printf("order is:%d,%d,%d \n",c,a,b);
	else if(a>c)
			printf("order is:%d,%d,%d \n",b,a,c);
	else if(b>c)
			printf("order is:%d,%d,%d \n",b,c,a);
	else
		printf("order is:%d,%d,%d \n",c,b,a);
}
