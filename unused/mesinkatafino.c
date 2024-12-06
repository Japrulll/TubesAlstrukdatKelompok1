#include <stdio.h>
#include "mesinkatafino.h"

void startMesinKata(MesinKarakter *mk, MesinKata *mK) {
    mK->currentLength = 0;

    while (!isEnd(mk) && mk->buffer[mk->currentIndex] != '\n') {
        mK->currentWord[mK->currentLength++] = mk->buffer[mk->currentIndex++];
    }

    mK->currentWord[mK->currentLength] = '\0'; // Null terminator
}
