#include <iostream>
#include "boundingbox.hpp"
using namespace std;

BoundingBox *_bb_cria(int x1, int x2, int y1, int y2)
{
    BoundingBox *bb = new BoundingBox; // Aloca memória para um novo BoundingBox usando new

    if(bb == nullptr) { // Verifica se a alocação de memória foi bem-sucedida
        cout << "Erro ao alocar memória para BoundingBox" << endl;
        return nullptr;
    }

    // Atribui os valores aos campos da estrutura
    bb->x1 = x1;
    bb->x2 = x2;
    bb->y1 = y1;
    bb->y2 = y2;

    // Retorna o ponteiro para a estrutura criada
    return bb;
}

void _bb_acessa(BoundingBox* bb, int* x1, int* x2, int* y1, int* y2)
{
    if(bb == nullptr) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    // Atribui o valor do parâmetro se o ponteiro não for nulo
    if(x1) *x1 = bb->x1; 
    if(x2) *x2 = bb->x2; 
    if(y1) *y1 = bb->y1; 
    if(y2) *y2 = bb->y2; 
}

void _bb_atribui(BoundingBox* bb, int x1, int x2, int y1, int y2)
{
    if(bb == nullptr) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    // Atribui os novos valores aos campos da estrutura
    bb->x1 = x1;
    bb->x2 = x2;
    bb->y1 = y1;
    bb->y2 = y2;
}

void _bb_libera(BoundingBox* bb)
{
    if(bb != nullptr) { // Verifica se o ponteiro é nulo antes de liberar a memória
        delete bb; // Libera a memória alocada para a estrutura usando delete
        cout << "Memoria do BoundingBox liberada" << endl;
    }
}

int main()
{
    int a1, a2, b1, b2;

    // Chamada da função _bb_cria para criar um BoundingBox (CREATE)
    BoundingBox * bb = _bb_cria(10, 20, 7, 30);

    // Chamada da função _bb_acessa para acessar os valores do BoundingBox (READ)
    _bb_acessa(bb, &a1, &a2, &b1, &b2);

    cout << "BoundingBox criado: x1=" << a1 << ", x2=" << a2 << ", y1=" << b1 << ", y2=" << b2 << endl;

    // Chamada da função _bb_atribui para modificar os valores do BoundingBox (UPDATE)
    _bb_atribui(bb, 15, 25, 10, 35);
    _bb_acessa(bb, &a1, &a2, &b1, &b2); // Acessa novamente para verificar os novos valores

    cout << "BoundingBox atualizado: x1=" << a1 << ", x2=" << a2 << ", y1=" << b1 << ", y2=" << b2 << endl;

    // Chamada da função _bb_libera para liberar a memória do BoundingBox (DELETE)
    _bb_libera(bb);    

    return 0;
}