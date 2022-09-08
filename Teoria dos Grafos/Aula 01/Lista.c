#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int qtd_arestas;
    int lista_adj[1000];
    //int *lista_adj;
}Vertice;

Vertice *aloca_vertice(int N){
    Vertice *vertice = calloc((N*2),sizeof(Vertice));
    int qtd_arestas = 0;
    //vertice->lista_adj = (int*)calloc(2,(N*2)*sizeof(int));
    return vertice;
}

void insere_aresta_final(Vertice *vertice,int a, int b){
    vertice[a].lista_adj[vertice[a].qtd_arestas] = b;
    vertice[a].qtd_arestas++;
    vertice[b].lista_adj[vertice[b].qtd_arestas] = a;
    vertice[b].qtd_arestas++;
}
void mostra_lista(Vertice *vertice,int qtd_vertices){
    for(int i = 0; i < qtd_vertices;i++){
        if(vertice[i].lista_adj[0] != 0)
            printf("%d: ", i);
        for(int j = 0; j < vertice[i].qtd_arestas;j++){
            if(vertice[i].lista_adj[j] != 0){
                printf("%d ",vertice[i].lista_adj[j]);
            }
        }
        printf("\n");
    }

}

int main(int argc, char const *argv[]){
    int N,a,b;
    Vertice *vertice;
    
    
    printf("Digite a quantidade de arestas: ");
    scanf("%d", &N);
    
    vertice = aloca_vertice(N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a,&b);
        insere_aresta_final(vertice,a,b);
    }
    mostra_lista(vertice,N*2);
    return 0;
}
