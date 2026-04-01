#include <stdio.h>
#include <iostream>

using namespace std;

int somarNumeros(int n1, int n2){
    return n1+n2;
}

int mostrarNumero(int n){
    cout << "Valor: " << n << endl;
    mostrarNumero(n+1);
    return 0;
}

int main(){
    cout << "Estrutura de Dados" << endl;
    int res;
    res = somarNumeros(3,9);
    cout << "Resultado: " << res << endl;

    mostrarNumero(0);
}