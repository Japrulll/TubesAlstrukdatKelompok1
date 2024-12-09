#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "work.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/mesinkata.h"

// Fungsi untuk membandingkan 2 string
// int compareStrings(const char *str1, const char *str2) {
//     while (*str1 && *str2) {
//         if (*str1 != *str2) {
//             return 0; 
//         }
//         str1++;
//         str2++;
//     }
//     return (*str1 == *str2); 
// }

// Fungsi untuk menyalin string
// void copyString(char *dest, const char *src) {
//     while (*src) {
//         *dest++ = *src++;
//     }
//     *dest = '\0';
// }

// Fungsi untuk mensimulasikan waktu kerja
void simulateWork(int durasi) {
    // for (int i = 0; i < durasi; i++) {
    //     for (volatile int j = 0; j < 100000000; j++);
    // }
    clock_t start = clock();
    while ((double)(clock() - start) / CLOCKS_PER_SEC < durasi) {
    }
}

// Fungsi work
void work(int *balance) {
    Job jobs[MAX_JOBS] = {
        {"Evil Lab Assistant", 100, 14},
        {"OWCA Hiring Manager", 4200, 21},
        {"Cikapundunginator Caretaker", 7000, 30},
        {"Mewing Specialist", 10000, 22},
        {"Inator Connoisseur", 997, 15}
    };

    printf(">> WORK\n\nDaftar pekerjaan:\n");
    for (int i = 0; i < MAX_JOBS; i++) {
        printf("%s (pendapatan=%d, durasi=%ds)\n", jobs[i].jobName, jobs[i].pekerjaan, jobs[i].durasi);
    }

    Word chosenJob;
    printf("\nMasukkan pekerjaan yang dipilih: ");
    
    STARTWORD();
    chosenJob = CurrentWord;
    
    int jobFound = 0;
    for (int i = 0; i < MAX_JOBS; i++) {
        if (compareStrings(chosenJob.TabWord, jobs[i].jobName)) {
            jobFound = 1;
            printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n\n", jobs[i].jobName);
            simulateWork(jobs[i].durasi); 
            *balance += jobs[i].pekerjaan;
            printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", jobs[i].pekerjaan);
            break;
        }
    }

    if (!jobFound) {
        printf("Pekerjaan tidak ditemukan. Silakan coba lagi.\n\n");
    }
}

// int main() {
//     int balance = 0;

//     work(&balance);
//     printf("Saldo saat ini: %d rupiah\n", balance);

//     return 0;
// }
