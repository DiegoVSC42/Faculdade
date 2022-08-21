#include<stdio.h>

int main (int argc, char const *argv[]){

    int amigo1, amigo2, amigo3;

    scanf("%d, %d, %d", &amigo1, &amigo2, &amigo3);

    if (amigo1 > amigo2 && amigo1 > amigo3){
            printf("amigo1 e o mais velho\n");
    }
    if (amigo2 > amigo3 && amigo2 > amigo1){
        printf("amigo2 é o mais velho\n");
    }
    if (amigo3 > amigo2 && amigo3 > amigo1){
        printf("amigo3 é o mais velho\n");
    }

    return 0;

}
