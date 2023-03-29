#include <stdio.h>

int main(int argc, char const *argv[])
{

    int N;

    scanf("%d", &N);

    if (N % 2 == 0){
        printf("par\n");
    }else{
        printf("impar\n");
    }

    return 0;

}