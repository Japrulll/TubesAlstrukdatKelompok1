#ifndef __BARANG_DINAMIK__
#define __BARANG_DINAMIK__

// Boolean
#include "boolean.h"

#define InitialSize 10
#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;

typedef int IdxType;


typedef struct {
    Barang *A;
    int Capacity;
    int Count;
} BarangDin;

// Array Dinamis

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk BarangDin kosong dengan ukuran InitialSize
 */
BarangDin MakeBarangDin();

/**
 * Destruktor
 * I.S. BarangDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateBarangDin(BarangDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(BarangDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(BarangDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Barang Get(BarangDin array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMAX_LEN(BarangDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(BarangDin *array, Barang el, IdxType i);

/**
 * Fungsi untuk menghapus elemen di index ke-i BarangDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(BarangDin *array, IdxType i);

#endif
