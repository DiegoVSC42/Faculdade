#include <stdio.h>
#include <stdlib.h>

void mergesort(int v[],int inicio,int fim){

    int i,j,k,meio,*auxiliar;
    if(inicio == fim){
        return;
    }
    /* ordenação recursiva das duas metades */
    meio = (inicio+fim)/2;
    mergesort(v,inicio,meio);
    mergesort(v,meio+1,fim); 

    /* intercalação no vetor temporário auxiliar */
    i = inicio;
    j = meio+1;
    k = 0;
    auxiliar = (int *) malloc(sizeof(int) * (fim-inicio+1));
    while(i<meio+1 || j<fim+1){
        /* i passou do final da primeira metade, pegar v[j] */
        if( i == meio+1){
            auxiliar[k] = v[j];
            j++; k++;
            /* j passou do final da segunda metade, pegar v[i] */
        }else if ( j == fim+1) {
            auxiliar[k] = v[i];
            i++; 
            k++;
            /* v[i]<v[j], pegar v[i] */
        }else if (v[i] < v[j]){

            auxiliar[k] = v[i];
            i++; k++;
            /* v[j]<=v[i], pegar v[j] */
        }else{

            auxiliar[k] = v[j];
            j++; k++;
        }
    }
    /* copia vetor intercalado para o vetor original */
    for( i=inicio; i<=fim; i++){

        v[i] = auxiliar[i-inicio];
    }
    free(auxiliar);
    return ;
}
int main(void){
    
    int iContador;
    int aMerge[] = {9,8,7,6,5,4,3,2,1};

    mergesort(aMerge, 0, 8);

    printf("Ordenado:");
    for(iContador = 0; iContador < 9; iContador++){
      
        printf(" %d ", aMerge[iContador] );
    
    } 
    printf("\n");

    return 0; 
}