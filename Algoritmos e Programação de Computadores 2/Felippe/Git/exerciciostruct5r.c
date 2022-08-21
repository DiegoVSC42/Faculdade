#include <stdlib.h>
#include <stdio.h>

typedef struct veiculo{
    int numero_chassi;
    int ano;
    float preco;
} veiculo;

void le_veiculo(veiculo *carro){
    printf("Digite o numero do chassi: ");
    scanf("%d", &carro->numero_chassi);
    printf("Digite o ano: ");
    scanf("%d", &carro->ano);
    printf("Digite o preco: ");
    scanf("%f", &carro->preco);
    printf("\n");
}

int main(){
    float valor_p;
    veiculo carro[5];
    for (int i = 0;i < 5;i++){
        le_veiculo(&carro[i]);
    }
    
    do{
        printf("\n");
        printf("\nDigite o valor de P: ");
        scanf("%f", &valor_p);
        for(int i = 0;i < 5;i++){
            if(carro[i].preco < valor_p){
                printf("\nNumero de chassi: %d", carro[i].numero_chassi);
                printf("\nAno: %d", carro[i].ano);
                printf("\nPreco: %.2f ", carro[i].preco);
            }
        }
    }while (valor_p != 0);
    return 0;
}