/*2) Faça um programa que apresente o seguinte menu para o usuário:
    1 - incluir carro
    2 - procurar carro
    3 - remover carro pelo chassi
    4 - mostrar carro mais velho
    5 - mostrar carro mais caro
    obs. Informações de um veículo: marca, modelo, chassi, ano, preco;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{

    int qtd;
    struct Registro *inicio;
    struct Registro *fim;

} Lista;

typedef struct Registro{

    struct Registro *prox;
    struct Registro *ant;
    char marca[30];
    char modelo[30];
    long int chassi;
    int ano;
    float preco;

} Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista*)calloc(1,sizeof(Lista));
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro*)calloc(1,sizeof(Registro));
    return novo;

}
void incluir_carro(Lista *lista);
void menu(Lista *lista);
void procurar_carro(Lista *lista, int ano);
void mostrar_carro_velho(Lista *lista);
void mostrar_carro_caro(Lista*lista);

int main(){

    Lista *lista;

    lista = aloca_lista();
    menu(lista);

    printf("\n");
    return 0;
}
void incluir_carro(Lista *lista){
    
    char marca[30];
    char modelo[30];
    long int chassi;
    int ano;
    float preco;

    if (lista == NULL)
    {
        printf("\n lista nao alocada");
        return;
    }

    Registro *novo;
    novo = aloca_registro();
    
    printf("\nDigite a marca do veiculo: ");
    fflush(stdin);
    fgets(marca,29,stdin);
    strcpy(novo->marca, marca);
    
    printf("Digite o modelo do veiculo: ");
    fflush(stdin);
    fgets(modelo,29,stdin);
    strcpy(novo->modelo, modelo);

    printf("Digite o ano do veiculo: ");
    scanf("%d", &ano);
    novo->ano = ano;
    
    printf("Digite o numero de chassi do veiculo: ");
    scanf("%ld", &chassi);
    novo->chassi = chassi;

    printf("Digite o preco do veiculo: ");
    scanf("%f", &preco);
    novo->preco = preco;

    if (lista->inicio == NULL && lista->fim == NULL){

        lista->inicio = novo;
        lista->fim = novo;
    
    }else{

        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;
    
    }
    
    lista->qtd++;
    printf("\n");

}

void mostrar_carro(Registro carro){
    
    printf("\nMarca: %s", carro.marca);
    printf("Modelo: %s", carro.modelo);
    printf("Chassi: %ld", carro.chassi);
    printf("\tAno: %d", carro.ano);
    printf("\tPreco: %.2f", carro.preco);
    printf("\n");

}

void mostrar_carros(Lista *lista)
{
    Registro *aux;

    if (lista->inicio == NULL){

        printf("\n lista vazia");

    }else{

        aux = lista->inicio;

        while (aux != NULL)
        {
            mostrar_carro(*aux);
            aux->ant = aux;
            aux = aux->prox;
        }
    }
}
void procurar_carro(Lista *lista, int ano){

    Registro *aux;

    if (lista->inicio == NULL){

        printf("\n lista vazia");

    }else{

        aux = lista->inicio;

        while (aux != NULL)
        {
            if(aux->ano == ano){
                mostrar_carro(*aux);
            }
            aux = aux->prox;
        }
    }
}
int remover_carro_chassi(Lista *lista,long int chassi){

    /*if (lista->inicio == NULL)
    {
        return 0;
    }

    Registro *aux;

    aux = lista->inicio;
    while (aux != NULL){
        
        if (aux->chassi == chassi){
            
            if (aux->ant == NULL){

                aux->ant = aux;
                lista->inicio = aux->prox;
            
            }else{

                aux->ant->prox = aux->prox;
            
            }

            lista->qtd--;
            free(aux);
            return 1;
        }
        aux->ant = aux;
        aux = aux->prox;
    }

    return 0;*/

    if(lista->inicio == NULL){
        return 0;
    }
    Registro *aux;

    aux = lista->inicio;
    while(aux != NULL && aux->chassi != chassi){
        aux = aux->prox;
    }
    if (aux == NULL){
        return 0;
    }
    if(aux->ant == NULL){
        lista->inicio = aux->prox;
    }else{
        aux->ant->prox = aux->prox;
    }
    if(aux->prox != NULL){
        aux->prox->ant = aux->ant;
    }
    free(aux);

    return 1;

}

void mostrar_carro_velho(Lista *lista){

    Registro *aux;
    int ano = 3000;    

    if (lista->inicio == NULL){

        printf("\n lista vazia");

    }else{

        aux = lista->inicio;

        while (aux != NULL)
        {
            
            if(ano > aux->ano){
                
                ano = aux->ano;
            }
            aux->ant = aux;
            aux = aux->prox;
        }
        aux = lista->inicio;
        while (aux != NULL)
        {
            
            if(aux->ano == ano){
                
                mostrar_carro(*aux);
            }
            aux->ant = aux;
            aux = aux->prox;
        }
    }

    printf("\n");
}

void mostrar_carro_caro(Lista *lista){
    
    Registro *aux;
    float preco = 0;    

    if (lista->inicio == NULL){

        printf("\n lista vazia");

    }else{

        aux = lista->inicio;

        while (aux != NULL){
            
            if(preco < aux->preco){
                
                preco = aux->preco;

            }
            aux->ant = aux;
            aux = aux->prox;
        }
        aux = lista->inicio;

        while (aux != NULL){
            
            if(aux->preco == preco){
                
                mostrar_carro(*aux);

            }
            aux->ant = aux;
            aux = aux->prox;
        }
    }

    printf("\n");
}
void menu(Lista *lista){

    int opcao;
    int ano;
    long int chassi;

    do{
        printf("\n1 - Incluir carro");
        printf("\n2 - Procurar carro pelo ano");
        printf("\n3 - Remover carro pelo chassi");
        printf("\n4 - Mostrar carro mais velho");
        printf("\n5 - Mostrar carro mais caro");
        printf("\n6 - Mostrar lista completa de carros");
        printf("\n    Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            incluir_carro(lista);
            break;
        case 2:
            printf("\nDigite o ano do carro: ");
            scanf("%d", &ano);
            procurar_carro(lista,ano);
   
            break;
        case 3:
            printf("\nDigite o chassi do carro: ");
            scanf("%ld", &chassi);

            if(remover_carro_chassi(lista,chassi))
            {
                printf("\n Removido com sucesso");
            }
            else
            {
                printf("\n Chassi nao encontrado ou lista vazia");
            }
            break;
        case 4:
            mostrar_carro_velho(lista);
            break;
        case 5:
            mostrar_carro_caro(lista);
            break;
        case 6:
            mostrar_carros(lista);
            break;
        case 7:
            printf("\n saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }while(opcao != 7);
}   