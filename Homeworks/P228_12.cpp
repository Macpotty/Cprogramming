#include"stdio.h"
void strcat(char *str1,char *str2);
void main()
{
	char str1[100]={"Do not go gentle "},str2[100]={"into that good night."};
	printf("this is string1:%s\nthis is string2:%s\n--------------------\n",str1,str2);
	strcat(str1,str2);
	printf("this is the merged string:");
	puts(str1);
}
void strcat(char *str1,char *str2)
{
	do
	{
		str1++;
	}while(*str1!='\0');
	do
	{
		*str1++=*str2++;
	}while(*str2!='\0');
}