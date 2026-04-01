#include <iostream>
#include "pessoa.hpp"
using namespace std;

Pessoa *_pessoa_cria(string nome, int idade, string endereco)
{
    Pessoa *p = new Pessoa; // Aloca memória para um novo Pessoa usando new

    if(p == nullptr) { // Verifica se a alocação de memória foi bem-sucedida
        cout << "Erro ao alocar memória para Pessoa" << endl;
        return nullptr;
    }

    // Atribui os valores aos campos da estrutura
    p->nome = nome;
    p->idade = idade;
    p->endereco = endereco;

    cout << "Pessoa Cadastrada com Sucesso" << endl;

    // Retorna o ponteiro para a estrutura criada
    return p;
}

void _pessoa_acessa(Pessoa* p, string* nome, int* idade, string* endereco)
{
    if(p == nullptr) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    // Atribui o valor do parâmetro se o ponteiro não for nulo
    if(nome) *nome = p->nome; 
    if(idade) *idade = p->idade; 
    if(endereco) *endereco = p->endereco; 

    cout << "Detalhe da Pessoa" << endl;
}

void _pessoa_atribui(Pessoa* p, string nome, int idade, string endereco)
{
    if(p == nullptr) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    // Atribui os novos valores aos campos da estrutura
    p->nome = nome;
    p->idade = idade;
    p->endereco = endereco;

    cout << "Pessoa Alterada com Sucesso" << endl;
}

void _pessoa_libera(Pessoa* p)
{
    if(p != nullptr) { // Verifica se o ponteiro é nulo antes de liberar a memória
        delete p; // Libera a memória alocada para a estrutura usando delete
        cout << "Pessoa Removida com Sucesso" << endl;
    }
}