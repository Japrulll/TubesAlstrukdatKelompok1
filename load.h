#ifndef FILE_NAME_H
#define FILE_NAME_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct {
    User users[MAX_LEN];
    int count;
} StaticUserList;

typedef struct {
    Barang *items;
    int count;
    int capacity;
} DinamicItemList;

void copyString(char* src, char* dest);
/*menyalin string dari source ke destination sebagai pengganti strcpy
  I.S. src merupakan source dan dest merupakan destination dari source
  F.S. src telah disalin ke dest*/

void initStaticUserList(StaticUserList *list);
/*fungsi iniStaticUserList berfungsi untuk menginisialisasi
struktur data StaticUserList, dibuat daftar kosong*/


void initDinamicItemList(DinamicItemList *list);
/*fungsi initDinamicItemList berfungsi untuk menginisialisasi
struktur data DinamicItemList dengan keterangan mengalokasikan
memori awal array items dengan kapasitas awal 2 dan count 0*/

void addUser(StaticUserList *list, int money, char*name, char*password);
/*menambahkan user baru ke dalam StaticUserList
  I.S. jumlah user kurang dari MAX_LEN, name dan password adalah string yang valid,
       money merupakan integer positif
  F.S. user baru dengan nama, password, dan money ditambahkan ke list*/

void addItem(DinamicItemList *list, int price, char*name);
/*menambahkan barang ke dalam DinamicItemList
  I.S. capacity awal = 2, name adalah string yang valid dan price adalah integer positif
  F.S. item baru dengan nama dan harga ditambahkan ke list */

void freeDinamicItemList(DinamicItemList *list);
/*menghapus memori yang telah dialokasikan secara dinamis untuk DinamicItemList,
  supaya memorinya tidak terbuang sia-sia dan bisa digunakan lagi*/
void constructfilepath(char*filepath, char*basepath, char*filename);
//fungsi constructfilepath berfungsi untuk menggabungkan dua string dan membentuk path file*/

void display(DinamicItemList *itemlist, StaticUserList *userlist);
/*fungsi untuk menampilkan isi daftar barang dan user ke layar*/

void readline(FILE *file, char *buffer);
/*fungsi readline berfungsi untuk membaca file ke buffer string*/

void loadFile(char*filename);
/*membaca file dengan nama file yang diberikan parameter filename. 
  I.S. File dengan nama yang diberikan di parameter filename mungkin tersedia di sistem, tetapi belum dibaca
  F.S. Apabila berhasil membaca file dengan nama file yang diberikan parameter filename, 
       maka akan diberitahu bahwa save file berhasil terbaca.
       Apabila tidak berhasil, maka akan diberitahu bahwa save file tidak berhasil terbaca.*/

#endif