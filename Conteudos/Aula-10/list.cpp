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

void libera_lista(Lista *li)
{
    free(li); // Libera a memória alocada para a lista
}

int tamanho_lista(Lista *li)
{
    if(li == NULL) // Verifica se a lista foi criada corretamente
        return -1; // Retorna -1 para indicar que a lista foi criada

    return li -> quantidade; // Retorna a quantidade de clientes na lista
}

int lista_cheia(Lista *li)
{
    if(li == NULL) // Verifica se a lista foi criada corretamente
        return -1; // Retorna -1 para indicar que a lista foi criada

    return (li -> quantidade == MAX); // Retorna true se a lista estiver cheia, false caso contrário
}

int insere_lista_final(Lista *li)
{
    if(li == NULL) // Verifica se a lista foi criada corretamente
        return -1; // Retorna -1 para indicar que a lista foi criada
    
    if(lista_cheia(li) == 1) // Verifica se a lista está cheia
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

void imprime_lista(Lista *li)
{
    if(li == NULL) // Verifica se a lista foi criada corretamente
    {
        cout << "Lista inexistente!" << endl; // Imprime mensagem de erro
        return; // Encerra a função
    }
    if(li -> quantidade == 0) // Verifica se a lista está vazia
    {
        cout << "Lista vazia!" << endl; // Imprime mensagem de erro
        return; // Encerra a função
    }

    for(int i = 0; i < li -> quantidade; i++) // Loop para percorrer a lista de clientes
    {
        cout << "Cliente " << i + 1 << ": " << endl; // Imprime o número do cliente
        cout << "CPF: " << li -> dados[i].cpf << endl; // Imprime o CPF do cliente
        cout << "Nome: " << li -> dados[i].nome << endl; // Imprime o nome do cliente
        cout << "-------------------------" << endl; // Imprime uma linha de separação entre os clientes
    }
}

int main()
{
    head = criar_lista(); // Criação da lista

    if(insere_lista_final(head) < 0) // Verifica se a inserção do cliente foi bem-sucedida
    {
        cout << "Erro ao inserir cliente!" << endl; // Imprime mensagem de erro
        return -1; // Encerra o programa com código de erro
    }
    else
    {
        cout << "Cliente inserido com sucesso!" << endl; // Imprime mensagem de sucesso
    }

    head = criar_lista(); // Criação da lista

    if(insere_lista_final(head) < 0) // Verifica se a inserção do cliente foi bem-sucedida
    {
        cout << "Erro ao inserir cliente!" << endl; // Imprime mensagem de erro
        return -1; // Encerra o programa com código de erro
    }
    else
    {
        cout << "Cliente inserido com sucesso!" << endl; // Imprime mensagem de sucesso
    }

    imprime_lista(head); // Impressão da lista de clientes

    libera_lista(head); // Liberação da memória alocada para a lista    

    //int resultInsert = inserir_cliente(head); // Inserção do cliente na lista

    return 0;
}
