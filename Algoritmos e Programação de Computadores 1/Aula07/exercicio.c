#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int m, n, quantidadeElementos;
    
    scanf("%i%i", &m, &n);
    char labirinto[m][n];
    quantidadeElementos = m * n;


    for(int i = 0; i < m; i++){
        scanf("%s", labirinto[i]);
    }

    int linhaG, colunaG;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(labirinto[i][j] == 'G'){
            linhaG = i;
            colunaG = j;
            break;
        }
      }
    }

    int temSaida = 0;
    for(int i = 0; i < quantidadeElementos; i++){

        if(linhaG > 0 && linhaG < (m - 1)){
            if(labirinto[linhaG - 1][colunaG] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                linhaG--;
            }else if(labirinto[linhaG - 1][colunaG] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
                break;
            }else if(labirinto[linhaG + 1][colunaG] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                linhaG++;
            }else if(labirinto[linhaG + 1][colunaG] == 'S'){
                temSaida = 1;
                labirinto[linhaG][colunaG] = 'X';
                break;
            }
        }else if(linhaG == 0){
            if(labirinto[linhaG + 1][colunaG] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                linhaG++;
            }else if(labirinto[linhaG + 1][colunaG] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
                break;
            }
        }else if(linhaG == (m - 1)){
            if(labirinto[linhaG - 1][colunaG] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                linhaG--;
            }else if(labirinto[linhaG - 1][colunaG] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
                break;
            }
        } 

        if(colunaG > 0 && colunaG < (n - 1)){
            if(labirinto[linhaG][colunaG - 1] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                colunaG--;
            }else if(labirinto[linhaG][colunaG - 1] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
            break;
            }else if(labirinto[linhaG][colunaG + 1] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                colunaG++;
            }else if(labirinto[linhaG][colunaG + 1] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
                break;
            }
        }else if(colunaG == 0){
            if(labirinto[linhaG][colunaG + 1] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                colunaG++;
            }else if(labirinto[linhaG][colunaG + 1] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
                break;
            }
        }else if(colunaG == (n - 1)){
            if(labirinto[linhaG][colunaG - 1] == 'V'){
                labirinto[linhaG][colunaG] = 'X';
                colunaG--;
            }else if(labirinto[linhaG][colunaG - 1] == 'S'){
                labirinto[linhaG][colunaG] = 'X';
                temSaida = 1;
                break;
            }
        }
    }
    
    if(temSaida == 1){
        printf("sim\n"); 
    }else{
        printf("nao");
    }
    
    return 0;
}