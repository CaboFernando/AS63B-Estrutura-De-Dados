#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define MAX 100 // Tamanho máximo da lista

struct cliente  // Estrutura para armazenar os dados do cliente
{
    int cpf; // 4 bytes
    char nome[50]; // 50 bytes
};

struct lista // Estrutura para armazenar a lista de clientes
{
    int quantidade; // 4 bytes
    cliente dados[MAX]; // 100 * (4 + 50) bytes = 5400 bytes
};

typedef struct lista Lista; // Definição do tipo Lista para facilitar a declaração de variáveis do tipo lista

Lista * head; // Ponteiro para a cabeça da lista

Lista * criar_lista() // Função para criar a lista
{
    Lista * li;

    li = (Lista*) malloc (sizeof(struct lista)); // Alocação dinâmica de memória para a lista

    if(li != NULL)
        li -> quantidade;

    return li;
}

int inserir_cliente(Lista *li) // Função para inserir um cliente na lista)
{
    if(li == NULL) // Verifica se a lista foi criada corretamente
        return -1; // Retorna -1 para indicar que a lista foi criada
    
    if(li -> quantidade == MAX) // Verifica se a lista está cheia
        return -2; // Retorna -2 para indicar que a lista está cheia

    cliente c; // Declaração de um cliente
    cout << "Digite o CPF do cliente: ";
    cin >> c.cpf; // Leitura do CPF do cliente
    cout << "Digite o nome do cliente: ";
    cin >> c.nome; // Leitura do nome do cliente

    li -> dados[li -> quantidade] = c; // Insere o cliente na posição indicada por quantidade
    li -> quantidade++; // Incrementa a quantidade de clientes na lista

    return li -> quantidade; // Retorna a nova quantidade de clientes na lista
}

int main()
{
    head = criar_lista(); // Criação da lista
    int resultado = inserir_cliente(head); // Inserção do cliente na lista

    return 0;
}
