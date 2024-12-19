#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADTStack.h"
#include "ADTFile.h"

//Fungsi ini hanya untuk debug, untuk mencetak isi stack
void printStackDebug(Stack *S) {
    if (IsEmptyS(*S)) {
        printf("Stack kosong.\n");
        return;
    }
    for (int i = 0; i <= S->TOP; i++) {
        printf("Item %d: Nama = %s, Total Harga = %d\n", i, S->T[i].namaBarang, S->T[i].totalHarga);
    }
    printf("\n");
}

int main() {
    Stack S1, S2;
    int total;
    char item[50];

    CreateEmptyS(&S1);
    
    printf("---uji IsEmpty---\n");
    printStackDebug(&S1);
    if (IsEmptyS(S1)){
        printf("IsEmpty: True, stack kosong\n"); //akan print IsEmpty: True, karena stack masih kosong
    }
    else{
        printf("IsEmpty: False, stack tidak kosong\n");
    }
    
    printf("\n");

    printf("---uji fungsi Push dan IsEmpty---\n");
    Push(&S1, 500, "Almond Tofu");
    Push(&S1, 700, "Anemoculus");
    Push(&S1, 300, "Mint Salad");
    Push(&S1, 450, "Skyward Blade");
    Push(&S1, 800, "Favonius Sword");
    printf("Setelah melakukan push pada stack:\n");
    printStackDebug(&S1); //Almond Tofu, Anemoculus, Mint Salad, Skyward Blade, Favonius Sword
    if (IsEmptyS(S1)){
        printf("IsEmpty: True, stack kosong\n");
    }
    else{
        printf("IsEmpty: False, stack tidak kosong\n");//akan print IsEmpty: False, karena stack tidak kosong
    }

    printf("\n");

    printf("---uji fungsi IsFullS---\n");
    if (IsFullS(S1)){
        printf("IsFullS: True, stack sudah penuh\n");
    }
    else{
        printf("IsFullS: False, stack tidak penuh\n"); //akan print IsFullS: False karena stack tidak penuh, MaxEl adalah 100
    }

    printf("\n");

    printf("---uji fungsi Pop---\n");
    Pop(&S1, &total, item); //akan menghapus item paling atas, yaitu Favonius Sword
    printf("Item yang dihapus: %s dengan total harga: %d\n", item, total);
    printf("Stack setelah item dihapus:\n");
    printStackDebug(&S1); 


    printf("---uji fungsi copyStack---\n");
    CreateEmptyS(&S2);
    copyStack(&S2, &S1);
    printf("Stack S2 setelah dicopy dari Stack S1:\n");
    printStackDebug(&S2); //akan print isi dari Stack 1


    printf("---uji printStack ke file---\n");
    FILE *file = fopen("stackUjiCoba.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return 1;
    }
    printStack(&S1, file);
    fclose(file);
    printf("Isi stack telah disimpan ke 'stackUjiCoba.txt'.\n");

    return 0;
}


