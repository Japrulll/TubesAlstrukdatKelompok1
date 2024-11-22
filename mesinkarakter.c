#include <stdio.h>
#include "mesinkarakter.h"

void startMesinKarakter(MesinKarakter *mk) {
    mk->currentIndex = 0;
    mk->totalChars = 0;

    // Baca hingga karakter newline ('\n') atau EOF
    while ((mk->buffer[mk->totalChars] = getchar()) != '\n' && mk->buffer[mk->totalChars] != EOF) {
        mk->totalChars++;
    }
    mk->buffer[mk->totalChars] = '\0'; // Tambahkan null terminator
}

char getNextChar(MesinKarakter *mk) {
    if (mk->currentIndex < mk->totalChars) {
        return mk->buffer[mk->currentIndex++];
    }
    return EOF; // Indikator akhir proses
}

int isEnd(MesinKarakter *mk) {
    return mk->currentIndex >= mk->totalChars || mk->totalChars == 0;
}