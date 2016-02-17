#include"stdio.h"
#include"string.h"
void copym(char *str1,char *str2,int m);
void main()
{
	char copystr[100]={0},str[]={"Do not go gentle into thay good night"};
	int n,m;
	n=strlen(str);
	printf("this is the string:%s\nplease input the key:",str);
	for(;;)
	{
		scanf("%d",&m);
		if(m>n)
		{
			printf("warning!please try again:");
			continue;
		}
		else break;
	}
	copym(str,copystr,m);
	puts(copystr);
}
void copym(char *str1,char *str2,int m)
{
	int i;
	for(i=0;i<m;i++,str1++);
	do
	{
		*str2++=*str1++;
	}while(*str1!='\0');
}