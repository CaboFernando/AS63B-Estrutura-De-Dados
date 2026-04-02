#include <iostream>
#include <algorithm>
#include "pessoa.cpp"
using namespace std;

// Capacidade maxima do vetor
const int CAPACIDADE = 10;

// Função auxiliar para converter uma string para minusculo, usada para comparações de nomes
string toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Funçao para encontrar o indice de uma pessoa no vetor pelo nome
int encontrarPessoa(Pessoa* vetor[], int total, string nome)
{
    for(int i = 0; i < total; i++) 
    {
        if(vetor[i] != nullptr && toLower(vetor[i]->nome) == toLower(nome))
            return i; // Retorna o indice da pessoa encontrada
    }
    return -1; // Retorna -1 se a pessoa nao for encontrada
}

// Funçao para listar todas as pessoas
void listarPessoas(Pessoa* vetor[], int total)
{
    if(total == 0) {
        cout << "\nNenhuma pessoa cadastrada para ser listada." << endl;
        return;
    }

    cout << "\n==== LISTA DE PESSOAS ====" << endl;
    for(int i = 0; i < total; i++) 
    {
        if(vetor[i] != nullptr) cout << i+1 << ". " << vetor[i]->nome << " (Idade: " << vetor[i]->idade << ")" << endl;
    }
    cout << "==========================\n" << endl;
}

// Funçao para criar uma nova pessoa e adiciona-la ao vetor
bool criarPessoa(Pessoa* vetor[], int& total)
{
    if(total >= CAPACIDADE) {
        cout << "\nCapacidade maxima atingida. Nao e possivel criar mais pessoas.\n" << endl;
        return false; // Retorna false se a capacidade maxima for atingida
    }

    string nome, endereco;
    int idade;

    cout << "Digite o nome da pessoa: ";
    cin.ignore();
    getline(cin, nome);

    if(encontrarPessoa(vetor, total, nome) != -1)
    {
        cout << "\nPessoa com esse nome ja existe. Tente novamente.\n" << endl;
        return false; // Retorna false se a pessoa ja existir
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
        cout << "\nPessoa criada com sucesso." << endl;

        return true; // Retorna true se a pessoa foi criada com sucesso
    }

    return false;
}

// Funçao para visualizar os detalhes de uma pessoa especifica
void visualizarPessoa(Pessoa* vetor[], int total)
{
    if(total == 0) {
        cout << "\nNenhuma pessoa cadastrada para ser visualizada." << endl;
        return;
    }

    listarPessoas(vetor, total);

    int escolha;
    cout << "Digite o numero da pessoa que deseja visualizar: ";
    cin >> escolha;

    if(escolha < 1 || escolha > total || vetor[escolha - 1] == nullptr) {
        cout << "\nNumero invalido. Tente novamente.\n" << endl;
        return; // Retorna se a escolha for invalida
    }

    Pessoa* p = vetor[escolha - 1]; // Obtem a pessoa selecionada
    string nome, endereco;
    int idade;

    _pessoa_acessa(p, &nome, &idade, &endereco); // Acessa os detalhes da pessoa

    cout << "\n==== DADOS DA PESSOA =====" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "==========================\n" << endl;
}

// Funçao para alterar os detalhes de uma pessoa especifica
void alterarPessoa(Pessoa* vetor[], int total)
{
    if(total == 0) {
        cout << "\nNenhuma pessoa cadastrada para ser alterada." << endl;
        return;
    }

    listarPessoas(vetor, total);

    int escolha;
    cout << "Digite o numero da pessoa que deseja alterar: ";
    cin >> escolha;

    if(escolha < 1 || escolha > total || vetor[escolha - 1] == nullptr) {
        cout << "\nNumero invalido. Tente novamente.\n" << endl;
        return; // Retorna se a escolha for invalida
    }

    string nome, endereco;
    int idade;

    cout << "Digite o novo nome da pessoa: ";
    cin.ignore();
    getline(cin, nome);

    // Verifica se o novo nome ja existe para outra pessoa no vetor, ignorando a pessoa que esta sendo alterada
    int indiceExistente = encontrarPessoa(vetor, total, nome);
    if(indiceExistente != -1 && indiceExistente != (escolha - 1)) {
        cout << "Pessoa com esse nome ja existe. Tente novamente.\n" << endl;
        return; // Retorna se o novo nome ja existir para outra pessoa
    }

    cout << "Digite a nova idade da pessoa: ";
    cin >> idade;

    cout << "Digite o novo endereco da pessoa: ";
    cin.ignore();
    getline(cin, endereco);

    _pessoa_atribui(vetor[escolha - 1], nome, idade, endereco);
    cout << "\nPessoa alterada com sucesso." << endl;
}

