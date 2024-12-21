#include <stdio.h>
#include <stdlib.h>
#include "ADTUser.h"
#include "ADTFile.h"
#include "ADTStack.h"
#include "ADTLinkedList.h"
#include "ADTMap.h"

//Fungsi khusus debugging, untuk mencetak isi dari StaticUserList
void printUserList(StaticUserList *list) {
    printf("Isi StaticUserList:\n");
    for (int i = 0; i < list->count; i++) {
        printf("User %d:\n", i+1);
        printf("Nama: %s\n", list->users[i].name);
        printf("Password: %s\n", list->users[i].password);
        printf("Jumlah_Uang: %d\n", list->users[i].money);

        printf("Riwayat Pembelian:\n");
        for (int j = 0; j <= list->users[i].riwayat_pembelian.TOP; j++) {
            printf(" - %s: %d\n", list->users[i].riwayat_pembelian.T[j].namaBarang, list->users[i].riwayat_pembelian.T[j].totalHarga);
        }

        printf("Wishlist:\n");
        address P = list->users[i].wishlist.First;
        while (P != NULL) {
            printf(" - %s\n", Info(P));
            P = Next(P);
        }
        printf("\n");
    }
}

int main() {
    StaticUserList userList;
    Stack riwayat_pembelian;
    List wishlist;

    printf("---uji initStaticUserList---\n");
    initStaticUserList(&userList);
    printf("StaticUserList berhasil diinisialisasi. Jumlah user: %d\n", userList.count);//akan print 0 karena inisialisasi userlist terlebih dahulu sblm add user, yaitu 0

    printf("\n");
    printf("---uji addUser ---\n");
    CreateEmptyS(&riwayat_pembelian);
    Push(&riwayat_pembelian, 190, "Mora Meat");
    Push(&riwayat_pembelian, 300, "Mint Salad");

    CreateEmptyLL(&wishlist);
    InsVLast(&wishlist, "Primogems");
    InsVLast(&wishlist, "WayPoint");

    addUser(&userList, 1000, "KaedeharaKzh", "password123", &riwayat_pembelian, &wishlist);

    Stack riwayat_pembelian2;
    List wishlist2;

    CreateEmptyS(&riwayat_pembelian2);
    Push(&riwayat_pembelian2, 500, "Almond Tofu");
    Push(&riwayat_pembelian2, 230, "Rice Buns");

    CreateEmptyLL(&wishlist2);
    InsVLast(&wishlist2, "Geoculus");
    InsVLast(&wishlist2, "Anemoculus");

    addUser(&userList, 2000, "X1ao", "password456", &riwayat_pembelian2, &wishlist2);
    printUserList(&userList);

    return 0;
}