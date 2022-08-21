#include <stdio.h>
#include <stdlib.h>

int main(){

    int i = 34 ,j;
    int *p;
    
    printf("Primeiro P como string  = %s\n", p);
    printf("Primeiro P como inteiro = %d\n", p);
    printf("Primeiro P como char    = %c\n", p);

    p = &i;

    printf("Segundo P como string   = %s\n", p);
    printf("Segundo P como inteiro  = %d\n", p);
    printf("Segundo P como char     = %c\n", p);

    *p++;

    printf("Terceiro P como string  = %s\n", p);
    printf("Terceiro P como inteiro = %d\n", p);
    printf("Terceiro P como char    = %c\n", p);
    
    j = *p + 33;

    printf("J como string           = %s\n", p);
    printf("J como inteiro          = %s\n", p);
    printf("J como char             = %s\n", p);
    printf("\n");
    return 0;

}