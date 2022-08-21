/* programa_bubble_02.c */
#include <stdio.h>
#include <stdlib.h>

void bubble( int piItem[], int iQtdElementos ){

    register int i,j;
    register int iAux;
    int bTroca;

    for(i=1;i<iQtdElementos;i++){
        bTroca = 0;
        for(j=iQtdElementos-1;j>=i;j--){
            if(piItem[j-1] > piItem[j]){    
                iAux = piItem[j-1];
                piItem[j-1] = piItem[j];
                piItem[j] = iAux;
                bTroca = 1;
            }
        }
    }
    if(!bTroca){
        return;
    }
    return;
}

int main(void){

    int iContador;
    int aBubble[] = {10,9,7,13,5};
    bubble(aBubble,5);

    printf("Ordenado:");
    for(iContador = 0; iContador < 5; iContador++){
        printf(" %d", aBubble[iContador] );
    }
    printf("\n");
    return 0;
}