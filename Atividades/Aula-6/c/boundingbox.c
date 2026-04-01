#include <stdio.h>
#include <stdlib.h>
#include "boundingbox.h"

BoundingBox *_bb_cria(int x1, int x2, int y1, int y2)
{
    BoundingBox *bb = (BoundingBox *)malloc(sizeof(BoundingBox));    

    if(bb == NULL) {// Sempre verifica se a alocação de memória foi bem-sucedida
        printf("Erro ao alocar memória para BoundingBox\n");
        return NULL;
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
    if(bb == NULL) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    // Atribui o valor do parâmetro se o ponteiro não for nulo
    if(x1) *x1 = bb->x1; 
    if(x2) *x2 = bb->x2; 
    if(y1) *y1 = bb->y1; 
    if(y2) *y2 = bb->y2; 
}

void _bb_atribui(BoundingBox* bb, int x1, int x2, int y1, int y2)
{
    if(bb == NULL) return; // Verifica se o ponteiro é nulo antes de acessar os campos

    // Atribui os novos valores aos campos da estrutura
    bb->x1 = x1;
    bb->x2 = x2;
    bb->y1 = y1;
    bb->y2 = y2;
}

void _bb_libera(BoundingBox* bb)
{
    if(bb != NULL) { // Verifica se o ponteiro é nulo antes de liberar a memória
        free(bb); // Libera a memória alocada para a estrutura
        printf("Memoria do BoundingBox liberada\n");
    }
}


int main()
{
    int a1, a2, b1, b2;

    // Chamada da função _bb_cria para criar um BoundingBox (CREATE)
    BoundingBox * bb = _bb_cria(10, 20, 7, 30);

    printf("BoundingBox criado: x1=%d, x2=%d, y1=%d, y2=%d\n\n", bb->x1, bb->x2, bb->y1, bb->y2);

    // Chamada da função _bb_acessa para obter os valores dos campos da estrutura (READE)
    _bb_acessa(bb, &a1, &a2, &b1, &b2);

    printf("BoundingBox lido: (%d, %d) ate (%d, %d)\n", a1, b1, a2, b2);

    // Chamada da função _bb_atribui para modificar os valores dos campos da estrutura (UPDATE)
    _bb_atribui(bb, 15, 25, 10, 35);
    _bb_acessa(bb, &a1, &a2, &b1, &b2);

    printf("BoundingBox alterado: (%d, %d) ate (%d, %d)\n", a1, b1, a2, b2); // Imprime os valores alterados
    printf("BoundingBox alterado (enderecos): (%p, %p) ate (%p, %p)\n", (void*)&a1, (void*)&b1, (void*)&a2, (void*)&b2); // Imprime os endereços de memória dos parâmetros para verificar se eles foram modificados

    // Chamada da função _bb_libera para liberar a memória alocada para o BoundingBox (DELETE)
    _bb_libera(bb);

    return 0;
}