#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 5, b = 12, c = 5;
    int *p;
    int *q;
    p = &a;
    q = &b;
    //(*pe)++;
    c = *p + *q;

    printf(" P = %d, Q = %d, C = %d\n", *p,*q,c);


    printf("\n");
    return 0;
}