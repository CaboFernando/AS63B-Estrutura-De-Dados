#include <iostream>
#include "pessoa.cpp"
using namespace std;

Pessoa* criarPessoa()
{
    string nome, endereco;
    int idade;

    cout << "Digite o nome da pessoa: ";
    cin >> nome;
    cout << "Digite a idade da pessoa: ";
    cin >> idade;
    cout << "Digite o endereco da pessoa: ";
    cin >> endereco;

    return _pessoa_cria(nome, idade, endereco); // Chama a função _pessoa_cria para criar uma nova Pessoa e retorna o ponteiro para ela
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

void removerPessoa(Pessoa** p)
{
    if(*p != nullptr) {
        _pessoa_libera(*p);
        *p = nullptr;
    }
}

void menu()
{
    int opcao;
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
            case 1: 
                if(p) cout << "Pessoa ja criada. Remova-a primeiro." << endl; 
                else p = criarPessoa(); break;
            case 2: visualizarPessoa(p); break;
            case 3: alterarPessoa(p); break;
            case 4: removerPessoa(&p); break;
            case 0: cout << "Saindo..." << endl; break;
            default: cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while(opcao != 0);

}

int main()
{
    menu();

    cout << "==========================" << endl;
    return 0;
}