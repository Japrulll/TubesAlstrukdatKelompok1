#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tebak_angka.h"

// Fungsi untuk random number generator
int generate_random_number() {
    srand(time(NULL)); 
    int angka_target =  rand() % 100;
    return angka_target;
}

int CharToInt() {
    int tebak = 0;

    STARTWORD();
    while ( !EndWord ) {
        ADVWORD();
    }

    for (int i=0; i<CurrentWord.Length;i++) {
        if (CurrentWord.TabWord[i]<'0' || CurrentWord.TabWord[i]>'9' ){
            return -1;
        }
        tebak = tebak * 10 + (CurrentWord.TabWord[i] - '0');
    }
    return tebak;
}

int Tebak_Angka(int uang) {
    printf("...Memulai permainan Tebak Angka...\n.\n");

    printf("*****************************************************\n");
    printf("*       WELCOME TO \"TEBAK ANGKA\" CHALLENGE!!!       *\n");
    printf("*                                                   *\n");
    printf("*                   DESKRIPSI                       *\n");
    printf("* Pada permainan ini, anda akan diminta menebak     *\n");
    printf("* angka yang benar dari antara 0 sampai 99.         *\n");
    printf("* Anda akan diberikan 10 kesempatan menebak angka.  *\n");
    printf("* Jika berhasil menebak dengan benar, anda akan     *\n");
    printf("* mendapat uang, bergantung pada sisa kesempatan    *\n");
    printf("* yang anda miliki.                                 *\n");
    printf("*                                                   *\n");
    printf("*                SELAMAT BERMAIN!                   *\n");
    printf("*                                                   *\n");
    printf("*****************************************************\n");
    printf("      Saldo awal Anda adalah: %d rupiah\n", uang);
    printf("-----------------------------------------------------\n");

    // Kurangi biaya permainan
    uang -= 200;

    int angka_target = generate_random_number();

    int tebakan;
    int kesempatan = 10;

    // Mulai permainan
    while (kesempatan > 0) {
        if (kesempatan==10){
            printf("(Anda memiliki %d kesempatan dalam challenge ini)\n", kesempatan);
        }
        else if (kesempatan < 10){
             printf("(Sisa kesempatan yang Anda miliki : %d)\n", kesempatan);
        }
        
        printf("Masukkan angka tebakan Anda -> ");
        tebakan = CharToInt();

        // Validasi input
        if (tebakan < 0 || tebakan > 99) {
            printf("Input tidak valid. Masukkan angka antara 0 dan 99!\n");
            continue;
        }

        // Periksa tebakan
        if (tebakan == angka_target) {
            // Hitung uang berdasarkan kesempatan
            int uang_didapatkan = 50 * (kesempatan);
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun anda\n", uang_didapatkan);
            uang += uang_didapatkan;
            printf("Saldo Anda saat ini: %d rupiah\n", uang);
            return uang; // Return uang setelah menang
        } else if (tebakan < angka_target) {
            printf("Tebakanmu lebih kecil dari jawaban benar!\n");
        } else {
            printf("Tebakanmu lebih besar dari jawaban benar!\n");
        }
        kesempatan--;
    }

    printf("Sayang sekali, kesempatan telah habis...\n");
    printf("Angka yang benar adalah %d.\n", angka_target);
    printf("Saldo Anda saat ini: %d rupiah\n", uang);
    return uang; 
}

/*
int main() {
    int uang = 1000;
    uang = Tebak_Angka(uang);
    return 0;
}
*/
