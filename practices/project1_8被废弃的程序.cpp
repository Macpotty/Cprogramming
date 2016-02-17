#include"stdio.h"
int main() {
	double *q;
	int i;
	double v[10] = { 1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9 };
	q = &v[0];
		printf("%f\n", *(q+9));
}