#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "ADTFile.h"
#include "ADTLinkedList.h"
#include "ADTStack.h"

int main() {
    Antrian q;
    CreateQueue(&q);

    printf("---uji IsEmptyQ---\n");
    if (IsEmptyQ(q)) {
        printf("Queue kosong.\n"); //akan print queue kosong karena queueu belum dienqueue
    } else {
        printf("Queue tidak kosong.\n");
    }

    printf("\n");

    printf("---uji fungsi enqueue---\n");
    char *barangNama[] = {"Almond Tofu", "Abalone", "Mint Jelly", "Season Salad", "Nasgor"};
    int barangHarga[] = {100, 200, 300, 400, 500};

    for (int i = 0; i < 5; i++) {
        Barang item;
        item.price = barangHarga[i];
        copyString(barangNama[i], item.name);
        enqueue(&q, item);
        printf("Menambahkan ke queue: %s, Harga: %d\n", item.name, item.price);
    }

    printf("\n");
    printf("---uji fungsi LengthQ---\n");
    printf("Panjang queue saat ini: %d\n", LengthQ(q));

    printf("\n");

    printf("---Isi dari queue setelah dienqueue---\n");
    for (int i = q.idxHead; i < q.idxTail; i++) {
        printf("Nama: %s, Harga: %d\n", q.A[i].name, q.A[i].price);
    }

    printf("\n");

    printf("---uji fungsi dequeue---\n");
    for (int i = 0; i < 2; i++) {
        Barang removedItem;
        dequeue(&q, &removedItem);
        printf("Elemen yang dihapus: Nama: %s, Harga: %d\n", removedItem.name, removedItem.price);
    }

    printf("\n");

    printf("---Elemen dalam queue setelah dequeue---\n");
    for (int i = q.idxHead; i < 5; i++) {
        printf("Nama: %s, Harga: %d\n", q.A[i].name, q.A[i].price);
    }

    printf("\n");

    printf("---uji fungsi IsFull---\n");
    if(IsFull(q)){
        printf("Queue sudah penuh.\n");
    }else{
        printf("Queue belum penuh.\n"); //akan print Queue belum penuh karena hanya terdapat 3 item
    }

    printf("\n");

    printf("--- uji fungsi IsEmptyQ setelah dequeue---\n");
    if (IsEmptyQ(q)) {
        printf("Queue kosong.\n");
    } else {
        printf("Queue tidak kosong.\n"); //akan print Queue tidak kosong karena di dalam queue masih terdapat item
    }

    return 0;
}
