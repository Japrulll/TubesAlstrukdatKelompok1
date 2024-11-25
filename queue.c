#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void CreateQueue(Antrian *q) {
    q->A = (Barang *) malloc(CAPACITY * sizeof(Barang));
    q->idxHead = 0;
    q->idxTail = 0;
    q->Capacity = CAPACITY;
}

boolean IsEmptyQ(Antrian q) {
    return q.idxHead == q.idxTail;
}

boolean IsFull(Antrian q) {
    return q.idxTail == q.Capacity;
}

int LengthQ(Antrian q) {
    return q.idxTail - q.idxHead;
}

void enqueue(Antrian *q, Barang val) {
    if (IsFull(*q)) {
        printf("Antrian penuh!\n");
        return;
    }
    q->A[q->idxTail] = val;
    q->idxTail++;
}

void dequeue(Antrian *q, Barang *val) {
    if (IsEmptyQ(*q)) {
        printf("Antrian kosong\n");
        return;
    }
    *val = q->A[q->idxHead];
    q->idxHead++;
}
