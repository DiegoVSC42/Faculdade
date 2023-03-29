#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[]){

    int elementos,valor_recebido,ministro = 0;

    scanf("%d", &elementos);
    
    int string[elementos];

    for(int i = 0; i < elementos;i++){
        scanf("%d", &valor_recebido);
        string[i] = valor_recebido;
    }

    for(int i = 0; i < elementos ;i++){

        int raiz = 1;
        while(string[i] != raiz*raiz && raiz <= string[i]/2){
            raiz = raiz + 1;
        }
        if(string[i] == raiz*raiz){
            ministro=ministro+1;
        }else{
            ministro=ministro - 1;
        }
        if(string[0] && ministro == -1){
            ministro = 0;
        }
        if(ministro == 1 || ministro == 0){
            ministro = ministro;
        }else{
            ministro = 42;
        }
    }
    if (ministro == 42){
        printf("TROQUE DE MINISTRO\n");
    }else{
        printf("O MINISTRO FICA\n");
    }       
    return 0;
}