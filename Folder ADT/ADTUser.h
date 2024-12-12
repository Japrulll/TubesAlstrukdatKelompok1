#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include "ADTLinkedList.h"
#include "ADTStack.h"
#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Map keranjang;
    Stack riwayat_pembelian;
    List wishlist;
} User;

typedef struct {
    User users[MAX_LEN];
    int count;
} StaticUserList;


void initStaticUserList(StaticUserList *list);
/*fungsi iniStaticUserList berfungsi untuk menginisialisasi
struktur data StaticUserList, dibuat daftar kosong*/

void addUser(StaticUserList *list, int money, char*name, char*password, Stack* riwayat_pembelian, List*wishlist);
/*menambahkan user baru ke dalam StaticUserList
  I.S. jumlah user kurang dari MAX_LEN, name dan password adalah string yang valid,
       money merupakan integer positif
  F.S. user baru dengan nama, password, dan money ditambahkan ke list*/


#endif