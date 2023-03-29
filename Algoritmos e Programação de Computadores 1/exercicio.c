#include <stdio.h>

int main(int argc, char const *argv[]){
    int i, j, m, n;
    int linha_G, coluna_G;
    char labirinto[5][5];

    for(i = 0; i < 5; i++){
    scanf("%s", labirinto[i]);
    }

    int linhaG, colunaG;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
        if(labirinto[i][j] == 'G'){
            linhaG = i;
            colunaG = j;
        }
    }
    
    while (0){
        if(linha_G == 0 || coluna_G == 0){
            if(labirinto[linha_G+1][coluna_G] == 'V'){
                labirinto[linha_G][coluna_G] = 'T';
                linha_G++;        
                printf("TROQUEI1\n");
            }
            if(labirinto[linha_G][coluna_G+1] == 'V'){
                labirinto[linha_G][coluna_G] = 'T';
                coluna_G++;
                printf("TROQUEI2\n");
            }
        }
        if(coluna_G == 5 || linha_G == 5){
            if(labirinto[linha_G-1][coluna_G] == 'V'){
                labirinto[linha_G][coluna_G] = 'T';
                linha_G--;
                printf("TROQUEI3\n");
            }
            if(labirinto[linha_G][coluna_G-1] == 'V'){
                labirinto[linha_G][coluna_G] = 'T';
                coluna_G--;
                printf("TROQUEI4\n");
            }
        }

        if(labirinto[linha_G][coluna_G] == 'S'){
            printf("sim\n")
        }   
    }
    return 0;
}