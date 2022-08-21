#include <stdio.h>
#include <math.h>

typedef struct Cartesiana{
    double x;
    double y;
}Cartesiana;

typedef struct Polares{
    double raio;
    double argumento;
}Polares;

int main(void) {
    Cartesiana a;
    Polares b;
    printf("Raio:");
    scanf("%lf",&b.raio);
    printf("Argumento:");
    scanf("%lf",&b.argumento);

    a.x=b.raio*cos(b.argumento);
    a.y=b.raio*sin(b.argumento);

    printf("X= %lf\tY= %lf\n",a.x,a.y);
}