#include"stdio.h"
#include<stdlib.h>
#include"math.h"
int main()
{
	printf("请输入水仙花数搜寻的上限值(不得超过10^10)：");
	double place[10];
	int n,m;
	long long sum,i,j;
	i=100;
	n=3;
	scanf("%lld",&j);
	do
	{
		sum=0;
		while(1)
		{
			if(i-pow(10.0,n)>=0)
			{
				n++;
				break;
			}
			else break;
		}
		for(m=0;m<10;m++)
		{
			
			place[m]=i/((long long int)(pow(10.0,m)))%10;
			sum+=pow(place[m],n);
		}
		if(sum==i)
			printf("%lld\n",i);
		i++;
	}while(i<j);
	system("pause");
	return 0;
}