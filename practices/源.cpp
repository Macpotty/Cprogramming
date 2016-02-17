#include"stdio.h"
#include"string.h"
void main()
{
	char a[80]="zworld",b[]=" world";
	int n;
	n=strcmp(a,b);
	printf("%s\n%d",a,n);
}