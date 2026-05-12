#include <iostream>
using namespace std;

struct aluno
{
    int matricula;
    string nome;
    float n1, n3, n3;
};

struct elemento
{
    aluno dados;
    elemento *prox;
};

typedef elemento* Lista;

Lista * cria_lista()
{
    Lista * li = new Lista;

    if(li != nullptr)
        *li = nullptr;

    return li;
}

int insere_lista_final(Lista * li, aluno al)
{
    if(li == nullptr)
        return 0;
    
    elemento * no = new elemento;

    if(no == nullptr)
        return 0;

    no -> dados = al;
    no -> prox = nullptr;

    if(*li == nullptr)
        *li = no;
    else
    {
        elemento *aux = *li;

        while (aux -> prox != nullptr)
            aux = aux -> prox;
        
        aux -> prox = no;
    }

    return 1;        
}

void imprime_lista(Lista *li)
{
    if(li == nullptr)
        return;

    elemento * no = *li;

    while (no != nullptr)
    {
        cout << "Matricula: " << no -> dados.matricula << endl;
        cout << "Matricula: " << no -> dados.matricula << endl;
        cout << "Matricula: " << no -> dados.matricula << endl;
        cout << "Matricula: " << no -> dados.matricula << endl;
        cout << "Matricula: " << no -> dados.matricula << endl;

        no = no -> prox;
    }
}

int remove_lista_final(Lista* li)
{
    if(li == nullptr || *li == nullptr)
        return 0;
    
    elemento *ant = nullptr;
    elemento *no = *li;

    while (no -> prox != nullptr)
    {
        ant = no;
        no = no -> prox;
    }
    
    if(ant == nullptr)
        *li = nullptr;
    else
        ant -> prox = nullptr;

    delete no;

    return 1;
}

int remove_lista_meio(Lista *li, int mat)
{
    if(li == nullptr || *li == nullptr)
        return 0;
    
    elemento *ant = nullptr;
    elemento *no = *li;

    while (no -> prox != nullptr && no -> dados.matricula != mat)
    {
        ant = no;
        no = no -> prox;
    }

    if(ant == nullptr)
        *li = nullptr;
    else
        ant -> prox = nullptr;

    delete no;

    return 1;
}

int main()
{
    aluno a[4] = {
        {2, "Andre", 9.0, 6.0, 7.6},
        {4, "Ricardo", 8.1, 7.1, 8.9},
        {1, "Bianca", 7.1, 10.0, 9.1},
        {3, "Ana", 8.6, 8.5, 9.2},
    };

    Lista * li = cria_lista();

    for (int i = 0; i < 5; i++)
        insere_lista_final(li, a[i]);

    imprime_lista(li);
    
    // Continuar implementação com:
    // - Remoção de um nó da lista - feito
    // - Inserção ordenada (matrícula)
    // - Liberação da lista (liberar cada nó existes, não somente a cabeça da lsita)
    // - Contar o tamanho da lista

    // Continuar implementação com:
    // - Crie uma função para remover todos os nós

    return 0;
}