#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int i, j, lenv;
    char frase[100], vogais[] = "aeiouAEIOU";

    lenv = strlen(vogais);

    gets(frase);
    printf("\n");

    for (i = 0; i < strlen(frase); i++)
    {

        for (j = 0; j < lenv; j++)
            if (frase[i] == vogais[j])
                break;

        if (j == lenv)
            printf("%c", frase[i]);
    }


    return 0;
}