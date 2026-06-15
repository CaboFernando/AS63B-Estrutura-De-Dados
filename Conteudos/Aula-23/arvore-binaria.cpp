#include <iostream>
using namespace std;

//criação do nodo
struct no
{
    int info;
    string nome;
    no* esq;
    no* dir;
};

//caveça da lista
typedef no* ArvBin;

//criação da arvore binária
ArvBin* cria_ArvBin()
{
    ArvBin* raiz = new ArvBin;

    if(raiz != nullptr)
        *raiz = nullptr;

    return raiz;
}

//inserir na arvore binária
bool insere_ArvBin (ArvBin* raiz, int valor)
{
    if(raiz == nullptr)
        return false;
    
    no* novo = new no;

    novo->info = valor;
    novo->esq = nullptr;
    novo->dir = nullptr;

    if(*raiz == nullptr)
        //ponteiro para ponteiro
        *raiz = novo;
        return true;
    
    no* atual = *raiz;

    while (true)
    {
        if(valor < atual->info)
        {
            if(atual->esq == nullptr)
            {
                atual->esq = novo;
                return true;
            }
            atual = atual->esq;
        }
        else
        {
            if(atual->dir == nullptr)
            {
                atual->dir = novo;
                return true;
            }
            atual = atual->dir;
        }            
    }    
}

void emOrdem(no* no)
{
    if(no == nullptr)
    {
        cout << "Deu ruim!" << endl;
        return;
    }

    emOrdem(no->esq);
    cout << "Passou pela raiz: " << no->info << endl;
    emOrdem(no->dir);
}

int main()
{
    ArvBin* raiz = cria_ArvBin();

    //inserção de alguns nodos
    insere_ArvBin(raiz, 3);
    insere_ArvBin(raiz, 7);
    insere_ArvBin(raiz, 6);
    insere_ArvBin(raiz, 15);
    insere_ArvBin(raiz, 101);

    cout << "Percurso em ordem" << endl;

    emOrdem(*raiz);

    return 0;
}

/*
Implementar:
- outros tipos de percurso
- menu para o usuário interagir com a aplicação
- a função de eliminação da árvore

*/