#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

// Daftar kata yang dapat dipilih
char *kata_kumpulan[] = {
    "MOUSE", "TABLE", "WATER", "STORE", "CHAIR",
    "GRAVE", "FLUSH", "CRANE", "DRAFT", "PLUMB",
    "QUICK", "SHOCK", "WORLD", "FAULT", "PRINT",
    "GLOVE", "JUMPY", "BIRTH", "SHORT", "CHORD",
    "CROWN", "BLANK", "FRESH", "MIXER", "SLOPE",
    "FLINT", "DROWN", "POWER", "GRASP", "SCORN",
    "TWIST", "SHOVE", "HARPY", "BRAVE", "DEPTH",
    "CURVE", "FLOCK", "TRUCE", "WHIRL", "KITES",
    "WOUND", "FLARE", "SHOUT", "CRISP", "CHARM"
};

// Fungsi untuk memilih kata acak
char * pilih_kata_acak() {
    srand(time(NULL)); 
    int indeks_acak = rand() % 45;
    char *sumber_kata = kata_kumpulan[indeks_acak];
    char *kata_terpilih;
    for (int i=0; i<5; i++){
        kata_terpilih[i] = sumber_kata[i];
    }
    return (kata_terpilih);
}

Word valid_word(){
    STARTWORD();
    while ( !EndWord ) {
        ADVWORD();
    }

    return CurrentWord;
}

void cetak(int KESEMPATAN, char kata_K5[15], char kata_K4[15], char kata_K3[15], char kata_K2[15], char kata_K1[15]){
    if (KESEMPATAN==5){
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K5[a]);
        }
        printf("\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n\n");
    }
    else if (KESEMPATAN==4){
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K5[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K4[a]);
        }
        printf("\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n\n");
    }
    else if (KESEMPATAN==3){
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K5[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K4[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K3[a]);
        }
        printf("\n__ __ __ __ __\n__ __ __ __ __\n\n");
    }
    else if (KESEMPATAN==2){
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K5[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K4[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K3[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K2[a]);
        }
        printf("\n__ __ __ __ __\n\n");
    }
    else if (KESEMPATAN==1){
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K5[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K4[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K3[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K2[a]);
        }
        printf("\n");
        for (int a=0; a<15; a++){
            printf("%c",kata_K1[a]);
        }
        printf("\n");
    }
}

int W0RDL3(int uang) {
    int KESEMPATAN = 5;
    uang -= 500; // Pemain membayar 500 untuk masuk
    char *kata_target = pilih_kata_acak();
    printf("WELCOME TO \"WORDL3\" CHALLENGE!!!\n.\n.\n");
    printf("~~~~~~~~~~~~~~~~~~~~ DESKRIPSI ~~~~~~~~~~~~~~~~~~~~\n");
    printf("Pada permainan ini, anda akan diminta menebak sebuah kata yang benar.\n");
    printf("Anda akan diberikan 5 kesempatan menebak kata dengan memasukkan input yang valid.\n");
    printf("Jika berhasil menebak dengan benar, anda akan mendapat tambahan uang sebesar 1500 rupiah.\n");
    printf("\n~~~~~~~~~~~~~~~~ SELAMAT BERMAIN ~~~~~~~~~~~~~~~~\n");
    printf("\nSaldo awal Anda adalah: %d rupiah\n", uang);
    printf("--------------------------------------------\n");

    printf("__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n\n");

    char kata_K5[15];
    char kata_K4[15];
    char kata_K3[15];
    char kata_K2[15];
    char kata_K1[15];
    char sementara[15];

    for (KESEMPATAN; KESEMPATAN > 0; KESEMPATAN--) {
        printf("(Kesempatan tersisa: %d)\n", KESEMPATAN);
        printf("Masukan kata tebakan Anda: ");

        valid_word();
        
        //Validasi input
        boolean cek = true;
        if (CurrentWord.Length!=5){
            KESEMPATAN++;
            cek=false;
        }
        else {
            for (int l=0; l<CurrentWord.Length; l++){
                if ((CurrentWord.TabWord[l]<65 || CurrentWord.TabWord[l]>90) && (CurrentWord.TabWord[l]<97 || CurrentWord.TabWord[l]>122)) {
                    KESEMPATAN++;
                    cek=false;
                    break;
                }
                if (CurrentWord.TabWord[l]>=97 && CurrentWord.TabWord[l]<=122){
                    CurrentWord.TabWord[l] -= 32;
                }
            }
        }
        if (!cek){
            printf("Input tidak valid.\nMasukkan kata dengan panjang 5 huruf dan terdiri dari alphabet yang valid (A-Z)!\n");
            continue;
        }
        
        printf("Hasil:\n");

        int sama_semua=0;
        for (int i = 0; i < 5; i++) {
            int ditemukan = 0;
            sementara[(i*3)] = CurrentWord.TabWord[i];
            sementara[((i*3)+2)] = ' ';
            for (int j = 0; j < 5; j++) {
                if (CurrentWord.TabWord[i] == kata_target[j]) {
                    ditemukan = 1;
                    if (i == j) {
                        sama_semua++;
                        sementara[((i*3)+1)] = ' ';
                    } else {
                        sementara[((i*3)+1)] = '*';
                    }
                    break;
                }
            }
            if (ditemukan == 0) {
                sementara[((i*3)+1)] = '%';
            }
            if (sama_semua==5){
                break;
            }
        }
        for (int k=0; k<15; k++){
            if (KESEMPATAN==5){
                kata_K5[k] = sementara[k];
            }
            else if (KESEMPATAN==4){
                kata_K4[k] = sementara[k];
            }
            else if (KESEMPATAN==3){
                kata_K3[k] = sementara[k];
            }
            else if (KESEMPATAN==2){
                kata_K2[k] = sementara[k];
            }
            else if (KESEMPATAN==1){
                kata_K1[k] = sementara[k];
            }
        }

        cetak(KESEMPATAN, kata_K5, kata_K4, kata_K3, kata_K2, kata_K1);     

        if (sama_semua==5){
            printf("\nSelamat, Anda menang!\n");
            uang += 1500;
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            printf("Saldo anda saat ini adalah : %d rupiah\n", uang);
            return uang;
        }

        printf("\n");

    }

    printf("\nMaaf, Anda kalah. Kata yang benar adalah: %s\n", kata_target);
    printf("Saldo anda saat ini adalah : %d rupiah\n", uang);

    return uang;
}

/*
int main() {
    int uang = 1000;
    uang = W0RDL3(uang); 
    return 0;
}
*/
