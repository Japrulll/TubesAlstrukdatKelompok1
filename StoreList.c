#include <stdio.h>
#include "barangdin.h"
#include "mesinkatajaprul.h"

void display(BarangDin list_barang){
    if (!IsEmpty(list_barang)){
        for (int i = 0; i < Length(list_barang); i++){
            printf("%d. %s %d", i+1, list_barang.A[i].name, list_barang.A[i].price);
        }
    }
} 

void store_request(Antrian *antrian_barang, BarangDin list_barang) {
    printf("Nama barang yang diminta: ");
    STARTWORD();
    while (!EndWord) {
        ADVWORD();
    }

    if (isIn(CurrentWord, list_barang)) {
        printf("Barang %.*s sudah ada di store!\n", CurrentWord.Length, CurrentWord.TabWord);
    } else {
        ElType new_item;
        for (int i = 0; i < CurrentWord.Length; i++) {
            new_item.name[i] = CurrentWord.TabWord[i];
        }
        new_item.name[CurrentWord.Length] = '\0'; 
        enqueue(antrian_barang, new_item);
        printf("Barang %.*s telah ditambahkan ke antrean.\n", CurrentWord.Length, CurrentWord.TabWord);
    }
}

void store_supply(Antrian *antrian_barang, BarangDin list_barang) {
    while (!isEmpty(*antrian_barang)) {
        ElType val;
        dequeue(antrian_barang, &val);

        printf("Apakah kamu ingin menambahkan barang %s (Tunda/Terima/Tolak)? ", val.name);
        STARTWORD();
        while (!EndWord) {
            ADVWORD();
        }

        if (isWordEqual(CurrentWord, "Tunda")) {
            enqueue(antrian_barang, val);
            printf("%s dikembalikan ke antrian.\n", val.name);
        } else if (isWordEqual(CurrentWord, "Terima")) {
            printf("Harga Barang: ");
            scanf("%d", &val.price);
            InsertAt(&list_barang, val, Length(list_barang));
        } else if (isWordEqual(CurrentWord, "Tolak")) {
            printf("Barang %s Dihapus dari Antrian!\n", val.name);
        } else {
            printf("Kembali ke menu.\n");
            break;
        }
    }

    if (isEmpty(*antrian_barang)) {
        printf("Antrian Kosong!\n");
    }
}

void store_remove(BarangDin list_barang) {
    int i = 0;
    STARTWORD();
    while (!EndWord) {
        ADVWORD();
    }

    while (i < Length(list_barang)) {
        if (isWordEqual(CurrentWord, list_barang.A[i].name)) {
            break;
        }
        i++;
    }

    if (i < Length(list_barang)) {
        DeleteAt(&list_barang, i);
        printf("Barang %.*s berhasil dihapus.\n", CurrentWord.Length, CurrentWord.TabWord);
    } else {
        printf("Toko tidak menjual %.*s\n", CurrentWord.Length, CurrentWord.TabWord);
    }
}
