#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
    int qtd_vertices;
    int qtd_arestas;
    int **matriz_adjacencia;
}Grafo;

int **aloca_matriz(int qtd_vertices){
    int **matriz;
    //alocando linhas
    matriz = malloc(sizeof(int*) * qtd_vertices);
    //alocando colunas
    for(int i=0;i<qtd_vertices;i++){
        matriz[i] = malloc(sizeof(int) * qtd_vertices);
    }
    return matriz;
}
Grafo *aloca_grafo(int qtd_vertices){
    Grafo *grafo;
    grafo = malloc(sizeof(Grafo));
    grafo->qtd_vertices = qtd_vertices;
    grafo->qtd_arestas = 0;
    grafo->matriz_adjacencia = aloca_matriz(qtd_vertices);
    return grafo;
}
void insere_aresta_matriz(Grafo *grafo,int inicio, int fim){
    if(grafo->matriz_adjacencia[inicio][fim] == 0){
        grafo->matriz_adjacencia[inicio][fim] = 1;
        grafo->qtd_arestas++;
    }
}
void mostra_matriz(Grafo *grafo){
    printf("   ");
    for (int i = 0; i < grafo->qtd_vertices ;i++){
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0 ; i < grafo->qtd_vertices ; i++){
        printf("%d: ", i);
        for(int j = 0 ; j < grafo->qtd_vertices ; j++){
            printf("%d ",grafo->matriz_adjacencia[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[]){
    Grafo *grafo;
    int N;
    int inicio,fim;
    
    printf("Digite a quantidade de arestas: ");
    scanf("%d",&N);

    grafo = aloca_grafo(N*2);
    
    printf("Digite os pares com valores de 0 a %d\n", (N*2) - 1);
    for(int i = 0; i < N; i++){
        scanf("%d %d",&inicio, &fim);
        insere_aresta_matriz(grafo,inicio,fim);
        insere_aresta_matriz(grafo,fim,inicio);
        insere_aresta_matriz(grafo,inicio,inicio);
        insere_aresta_matriz(grafo,fim,fim);
    }
    
    mostra_matriz(grafo);
    return 0;
}
