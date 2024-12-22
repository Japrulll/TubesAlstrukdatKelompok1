#include "history.h"
#include <stdio.h>
#include "./Folder ADT/ADTStack.h"

void dis_history(Stack *S, int N){
    if (n>S->TOP){
        n = S->TOP;
    }
    if (Top(*S) == NilS){
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");
    
    for (int i = 0; i <= n; i++){
        if (!IsEmptyS(*S)){
            Pop(&tempStack, &totalHarga, namaBarang);
            printf("%d %s\n", S->T[i].totalHarga, S->T[i].namaBarang);
        }
        return;
    }
}
