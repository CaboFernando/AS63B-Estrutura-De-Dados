#include <iostream>
#include "arvore-binaria.cpp"
using namespace std;

int main()
{
    // Cria a árvore
    ArvBin* raiz = cria_ArvBin();

    // Insere alguns valores
    insere_ArvBin(raiz, Aluno{101, "John Smith", "Engenharia de Software"});
    insere_ArvBin(raiz, Aluno{102, "Alice Johnson", "Sistemas de Informação"});
    insere_ArvBin(raiz, Aluno{103, "Michael Brown", "Ciência da Computação"});
    insere_ArvBin(raiz, Aluno{104, "Emily", "Engenharia de Software"});

    cout << "Percurso em ordem: ";
    emOrdem(*raiz);
    cout << endl;

    // Libera a árvore
    libera_ArvBin(raiz);

    return 0;
}