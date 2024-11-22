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

#endif