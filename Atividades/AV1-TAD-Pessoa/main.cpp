#include <iostream>
#include "pessoa.cpp"
using namespace std;

void menu()
{
    int opcao;

    do{
        cout << "========== MENU ==========" << endl;
        cout << "1. Criar Pessoa" << endl;
        cout << "2. Visualizar Pessoa" << endl;
        cout << "3. Alterar Pessoa" << endl;
        cout << "4. Remover Pessoa" << endl;
        cout << "0. Sair" << endl;
        cout << "==========================" << endl;
        cin >> opcao;
    } while(opcao != 0);

}

int main()
{
    menu();

    return 0;
}