#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include <stdio.h>

#define MAX_BUFFER 100 

typedef struct {
    char buffer[MAX_BUFFER]; 
    int currentIndex;        
    int totalChars;          
} MesinKarakter;

void startMesinKarakter(MesinKarakter *mk, FILE *inputFile);
/* Memulai mesin karakter untuk membaca input hingga akhir baris atau EOF */
/* I.S. Mesin karakter belum aktif atau sedang tidak membaca input */
/* F.S. Mesin karakter membaca input dari pengguna, menyimpan karakter ke buffer, menambahkan null terminator ('\0'), dan mempersiapkan untuk pembacaan karakter per karakter */

char getNextChar(MesinKarakter *mk);
/* Mengambil karakter berikutnya dari buffer mesin karakter */
/* I.S. Mesin karakter aktif dan tidak berada di akhir proses */
/* F.S. Karakter berikutnya di buffer dikembalikan, dan indeks pembacaan (currentIndex) maju satu.Mengembalikan EOF jika sudah mencapai akhir proses */

int isEnd(MesinKarakter *mk);
/* Mengecek apakah pembacaan mesin karakter telah mencapai akhir proses */
/* I.S. Mesin karakter aktif */
/* F.S. Mengembalikan nilai true (1) jika seluruh karakter dalam buffer telah dibaca, atau buffer kosong. Mengembalikan false (0) jika masih ada karakter yang dapat dibaca */

#endif
