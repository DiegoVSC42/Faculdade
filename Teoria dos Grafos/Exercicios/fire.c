#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int qtd_arestas;
    int lista_adj[1000];
    int visitado;
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->qtd_arestas = 0;
    vertice->visitado = 0;
    return vertice;
}

void dfs(Vertice *vertice, int raiz, int *chefes){
    vertice[raiz].visitado = 1;
    (*chefes)++;
    for(int i = 0; i < vertice[raiz].qtd_arestas;i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],chefes);
        }
    }
}
void insere_aresta(Vertice *vertice,int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].qtd_arestas] = destino;
    vertice[origem].qtd_arestas++;
    vertice[destino].lista_adj[vertice[destino].qtd_arestas] = origem;
    vertice[destino].qtd_arestas++;
}

int main(int argc, char const *argv[]){

    Vertice *vertice;
    int qtd_vertices, qtd_arestas;
    int origem, destino;
    int qtd_cc = 0;
    int chefes = 0;
    int *qtd_chefes;
    int cont = 1;

    //printf("Digite a quantidade de vertices e arestas\n");
    scanf("%d %d",&qtd_vertices,&qtd_arestas);
    
    qtd_chefes = (int*)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice = aloca_vertice(qtd_vertices);

    //printf("Digite as arestas\n");
    for(int i = 0; i < qtd_arestas;i++){
        scanf("%d %d",&origem,&destino);
        insere_aresta(vertice,origem,destino);
    }
    
    for(int i = 0; i < qtd_vertices;i++){
        if(vertice[i].visitado == 0){
            dfs(vertice,i,&chefes);
            qtd_chefes[qtd_cc] = chefes;
            qtd_cc++;
            chefes = 0;
        }
    }
    // printf("\n");
    // for(int i = 0; i < qtd_vertices;i++){
    //     printf("%d ", qtd_chefes[i]);
    // }
    // printf("\n");

    for(int i = 0; i < qtd_cc;i++){
        cont = cont*qtd_chefes[i];
    }
    
    
    // printf("\nComponentes conectados: %d", qtd_cc);
    // printf("\nChefes: %d",cont);

    printf("%d %d", qtd_cc, cont);
    printf("\n");
    return 0;
}
