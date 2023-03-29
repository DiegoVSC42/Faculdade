#include <stdio.h>

int main (int argc, char const *argv[]){

    float b, h , a, p;

    scanf("%f", &b);
    scanf("%f", &h);

    a = b * h;
    
    printf("a area do retangulo eh %.0f\n", a);
    
    p = 2 * b + 2 * h;

    printf("o perimetro do retangulo eh %.0f", p);
    
    printf("\n");

    return 0;

}