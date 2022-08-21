#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];

    printf("Digite a string:");
    fgets(string,100,stdin);
    

    for(int i = 0;i < strlen(string);i++){
        if(string[i] != ' '){
            string[i]= string[i]  + 3;
        }
    }

    printf("%s", string);
    printf("\n");
    return 0;
}