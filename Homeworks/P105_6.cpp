#include"stdio.h"
#define PI 3.14159
void main()
{
	float r,h,C,S1,S2,V;
	printf("please input your parameters:r=1.5,h=3\nr=");
	scanf("%f",&r);
	printf("h=");scanf("%f",&h);
	C=2*r*PI;
	S1=r*r*PI;
	S2=4*PI*r*r;
	V=S1*h;
	printf("C=%5.2f   S1=%5.2f   S2=%5.2f   V=%5.2f\n",C,S1,S2,V);
}