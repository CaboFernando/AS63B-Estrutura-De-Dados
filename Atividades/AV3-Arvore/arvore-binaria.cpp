#include <iostream>
using namespace std;

struct aluno
{
    int matricula;
    string nome;
    string curso;
};

typedef aluno Aluno;

// Definição do nó da árvore
struct no 
{
    aluno info;
    no* esq;
    no* dir;
};

// ArvBin é um ponteiro para NO
typedef no* ArvBin;

// Cria uma árvore vazia
ArvBin* cria_ArvBin() 
{
    ArvBin* raiz = new ArvBin;

    if (raiz != nullptr)
        *raiz = nullptr;

    return raiz;
}

// Libera todos os nós da árvore
void libera_no(no* no) 
{
    if (no == nullptr)
        return;

    libera_no(no->esq);
    libera_no(no->dir);

    delete no;
}

// Libera a estrutura da árvore
void libera_ArvBin(ArvBin* raiz) 
{
    if (raiz == nullptr)
        return;

    libera_no(*raiz);  // libera todos os nós
    delete raiz;       // libera o ponteiro da raiz
}

// Função auxiliar para inserir nós
bool insere_ArvBin(ArvBin* raiz, aluno aluno) 
{
    if (raiz == nullptr)
        return false;

    no* novo = new no;
    novo->info = aluno;
    novo->esq = nullptr;
    novo->dir = nullptr;

    if (*raiz == nullptr) {
        *raiz = novo;
        return true;
    }

    no* atual = *raiz;

    while (true) {
        if (aluno.nome < atual->info.nome) {
            if (atual->esq == nullptr) {
                atual->esq = novo;
                return true;
            }
            atual = atual->esq;
        }
        else {
            if (atual->dir == nullptr) {
                atual->dir = novo;
                return true;
            }
            atual = atual->dir;
        }
    }
}

// Percurso em ordem
void emOrdem(no* no) 
{
    if (no == nullptr)
        return;

    emOrdem(no->esq);
    cout << no->info.nome << " - " << no->info.matricula << " - " << no->info.curso << endl;
    emOrdem(no->dir);
}