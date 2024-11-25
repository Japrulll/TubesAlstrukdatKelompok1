#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

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


#endif