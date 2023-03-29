#include <stdio.h>
int main(int argc, char const *argv[]){
    
	int numero_1, numero_2, auxiliar;
    
    scanf("%d", &numero_1);
    
    scanf("%d", &numero_2);
    
    auxiliar = numero_1;
    
    numero_1 = numero_2;
    
    numero_2 = auxiliar;
    
    printf("%d %d\n", numero_1, numero_2);
    
    return 0;

}
