#include <stdio.h>
#include <string.h>

void qs( char *item, int left, int right){
        
    int i,j;
    char x,y;
    i = left;
    j = right;
    x = item [ (left+right)/2 ]; /* elemento pivo */

    /*particao das listas */

    do{
        /*procura elementos mairoes que o pivo na primeira parte*/
        while(item[i] < x && i < right){
            i++;
        }
         /* procura elementos menores que o pivô na segunda parte */
        while(x < item[j] && j > left){
            j--;
        }
        if(i<=j){
            /* processo de troca (ordenação) */
            y = item[i];         
            item[i] = item[j];
            item[j] = y;
            i++;
            j--; 
        }
    }while(i <= j);

    /* chamada recursiva */
    if(left < j ){
    
        qs(item, left, j);
    
    }
    if(i < right ){

        qs(item, i, right);
    
    }
    return ;
}

int main(void){

    char aVetor[]="3490bn09685lnv 3-49580bgojfog39458=9ugkj n098=526yh";

    printf("\nAntes = [%s]", aVetor);

    /* na primeira chamada, os parâmetros iniciais são os extremos da matriz */
    qs(aVetor,0,strlen(aVetor)-1); 

    printf("\nDepois = [%s]", aVetor);
    return 0; 

}