// Funçao para remover uma pessoa especifica do vetor
void removerPessoa(Pessoa* vetor[], int& total)
{
    if(total == 0) {
        cout << "\nNenhuma pessoa cadastrada para ser removida." << endl;
        return;
    }

    listarPessoas(vetor, total);

    int escolha;
    cout << "Digite o numero da pessoa que deseja remover: ";
    cin >> escolha;

    if(escolha < 1 || escolha > total || vetor[escolha - 1] == nullptr) {
        cout << "\nNumero invalido. Tente novamente.\n" << endl;
        return; // Retorna se a escolha for invalida
    }

    _pessoa_libera(vetor[escolha - 1]); // Libera a memória da pessoa selecionada

    // Remove do vetor deslovando os elementos seguintes
    for(int i = escolha - 1; i < total - 1; i++) {
        vetor[i] = vetor[i + 1]; // Desloca os elementos seguintes para preencher a lacuna
    }

    total--;
    cout << "\nPessoa removida com sucesso." << endl;
}

void liberarTodasPessoas(Pessoa* vetor[], int& total)
{
    for(int i = 0; i < total; i++) {
        if(vetor[i] != nullptr) _pessoa_libera(vetor[i]); // Libera a memória de cada pessoa
    }
}


// Pessoa* criarPessoa()
// {
//     string nome, endereco;
//     int idade;

//     cout << "Digite o nome da pessoa: ";
//     cin.ignore();
//     getline(cin, nome);

//     cout << "Digite a idade da pessoa: ";
//     cin >> idade;

//     cout << "Digite o endereco da pessoa: ";
//     cin.ignore();
//     getline(cin, endereco);

//     return _pessoa_cria(nome, idade, endereco);
// }

// void visualizarPessoa(Pessoa* p)
// {
//     string nome, endereco;
//     int idade;

//     _pessoa_acessa(p, &nome, &idade, &endereco);

//     cout << "Nome: " << nome << endl;
//     cout << "Idade: " << idade << endl;
//     cout << "Endereco: " << endereco << endl;
// }

// void alterarPessoa(Pessoa* p)
// {
//     string nome, endereco;
//     int idade;

//     cout << "Digite o novo nome da pessoa: ";
//     cin.ignore();
//     getline(cin, nome);

//     cout << "Digite a nova idade da pessoa: ";
//     cin >> idade;

//     cout << "Digite o novo endereco da pessoa: ";
//     cin.ignore();
//     getline(cin, endereco);

//     _pessoa_atribui(p, nome, idade, endereco);
// }

// void removerPessoa(Pessoa** p)
// {
//     if(*p != nullptr) {
//         _pessoa_libera(*p);
//         *p = nullptr;
//     }
// }

void menu()
{
    char opcao;
    Pessoa* pessoas[CAPACIDADE] = {nullptr}; // Vetor para armazenar os ponteiros para as pessoas
    int totalPessoas = 0; // Variavel para controlar o total de pessoas cadastradas

    do{
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Criar Pessoa" << endl;
        cout << "2. Visualizar Pessoa" << endl;
        cout << "3. Alterar Pessoa" << endl;
        cout << "4. Remover Pessoa" << endl;
        cout << "5. Listar Pessoas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";        
        cin >> opcao;

        switch(opcao)
        {
            case '1': criarPessoa(pessoas, totalPessoas); break;
            case '2': visualizarPessoa(pessoas, totalPessoas); break;
            case '3': alterarPessoa(pessoas, totalPessoas); break;
            case '4': removerPessoa(pessoas, totalPessoas); break;
            case '5': listarPessoas(pessoas, totalPessoas); break;
            case '0': cout << "Saindo...\n" << endl; liberarTodasPessoas(pessoas, totalPessoas); break;
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