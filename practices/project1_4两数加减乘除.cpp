#include"stdio.h"
int main()
{
	long a,b,sum,i;
	char c;
	for(;;)
	{
		scanf("%d%c%d",&a,&c,&b);
		switch(c)
		{
			case '+':sum=a+b;break;
			case '-':sum=a-b;break;
			case '*':sum=a*b;break;
			case '/':sum=a/b;break;
		}
		printf("here you are:%d\n",sum);
		continue;
	}
}

