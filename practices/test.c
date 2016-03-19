#include <stdio.h>
#include <stdlib.h>

typedef struct Class{
    int a;
    int (*generator)(struct Class *this);
}Class;


int func(struct Class *this){
    this->a++;
    printf("%d", this->a);
}

Class *ClassCtreator(){
    Class *this;
    this = (Class*)malloc(sizeof(Class));
    this->a = 0;
    this->generator = func;
    return this;
}

int main()
{
    Class *p = ClassCtreator();
    p->generator(p);
    printf("%d", p->a);
}
