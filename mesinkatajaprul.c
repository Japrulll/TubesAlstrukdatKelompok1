#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakter.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   // hanya untuk awal kata saja, blank di dalam kalimat tetap terbaca */
   while (currentChar == BLANK){
        ADV();
    }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
   //IgnoreBlanks();
   if ( currentChar == MARK ){
        EndWord = true;
   }
   else{
        EndWord = false;
        CopyWord();
   }
}

void CopyWord(){
    int idx = 0;
    while ((currentChar != MARK) && (idx < NMax)){
        CurrentWord.TabWord[idx] = GetCC();
        ADV();
        idx++;
    } 
    CurrentWord.Length = idx;
    
//    CurrentWord.Length = idx;
}

int main() {
    // Memulai pembacaan kata
    STARTWORD();

    // Selama tidak mencapai akhir input
    while (!EndWord) {
        // Mencetak kata yang saat ini ada di CurrentWord
        // for (int i = 0; i < CurrentWord.Length; i++) {
        //     printf("%c", CurrentWord.TabWord[i]);
        // }
        //printf("\n"); // Pindah baris untuk setiap kata

        // Memproses kata berikutnya
        ADVWORD();
    }
    printf("%s", CurrentWord.TabWord);

    // Memberi tahu bahwa proses selesai
    //printf("End of input reached.\n");

    return 0;
}