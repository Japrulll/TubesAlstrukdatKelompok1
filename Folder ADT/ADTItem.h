#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define InitialSize 10
#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;
typedef int IdxType;
typedef struct {
    Barang *items;
    int count;
    int capacity;
} DinamicItemList;


void initDinamicItemList(DinamicItemList *list);
/*fungsi initDinamicItemList berfungsi untuk menginisialisasi
struktur data DinamicItemList dengan keterangan mengalokasikan
memori awal array items dengan kapasitas awal 2 dan count 0*/

void addItem(DinamicItemList *list, int price, char*name);
/*menambahkan barang ke dalam DinamicItemList
  I.S. capacity awal = 2, name adalah string yang valid dan price adalah integer positif
  F.S. item baru dengan nama dan harga ditambahkan ke list */

void freeDinamicItemList(DinamicItemList *list);
/*menghapus memori yang telah dialokasikan secara dinamis untuk DinamicItemList,
  supaya memorinya tidak terbuang sia-sia dan bisa digunakan lagi*/

DinamicItemList MakeDinamicItemList();

/**
 * Destruktor
 * I.S. DinamicItemList terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateDinamicItemList(DinamicItemList *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(DinamicItemList array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(DinamicItemList array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Barang Get(DinamicItemList array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMAX_LEN(DinamicItemList array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(DinamicItemList *array, Barang el, IdxType i);

/**
 * Fungsi untuk menghapus elemen di index ke-i DinamicItemList
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(DinamicItemList *array, IdxType i);



#endif
