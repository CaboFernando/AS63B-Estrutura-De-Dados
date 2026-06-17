#include <iostream>
using namespace std;

// criação de um nodo
struct no 
{
    int info;
    string nome;
    no* esq;
    no* dir;
    int alt;
};

//cabeça da lista
typedef no* ArvAvl;

ArvAvl* raiz;

//funções auxiliares

//calcula a altura de um nó
int alt_no(struct no* no)
{
    if(no == nullptr)
        return -1;
    else
        return no->alt;
}

//calcula o fator de balanceamento
int fat_balanceamento_no(struct no* no)
{
    return alt_no(no->esq) - alt_no(no->dir);
}

//rotação LL
void rotacaoLL(ArvAvl* raiz)
{
    struct no* no;

    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = alt_no((*raiz)->esq) - alt_no((*raiz)->dir) + 1;    
    no->alt = alt_no(no->esq) + (*raiz)->alt - 1;
    
    *raiz = no;
}