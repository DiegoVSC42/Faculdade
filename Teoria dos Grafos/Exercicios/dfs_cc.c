/*Problema
Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph. 
Calculate the total number of connected components in the graph. 
A connected component is a set of vertices in a graph that are linked to each other by paths.

Input Format:

First line of input line contains two integers n and e. 
Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. 

Output Format:

For each input graph print an integer x denoting total number of connected components.

Constraints:

All the input values are well with in the integer range.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int lista_adj[1000];
    int qtd_arestas;
    int visitado;
}Vertice;

Vertice *aloca_vertice(int N){
    Vertice *vertice;
    vertice = (Vertice*)calloc(N+1,sizeof(Vertice));
    int qtd_arestas = 0;
    return vertice;
}

void insere_aresta_lista(Vertice *vertice, int a,int b){
    vertice[a].lista_adj[vertice[a].qtd_arestas] = b;
    vertice[a].qtd_arestas++;
    vertice[b].lista_adj[vertice[b].qtd_arestas] = a;
    vertice[b].qtd_arestas++;
}

void dfs(Vertice *vertice, int qtd_vertices,int raiz){
    
    if (vertice[raiz].visitado!=0){
        return;
    }
    vertice[raiz].visitado = 1;
    for(int i = 0; i < vertice[raiz].qtd_arestas;i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,qtd_vertices,vertice[raiz].lista_adj[i]);
        }
    }
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

    int qtd_vertices,qtd_arestas,u,w,qtd_cc = 0;

    scanf("%d %d",&qtd_vertices, &qtd_arestas);
    Vertice *vertice;
    vertice = aloca_vertice(qtd_vertices);
    for(int i = 0; i < qtd_arestas; i++){
        scanf("%d %d",&u,&w);
        insere_aresta_lista(vertice,u,w);
    }	
    //mostra_lista(vertice,qtd_vertices);
    for(int i = 1; i <= qtd_vertices; i++){
        if(vertice[i].visitado == 0){
            dfs(vertice,qtd_vertices,i);
            qtd_cc++;
        }
    }

    printf("%d\n",qtd_cc);
    return 0;
}


/*

ENTRADA

8 5
1 2
2 3
2 4
3 5
6 7

SAIDA

3

*/