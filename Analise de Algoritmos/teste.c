#include <stdio.h>

int minhaFuncao(int num){
    int resultado = 0;
    for(int i = 0; i <= num;i++){
        resultado += 1;
    }
    return resultado;
}
int main(int argc, char const *argv[]){
    int limite = 5;
    for(int i = 1; i <= limite;i++){
        int resultado = minhaFuncao(i);
        printf("Resultado para %d: %d\n",i, resultado);
    }


    return 0;
}
