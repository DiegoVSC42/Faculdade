#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int lista_adj[1000];
    int tamanho_lista;
    int distancia;
}Vertice;

Vertice *aloca_vertice(int qtd_vertices){
    Vertice *vertice;
    vertice = (Vertice *)malloc((qtd_vertices+1)*sizeof(Vertice));
    int visitado = 0;
    int tamanho_lista = 0;
    int distancia = 0;
    return vertice;
}

void dfs(Vertice *vertice, int raiz,int distancia){

    if(vertice[raiz].visitado!=0){
        return;
    }
    vertice[raiz].visitado = 1;
    vertice[raiz].distancia = distancia;
    for(int i = 0; i < vertice[raiz].tamanho_lista;i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            dfs(vertice,vertice[raiz].lista_adj[i],distancia+1);
        }
    }
}

int insere_aresta_lista(Vertice *vertice,int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tamanho_lista] = destino;
    vertice[origem].tamanho_lista++;
    vertice[destino].lista_adj[vertice[destino].tamanho_lista] = origem;
    vertice[destino].tamanho_lista++;
}

void mostra_lista(Vertice *vertice, int qtd_vertices){
    for(int i = 0 ; i < qtd_vertices ; i++){
        if(vertice[i].lista_adj[0] != 0)    
            printf("%d ",i);
        for(int j = 0 ; j < vertice[i].tamanho_lista ; j++){
            printf("%d ",vertice[i].lista_adj[j]);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]){

    Vertice *vertice;
    int Bishu = 1;
    int distancia = 0;
    int N_countries;
    int road_begin, road_end;
    int Q_girls;
    int girls[1000];
    int u,v;
    int girl_id;

    scanf("%d",&N_countries);
    vertice = aloca_vertice(N_countries);
    for (int i = 0; i < N_countries -1; i++){
        scanf("%d %d", &u, &v);
        insere_aresta_lista(vertice,u,v);
    }

    dfs(vertice,Bishu,0);
    scanf("%d", &Q_girls);
    for(int i = 0; i < Q_girls; i++){
        scanf("%d", &girls[i]);
    }
    girl_id = girls[0];

    for(int i = 1 ; i < Q_girls; i++){
        if(vertice[girls[i]].distancia < vertice[girl_id].distancia){
            girl_id = girls[i];
        }else{
            if(vertice[girls[i]].distancia == vertice[girl_id].distancia){
                if(girls[i] < girl_id){
                    girl_id = girls[i];
                }
            }
        }
    } 
    printf("%d\n", girl_id);
    return 0;
}

/*
INPUT

6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4

OUTPUT 

3

*/