#include <stdio.h>
#include "help.h"

void displayMainMenu(){
    printf("====== [ Welcome Menu ]======\n");
    printf("    1. File Menu\n");
    printf("    2. Login and Register\n");
    printf("    3. Main Menu\n");
    printf("    4. Exit\n");
    printf("    5. Check File Status\n");
}

void displayHelpWelcome(){
    printf("===== [ File Menu PURRMART ]=====\n");
    printf("    1. START -> Untuk masuk sesi baru\n");
    printf("    2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("    3. Back -> Balik ke setting\n");
}

void displayHelpLogin(){
    printf("=====[ Login Menu PURRMART ]=====\n");
    printf("    1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("    2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("    3. PROFILE -> Cek profile akun\n");
    printf("    4. Back -> Balik ke setting\n");
}

void displayHelpMain(){
    printf("=====[ Menu PURRMART ]=====\n");
    printf("    1. WORK -> Untuk bekerja\n");
    printf("    2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf("    3. STORE\n");
    printf("    4. CART\n");
    printf("    5. HISTORY\n");
    printf("    6. WISHLIST\n");
    printf("    7. LOGOUT -> Untuk keluar dari sesi\n");
    printf("    8. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("    9. Back -> Balik ke setting\n");
}

void displayChallange(){
    printf("=====[ Challenge Menu PURRMART ]=====\n");
    printf("    1. Tebak Angka -> mainkan tebak angka\n");
    printf("    2. Wordl3 -> mainkan worle 3\n");
    printf("    3. Back -> Balik ke setting\n"); 
}
void displayStore(){
    printf("    1. STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("    2. STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf("    3. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("    4. STORE REMOVE -> Untuk menghapus barang\n");
    printf("    5. Back -> Balik ke setting\n"); 

}
void displayCart(){
    printf("    0. DISPLAY STORE\n");
    printf("    1. CART ADD\n");
    printf("    2. CART REMOVE\n");
    printf("    3. CART SHOW\n");    
    printf("    4. CART PAY\n");
    printf("    5. Back -> Balik ke setting\n"); 

}

void displayWishlist(){
    printf("    1. WISHLIST ADD\n");
    printf("    2. WISHLIST SWAP\n");
    printf("    3. WISHLIST REMOVE\n");
    printf("    4. WISHLIST CLEAR\n");
    printf("    5. WISHLIST SHOW\n");
    printf("    6. Back -> Balik ke setting\n"); 
}