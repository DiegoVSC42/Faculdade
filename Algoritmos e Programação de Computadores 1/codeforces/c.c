#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int num_char = 0,contador_vog = 0,qtd_texto = 0, i = 0,s;
    char palavra[100000];
    char vogais[] = "aeiouAEIOU";
    scanf("%d", &qtd_texto);

    int contador[qtd_texto];
    
    for(int i=0;i<qtd_texto;i++){
        scanf("%s ", &palavra);
        num_char=strlen(palavra);
        contador_vog = 0;
        for(int i=0;i<strlen(palavra);i++){
            for(int j=0;j<strlen(vogais);j++){
                if(palavra[i]==vogais[j]){
                    contador_vog++;
                }
            }
        }
        
        if(contador_vog!=0){
            if (num_char%2==0){
                if(num_char%contador_vog==0){
                    contador[i]=1;
                }else{
                    contador[i]=0;
                }
                break;
            }else{
                contador[i]=0;
            }
        }
    }
    for(int i=0;i<qtd_texto;i++){
        if(contador[i]==1){
            printf("hahaha\n");
        }
        if(contador[i]==0){
            printf("assim nao po\n");
        }
    }
    return 0;
}
