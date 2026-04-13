#include <iostream>
#include <string>
#include "funcionario.hpp"
using namespace std;

int main()
{
    Funcionario funcionario;
    float aumentoSalario;
    int novaIdade;

    cout << "Digite o nome do funcionario: ";
    getline(cin, funcionario.nome);

    cout << "Digite o salario atual: ";
    cin >> funcionario.salario;

    cout << "Digite a idade atual: ";
    cin >> funcionario.idade;

    cout << "Digite o aumento salarial: ";
    cin >> aumentoSalario;

    cout << "Digite a nova idade: ";
    cin >> novaIdade;

    atualizarDados(&funcionario, aumentoSalario, novaIdade);

    cout << "\nDados atualizados do funcionario:" << endl;
    cout << "Nome: " << funcionario.nome << endl;
    cout << "Salario: " << funcionario.salario << endl;
    cout << "Idade: " << funcionario.idade << endl;

    return 0;
}