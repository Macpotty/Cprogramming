#include"stdio.h"
void main()
{
	int a[8],i,done,temp,*pa;
	pa=&a[7];
	printf("please input your number:\n");
	for(;;)
	{
		for(i=0;i<8;i++)
			scanf("%d",&a[i]);
		for(i=0;i<8;i++)
		{
			done=0;
			do
			{
				if(*pa<*(pa-1))
				{
					done=1;
					temp=*pa;
					*pa=*(pa-1);
					*(pa-1)=temp;
				}
				*pa--;
			}while(pa!=&a[0]);	
			pa=&a[7];
			if(done==0)
				break;
	
		}
		for(i=0;i<8;i++)
			printf("%d ",a[i]);
		printf("\n");
		continue;
	}
}