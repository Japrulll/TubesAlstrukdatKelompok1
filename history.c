#include "history.h"
#include <stdio.h>
#include "./Folder ADT/ADTStack.h"

void history(Stack *out, int N){
    if (N > out->TOP){
        N = out->TOP;
    }
    if (Top(*out) == NilS){
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");

    Stack tempStack;
    CreateEmptyS(&tempStack);

    for (int i = 0; i <= N; i++){
        int totalHarga;
        char namaBarang[100];
        Pop(out, &totalHarga, namaBarang);
        printf("%d. %d %s\n", i+1, totalHarga, namaBarang);  
        Push(&tempStack, totalHarga, namaBarang);
    }
    while (!IsEmptyS(tempStack)){
        int totalHarga; 
        char namaBarang[100];
        Pop(&tempStack, &totalHarga, namaBarang);
        Push(out, totalHarga, namaBarang);
    }
    return;
}
