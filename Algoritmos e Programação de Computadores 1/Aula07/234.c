#include <stdio.h>

void main() {
    int m, n, quantidadeElementos;

    //Recebe as linhas e colunas do tabuleiro
    scanf("%i%i", &m, &n);
    //Cria uma matriz do tamanho recebido
    char labirinto[m][n];
    quantidadeElementos = m * n;


    //Recebe a matriz labirinto do teclado
    for(int i = 0; i < m; i++) {
      scanf("%s", labirinto[i]);
    }

    //Localiza o G
    int linhaG, colunaG;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++){
        if(labirinto[i][j] == 'G') {
          //Ao receber o G guarda suas coordenadas
          linhaG = i;
          colunaG = j;
          break;
        }
      }
    }

    //Percorre todos os espaços da matriz 1 a 1
    int temSaida = 0;
    for(int i = 0; i < quantidadeElementos; i++) {

      //Verifica as possibilidades de movimentos na vertical
      if(linhaG > 0 && linhaG < (m - 1)) {
        //Pode se mover para cima e para baixo
        if(labirinto[linhaG - 1][colunaG] == 'V'){
          //Verifica se tem caminho para cima, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          linhaG--;
        } else if(labirinto[linhaG - 1][colunaG] == 'S') {
          /*Verifica se tem saída para cima
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
        } else if(labirinto[linhaG + 1][colunaG] == 'V'){
          //Verifica se tem caminho para baixo, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          linhaG++;
        } else if(labirinto[linhaG + 1][colunaG] == 'S') {
          /*Verifica se tem saída para baixo
          se tiver, sai e encerra o loop*/
          temSaida = 1;
          labirinto[linhaG][colunaG] = 'X';
          break;
        }
      } else if(linhaG == 0) {
        //Pode se mover apenas para baixo
        if(labirinto[linhaG + 1][colunaG] == 'V'){
          //Verifica se tem caminho para baixo, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          linhaG++;
        } else if(labirinto[linhaG + 1][colunaG] == 'S') {
          /*Verifica se tem saída para baixo
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
        }
      } else if(linhaG == (m - 1)) {
        //Pode se mover apenas para cima
        if(labirinto[linhaG - 1][colunaG] == 'V'){
          //Verifica se tem caminho para cima, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          linhaG--;
        } else if(labirinto[linhaG - 1][colunaG] == 'S') {
          /*Verifica se tem saída para cima
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
        }
      }

      //Verifica as possibilidades de movimentos na horizontal
      if(colunaG > 0 && colunaG < (n - 1)) {
        //Pode se mover para a esquerda e para a direita
        if(labirinto[linhaG][colunaG - 1] == 'V'){
          //Verifica se tem caminho para esquerda, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          colunaG--;
        } else if(labirinto[linhaG][colunaG - 1] == 'S') {
          /*Verifica se tem saída para esquerda
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
        } else if(labirinto[linhaG][colunaG + 1] == 'V'){
          //Verifica se tem caminho para direita, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          colunaG++;
        } else if(labirinto[linhaG][colunaG + 1] == 'S') {
          /*Verifica se tem saída para direita
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
        }
      } else if(colunaG == 0) {
        //Pode se mover apenas para a direita
        if(labirinto[linhaG][colunaG + 1] == 'V'){
          //Verifica se tem caminho para direita, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          colunaG++;
        } else if(labirinto[linhaG][colunaG + 1] == 'S') {
          /*Verifica se tem saída para direita
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
        }
      } else if(colunaG == (n - 1)) {
        //Pode se mover apenas para a esquerda
        if(labirinto[linhaG][colunaG - 1] == 'V'){
          //Verifica se tem caminho para esquerda, se tiver se move
          labirinto[linhaG][colunaG] = 'X';//Marca que já andou
          colunaG--;
        } else if(labirinto[linhaG][colunaG - 1] == 'S') {
          /*Verifica se tem saída para esquerda
          se tiver, sai e encerra o loop*/
          labirinto[linhaG][colunaG] = 'X';
          temSaida = 1;
          break;
      }
    }
  }

    //Verifica se é possível sair ou não do labirinto
    if(temSaida == 1) {
      printf("sim\n");
    } else {
      printf("nao");
    }
}
