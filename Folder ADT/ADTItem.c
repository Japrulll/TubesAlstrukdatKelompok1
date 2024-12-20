#include <stdio.h>
#include <stdlib.h>
#include "ADTItem.h"
#include "ADTFile.h"
#include "boolean.h"

void initDinamicItemList(DinamicItemList *list){
    list->capacity = 2;
    list->count = 0;
    list->items = (Barang*)malloc(list->capacity * sizeof(Barang));
}


void addItem(DinamicItemList *list, int price, char*name){
    if(list->count == list->capacity){
        list->capacity *= 2;
        list->items = (Barang*)realloc(list->items, list->capacity * sizeof(Barang));
    }
    list->items[list->count].price = price;
    copyString(name, list->items[list->count].name);
    list->count++;
}


void freeDinamicItemList(DinamicItemList *list){
    free(list->items);
    list->items = NULL;
    list->capacity = 0;
    list->count = 0;
}

int Length(DinamicItemList list){
    return list.count;
}

boolean IsEmpty(DinamicItemList list){
    return list.count == 0;
}

boolean isIn(DinamicItemList list,char *what){
    for (int i = 0; i<list.count;i++){
        if(compareStrings(list.items[i].name,what)){
            return true;
        }
    }
    return false;
}

Barang getBarang(DinamicItemList list,char *name){
    for (int i = 0; i<list.count;i++){
        if(compareStrings(list.items[i].name,name)){
            return list.items[i];
        }
    }
    // need null return
}

void InsertAt(DinamicItemList *array, Barang el, int i) {
    if (i < 0 || i > Count(*array)) {
        // Cek jika indeks tidak valid
        printf("Index Kelebihan!\n");
        exit(1);
    }

    if (Count(*array) == Capacity(*array)) {
        Items(*array) = realloc(Items(*array), (Capacity(*array) * 2) * sizeof(Barang));
        if (Items(*array) == NULL) {
            // Cek apakah realloc berhasil
            printf("Realloc Gagal!\n");
            exit(1);
        }
        Capacity(*array) = Capacity(*array) * 2;
    }

    // Geser elemen ke kanan untuk memberi ruang
    for (int j = Count(*array); j > i; j--) {
        Items(*array)[j] = Items(*array)[j - 1];
    }

    // Masukkan elemen baru di index ke-i
    Items(*array)[i] = el;
    Count(*array) = Count(*array) + 1;
}

void DeleteAt(DinamicItemList *array, int i) {
    if (i < 0 || i >= Count(*array)) {
        // Cek jika indeks tidak valid
        printf("Index Kelebihan!\n");
        exit(1);
    }

    // Geser elemen setelahnya untuk menghapus elemen di index ke-i
    for (int j = i; j < Count(*array) - 1; j++) {
        Items(*array)[j] = Items(*array)[j + 1];
    }
    Count(*array) = Count(*array) - 1;
}