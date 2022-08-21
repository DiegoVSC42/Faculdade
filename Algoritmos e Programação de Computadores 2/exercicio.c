#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada
{
    int x, y;
} coordenada;

void preenche_coordenada(coordenada *x)
{

    printf("\n Digite a coordenada X: ");
    scanf("%d", &x->x);
    printf("\n Digite a coordenada Y: ");
    scanf("%d", &x->y);
}

void mostrar_quadrante(coordenada x)
{

    if (x.x != 0 && x.y == 0)
    {
        printf("\n Coordenada sobre o eixo Y\n");
    }

    if (x.x == 0 && x.y != 0)
    {
        printf("\n Coordenada sobre o eixo X\n");
    }

    if (x.x == 0 && x.y == 0)
    {
        printf("\n Coordenada no ponto neutro\n");
    }

    if (x.x > 0 && x.y > 0)
    {
        printf("\n Coordenada no primeiro quadrante\n");
    }

    if (x.x < 0 && x.y > 0)
    {
        printf("\n Coordenada no segundo quadrante\n");
    }

    if (x.x < 0 && x.y < 0)
    {
        printf("\n Coordenada no terceiro quadrante\n");
    }

    if (x.x > 0 && x.y < 0)
    {
        printf("\n Coordenada no quarto quadrante\n");
    }
}

int main(int argc, char const *argv[])
{

    coordenada coordenadas[10];

    for (int i = 0; i < 10; i++)
    {
        preenche_coordenada(&coordenadas[i]);
        mostrar_quadrante(coordenadas[i]);
    }
    return 0;
}