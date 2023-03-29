#include <stdio.h>
#include <stdlib.h>

typedef struct produtos{
    int codigo;
    float preco;
    int quantidade;
} produtos;

void criar_produto(produtos *produto_criado){
    
    do{
        printf("Digite o codigo do produto que sera criado: ");
        scanf("%d", &produto_criado->codigo);
        if(produto_criado->codigo == 0){
            printf("\n Numero de produto igual a 0 nao permitido!!!");
            printf("\n");
        }

    }while(produto_criado->codigo == 0);
    
    printf("Digite a quantidade desejada do produto que sera criado: ");
    scanf("%d", &produto_criado->quantidade);
    printf ("Digite o preco do produto: ");
    scanf("%f", &produto_criado->preco);

}


void le_produto(produtos pedido, produtos *produto){
    
    do{
        int i = 0;
        float total;
        for(int j = 0; j < 5;j++){
            printf("Codigo: %d Preco: %.2f Quantidade: %d",produto[j].codigo, produto[j].preco, produto[j].quantidade);
            printf("\n");
        }
        printf("Digite o codigo do produto referente ao pedido: ");
        scanf("%d", &pedido.codigo);
        printf("Digite a quantidade desejada referente ao pedido: ");
        scanf("%d", &pedido.quantidade);
        if(produto->codigo > 0){
            for(int i = 0;i < 5;i++){
                if(produto[i].codigo == pedido.codigo){
                    if(pedido.quantidade <= produto[i].quantidade){
                        total = produto[i].preco * pedido.quantidade;
                        produto[i].quantidade = produto[i].quantidade - pedido.quantidade;
                        printf("\nTotal do pedido: R$ %.2f", total);
                        printf("\n");
                    }else{
                        printf("\nNao temos o produto no estoque");
                        printf("\n");
                
                    }
                }else if (pedido.codigo <= 0){
                    printf("\nNumeros menores que 0 nao sao permitidos");
                    printf("\n");
                }
            }
        }

        i++;
    }while(pedido.codigo != 0);
}

int main (){
    produtos produto[5];
    produtos pedido;

    for(int i = 0;i < 5;i++){
        criar_produto(&produto[i]);

    }
    le_produto(pedido, produto);

    
}