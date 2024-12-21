#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakter.h"
#include "ADTFile.h"

int main() {
    // Memulai pembacaan kata
    printf("---UJI MESINKATA---\n");
    printf("Input beberapa kata untuk uji coba: \n");
    STARTWORD();

    // Selama tidak mencapai akhir input
    while (!EndWord) {
        // Mencetak kata yang saat ini ada di CurrentWord
        for (int i = 0; i < CurrentWord.Length; i++) {
            printf("%c", CurrentWord.TabWord[i]);
        }
        printf("\n"); // Pindah baris untuk setiap kata

        // Memproses kata berikutnya
        ADVWORD();
    }
    printf("%s", CurrentWord.TabWord);
   

    printf("\n");
    // Memberi tahu bahwa proses selesai
    printf("End of input reached.\n");

    return 0;
}
