#include "stdio.h"
#include "time.h"
int main(){
    int i;
    for(i = 0;i < 1000;i++)
        printf("%f",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
