#include <stdio.h>
#include <stdlib.h>

int main(){

    int i = 7, j = 5;
    
    putchar('\n');

    //printf("Primeiro I como string  = %s\n", i);
    printf("Primeiro I como inteiro = %d\n", i);
    //printf("Primeiro I como char    = %c\n", i);

    //printf("Primeiro j como string  = %s\n", j);
    printf("Primeiro j como inteiro = %d\n", j);
    //printf("Primeiro j como char    = %c\n", j);
    
    int *p;
    
    //printf("Primeiro P como string  = %s\n", p);
    printf("Primeiro P como inteiro = %d\n", p);
   // printf("Primeiro P como char    = %c\n", p); 
    
    
    int **q;
    
    //printf("Primeiro Q como string  = %s\n", q);
    printf("Primeiro Q como inteiro = %d\n", q);
    //printf("Primeiro Q como char    = %c\n", q); 

    p = &i;
    
    //printf("Segundo P como string   = %s\n", p);
    printf("Segundo P como inteiro  = %d\n", p);
    //printf("Segundo P como char     = %c\n", p);
    
    q = &p;
    
    //printf("Segundo Q como string  = %s\n", q);
    printf("Segundo Q como inteiro = %d\n", q);
    //printf("Segundo Q como char    = %c\n", q);

    /*c = **q + j;*/
    
    printf("\n");
    return 0;
}