/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"

#define NilS -1
#define MaxEl 100
#define MAX_LEN 100
/* NilS adalah stack dengan elemen kosong . */

typedef int addressS;   /* indeks tabel */
typedef struct{
    int totalHarga;
    char namaBarang[MAX_LEN];
} infotypeS;
/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotypeS T[MaxEl]; /* tabel penyimpan elemen */
  int TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = NilS */
/* Elemen yang dipakai menyimpan NilSai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyS(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP berNilSai NilS */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullS(Stack S);
/* Mengirim true jika tabel penampung NilSai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, int total, char* nama);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, int* total, char* nama);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilSai elemen TOP yang lama, TOP berkurang 1 */

void copyStack(Stack *S, Stack *S2);

void printStack(Stack *S);


#endif