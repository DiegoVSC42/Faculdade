#include <stdio.h>
#include <string.h>
 
int main(int argc, char const *argv[]){
 
    int qtd_texto,num_char = 0,contador_vog,fake_noise,contador[10000];
    char palavra[1001];
    char vogais[] = "aeiouAEIOU";
 
    scanf("%d", &qtd_texto);

    int char_cont[qtd_texto];
 
    for(int i = 0;i < qtd_texto;i++){
        scanf("%s", &palavra);
        num_char = strlen(palavra);
        printf("%d", num_char);
        contador_vog = 0;
        for(int i=0;i<strlen(palavra);i++){
            for(int j=0;j<strlen(vogais);j++){
                if(palavra[i] == vogais[j]){
                contador_vog++;
                }
            }
        }   
        if(contador_vog != 0){
            if (num_char % 2 == 0){
                if(num_char % contador_vog == 0){
                    contador[i] = 1;
                }else{
                    contador[i] = 0;
                }
                break;
            }
        }
    }
    for(int i = 0;i < qtd_texto;i++){
        if(contador[i] == 1){
            printf("hahaha\n");
        }else if(contador[i] == 1){
            printf("assim nao po\n");
        }
    }
        
    return 0;
}