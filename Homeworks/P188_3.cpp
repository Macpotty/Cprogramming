#include"stdio.h"
int length(char a[]);
void main()
{
	int i,n,temp;
	char a[100];
	gets(a);
	n=length(a)-1;
	for(i=0;i<n/2;i++)
	{
		temp=a[i];
		a[i]=a[n-i];
		a[n-i]=temp;
	}
	printf("%s",a);
}
int length(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}