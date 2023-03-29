#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{

    int dia;
    int mes;
    int ano;

} data;

typedef struct carro{
    
    int ano;
    char modelo[30];
    char marca[30];
    data * revisoes;
    int qtd_revisoes;

}carro;

int main(){

    carro *carros;
    int N,X;
    int cont = 0;


    printf("Digite a quantidade de carros: ");
    scanf("%d", &N);

    carros = malloc(sizeof(carro)* N);

    for(int i = 0; i < N; i++){
        printf("Digite a marca do carro: ");
        scanf("%s", carros[i].marca);
        printf("Digite o modelo do carro: ");
    	scanf("%s", carros[i].modelo);
        printf("Digite o ano do carro: ");
        scanf("%d", &carros[i].ano);
        printf("Digite a quantidade de revisoes do carro: ");
        scanf("%d", &carros[i].qtd_revisoes);
        carros[i].revisoes = malloc(sizeof(data)*carros[i].qtd_revisoes);
        for(int j = 0;j < carros[i].qtd_revisoes;j++){
            printf("Digite a data da revisao do carro(digite no formato dd/mm/aaaa): \n");
            scanf("%d/", &carros[i].revisoes[j].dia);
            scanf("%d/", &carros[i].revisoes[j].mes);
            scanf("%d", &carros[i].revisoes[j].ano);
        }
    }

    printf("Digite um numero de revisoes: ");
    scanf("%d", &X);

    printf("Carros que passaram por %d revisoes: \n", X);

    for(int i = 0; i < N; i++){
        if(carros[i].qtd_revisoes == X){
            printf("Marca : %s\n",carros[i].marca);
            printf("Modelo: %s\n",carros[i].modelo);
            printf("Ano   : %d\n",carros[i].ano);
            cont++;
        }
    }
    if(cont == 0){
        printf("Nenhum carro passou pela mesma quantidade de revisoes que a solicitada\n");
    }
    printf("\n");
    return 0;
}