#include <iostream>
#include <string>
using namespace std;

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

// definição do nodo
struct elemento{
    aluno dados;
    elemento *prox;
};

typedef elemento* Lista;

Lista * cria_lista(){
    Lista * li = new Lista;
    if(li != nullptr)
        *li=nullptr;
    return li;
};;;;;;;;;;;;


int insere_lista_final(Lista * li, aluno al){
    if(li == nullptr){
        return 0;
    }
    // criação do nó / nodo (node)
    elemento* no = new elemento;
    if(no == nullptr){
        return 0;
    } 
    no -> dados = al;
    no -> prox = nullptr;

    // caso a lista esteja vazia
    if(*li == nullptr){
        *li = no;
    }else{
        elemento *aux = *li;

        // percorre até o último nó
       while(aux-> prox != nullptr){
        // quando entrar aqui o nodo não é o último
        aux = aux->prox;
       }
       aux -> prox = no;
    }

    return 1;
    
}


void imprime_lista(Lista * li){
    if (li == nullptr){
        return;
    }
    elemento * no = *li;

    //percorre e imprime cada nó
    while(no!=nullptr){
        cout << "Matrícula: "<< no->dados.matricula << endl; 
        // continuar, pls
        no = no->prox;

    }



}


int main(){
    // tipo abstrato de dados (TAD)
    aluno a[4] = {
        {2, "Andre", 9.0, 6.0, 7.6},
        {4, "Ricardo", 8.1, 7.1, 8.9},
        {1, "Bianca", 7.1, 10.0, 9.1},
        {3, "Ana", 8.6, 8.5, 9.2}
    } ;

    // head
    Lista * li = cria_lista();
    for (int i = 0; i < 5; i++)
    {
        insere_lista_final(li, a[i]);
    }

    imprime_lista(li);

    /*
    Implementar:
    Remoção de um nó da lista
    Inserção ordenada (matrícula)
    Liberação da lista
    */
    

    return 0;
}

