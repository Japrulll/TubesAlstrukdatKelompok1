#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakter.h"
#include "ADTFile.h"

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
    
    CurrentWord.Length = 0;
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

void STARTWORDBLANKS(){
    
    CurrentWord.Length = 0;
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
        CopyWordBlanks();
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

void ADVWORDBLANKS(){
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
        CopyWordBlanks();
   }
}

void CopyWord(){
    boolean quote = false;
    for (int i = 0;i<100;i++){
        if (CurrentWord.TabWord[i]=='\0'){
            break;
        }
        else{
            CurrentWord.TabWord[i] = '\0';
        }
    }
    int idx = 0;
    
    while ((currentChar != MARK) && (idx < NMax)){
        if(currentChar == '"'){
            if (quote){
                quote = false;
            }
            else{
                quote = true;
            }
            ADV();
        }
        if (currentChar == BLANK && !quote){
            break;
        }
        CurrentWord.TabWord[idx] = GetCC();
        ADV();
        idx++;
    } 
    CurrentWord.Length = idx;
    IgnoreBlanks();
    if ( currentChar == MARK ){
        EndWord = true;
   }
}

void CopyWordBlanks(){
    for (int i = 0;i<100;i++){
        if (CurrentWord.TabWord[i]=='\0'){
            break;
        }
        else{
            CurrentWord.TabWord[i] = '\0';
        }
    }
    int idx = 0;
    while ((currentChar != MARK) && (idx < NMax)){
        CurrentWord.TabWord[idx] = GetCC();
        ADV();
        idx++;
    } 
    CurrentWord.Length = idx;
    IgnoreBlanks();
    if ( currentChar == MARK ){
        EndWord = true;
   }
}

boolean isWordEqual(Word word, char* str) {
    int i = 0;
    while (i < word.Length && str[i] != '\0') {
        if (word.TabWord[i] != str[i]) {
            return false;
        }
        i++;
    }
    return (i == word.Length && str[i] == '\0');
}

void AS_WORD(){
    if (EndWord){
        STARTWORD();
    }
    else{
        ADVWORD();
    }
}

void AS_WORDBLANKS(){
    if (EndWord){
        STARTWORDBLANKS();
    }
    else{
        ADVWORDBLANKS();
    }
} 

void spitnamaharga(Word src, char*produk, int *jumlah){
    int len = src.Length;
    char cur = '\0';
    int l = len;
    char jum[10];
    int ids=0;

    for (;l>=0;l--){
        cur = src.TabWord[l];
        if (cur ==' '){
            ids =l;
            break;
        }
    }
    int k = 0;
    l++;
    for (;l <=len;l++){
        jum[k] = src.TabWord[l];
        k++;
        // printf("jj\n");
    }
    jum[k] = '\0';
    *jumlah = StrToInt(jum);
    if (*jumlah == -1){
        return;
    }
    for (int i = 0; i<ids;i++){
        produk[i] = src.TabWord[i];
    }
    produk[ids] = '\0';
}

// boolean isIn(Word word, BarangDin list_barang) {
//     for (int i = 0; i < Length(list_barang); i++) {
//         int j = 0;
//         boolean match = true;
//         while (j < word.Length && list_barang.A[i].name[j] != '\0') {
//             if (word.TabWord[j] != list_barang.A[i].name[j]) {
//                 match = false;
//                 break;
//             }
//             j++;
//         }
//         if (match && j == word.Length && list_barang.A[i].name[j] == '\0') {
//             return true;
//         }
//     }
//     return false;
// }





// int main() {
//     // Memulai pembacaan kata
//     STARTWORD();

//     // Selama tidak mencapai akhir input
//     while (!EndWord) {
//         // Mencetak kata yang saat ini ada di CurrentWord
//         // for (int i = 0; i < CurrentWord.Length; i++) {
//         //     printf("%c", CurrentWord.TabWord[i]);
//         // }
//         //printf("\n"); // Pindah baris untuk setiap kata

//         // Memproses kata berikutnya
//         ADVWORD();
//     }
//     printf("%s", CurrentWord.TabWord);

//     // Memberi tahu bahwa proses selesai
//     //printf("End of input reached.\n");

//     return 0;
// }
