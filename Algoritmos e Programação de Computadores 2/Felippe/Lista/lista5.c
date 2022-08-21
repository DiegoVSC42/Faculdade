#include <stdio.h>
#include <stdlib.h>

typedef struct Vetor{

    float x;
    float y;
    float z;

} Vetor;

void soma(Vetor *vetor1, Vetor *vetor2){

    Vetor resultado;

    resultado.x = vetor1->x + vetor2->x;
    resultado.y = vetor1->y + vetor2->y;
    resultado.z = vetor1->z + vetor2->z;

    printf("A soma dos dois vetores e: %.1f;%.1f;%.0f", resultado.x, resultado.y, resultado.z);
    
}

int main(){

    Vetor vetor1;
    Vetor vetor2;

    printf("Digite as coordenadas do vetor 1: x,y,z\n");
    scanf("%f,%f,%f", &vetor1.x, &vetor1.y, &vetor1.z);
    printf("\n");
    printf("Digite as coordenadas do vetor 2: x,y,z\n");
    scanf("%f,%f,%f", &vetor2.x, &vetor2.y, &vetor2.z);

    soma(&vetor1, &vetor2);

}