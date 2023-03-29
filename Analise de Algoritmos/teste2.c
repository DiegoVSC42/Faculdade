#include <stdio.h>
int z = 0;
void funcao( int n){
    if(n == 0)
        return;
    z += n;
    funcao(n-1);

}

int main(){
    funcao(5);
    printf("\n");
    return 0;
}