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
    insere_ArvBin(raiz, Aluno{105, "Angela", "Analise e Desenvolvimento de Sistemas"});
    insere_ArvBin(raiz, Aluno{106, "Ana", "Analise e Desenvolvimento de Sistemas"});

    // Percorre a árvore em ordem
    cout << "Percurso em ordem: " << endl;
    emOrdem(*raiz);
    cout << endl;

    // Tenta inserir aluno duplicado
    insere_ArvBin(raiz, Aluno{104, "Emily", "Engenharia de Software"});

    // Busca aluno por nome
    string alunoBusca = "John Smith";
    buscaAlunoPorNome(*raiz, alunoBusca);

    // Exibe as informações da árvore
    infoArvore(raiz);

    // Libera a árvore
    libera_ArvBin(raiz);

    return 0;
}

// validar o uso dessas libs
// allegro
// opecv