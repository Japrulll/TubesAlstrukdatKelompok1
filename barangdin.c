#include <stdio.h>
#include <stdlib.h>
#include "barangdin.h"

#define A(dinamic) (dinamic).A
#define Cap(dinamic) (dinamic).Capacity
#define Neff(dinamic) (dinamic).Neff

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
BarangDin MakeBarangDin(){
    BarangDin dinamic;
    Cap(dinamic) = InitialSize;
    A(dinamic) = (ElType*) malloc (InitialSize*sizeof(ElType));
    Neff(dinamic) = 0;
    return dinamic;

}
/**
 * Destruktor
 * I.S. BarangDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateBarangDin(BarangDin *array){
    free(A(*array));
    Cap(*array) = 0;
    Neff(*array) = 0;
}    
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(BarangDin array){
    return (Neff(array) == 0);

}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(BarangDin array){
    return Neff(array);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(BarangDin array, IdxType i){
    return A(array)[i];

}
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetMAX_LEN(BarangDin array){
    return Cap(array);

}
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(BarangDin *array, ElType el, IdxType i){
    if (Neff(*array) == Cap(*array)){
        A(*array) = realloc (A(*array),(Cap(*array)*2)*sizeof(ElType));
        Cap(*array) = Cap(*array)*2;
    }
    for (int j = Neff(*array); j > i; j--){
        A(*array)[j] = A(*array)[j-1];
    }
    A(*array)[i] = el;
    Neff(*array) = Neff(*array) + 1;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i BarangDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(BarangDin *array, IdxType i){
    ElType save = A(*array)[i];
    for (int j = i; j < Neff(*array)-1 ; j++ ){
        A(*array)[j] = A(*array)[j+1];
    }
    Neff(*array) = Neff(*array) - 1;
}
void CreateQueue(Antrian *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Antrian q){;
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}
boolean isFull(Antrian q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return ((q.idxTail+1) % MAX_LEN == q.idxHead); 
}
int length(Antrian q){
/* Mengirimkan banyaknya elemen Antrian. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)) return 0;
    if (q.idxHead <= q.idxTail){
        return q.idxTail - q.idxHead + 1;
    }
    else return MAX_LEN - (q.idxHead - q.idxTail) + 1;
}
/* *** Primitif Add/Delete *** */
void enqueue(Antrian *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q)){
        (*q).idxTail = 0;
        (*q).idxHead = 0;
        (*q).buffer[(*q).idxTail] = val;
    }
    else{
        (*q).idxTail = ((*q).idxTail + 1) % MAX_LEN;
        (*q).buffer[(*q).idxTail] = val;
    }
}

void dequeue(Antrian *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = (*q).buffer[(*q).idxHead];
    if ((*q).idxHead == (*q).idxTail){
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    }
    else {
        (*q).idxHead = ((*q).idxHead + 1) % MAX_LEN;
    }
}
/* *** Display Queue *** */
void displayQueue(Antrian q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    printf("[");
    if (!isEmpty(q)){
        int i = q.idxHead;
        while (i != q.idxTail){
            printf("%d,",q.buffer[i]); 
            i = (i + 1) % MAX_LEN;
        }
        printf("%d",q.buffer[q.idxTail]);
    }   
    printf("]\n");
}


// int main(){
//     BarangDin arr = MakeBarangDin();
//     InsertAt(&arr,1,0);
//     printf("%d\n", Get(arr,0));
//     printf("%d\n", Length(arr));
    
// }