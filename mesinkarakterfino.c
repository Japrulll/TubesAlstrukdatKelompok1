#include <stdio.h>
#include "mesinkarakterfino.h"

void startMesinKarakter(MesinKarakter *mk, FILE *inputFile) {
    mk->currentIndex = 0;
    mk->totalChars = 0;

    // Membaca karakter hingga newline ('\n') atau EOF
    char c;
    while (fscanf(inputFile, "%c", &c) == 1 && c != '\n' && c != EOF) {
        mk->buffer[mk->totalChars++] = c;
    }
    mk->buffer[mk->totalChars] = '\0'; // Null terminator
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
