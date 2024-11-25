#include <stdio.h>
#include <stdlib.h>
#include "ADTItem.h"
#include "ADTFile.h"

#define A(dinamic) (dinamic).items
#define Cap(dinamic) (dinamic).capacity
#define Count(dinamic) (dinamic).count
#define InitialSize 2

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

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk BarangDin kosong dengan ukuran InitialSize
 */
DinamicItemList MakeDinamicItemList() {
    DinamicItemList dinamic;
    Cap(dinamic) = InitialSize;
    A(dinamic) = (Barang*) malloc(InitialSize * sizeof(Barang));
    if (A(dinamic) == NULL) {
        // Cek apakah malloc berhasil
        printf("Memory allocation failed!\n");
        exit(1);  // Keluar jika alokasi gagal
    }
    Count(dinamic) = 0;
    return dinamic;
}

/**
 * Destruktor
 * I.S. DinamicItemList terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateDinamicItemList(DinamicItemList *array) {
    free(A(*array));
    Cap(*array) = 0;
    Count(*array) = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(DinamicItemList array) {
    return (Count(array) == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(DinamicItemList array) {
    return Count(array);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Barang Get(DinamicItemList array, IdxType i) {
    if (i < 0 || i >= Count(array)) {
        // Cek jika indeks tidak valid
        printf("Index Kelebihan!\n");
        exit(1);
    }
    return A(array)[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMAX_LEN(DinamicItemList array) {
    return Cap(array);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(DinamicItemList *array, Barang el, IdxType i) {
    if (i < 0 || i > Count(*array)) {
        // Cek jika indeks tidak valid
        printf("Index Kelebihan!\n");
        exit(1);
    }

    if (Count(*array) == Cap(*array)) {
        A(*array) = realloc(A(*array), (Cap(*array) * 2) * sizeof(Barang));
        if (A(*array) == NULL) {
            // Cek apakah realloc berhasil
            printf("Realloc Gagal!\n");
            exit(1);
        }
        Cap(*array) = Cap(*array) * 2;
    }

    // Geser elemen ke kanan untuk memberi ruang
    for (int j = Count(*array); j > i; j--) {
        A(*array)[j] = A(*array)[j - 1];
    }

    // Masukkan elemen baru di index ke-i
    A(*array)[i] = el;
    Count(*array) = Count(*array) + 1;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i BarangDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(DinamicItemList *array, IdxType i) {
    if (i < 0 || i >= Count(*array)) {
        // Cek jika indeks tidak valid
        printf("Index Kelebihan!\n");
        exit(1);
    }

    // Geser elemen setelahnya untuk menghapus elemen di index ke-i
    for (int j = i; j < Count(*array) - 1; j++) {
        A(*array)[j] = A(*array)[j + 1];
    }
    Count(*array) = Count(*array) - 1;
}

