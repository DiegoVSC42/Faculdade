#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i, j, m, n;

  scanf("%d %d", &m, &n);
  printf("%d, %d\n", m, n);

  char nomes[m][n];


  for(i = 0; i < m; i++) {
      scanf("%s", nomes[i]);
  }

  printf("Lista de nomes: \n");
  for(i = 0; i < n; i++) {
      printf("%s\n", nomes[i]);
  }

  return 0;
}
