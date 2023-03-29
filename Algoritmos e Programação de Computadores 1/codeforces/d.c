#include <stdio.h>

int main(int argc, char const *argv[]){

    int num_testes, num_ministros, temp_ministros,qtd_disc,temp_biro,r1,r2,resposta, vetor[100000];
        
    scanf("%d", &num_testes);
    
    for(int i = 0; i < num_testes;i++){
        
        scanf("%d%d%d%d", &num_ministros, &temp_ministros, &qtd_disc, &temp_biro);

        r1 = num_ministros * temp_ministros;
        r2 = qtd_disc * temp_biro;
        resposta = r1 + r2;
        vetor[i] = resposta;
    }
    for(int i = 0;i < num_testes;i++){
        printf("%d\n",vetor[i]);
    }
    return 0;
}


for(int i = 0;i < qtd_texto;i++){
        if(char_cont[i] = 1){
            printf("hahaha\n");
        }else if(char_cont[i] = 0){
            printf("assim nao po\n");
        }
    }

    printf("TROQUE DE MINISTRO\n");
    printf("O MINISTRO FICA\n");