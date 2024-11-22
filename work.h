#ifndef WORK_H
#define WORK_H

#include "mesinkarakter.h"
#include "mesinkata.h"

#define MAX_JOBS 5
#define JOB_NAME_LEN 50
#define MAX_LEN 100

typedef struct {
    char jobName[JOB_NAME_LEN];
    int pekerjaan;
    int durasi; // dalam detik
} Job;

// // Deklarasi fungsi Mesin Karakter
// void startMesinKarakter(MesinKarakter *mk);
// char getNextChar(MesinKarakter *mk);
// int isEnd(MesinKarakter *mk);

// // Deklarasi fungsi Mesin Kata
// void startMesinKata(MesinKarakter *mk, MesinKata *mK);

// Operasi string
int compareStrings(const char *str1, const char *str2);
void copyString(char *dest, const char *src);

// Fungsi utama
void simulateWork(int durasi);
void work(int *balance);
int main();

#endif