#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
    int visitado;
    int lista_adj[1000];
    int tam_lista_adj;
    int cor;
}Vertice;

Vertice *aloca_vertice(int N,int cont){
    Vertice *vertice;
    if(cont == 0){
        vertice = (Vertice *)calloc(N+1,sizeof(Vertice));
    }else{
        vertice = (Vertice*)realloc(vertice,sizeof(Vertice)*(N+1));
    }
    vertice->visitado = 0;
    vertice->tam_lista_adj = 0;
    vertice->cor = 0;
}

void insere_aresta(Vertice *vertice, int origem, int destino){
    vertice[origem].lista_adj[vertice[origem].tam_lista_adj] = destino;
    vertice[origem].tam_lista_adj++;
    vertice[destino].lista_adj[vertice[destino].tam_lista_adj] = origem;
    vertice[destino].tam_lista_adj++;
}

int dfs(Vertice *vertice, int raiz, int cor){
    vertice[raiz].visitado = 1;
    vertice[raiz].cor = cor;
    // printf("\n%d\n",vertice[raiz].cor);
    for(int i = 0; i < vertice[raiz].tam_lista_adj; i++){
        if(vertice[vertice[raiz].lista_adj[i]].visitado == 0){
            if(!dfs(vertice,vertice[raiz].lista_adj[i],cor * -1)){
                return 0;
            }
        }else{
            if(vertice[raiz].cor == vertice[vertice[raiz].lista_adj[i]].cor){
                // printf("\nDEU RUIM\n");
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    Vertice *vertice;
    int cont;
    int qtd_vertices,qtd_arestas,origem,destino,qtd_cenarios;

    scanf("%d",&qtd_cenarios);
    for(int i=0;i<qtd_cenarios;i++){
        scanf("%d", &qtd_vertices);;
        scanf("%d", &qtd_arestas);
        vertice = aloca_vertice(qtd_vertices,cont);
        cont++;
        for(int i = 0; i < qtd_arestas; i++){
            scanf("%d %d", &origem,&destino);
            insere_aresta(vertice,origem,destino);
        }
        printf("Scenario #%d\n",i+1);
        if(dfs(vertice,1,1)){
            printf("No suspicious bugs found!\n");
        }else{
            printf("Suspicious bugs found!\n");
        }
        free(vertice);
    }

    // printf("\n");
    return 0;

}