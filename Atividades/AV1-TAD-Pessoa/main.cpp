#include <iostream>
#include "pessoa.cpp"
using namespace std;

Pessoa* criarPessoa()
{
    string nome, endereco;
    int idade;

    cout << "Digite o nome da pessoa: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite a idade da pessoa: ";
    cin >> idade;

    cout << "Digite o endereco da pessoa: ";
    cin.ignore();
    getline(cin, endereco);

    return _pessoa_cria(nome, idade, endereco);
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
    cin.ignore();
    getline(cin, nome);

    cout << "Digite a nova idade da pessoa: ";
    cin >> idade;

    cout << "Digite o novo endereco da pessoa: ";
    cin.ignore();
    getline(cin, endereco);

    _pessoa_atribui(p, nome, idade, endereco);
}

void removerPessoa(Pessoa** p)
{
    if(*p != nullptr) {
        _pessoa_libera(*p);
        *p = nullptr;
    }
}

void menu()
{
    char opcao;
    Pessoa* p = nullptr;

    do{
        cout << "========== MENU ==========" << endl;
        cout << "1. Criar Pessoa" << endl;
        cout << "2. Visualizar Pessoa" << endl;
        cout << "3. Alterar Pessoa" << endl;
        cout << "4. Remover Pessoa" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";        
        cin >> opcao;

        switch(opcao)
        {
            case '1': if(p) cout << "Pessoa ja criada. Remova-a primeiro.\n" << endl; else p = criarPessoa(); break;

            case '2': if(p) visualizarPessoa(p); else cout << "Nenhuma pessoa listada.\n" << endl; break;

            case '3': if(p) alterarPessoa(p); else cout << "Nenhuma pessoa para ser alterada.\n" << endl; break;

            case '4': if(p) removerPessoa(&p); else cout << "Nenhuma pessoa para ser removida.\n" << endl; break;

            case '0': cout << "Saindo...\n" << endl; break;

            default: cout << "Opcao invalida. Tente novamente.\n" << endl;
        }

    } while(opcao != '0');

    cout << "==========================" << endl;
}

int main()
{
    menu();
    
    return 0;
}