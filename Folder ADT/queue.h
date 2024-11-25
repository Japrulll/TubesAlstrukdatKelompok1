#ifndef QUEUEJAPRUL_H
#define QUEUEJAPRUL_H

#include "ADTItem.h"
#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef int IdxType;

typedef struct {
    Barang *A;
    int idxHead;
    int idxTail;
    int Capacity;
} Antrian;

void CreateQueue(Antrian *q);
boolean IsEmptyQ(Antrian q);
boolean IsFull(Antrian q);
int LengthQ(Antrian q);
void enqueue(Antrian *q, Barang val);
void dequeue(Antrian *q, Barang *val);

#endif
