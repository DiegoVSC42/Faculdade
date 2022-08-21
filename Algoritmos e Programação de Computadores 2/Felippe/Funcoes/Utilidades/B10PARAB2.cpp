#include <bits/stdc++.h>

//g++ "NOME DO ARQUIVO.cpp" -02 -o "NOME DO EXECUTAVEL"

using namespace std;

int main(){

    int b10;
    int b2[32];
    int aux;

    cout << "Qual o numero na base 10 que sera convertido ?"<< endl;
    scanf("%d", &b10);

    for(aux = 31 ;aux >= 0 ;aux--){
        if(b10 % 2 == 0){
            b2[aux] = 0;
        }else{
            b2[aux] = 1;
        }
        b10 = b10/2;
    }

    
    for(aux = 0; aux < 32;aux ++){
        printf("%d", b2[aux]);
    }

    return 0;
}