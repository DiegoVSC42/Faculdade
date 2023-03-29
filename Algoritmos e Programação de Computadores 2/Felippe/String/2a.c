#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string1[100];
    char string2[100];

    printf("Digite as palavras: \n");
    fgets(string1,100,stdin);
    fgets(string2,100,stdin);
    
    printf("A palavra 1 invertida e alterada e: ");
    
    for(int i = strlen(string1)-2;i >= 0;i--){
        if(string1[i] == 'a' || string1[i] == 'A'){
            string1[i] = '*';
        }
        printf("%c", string1[i]);
    }
    printf("\n");
    printf("A palavra 2 invertida e alterada e: ");
    
    for(int i = strlen(string2)-2;i >= 0;i--){
        if(string2[i] == 'a' || string1[i] == 'A'){
            string2[i] = '*';
            
        }
        printf("%c", string2[i]);
    }

    printf("\n");
    return 0;
}