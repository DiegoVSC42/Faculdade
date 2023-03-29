#include <stdio.h>

int main(int argc, char const *argv[]){

    int i, numero = 0, num_consoante = 0, ii = 0,qtd_pessoas;
    char nome[1000], sobrenome[1000], consoante[1000],consoante_invertida[1000];

    scanf("%d", &qtd_pessoas);

    while(qtd_pessoas > 0){
            
        numero = 0;

        scanf("%s", nome);
        scanf("%s", sobrenome);
            
        for(i = 0 ; nome[i] != '\0'; i += 1){
            if (nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u'){
                consoante[num_consoante] = nome[i];
                num_consoante += 1; 
            }
        }
        
        for(ii = 0; num_consoante >= 0; ii += 1){
            consoante_invertida[ii] = consoante[num_consoante];
            num_consoante -= 1;
        }
        
        consoante_invertida[ii]='\0';

        for(i = 0 ; sobrenome[i] != '\0'; i += 1){
            numero += 1;
        }

        qtd_pessoas -= 1;

        printf("%s%d\n", consoante_invertida, numero);
    }

    return 0;
}