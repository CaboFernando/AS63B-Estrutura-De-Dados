#include <iostream>
using namespace std;

int contagemRegressiva(int n){
    if(n == 0)
        return 0;
    else{
        cout << n << endl;
        return contagemRegressiva(n-1);
    }
}

int main()
{
    int numero;

    cout << "Digite um numero: ";
    cin >> numero;

    cout << contagemRegressiva(numero);

    return 0;
}