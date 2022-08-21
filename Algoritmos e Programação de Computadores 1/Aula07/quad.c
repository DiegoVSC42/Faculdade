#include <stdio.h>

int main (int argc, char const *argv[]){
    
    int valor_informado, valor_multi;

    valor_multi = 1;

    scanf ("%d", &valor_informado);

    while (valor_informado >= 0){
        if(valor_informado == valor_multi * valor_multi){
            valor_multi = 1;

            printf("sim\n");
        
            scanf ("%d", &valor_informado);
        }
        if(valor_multi == valor_informado/2){
            
            valor_multi = 1;

            printf("nao\n");
            
            scanf ("%d", &valor_informado);
        }
        
        valor_multi += 1;

    }
        
    return 0;
    
}