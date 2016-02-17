# include<stdio.h>
# define N 9
void main()
{
	int i,j,t;
	int a[N]={2,3,5,7,8,1,9,4,6};
	printf ("待排数列为:");
	for (i=0;i<N;i++)
	printf ("%d",a[i]);
	for (j=0;j<N;j++)
		for (i=0;i<N-j;i++)
		if (a[i]<a[i+1])
			{
				t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
			}
	printf ("排序后数列为:");
	for (i=0;i<N;i++)
	printf ("%d",a[i]);

}