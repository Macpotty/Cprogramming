#include"stdio.h"
#include"string.h"
void getint(char *pa,int *pb);
void main()
{
	int i,b[100];
	char a[100];
	printf("请输入所需转换的字符串：");
	scanf("%s",a);
	getint(a,b);
	for(i=0;i<strlen(a);i++)
		printf("%-4d",b[i]);
}
void getint(char *pa,int *pb)
{
	do
	{
		*pb=(int)*pa;
		pb++;
		pa++;
	}while(*pa!='\0');
}