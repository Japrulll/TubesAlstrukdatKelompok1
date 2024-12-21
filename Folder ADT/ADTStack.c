#include "boolean.h"
#include "ADTStack.h"
#include <stdio.h>
#include <stdlib.h>
#include "ADTFile.h"
#include "ADTMap.h"
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
void CreateEmptyS(Stack *S){
    Top(*S) = NilS;
    for (int i = 0; i < sizeof(S->T)/sizeof(S->T[0]); i++){
        S->T[i].totalHarga = 0;
        copyString("",S->T[i].namaBarang);
    }
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsEmptyS(Stack S){
    return Top(S) == NilS;
}


/* Mengirim true jika tabel penampung nilai elemen stack penuh */
boolean IsFullS(Stack S){
    return Top(S) == MaxEl - 1;
}



/* ************ Menambahkan sebuah elemen ke Stack ************ */
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void Push(Stack * S, int total, char* nama){
    if (IsEmptyS(*S)){
        Top(*S) = 0;
    }
    else{
        Top(*S)++;
    }
    copyString(nama, InfoTop(*S).namaBarang);
    InfoTop(*S).totalHarga = total;
}




/* ************ Menghapus sebuah elemen Stack ************ */
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


void Pop(Stack * S, int* total, char* name){
    *total = InfoTop(*S).totalHarga;
    copyString(InfoTop(*S).namaBarang, name);
    Top(*S)--;
}

void copyStack(Stack *S, Stack *S2){
    for (int i = 0; i < sizeof(S2->T)/sizeof(S2->T[0]); i++){
        S->T[i] = S2->T[i];
    }
    S->TOP = S2->TOP;
}

void printStack(Stack *S, FILE* file){
    if (Top(*S) == NilS){
        return;
    }
    for (int i = 0; i <= S->TOP; i++){
        fprintf(file, "%d %s\n", S->T[i].totalHarga, S->T[i].namaBarang);
    }
}