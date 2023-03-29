#include <stdio.h>

int Potencia_B(int B,int N){
    
    if(N == 0){   
        return 1;
        
    }
    
    return B*Potencia_B(B, N-1);

}

int main(int argc, char const *argv[]){
    
    int B, N;

    scanf("%d%d",&B,&N);

    int potencia = Potencia_B(B,N);

    printf("%d\n", potencia);

    return 0;
    
}