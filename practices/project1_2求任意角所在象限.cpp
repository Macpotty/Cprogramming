#include"stdio.h"
void main()
{
	int intangle;
	float angle;
	printf("please input angle. \n");
	scanf("%f",&angle);
	intangle=(int)angle;
	if(intangle>=0)
		intangle=intangle%360;
	else
	{	
		intangle=(-intangle)%360;
		intangle=360-intangle;
	}
	switch(intangle/90)
	{
		case 0:printf("the frist\n");break;
		case 1:printf("the second\n");break;
		case 2:printf("the third\n");break;
		case 3:printf("the fourth\n");
	}
}