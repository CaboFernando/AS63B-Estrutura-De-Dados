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

    // Retorna o ponteiro para a estrutura criada
    return p;
}