#include <iostream>
#include "pessoa.cpp"
using namespace std;

void criarPessoa()
{
    string nome, endereco;
    int idade;

    cout << "Digite o nome da pessoa: ";
    cin >> nome;
    cout << "Digite a idade da pessoa: ";
    cin >> idade;
    cout << "Digite o endereco da pessoa: ";
    cin >> endereco;

    Pessoa* p = _pessoa_cria(nome, idade, endereco);
}

void visualizarPessoa(Pessoa* p)
{
    string nome, endereco;
    int idade;

    _pessoa_acessa(p, &nome, &idade, &endereco);

    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Endereco: " << endereco << endl;
}

void alterarPessoa(Pessoa* p)
{
    string nome, endereco;
    int idade;

    cout << "Digite o novo nome da pessoa: ";
    cin >> nome;
    cout << "Digite a nova idade da pessoa: ";
    cin >> idade;
    cout << "Digite o novo endereco da pessoa: ";
    cin >> endereco;

    _pessoa_atribui(p, nome, idade, endereco);
}

void removerPessoa(Pessoa* p)
{
    _pessoa_libera(p);
}

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
        cout << "Escolha uma opcao: ";        
        cin >> opcao;

    } while(opcao != 0);

}

int main()
{
    menu();

    cout << "==========================" << endl;
    return 0;
}