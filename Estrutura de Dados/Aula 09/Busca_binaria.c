#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long int *aloca_vetor(long long int x)
{
    long long int *vetor;
    vetor = (long long int *)calloc(x, sizeof(long long int));
    long long int i, sorteado, aux;

    for (i = 0; i < x; i++)
    {
        vetor[i] = i + 1;
    }

    for (i = 0; i < x; i++)
    {
        sorteado = rand() % x;
        aux = vetor[i];
        vetor[i] = vetor[sorteado];
        vetor[sorteado] = aux;
    }
    return vetor;
}

void mostrar(long long int *vet, long long int tam)
{
    int i;

    printf("\n Vetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}
void quicksort(long long int *item, long long int left, long long int right){
        
    long long int i,j;
    long long int x,y;
    i = left;
    j = right;
    x = item [ (left+right)/2 ];

    do{
        while(item[i] < x && i < right){
            i++;
        }
        while(x < item[j] && j > left){
            j--;
        }
        if(i<=j){
            y = item[i];         
            item[i] = item[j];
            item[j] = y;
            i++;
            j--; 
        }
    }while(i <= j);

    if(left < j ){
    
        quicksort(item, left, j);
    
    }
    if(i < right ){

        quicksort(item, i, right);
    
    }
    return ;
}

long long int buscaSequencial (long long int x, long long int n, long long int *v) {
  
  for(int j = 0; j < n;j++){
    if(v[j]==x){
      return j;
    }
  }
}

long long int buscaBinaria (long long int x, long long int n, long long int *v) { 
   long long int e = -1, d = n; // atenção!
   while (e < d-1) {  
      long long int m = (e + d)/2;
      if (v[m] < x) e = m;
      else d = m; 
   }
   return d;
}

int main()
{
    clock_t t1_seq, t2_seq, t1_bus, t2_bus;
    srand(time(NULL));
    long long int tam = 10000000;
    long long int *vet;
    long long int valor;
    long long int seq, bin;
    double diff;
    printf("\nDigite um valor: ");
    scanf("%lld", &valor);


    vet = aloca_vetor(tam);
    // printf("\n Desordenado: ");
    // mostrar(vet, tam);
    quicksort(vet,0, tam);
    // printf("\n Ordenado: ");
    // mostrar(vet, tam);

    t1_seq = clock();
    seq = buscaSequencial(valor,tam,vet);
    if(seq == valor){
        printf("\nValor encontrado no vetor");
    }else{
        printf("\nValor nao encontrado no vetor");
    }
    t2_seq = clock();
    diff = (((double)t2_seq - (double)t1_seq) / 1000000.0);
    printf("\nTempo Gasto sequencial: %f ", diff);
    
    t1_bus = clock();
    bin = buscaBinaria(valor,tam,vet);
    if(bin == valor){
        printf("\nValor encontrado no vetor");
    }else{
        printf("\nValor nao encontrado no vetor");
    }
    t2_bus = clock();
    diff = (((double)t2_bus - (double)t1_bus) / 1000000.0);
    printf("\nTempo Gasto busca binaria: %f ", diff);

    free(vet);
    printf("\n");
    return 0;
}