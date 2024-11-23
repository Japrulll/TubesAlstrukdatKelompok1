#ifndef __BARANG_DINAMIK__
#define __BARANG_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0
#define InitialSize 10
#define MAX_LEN 100
#define IDX_UNDEF -1

typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;

typedef int IdxType;
typedef Barang ElType;

typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} BarangDin;

typedef struct {
	ElType *buffer; 
	int idxHead;
	int idxTail;
} Antrian;

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
ElType Get(BarangDin array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMAX_LEN(BarangDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(BarangDin *array, ElType el, IdxType i);

/**
 * Fungsi untuk menghapus elemen di index ke-i BarangDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(BarangDin *array, IdxType i);

// QUEUE
void CreateQueue(Antrian *q);

boolean isEmpty(Antrian q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Antrian q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Antrian q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Antrian *q, ElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Antrian *q, ElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Antrian q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */


#endif