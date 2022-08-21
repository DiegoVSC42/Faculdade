#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada{
    int x,y;
} coordenada;

void mostrar_coordenada(coordenada *lista1, coordenada *lista2){
    
    int ocor_x_l1 = 0;
    int ocor_y_l1 = 0;
    int ocor_1qdt_l1 = 0;
    int ocor_2qdt_l1 = 0;
    int ocor_3qdt_l1 = 0;
    int ocor_4qdt_l1 = 0;
    int ocor_x_l2 = 0;
    int ocor_y_l2 = 0;
    int ocor_1qdt_l2 = 0;
    int ocor_2qdt_l2 = 0;
    int ocor_3qdt_l2 = 0;
    int ocor_4qdt_l2 = 0;
    int ocor_qdt1_total = 0;
    int ocor_qdt2_total = 0;
    int ocor_qdt3_total = 0;
    int ocor_qdt4_total = 0;

    for(int i = 0;i < 3;i++){
        if(lista1[i].x == 0 ){
            ocor_x_l1++;
        }if(lista2[i].x == 0){
            ocor_x_l2++;
        }
    }
    for(int i = 0;i < 3;i++){
        if(lista1[i].y == 0){
            ocor_y_l1++;
        }if(lista2[i].y == 0){
            ocor_y_l2++;
        }
    }
    for(int i = 0;i < 3;i++){
        if(lista1[i].x > 0 && lista1[i].y > 0){
            ocor_1qdt_l1++;
        }if(lista2[i].x > 0 && lista2[i].y > 0){
            ocor_1qdt_l2++;
        }
    }
    for(int i = 0;i < 3;i++){
        if(lista1[i].x < 0 && lista1[i].y > 0){
            ocor_2qdt_l1++;
        }if(lista2[i].x < 0 && lista2[i].y > 0){
            ocor_2qdt_l2++;
        }
    }
    for(int i = 0;i < 3;i++){
        if(lista1[i].x < 0 && lista1[i].y < 0){
            ocor_3qdt_l1++;
        }if(lista2[i].x < 0 && lista2[i].y < 0){
            ocor_3qdt_l2++;
        }
    }
    for(int i = 0;i < 3;i++){
        if(lista1[i].x > 0 && lista1[i].y < 0){
            ocor_4qdt_l1++;
        }if(lista2[i].x > 0 && lista2[i].y < 0){
            ocor_4qdt_l2++;
        }
    }
    ocor_qdt1_total = ocor_1qdt_l1 + ocor_1qdt_l2;
    ocor_qdt2_total = ocor_2qdt_l1 + ocor_2qdt_l2;
    ocor_qdt3_total = ocor_3qdt_l1 + ocor_3qdt_l2;
    ocor_qdt4_total = ocor_4qdt_l1 + ocor_4qdt_l2;
    if (ocor_qdt1_total > ocor_qdt2_total && ocor_qdt1_total > ocor_qdt3_total && ocor_qdt1_total > ocor_qdt4_total){
        printf("\nO primeriro quadrante foi o que teve mais ocorrencias");
    }else if (ocor_qdt2_total > ocor_qdt1_total && ocor_qdt2_total > ocor_qdt3_total && ocor_qdt2_total > ocor_qdt4_total){
        printf("\nO segundo quadrante foi o que teve mais ocorrencias");
    }else if (ocor_qdt3_total > ocor_qdt1_total && ocor_qdt3_total > ocor_qdt2_total && ocor_qdt3_total > ocor_qdt4_total){
        printf("\nO primeriro quadrante foi o que teve mais ocorrencias");
    }else if (ocor_qdt4_total > ocor_qdt1_total && ocor_qdt4_total > ocor_qdt2_total && ocor_qdt4_total > ocor_qdt3_total){
        printf("\nO primeriro quadrante foi o que teve mais ocorrencias");
    }

    if(ocor_x_l1 > 0 && ocor_x_l1 > ocor_x_l2){
        printf("\n A lista 1 possui mais ocorrencias no eixo X");
    }else if(ocor_x_l2 > 0 && ocor_x_l2 > ocor_x_l1){
        printf("\n A lista 2 possui mais ocorrencias no eixo X");
    }else if(ocor_x_l1 > 0 && ocor_x_l2 > 0 && ocor_x_l1 == ocor_x_l2){
        printf("\n As duas listas possuem a mesma quantidade de ocorrencias no eixo X");
    }
    if(ocor_y_l1 > 0 && ocor_y_l1 >ocor_y_l2){
        printf("\n A lista 1 possui mais ocorrencias no eixo Y");
    }else if(ocor_y_l2 > 0 && ocor_x_l2 > ocor_y_l1){
        printf("\n A lista 2 possui mais ocorrencias no eixo Y");
    }else if(ocor_y_l1 > 0 && ocor_y_l2 > 0 && ocor_y_l1 == ocor_y_l2){
        printf("\n As duas listas possuem a mesma quantidade de ocorrencias no eixo Y");
    }
    if(ocor_1qdt_l1 > ocor_1qdt_l2){
        printf("\n A lista 1 possui mais ocorrencias no quadrante 1");
    }else if(ocor_1qdt_l2 > ocor_1qdt_l1){
        printf("\n A lista 2 possui mais ocorrencias no quadrante 1");   
    }else if(ocor_1qdt_l1 == ocor_1qdt_l2){
        printf("\n As duas listas possuem a mesma quantidade de ocorrencias no quadrante 1");
    }
    if(ocor_2qdt_l1 > ocor_2qdt_l2){
        printf("\n A lista 1 possui mais ocorrencias no quadrante 2");
    }else if(ocor_2qdt_l2 > ocor_2qdt_l1){
        printf("\n A lista 2 possui mais ocorrencias no quadrante 2");   
    }else if(ocor_2qdt_l1 == ocor_2qdt_l2){
        printf("\n As duas listas possuem a mesma quantidade de ocorrencias no quadrante 2");
    }
    if(ocor_3qdt_l1 > ocor_3qdt_l2){
        printf("\n A lista 1 possui mais ocorrencias no quadrante 3");
    }else if(ocor_3qdt_l2 > ocor_3qdt_l1){
        printf("\n A lista 2 possui mais ocorrencias no quadrante 3");   
    }else if(ocor_3qdt_l1 == ocor_3qdt_l2){
        printf("\n As duas listas possuem a mesma quantidade de ocorrencias no quadrante 3");
    }
    if(ocor_4qdt_l1 > ocor_4qdt_l2){
        printf("\n A lista 1 possui mais ocorrencias no quadrante 4");
    }else if(ocor_4qdt_l2 > ocor_4qdt_l1){
        printf("\n A lista 2 possui mais ocorrencias no quadrante 4");   
    }else if(ocor_4qdt_l1 == ocor_4qdt_l2){
        printf("\n As duas listas possuem a mesma quantidade de ocorrencias no quadrante 4");
    }
    printf("\n");
}
int main(){
    coordenada lista1_coordenadas[3];
    coordenada lista2_coordenadas[3];
    
    for(int i = 0; i < 3;i++){
        printf("\nEscreva as coordenadas para x e y da lista 1: ");
        scanf("%d %d", &lista1_coordenadas[i].x, &lista1_coordenadas[i].y);
    }
    for(int i = 0; i < 3;i++){
        printf("\nEscreva as coordenadas para x e y da lista 2: ");
        scanf("%d %d", &lista2_coordenadas[i].x, &lista2_coordenadas[i].y);
    }
    mostrar_coordenada(lista1_coordenadas, lista2_coordenadas);
}