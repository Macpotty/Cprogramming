#include"stdio.h"
void main()
{
	long long int a,b,k;
	int i,j,n;
	printf("this is a program for Fibonacci Sequence and hello captain\n");
	for(;;)
	{	
		scanf("%d",&n);
		a=1;b=1;
		if(n%2==0)
			j=n/2;
		else
			j=n/2+1;
		for(i=1;i<j;i++)
		{
			a+=b;
			b+=a;
		}
		if(n%2==0)
			k=b;
		else
			k=a;
		printf("%dth=%lld\n",n,k);
		continue;
	}
}