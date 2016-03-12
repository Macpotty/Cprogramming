#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i, j, k;
    srand(time(0));
    for(i=0; i<1000; i++){
        k = rand()%100;
        printf("%3d\n", k);
        if(k > 50)
            j++;
    }
    printf("%d\n", j);
    return 0;
}
