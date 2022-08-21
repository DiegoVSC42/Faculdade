#include <stdio.h>
#include <string.h>
 
int main(int argc, char const *argv[]){
 
    int qtd_texto,num_char = 0,contador_vog = 0,fake_noise,char_cont[10000],contador[10000];
    int resultado1,resultado2;
    char palavra[10000];
    char vogais[] = "aeiouAEIOU";
 
    scanf("%d", &qtd_texto);
 
    for(int i = 0;i < qtd_texto;i++){
        scanf("%s", &palavra);
 
        contador_vog = 0;
        for(int i=0;i<strlen(palavra);i++){
            for(int j=0;j<strlen(vogais);j++){
                if(palavra[i] == vogais[j]){
                contador_vog++;
                }
            }
        }   
        
        num_char = strlen(palavra);
 
        for(int j = qtd_texto*2;j > qtd_texto;j--){
            resultado1 = 0;
            resultado2 = 0;
            if (num_char % 2 == 0){
                if(num_char % contador_vog == 0){
                    resultado1 = num_char/contador_vog;
                    if (resultado1 == num_char){
                        resultado1 = 0;
                        resultado2 = num_char-1;
                        contador[i] = resultado2;
                    }else{
                        contador[i] = resultado1;
                    }
                }else{
                    resultado2 = num_char-1;
                    contador[i] = resultado2;
                }
            }
            break; 
        }
 
    }
    for(int i = 0;i < qtd_texto;i++){
        if(contador[i] < num_char){
            printf("hahaha\n");
        }else{
            printf("assim nao po\n");
        }
    }
        
    return 0;
}