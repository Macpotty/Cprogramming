#include"stdio.h"
void main()
{
	char a[40]={"For this night "},b[40]={"and all nights to come."} ;
	int i,j;
	puts(a);
	puts(b);
	for(i=0;i<40;i++)
		if(a[i]==0)break;
	for(j=0;j<40;i++,j++)					//ÓÃwhileÔõÃ´Ð´
	{
		a[i]=b[j];
		if(a[i]==0)
		{
			a[i]='\0';
			break;
		}
	}
	puts(a);
}