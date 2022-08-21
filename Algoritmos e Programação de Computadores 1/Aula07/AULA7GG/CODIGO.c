#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int m, n, qtd_elementos,i = 0;
    
    scanf("%d%d", &m, &n);
    char labirinto[m][n];
    qtd_elementos = m * n;

    for(int i = 0; i < m; i++){
        scanf("%s", labirinto[i]);
    }

    int linha_G, coluna_G;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(labirinto[i][j] == 'G'){
                linha_G = i;
                coluna_G = j;
            }
        }
    }

    int tem_saida = 0;
    while (i < qtd_elementos){

        if(linha_G > 0 && linha_G < (m - 1)){
            if(labirinto[linha_G - 1][coluna_G] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                linha_G--;
            }else if(labirinto[linha_G - 1][coluna_G] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }else if(labirinto[linha_G + 1][coluna_G] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                linha_G++;
            }else if(labirinto[linha_G + 1][coluna_G] == 'S'){
                tem_saida = 1;
                labirinto[linha_G][coluna_G] = 'X';
            }
        }else if(linha_G == 0){
            if(labirinto[linha_G + 1][coluna_G] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                linha_G++;
            }else if(labirinto[linha_G + 1][coluna_G] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }
        }else if(linha_G == (m - 1)){
            if(labirinto[linha_G - 1][coluna_G] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                linha_G--;
            }else if(labirinto[linha_G - 1][coluna_G] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }
        } 

        if(coluna_G > 0 && coluna_G < (n - 1)){
            if(labirinto[linha_G][coluna_G - 1] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                coluna_G--;
            }else if(labirinto[linha_G][coluna_G - 1] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }else if(labirinto[linha_G][coluna_G + 1] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                coluna_G++;
            }else if(labirinto[linha_G][coluna_G + 1] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }
        }else if(coluna_G == 0){
            if(labirinto[linha_G][coluna_G + 1] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                coluna_G++;
            }else if(labirinto[linha_G][coluna_G + 1] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }
        }else if(coluna_G == (n - 1)){
            if(labirinto[linha_G][coluna_G - 1] == 'V'){
                labirinto[linha_G][coluna_G] = 'X';
                coluna_G--;
            }else if(labirinto[linha_G][coluna_G - 1] == 'S'){
                labirinto[linha_G][coluna_G] = 'X';
                tem_saida = 1;
            }
        }
        i++;
    }
    
    if(tem_saida == 1){
        printf("sim\n"); 
    }else{
        printf("nao");
    }
    
    return 0;
}