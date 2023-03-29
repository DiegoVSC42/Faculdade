#include <stdio.h>

int main (int argc, char const *argv[]){

    float x, y;

    scanf("%f %f", &x, &y);
    
    if(x > 0){
        if (y > 0){
            printf("Primeiro Quadrante\n");
        }else {
            printf("Quarto Quadrante\n");
        }
    }else {
        if (y < 0){
            printf("Terceiro Quadrante\n");
        }else {
            printf("Segundo Quadrante\n");
        }
    }

    return 0;
    
}