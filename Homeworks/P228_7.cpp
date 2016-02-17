#include"stdio.h"
#include"string.h"
void squeeze(char *s1,char *s2);
void main()
{
	int i;
	char s1[100],s2[100];
	printf("please input str1:");
	scanf("%s",s1);
	printf("please input str2:");
	scanf("%s",s2);
	squeeze(s1,s2);
	puts(s1);
}
void squeeze(char *s1,char *s2)
{
	int strlen2,strlen1,k;
	strlen2=strlen(s2);
	strlen1=strlen(s1);
	do
	{
		do
		{	
			if(*s1==*s2)
			{
				k=0;
				do
				{
					*s1=*(s1+1);
					s1++;
					k++;
				}while(*s1!='\0');
				strlen1--;
				s1-=k;
			}
			s2++;
		}while(*s2!='\0');
		s2-=strlen2;
		s1++;
	}while(*s1!='\0');
	s1-=strlen1;
}