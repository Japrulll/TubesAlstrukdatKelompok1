#include <stdio.h>
#include "ADTSetMap.h"

int main() {
    Map M;
    CreateEmptyMap(&M);

    printf("---uji fungsi IsEmptyMap---\n");
    if (IsEmptyMap(M)) {
        printf("Map kosong.\n");//akan print map kosong karena map belum diinsert
    }else{
        printf("Map tidak kosong.\n");
    }

    printf("\n");

    printf("---uji fungsi InsertMap---\n");
    InsertMap(&M, "Almond", 10);
    InsertMap(&M, "Tahu", 20);
    InsertMap(&M, "Pistachio", 30);
    InsertMap(&M, "Komputer", 900);
    InsertMap(&M, "Tempe", 700);

    printf("Isi map setelah insert:\n");
    for (int i = 0; i < M.Count; i++) {
        printf("Nama: %s, Jumlah: %d\n", M.Elements[i].nama_item, M.Elements[i].qty);
    }

    printf("\n");

    printf("---uji fungsi IsMemberMap---\n");
    if (IsMemberMap(M, "Almond")) {
        printf("'Almond' ada di dalam map.\n"); //akan print ini karena Almond terdapat di dalam map
    } else {
        printf("'Almond' tidak ada di dalam map.\n");
    }

    if (IsMemberMap(M, "Kembang Tahu")) {
        printf("'Kembang Tahu' ada di dalam map.\n");
    } else {
        printf("'Kembang Tahu' tidak ada di dalam map.\n"); //akan print ini karena kembang tahu tidak terdapat di dalam map
    }

    printf("\n");
    printf("---uji fungsi Value---\n");
    printf("Jumlah dari 'Tempe': %d\n", Value(M, "Almond"));
    printf("Jumlah dari 'Tahu': %d\n", Value(M, "Tahu"));
    printf("Jumlah dari 'Kembang tahu' (tidak ada): %d\n", Value(M, "Kembang tahu"));

    printf("\n");
    printf("---uji fungsi DeleteMap---\n");
    DeleteMap(&M, "Tahu");

    printf("Isi map setelah delete:\n");
    for (int i = 0; i < M.Count; i++) {
        printf("Nama: %s, Jumlah: %d\n", M.Elements[i].nama_item, M.Elements[i].qty);
    }

    printf("\n");

    printf("---uji fungsi UpdateMap---\n");
    UpdateMap(&M, "Almond", 170); 
    UpdateMap(&M, "Pistachio", 50);

    printf("Isi map setelah update:\n");
    for (int i = 0; i < M.Count; i++) {
        printf("Nama: %s, Jumlah: %d\n", M.Elements[i].nama_item, M.Elements[i].qty);
    }

    printf("\n");

    printf("---uji fungsi IsFullMap---\n");
    if (IsFullMap(M)) {
        printf("Map penuh.\n");
    } else {
        printf("Map belum penuh.\n");//akan print ini karena isi dari map belum penuh
    }

    return 0;
}
