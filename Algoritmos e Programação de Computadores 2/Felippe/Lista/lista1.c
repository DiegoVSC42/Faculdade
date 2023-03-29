#include <stdio.h>
#include <stdlib.h>

typedef struct Horario{

    int hora;
    int minutos;
    int segundos;

} Horario;

typedef struct Data{
    
    int dia;
    char mes[20];
    int ano;

}Data;

typedef struct Compromisso{
    
    Data data;
    Horario horario;
    char compromisso;
    
}Compromisso;
