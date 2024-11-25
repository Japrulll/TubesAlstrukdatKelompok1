#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkarakterjaprul.h"
#include "mesinkatajaprul.h"


Word valid_word(){
    STARTWORD();
    while ( !EndWord ) {
        ADVWORD();
    }
    return CurrentWord;
}

int W0RDL3(int uang) {
    char kata_kumpulan[160][6] = {
    "BUKIT", "LAMPU", "KURSI", "PINTU", "GARIS", "ASPEK", "ASYIK", "BESAR",
    "BENCI", "HUTAN", "KIPAS", "LUKIS", "PESAN", "BEKAS", "BEGAL", "BECAK",
    "KERJA", "KUNCI", "TENDA", "CERNA", "RIMBA", "PUTIH", "HARUM", "BETAH",
    "SULIT", "DEBIT", "TULIS", "LIRIK", "CEPAT", "TERIK", "ANGIN", "BASUH",
    "EMPUK", "LEBAR", "SUAMI", "BERAT", "FIGUR", "KASIH", "MERAH", "BAGUS",
    "IKLAN", "GITAR", "GADIS", "FINAL", "SEDIH", "SALUT", "BURAM", "LOMBA",
    "RINDU", "HAKIM", "GABUS", "GEMUK", "SENAM", "GEMPA", "HADIR", "HALUS",
    "BELAS", "GARPU", "HAMIL", "HASUT", "LUNAS", "HABIS", "MEGAH", "IDOLA",
    "CERIA", "BASMI", "HOTEL", "BONUS", "HUMOR", "NAFAS", "BANCI", "BIDAN",
    "IMLEK", "INDUK", "GEMAR", "PANIK", "LUKIS", "MIKRO", "MASIH", "BAKSO",
    "KUDIS", "PANIK", "INGAT", "INTEL", "RATUS", "SAYUR", "WAKIL", "DOMBA",
    "PETIR", "JAKUN", "TIRAM", "LATIH", "JILAT", "JUMAT", "PELUK", "CINTA",
    "JERAT", "JUBAH", "TUGAS", "JEJAK", "JUMPA", "JUMBO", "BAKTI", "TAHUN",
    "BATIK", "KAGUM", "SELAM", "KAGET", "JAKET", "KAMUS", "KAMIS", "KARTU",
    "SENJA", "RUANG", "HIJAB", "PILAR", "LARUT", "TIMUR", "SALJU", "KARGO",
    "TULIP", "KATUP", "KITAB", "DOSEN", "SERAT", "KETUA", "BALOK", "KEMAH",
    "MULIA", "LAPOR", "JADUL", "LERAI", "DUNIA", "JENIS", "HEWAN", "LEBIH",
    "LEKAS", "LEBAT", "LEMON", "HALUS", "LIHAT", "LOGIS", "LIDAH", "MANDI",
    "MERDU", "MODEL", "MOTIF", "NASIB", "OPTIK", "ORANG", "PAMER", "PANCI",
    "PASTI", "PEGAL", "PANIK", "PERGI", "RACUN", "RESMI", "RIVAL", "SANDI"
    };

    int KESEMPATAN = 6;
    uang -= 500; // Pemain membayar 500 untuk masuk

    srand(time(NULL)); 
    int indeks_acak = rand() % 160;

    printf("*****************************************************\n");
    printf("*         WELCOME TO \"WORDL3\" CHALLENGE!!!          *\n");
    printf("*                                                   *\n");
    printf("*                   DESKRIPSI                       *\n");
    printf("* Pada permainan ini, anda akan diminta menebak     *\n");
    printf("* sebuah kata yang benar. Anda akan diberikan 5     *\n");
    printf("* kesempatan menebak kata dengan memasukkan input   *\n");
    printf("* yang valid. Jika berhasil menebak dengan benar,   *\n");
    printf("* anda akan mendapat uang sebesar 1500 rupiah.      *\n");
    printf("* Pada permainan ini, anda akan diminta menebak     *\n");
    printf("*                                                   *\n");
    printf("*                SELAMAT BERMAIN!                   *\n");
    printf("*                                                   *\n");
    printf("*****************************************************\n");
    printf("       Saldo awal Anda adalah: %d rupiah\n", uang);
    printf("-----------------------------------------------------\n");

    printf("__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n__ __ __ __ __\n\n");

    char kata[5][15];

    for (KESEMPATAN; KESEMPATAN > 0; KESEMPATAN--) {
        printf("(Kesempatan tersisa: %d)\n", KESEMPATAN);
        printf("Masukan kata tebakan Anda: ");

        valid_word();
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
            kata[KESEMPATAN-1][(i*3)] = CurrentWord.TabWord[i];
            kata[KESEMPATAN-1][((i*3)+2)] = ' ';
            for (int j = 0; j < 6; j++) {
                if (CurrentWord.TabWord[i] == kata_kumpulan[indeks_acak][j]) {
                    ditemukan = 1;
                    if (i == j) {
                        sama_semua++;
                        kata[KESEMPATAN-1][((i*3)+1)] = ' ';
                    } else {
                        kata[KESEMPATAN-1][((i*3)+1)] = '*';
                    }
                    break;
                }
            }
            if (ditemukan == 0) {
                kata[KESEMPATAN-1][((i*3)+1)] = '%';
            }
            if (sama_semua==5){
                break;
            }
        }
       
        for (int b=5; b>=(KESEMPATAN-1); b--){
            for (int a=0; a<15; a++){
                printf("%c",kata[b][a]);
            }
            printf("\n");
        }
        for (int c=0;c<(KESEMPATAN-1); c++){
            printf("__ __ __ __ __\n");
        }

        if (sama_semua==5){
            printf("\nSelamat, Anda menang!\n");
            uang += 1500;
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            printf("Saldo anda saat ini adalah : %d rupiah\n", uang);
            return uang;
        }
        printf("\n");
    }

    printf("Maaf, Anda kalah. Kata yang benar adalah: ");
    for (int x=0; x<6; x++){
        printf("%c",kata_kumpulan[indeks_acak][x]);
    }
    printf("\nSaldo anda saat ini adalah : %d rupiah\n", uang);

    return uang;
}

/*
int main() {
    int uang = 1000;
    uang = W0RDL3(uang); 
    return 0;
}
*/
