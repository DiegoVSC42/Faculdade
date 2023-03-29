#include <stdio.h>
    
int potencia_B(int B,int N){
    
    int potencia = 1;
    
    for(int i=0; i < N; i++){
        potencia *= B;
    }
    return potencia;

}

int main(int argc, char const *argv[]){
    
    int B, N;

    scanf("%d%d",&B,&N);

    int potencia = potencia_B(B,N);

    printf("%d\n", potencia);

    return 0;
    
}