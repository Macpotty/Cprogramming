#include"stdio.h"
#include"math.h"
#define PI 3.14159
#define c 2.997924*(10^8)
#define h 6.6252*(10^-34)
#define beta 5.6689*(10^-8)
float main()
{
	float T,lamda,E;
	printf("please input your parameters:\nT=");
	scanf("%f",&T);
	printf("lamda=");
	scanf("%f",&lamda);
	E=(2*PI*c*h*pow((lamda),(-5)))/(exp((c*h)/(beta*lamda*T))-1);
	printf("E=%f",E);
}