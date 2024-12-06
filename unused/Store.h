#include <stdio.h>
#include "ADTITem.h"
#include "mesinkata.h"
#include "queue.h"

int CharToInt();
// MENGUBAH INPUTAN HARGA DALAM BENTUK STRING MENJADI INTEGER

void display_barang(DinamicItemList list_barang);
// MENAMPILKAN SELURUH ISIAN DATA PADA STORE

void store_request(Antrian *antrian_barang, DinamicItemList list_barang);
//MEWUJUDKAN REQUEST DARI USER DENGAN MEMASUKKAN REQUEST BARANG KE ANTRIAN

void store_supply(Antrian *antrian_barang, DinamicItemList *list_barang);
//MENMBERIKAN INPUTAN HARGA DARI USER SEHINGGA DATA LENGKAP DENGAN HARGA LALU 
//MEMASUKKAN KE LIST OF BARANG

void store_remove(DinamicItemList *list_barang);
//MEGELUARKAN BARANG DARI LIST OF BARANG