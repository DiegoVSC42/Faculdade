#include <stdio.h>

int main(int argc, char const *argv[]){char comando;

    scanf("%c", &comando);

    switch (comando){
        case 'o':
            printf("t\n");
            break;
        
        case 't':
            printf("o\n");
            break;
        
        default:
            printf("?\n");
            break;
        }
        
    return 0;

}
