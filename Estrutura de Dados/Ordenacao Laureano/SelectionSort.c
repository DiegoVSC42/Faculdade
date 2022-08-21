/* programa_selecao.c */
#include <stdio.h>
#include <stdlib.h>

void selection( int piItem[], int iQtdElementos ){

    register int i,j,iMinimo,iAux;

    for(i = 0; i < iQtdElementos-1 ; i++){
        iMinimo = i;
        for(j = i + 1; j < iQtdElementos ; j++){
            if(piItem[j] < piItem[iMinimo]){    
                iMinimo = j;
            }
        }
        iAux = piItem[i];
        piItem[i] = piItem[iMinimo];
        piItem[iMinimo] = iAux; 
    }
    return;
}

int main(void){

    int iContador;
    int aSelect[] = {13,7,5,1,4};
    selection(aSelect,5);

    printf("Ordenado:");
    for(iContador = 0; iContador < 5; iContador++){
        printf(" %d", aSelect[iContador] );
    }
    printf("\n");
    return 0;
}