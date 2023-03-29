#include <stdio.h>

int pow2(int B,int N){
    if(N == 0){
        return B;
    }
    if(B == 0){
        return N;
    }
    return 1 + pow2(B, N - 1);
}

int main(int argc, char const *argv[]){
    
    int B,N;
    scanf("%d%d",&B, &N);
    printf("%d\n", pow2(B, N));
    return 0;
}