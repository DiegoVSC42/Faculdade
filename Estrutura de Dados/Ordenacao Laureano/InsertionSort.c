/* programa_insercao.c */
#include <stdio.h>
#include <stdlib.h>

void selection( int piItem[], int iQtdElementos ){

    register int i,j,iAux;

    for(i = 1; i < iQtdElementos; i++){
        iAux = piItem[i];
        for( j = i - 1; j >= 0 && iAux < piItem[j]; j--){

            piItem[j+1]=piItem[j];
        
        }
        piItem[j+1]=iAux; 
    }

    return;
}

int main(void){

    int iContador;
    int aInsert[] = {13,7,5,1,4};
    selection(aInsert,5);

    printf("Ordenado:");
    for(iContador = 0; iContador < 5; iContador++){
        printf(" %d", aInsert[iContador] );
    }
    printf("\n");
    return 0;
}