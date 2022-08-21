#include<stdio.h>

int main (int argc, char const *argv[]){

    int valor_compra = 0, valor_pago = 0, troco = 0; 
    
    scanf("%d", &valor_compra);
    scanf("%d", &valor_pago);

    //N se refere a "notas"

    int N100 = 0, N50 = 0, N20 = 0, N10 = 0, N5 = 0, N2 = 0, N1 = 0;

    troco = valor_pago - valor_compra;

    if(troco >= 100 ){
        N100 = troco / 100 ;
        troco = troco % 100;
        printf("%d Nota(s) de 100\n", N100);
    }    
        if(troco >= 50 ){
        N50 = troco / 50 ;
        troco = troco % 50;
            printf("%d Nota(s) de 50\n", N50);
    }    
        if(troco >= 20 ){
        N20 = troco / 20;
        troco = troco % 20;
            printf("%d Nota(s) de 20\n", N20);
    }    
        if(troco >= 10 ){
        N10 = troco / 10;
        troco = troco % 10;
         printf("%d Nota(s) de 10\n", N10);
    }    
        if(troco >= 5 ){
        N5 = troco / 5 ;
        troco = troco % 5;
            printf("%d Nota(s) de 5\n", N5);
    }    
        if(troco >= 2 ){
        N2 = troco / 2 ;
        troco = troco % 2;
            printf("%d Nota(s) de 2\n", N2);
    }
        if(troco >= 1 ){
        N1 = troco / 1 ;
        troco = troco % 1;
            printf("%d Nota(s) de 1\n", N1);
    }      
    
    printf("\n");

    return 0;

}