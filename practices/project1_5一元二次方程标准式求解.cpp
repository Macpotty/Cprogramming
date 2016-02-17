#include"stdio.h"
#include"math.h"
float main()
{
	printf("请将方程化为一般式，输入参数a,b,c\n");
	float a,b,c,i,x1,x2;
	for(;;)
	{
		printf("a=");scanf("%f",&a);
		printf("b=");scanf("%f",&b);
		printf("c=");scanf("%f",&c);
		i=b*b-4*a*c;
		if(i<0)
			printf("无解\n");
		else
		{
			x1=(-b-sqrt(i))/2*a;
			x2=(-b+sqrt(i))/2*a;
			printf("x1=%f,x2=%f\n",x1,x2);
		}
		continue;
	}
}