#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()
int main(void)
{
  int i;
  
  printf("Gerando 10 valores aleatorios:\n\n");
  
  /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
  com o valor da função time(NULL). Este por sua vez, é calculado
  como sendo o total de segundos passados desde 1 de janeiro de 1970
  até a data atual.
  Desta forma, a cada execução o valor da "semente" será diferente.
  */
  srand(time(NULL));
  
  for (i=0; i < 10; i++)
  {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d ", rand() % 100);
  }
  
  getch();
  return 0;
}