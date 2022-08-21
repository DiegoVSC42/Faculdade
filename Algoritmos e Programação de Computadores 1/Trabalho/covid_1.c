#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*

####### Objetivos ##########
5 individuos começam com a doenca;
Leva 60s para o individuo ficar doente;
Durante os 60s, o individuo pode passar a doença;
Disseminacao ocorre num raio de 3;
Sem isolamento social: 100% de movimento a cada 2s;
Isolamento social parcial: 50% a cada 2s;
Isolamento social maximo: 20% se move a cada 2s;
36 segundos para a cura;
A cura demora 36s;
Cura = 90%;
Quem nao e curado, morre, nao trasmite e sai da matriz;
A simulacao ocorre em 3600s;
Ao final deve apresentar a quantidade de pessoas infectadas para cada 2s, 
e o total de mortos;


####### Termos ##########
Infectados assintomaticos = 60-96;
Infectados sintomaticos = 0-60;
Curado = 97;
Saudavel = -1;
Mortos = 'M';

*/


//Randomizadores

//20%, check da movimentacao, isolamento social maximo.
int random20(){
    int conta = rand()%100;
    if(conta >= 20){
        return 0;
    }
    else{
        return 1;
    }
}

//50%, check da movimentacao, isolamento social parcial.
int random50(){
    int conta = rand()%100;
    if(conta >= 50){
        return 1;
    }
    else{
        return 0;
    };
}

//Escolher randomicamente a direcao.
int random75(){
    int conta = rand()%100;
    if(conta >= 75){
        return 0;
    }
    if(conta >= 50 && conta < 75){
        return 1;
    }
    if(conta >= 25 && conta < 50){
        return 2;
    }
    else{
        return 3;
        
    }
}


//90%, check da morte.
int random90(){
    int conta = rand()%100;
    if(conta >= 90){
        return 1;
    }
    else{
        return 0;
    };
}


//Funcao Principal
int main(){
    char demografico[100][100];
    int contas = 0;
    int mortos = 0;
    int infectados = 0;
    int infectados_j = 0;
    int infectados_i = 0;
    int j = 0;
    int i = 0;
    

    //Colocar as pessoas na matriz
    for(int i = 0; i < 100; i++){
        if(contas < 500){
            for(int j = 0; j < 100; j++){
                if (random50()!=1){
                    demografico[i][j] = ' ';
                }
                else{
                    demografico[i][j] = -1;
                    contas++;
                }
            }
        }
    }

    //Colocar os doentes.
    for(int i = 0;i < 100 && contas < 5;i=i+20){
        for(int j = 0;j < 100;j=j+20){
            demografico[i][j] = 0;
            contas++;
        }
    }

    //Loop Principal
    for(int contador = 0;contador < 3600;contador+=2){
        
        //Infeccao
        for(int i;i < 100;i++){
            for(int j;j < 100;j++){ 
                if(demografico[i][j]>=0){
                    //Cima
                    if(demografico[i+1][j] == -1 && i < 100){
                        demografico[i+1][j]=0;
                    }
                    if( demografico[i+2][j]==-1 && i < 100){
                        demografico[i+2][j]=0;
                    }
                    if(demografico[i+3][j] == -1 && i < 100){
                        demografico[i+3][j]=0;
                    }
                    //Baixo
                    if(demografico[i-1][j] == -1 && i>0){
                        demografico[i-1][j]=0;
                    }
                    if( demografico[i-2][j]==-1 && i>0){
                        demografico[i-2][j]=0;
                    }
                    if(demografico[i-3][j] == -1 && i>0){
                        demografico[i-3][j]=0;
                    }
                    //Direita
                    if(demografico[i][j+1]){
                        demografico[i][j+1]=0;
                    }
                    if(demografico[i][j+2]){
                        demografico[i][j+2]=0;
                    }
                    if(demografico[i][j+3]){
                        demografico[i][j+3]=0;
                    }
                    //Esquerda
                    if(demografico[i][j-1]){
                        demografico[i][j-1]=0;
                    }
                    if(demografico[i][j-2]){
                        demografico[i][j-2]=0;
                    }
                    if(demografico[i][j-3]){
                        demografico[i][j-3]=0;
                    }
                    }
                }
            }

        //Movimentacao
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                if (demografico[i][j] != ' '){
                    for (int infic = 0; infic != 1 ;){
                        if(random75() == 0){
                            demografico[i][j-1] = demografico[i][j];
                            demografico[i][j] = ' ' ;
                            infic = 1;
                        }
                        if(random75() == 1){
                            demografico[i-1][j] = demografico[i][j];
                            demografico[i][j] = ' ' ;
                            infic = 1;
                        }
                        if(random75() == 2){
                            demografico[i][j+1] = demografico[i][j];
                            demografico[i][j] = ' ' ;
                            infic = 1;
                        }
                        if(random75() == 3){
                            demografico[i+1][j] = demografico[i][j];
                            demografico[i][j] = ' ' ;
                            infic = 1;
                        }
                    }
                }
            }
        }
        //Loop pra tirar os mortos da funcao e contar a quantidade de mortos.
        for(int i = 0;i < 100;i++){
            for(int j;j < 100;j++){
                if(demografico[i][j] == 96){
                    if(random90()==1){
                        demografico[i][j]= ' ';
                        mortos++;
                    }else{
                        demografico[i][j]+=1;
                    }
                }
            }
        }

        //Loop pra contar quantos infectados tem.
        for(int i;i < 100;i++){
            for(int j; j < 100; j++){
                if(demografico[i][j] == 0){
                    infectados++;
                }
            }
        }
        
        for(int i;i < 100;i++){
            for(int j; j < 100; j++){
                if(demografico[i][j] >= 0){
                    demografico[i][j]+=2;
                }
            }
        }
        
        //Contagem
        sleep(2);
        printf("Infectadas:%d Mortas:%d", infectados,mortos);
    }
    return 0;        
        
}