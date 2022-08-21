#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{

    long int matricula;
    float salario_bruto;
    int carga_horaria;

} funcionario;

void colocar_funcionario(funcionario *jack){
    
    printf("\nDigite a matricula de jack: ");
    scanf("%ld", &jack->matricula);
    printf("\nDigite o salario de jack: ");
    scanf("%f", &jack->salario_bruto);
    printf("\nDigite a carga horaria de jack: ");
    scanf("%d", &jack->carga_horaria);
    printf("\n");

}

void mostrar_tela(funcionario jack){
    
    printf("\nMatricula de jack: %ld", jack.matricula);
    printf("\nSalario de jack: %.2f", jack.salario_bruto);
    printf("\nCarga horaria de jack: %d\n", jack.carga_horaria);
    printf("\n");
}
int main(){
    funcionario jack;

    colocar_funcionario(&jack);
    mostrar_tela(jack);
}