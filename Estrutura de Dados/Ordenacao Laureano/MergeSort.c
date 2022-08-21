/* programa_merge_01.c */
#include <stdio.h>
#include <stdlib.h>

void mergesort(int v[],int inicio,int fim);
void intercala(int v[], int inicio, int meio, int fim);

void mergesort(int v[],int inicio,int fim){

    int meio;
    if (inicio < fim){

        meio = (inicio+fim)/2;
        mergesort(v,inicio,meio);
        mergesort(v,meio+1,fim);
        intercala(v, inicio, meio, fim);
    
    }
    return;
} 

void intercala(int v[], int inicio, int meio, int fim){

    /* intercalação no vetor temporário auxiliar */
    int i,j,k, *auxiliar;
    auxiliar = (int *) calloc(sizeof(int) , fim-inicio+1);
    i = inicio;
    j = meio+1;
    k = 0;
    while( i<=meio && j<=fim ){

        if( v[i] <= v[j] ){

            auxiliar[k] = v[i];
            i++;
        
        }else{

            auxiliar[k] = v[j];
            j++;
        
        }

        k++;

    } 

    while( i <= meio ){

        auxiliar[k] = v[i];
        i++;
        k++;

    } 

    while( j <= fim ){

        auxiliar[k] = v[j];
        j++;
        k++;

    }

    /* copia vetor intercalado para o vetor original */
    for( i = 0; i< (fim - inicio)+1; i++){
        v[inicio + i] = auxiliar[i];
    }

    free(auxiliar);

    return;
}

int main(void){

    int iContador;
    int aMerge[] = {9,1,11,13,17,19,21,1,3,89,24};

    mergesort(aMerge, 0, 10);

    printf("Ordenado:");
    for(iContador = 0; iContador < 11; iContador++){

        printf(" %d ", aMerge[iContador] );
    
    }

    printf("\n");
    return 0;
}