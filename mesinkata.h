#ifndef MESINKATA_H
#define MESINKATA_H

#include "mesinkarakter.h" 

#define MAX_WORD_LENGTH 100 

typedef struct {
    char currentWord[MAX_WORD_LENGTH]; 
    int currentLength;                
} MesinKata;

// Fungsi untuk memulai mesin kata
void startMesinKata(MesinKarakter *mk, MesinKata *mK);
/* Memulai pembacaan kata dari mesin karakter */
/* I.S. Mesin karakter telah diinisialisasi dan siap digunakan */
/* F.S. Sebuah kata telah dibaca dari mesin karakter dan disimpan dalam mesin kata (mK). Kata berhenti di akhir baris atau setelah spasi, tergantung pada karakter pembatas */

#endif