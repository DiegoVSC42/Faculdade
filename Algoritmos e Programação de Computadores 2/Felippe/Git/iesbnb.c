#include <stdio.h>
#include <stdlib.h>

typedef struct anuncio{

    int codigo_anuncio;
    char cidade[30];
    int qtd_quartos;
    float valor_diaria;
    int ind_ocupacao;

} anuncio;

void preenche_vetor(anuncio *informacao){
    
    for(int i = 0;i < 5;i++){
        printf("\nDigite o codigo do anuncio: ");
        scanf("%d", &informacao[i].codigo_anuncio);
        printf("\nDigite a cidade do anuncio: ");
        scanf("%s", informacao[i].cidade);
        printf("\nDigite a quantidade de quartos do anuncio: ");
        scanf("%d", &informacao[i].qtd_quartos);
        printf("\nDigite o valor da diaria do anuncio: ");
        scanf("%f", &informacao[i].valor_diaria);

        informacao[i].ind_ocupacao = 0;
    }
}
int recebe_qtd_quartos(int qtd_quartos){
    
    int qtd_quarto;
    printf("\nDigite a quantidade de quartos desejada: ");
    scanf("%d", &qtd_quarto);

    return qtd_quarto;
}

float recebe_valor(float valor_anuncio){
    
    float valor_anuncios;
    printf("\nDigite o preco maximo desejado: ");
    scanf("%f", &valor_anuncios);

    return valor_anuncios;
}


void check_in(anuncio *ocupa_quarto){
    
    anuncio ocupa_quartos;

    print("\nDigite o codigo do anuncio para solicitar o check-in");
    scanf("%d", ocupa_quartos.codigo_anuncio);
    for (int i = 0; i < 5; i++)
    {
        if (ocupa_quartos.codigo_anuncio == ocupa_quarto[i].codigo_anuncio){
            if(ocupa_quarto[i].codigo_anuncio == 0){
                ocupa_quarto[i].codigo_anuncio = 1;

            }
        }else if (ocupa_quartos.codigo_anuncio != ocupa_quarto[0].codigo_anuncio && ocupa_quartos.codigo_anuncio != ocupa_quarto[1].codigo_anuncio && ocupa_quartos.codigo_anuncio != ocupa_quarto[2].codigo_anuncio && ocupa_quartos.codigo_anuncio != ocupa_quarto[3].codigo_anuncio && ocupa_quartos.codigo_anuncio != ocupa_quarto[4].codigo_anuncio{
           printf("\nNao possuimos anuncio para esse codigo")
        }
        
    }
    
    printf("\nDigite 1 caso queira fazer check-in: ");
    scanf("%d", &ocupa_quartos.ind_ocupacao);

}
void check_out(anuncio *desocupa_quarto){
    
    anuncio desocupa_quartos;
    printf("\nDigite 0 caso queira fazer check-out: ");
    scanf("%d", &desocupa_quartos.ind_ocupacao);

}

void listar_qtd_quarto(anuncio qtd_quarto){
    anuncio qtd_room[5];
    int qtd_quarto_desejado;
    recebe_qtd_quartos(qtd_quarto_desejado);
    for (int i = 0; i < 5; i++){
        if(qtd_quarto_desejado <= qtd_room[i].qtd_quartos){
            
            printf("\nCodigo do anuncio: %d ", qtd_room[i].codigo_anuncio );
            printf("\nCidade do anuncio: %c ", qtd_room[i].cidade);
            printf("\nQuantidade de quartos do anuncio: %d",qtd_room[i].qtd_quartos);
            printf("\nValor da diaria do anuncio: %f", qtd_room[i].valor_diaria);
        
        }else if(qtd_quarto_desejado > qtd_room[0].qtd_quartos && qtd_room[1].qtd_quartos && qtd_room[2].qtd_quartos && qtd_room[3].qtd_quartos && qtd_room[4].qtd_quartos) {
            printf("Sem anuncio disponivel para a quantidade de quartos solicitada");
        }
        
    }
}
void listar_valor(anuncio valor_quarto){
    anuncio valor[5];
    float valor_quarto_desejado;
    recebe_valor(valor_quarto_desejado);
    for (int i = 0; i < 5; i++){
        if(valor_quarto_desejado >= valor[i].qtd_quartos){
            
            printf("\nCodigo do anuncio: %d ", valor[i].codigo_anuncio );
            printf("\nCidade do anuncio: %c ", valor[i].cidade);
            printf("\nQuantidade de quartos do anuncio: %d", valor[i].qtd_quartos);
            printf("\nValor da diaria do anuncio: %f", valor[i].valor_diaria);
        
        }else if(valor_quarto_desejado < valor[0].valor_diaria && valor[1].valor_diaria && valor[2].valor_diaria && valor[3].valor_diaria && valor[4].valor_diaria) {
            printf("Sem anuncio disponivel para o valor solicitado");
        }
        
    }
}

int main(){

    anuncio informacao[5];
    int qtd_quartos;
    float valor_anuncio;

    preenche_vetor(informacao);
    recebe_qtd_quartos(qtd_quartos);
    recebe_valor(valor_anuncio);

}