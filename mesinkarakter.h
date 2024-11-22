#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include <stdio.h>

#define MAX_BUFFER 100 

typedef struct {
    char buffer[MAX_BUFFER]; 
    int currentIndex;        
    int totalChars;          
} MesinKarakter;

// Prosedur untuk memulai mesin karakter
void startMesinKarakter(MesinKarakter *mk);

// Fungsi untuk mendapatkan karakter berikutnya
char getNextChar(MesinKarakter *mk);

// Fungsi untuk mengecek apakah sudah mencapai akhir proses (EOP)
int isEnd(MesinKarakter *mk);

#endif