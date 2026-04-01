#include <iostream>
using namespace std;

int fatorial(int n){
    if(n == 0)
        return 1;
    else
        return n * fatorial(n-1);
}

int main(){
    int numero;

    cout << "Digite um numero: ";
    cin >> numero;

    cout << "O Fatorial de " << numero << " eh: " << fatorial(numero) << endl;

    return 0;
}