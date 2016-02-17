#include"stdio.h"
#include"math.h"
#define PI 3.14159
void main()
{
	double a,b;
	float i;
	for(i=0;i<=180;i=i+5)
	{
		a=sin(i/180*PI);
		b=cos(i/180*PI);
		printf("%f   %f\n",a,b);
	}
}