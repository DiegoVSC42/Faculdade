#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{

    int tamanho_lista;
    int lista_adj[1000];
    int visitado;
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice*)calloc(qtd_vertices+1,sizeof(Vertice));
    vertice->tamanho_lista = 0;
    vertice->visitado = 0;
    return vertice;
}

void dfs(Vertice *vertice, int raiz , int *qtd_chefes){

    
    if(vertice[raiz].visitado != 0)
        return;
    vertice[raiz].visitado = 1;
    (*qtd_chefes)++;
    for(int i = 0; i < vertice[raiz].tamanho_lista;i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],qtd_chefes);
        }
    }
}

void insere_aresta(Vertice *vertice,int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

int main(int argc, char const *argv[]){
    Vertice *vertice;
    int qtd_testes,qtd_vertices,qtd_arestas,origem,destino;
    int qtd_cc;
    int qtd_chefes;
    int vetor[1000];
    int cont;
    scanf("%d", &qtd_testes);
    for(int i = 0; i < qtd_testes;i++){
        qtd_cc = 0;
        qtd_chefes = 0;
        cont = 1;
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        vertice = aloca_vertice(qtd_vertices);
        for(int i = 0; i < qtd_arestas; i++) {
            scanf("%d %d", &origem, &destino);
            insere_aresta(vertice,origem,destino);
        }
        for(int i = 1; i <= qtd_vertices; i++) {
            if(vertice[i].visitado == 0){
                dfs(vertice,i, &qtd_chefes);
                vetor[qtd_cc] = qtd_chefes;
                qtd_cc++;
                qtd_chefes = 0;
            }
        }
        for(int i = 0; i < qtd_cc;i++){
            //printf("%d ", vetor[i]);
            cont = cont*vetor[i];
        }
        printf("%d %d",qtd_cc,cont);
        printf("\n");
    }
    return 0;
}
