#include <iostream>
#include "pessoa.cpp"
using namespace std;

// Capacidade máxima do vetor
const int CAPACIDADE = 10;

// Função para encontrar o índice de uma pessoa no vetor pelo nome
int encontrarPessoa(Pessoa* vetor[], int total, string nome)
{
    for(int i = 0; i < total; i++) 
    {
        if(vetor[i] != nullptr && vetor[i]->nome == nome)
            return i; // Retorna o índice da pessoa encontrada
    }
    return -1; // Retorna -1 se a pessoa não for encontrada
}

// Função para listar todas as pessoas
void listarPessoas(Pessoa* vetor[], int total)
{
    if(total == 0) {
        cout << "Nenhuma pessoa cadastrada.\n" << endl;
        return;
    }

    cout << "\n==== LISTA DE PESSOAS ====" << endl;
    for(int i = 0; i < total; i++) 
    {
        if(vetor[i] != nullptr) cout << i+1 << ". " << vetor[i]->nome << " (Idade: " << vetor[i]->idade << ")" << endl;
    }
    cout << "==========================\n" << endl;
}

// Função para criar uma nova pessoa e adicioná-la ao vetor
bool criarPessoa(Pessoa* vetor[], int& total)
{
    if(total >= CAPACIDADE) {
        cout << "Capacidade máxima atingida. Não é possível criar mais pessoas.\n" << endl;
        return false; // Retorna false se a capacidade máxima for atingida
    }

    string nome, endereco;
    int idade;

    cout << "Digite o nome da pessoa: ";
    cin.ignore();
    getline(cin, nome);

    if(encontrarPessoa(vetor, total, nome) != -1)
    {
        cout << "Pessoa com esse nome já existe. Tente novamente.\n" << endl;
        return false; // Retorna false se a pessoa já existir
    }

    cout << "Digite a idade da pessoa: ";
    cin >> idade;

    cout << "Digite o endereco da pessoa: ";
    cin.ignore();
    getline(cin, endereco);

    Pessoa* novaPessoa = _pessoa_cria(nome, idade, endereco);
    if(novaPessoa != nullptr)
    {
        vetor[total] = novaPessoa; // Adiciona a nova pessoa ao vetor
        total++; // Incrementa o total de pessoas cadastradas
        return true; // Retorna true se a pessoa foi criada com sucesso
    }

    return false;
}

// Função para visualizar os detalhes de uma pessoa específica
void visualizarPessoa(Pessoa* vetor[], int total)
{
    if(total == 0) {
        cout << "Nenhuma pessoa cadastrada.\n" << endl;
        return;
    }

    listarPessoas(vetor, total);

    int escolha;
    cout << "Digite o número da pessoa que deseja visualizar: ";
    cin >> escolha;

    if(escolha < 1 || escolha > total || vetor[escolha - 1] == nullptr) {
        cout << "Número inválido. Tente novamente.\n" << endl;
        return; // Retorna se a escolha for inválida
    }

    Pessoa* p = vetor[escolha - 1]; // Obtém a pessoa selecionada
    string nome, endereco;
    int idade;

    _pessoa_acessa(p, &nome, &idade, &endereco); // Acessa os detalhes da pessoa

    cout << "\n==== DADOS DA PESSOA =====" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "==========================\n" << endl;
}

// Função para alterar os detalhes de uma pessoa específica
void alterarPessoa(Pessoa* vetor[], int total)
{
    if(total == 0) {
        cout << "Nenhuma pessoa cadastrada.\n" << endl;
        return;
    }

    listarPessoas(vetor, total);

    int escolha;
    cout << "Digite o número da pessoa que deseja alterar: ";
    cin >> escolha;

    if(escolha < 1 || escolha > total || vetor[escolha - 1] == nullptr) {
        cout << "Número inválido. Tente novamente.\n" << endl;
        return; // Retorna se a escolha for inválida
    }

    string nome, endereco;
    int idade;

    cout << "Digite o novo nome da pessoa: ";
    cin.ignore();
    getline(cin, nome);

    // Verifica se o novo nome já existe para outra pessoa no vetor, ignorando a pessoa que está sendo alterada
    int indiceExistente = encontrarPessoa(vetor, total, nome);
    if(indiceExistente != -1 && indiceExistente != (escolha - 1)) {
        cout << "Pessoa com esse nome já existe. Tente novamente.\n" << endl;
        return; // Retorna se o novo nome já existir para outra pessoa
    }

    cout << "Digite a nova idade da pessoa: ";
    cin >> idade;

    cout << "Digite o novo endereco da pessoa: ";
    cin.ignore();
    getline(cin, endereco);

    _pessoa_atribui(vetor[escolha - 1], nome, idade, endereco);
}

// Função para remover uma pessoa específica do vetor
void removerPessoa(Pessoa* vetor[], int& total)
{
    if(total == 0) {
        cout << "Nenhuma pessoa cadastrada.\n" << endl;
        return;
    }

    listarPessoas(vetor, total);

    int escolha;
    cout << "Digite o número da pessoa que deseja remover: ";
    cin >> escolha;

    if(escolha < 1 || escolha > total || vetor[escolha - 1] == nullptr) {
        cout << "Número inválido. Tente novamente.\n" << endl;
        return; // Retorna se a escolha for inválida
    }

    _pessoa_libera(vetor[escolha - 1]); // Libera a memória da pessoa selecionada

    // Remove do vetor deslovando os elementos seguintes
    for(int i = escolha - 1; i < total - 1; i++) {
        vetor[i] = vetor[i + 1]; // Desloca os elementos seguintes para preencher a lacuna
    }

    total--;
    cout << "Pessoa removida com sucesso.\n" << endl;
}


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