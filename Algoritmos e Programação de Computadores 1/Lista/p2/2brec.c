//Calcule o fatorial de K de forma iterativa e de forma recursiva.


#include<stdio.h>

long int fatorial(long int numero){
    long int fator;

    if(numero <= 1){
        return 1;
    }else{
        fator = numero * fatorial(numero-1); 
        return fator;
    }
}
int main (int argc, char const *argv[]){

    long int numero,resultado;

    scanf("%ld", &numero);

    resultado = fatorial(numero);

    printf("%ld\n", resultado);


    return 0;
}