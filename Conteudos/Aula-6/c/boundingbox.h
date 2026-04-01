#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

struct BoundingBox {
    int x1, x2, y1, y2;
};

typedef struct BoundingBox BoundingBox;

BoundingBox *_bb_cria(int x1, int x2, int y1, int y2);

void _bb_acessa(BoundingBox* bb, int* x1, int* x2, int* y1, int* y2);

void _bb_atribui(BoundingBox* bb, int x1, int x2, int y1, int y2);

void _bb_libera(BoundingBox* bb);

#endif