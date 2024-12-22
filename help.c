#include <stdio.h>
#include "help.h"

void displayMainMenu(){
    printf(" _______ __   __ ______   ______   __   __ _______ ______ _______ \n");
    printf("|       |  | |  |    _ | |    _ | |  |_|  |   _   |    _ |       |\n");
    printf("|    _  |  | |  |   | || |   | || |       |  |_|  |   | ||_     _|\n");
    printf("|   |_| |  |_|  |   |_||_|   |_||_|       |       |   |_||_|   |  \n");
    printf("|    ___|       |    __  |    __  |       |       |    __  |   |  \n");
    printf("|   |   |       |   |  | |   |  | | ||_|| |   _   |   |  | |   |  \n");
    printf("|___|   |_______|___|  |_|___|  |_|_|   |_|__| |__|___|  |_|___|  \n"); 
    printf("====== [ Welcome Menu ]======\n");
    printf("    1. File Menu\n");
    printf("    2. Login and Register\n");
    printf("    3. Main Menu\n");
    printf("    4. Exit\n");
    printf("    5. Check File Status\n");
}

void displayHelpWelcome(){
    printf(" _______ ___ ___     _______ \n");
    printf("|       |   |   |   |       |\n");
    printf("|    ___|   |   |   |    ___|\n");
    printf("|   |___|   |   |   |   |___ \n");
    printf("|    ___|   |   |___|    ___|\n");
    printf("|   |   |   |       |   |___ \n");
    printf("|___|   |___|_______|_______|\n");
    printf("===== [ File Menu PURRMART ]=====\n");
    printf("    1. START -> Untuk masuk sesi baru\n");
    printf("    2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("    3. Back -> Balik ke setting\n");
}

void displayHelpLogin(){
    printf(" ______   _______ _______ ___ _______ _______ _______ ______   \n");
    printf("|    _ | |       |       |   |       |       |       |    _ |  \n");
    printf("|   | || |    ___|    ___|   |  _____|_     _|    ___|   | ||  \n");
    printf("|   |_||_|   |___|   | __|   | |_____  |   | |   |___|   |_||_ \n");
    printf("|    __  |    ___|   ||  |   |_____  | |   | |    ___|    __  |\n");
    printf("|   |  | |   |___|   |_| |   |_____| | |   | |   |___|   |  | |\n");
    printf("|___|  |_|_______|_______|___|_______| |___| |_______|___|  |_|\n");
    printf(" ___     _______ _______ ___ __    _ \n");
    printf("|   |   |       |       |   |  |  | |\n");
    printf("|   |   |   _   |    ___|   |   |_| |\n");
    printf("|   |   |  | |  |   | __|   |       |\n");
    printf("|   |___|  |_|  |   ||  |   |  _    |\n");
    printf("|       |       |   |_| |   | | |   |\n");
    printf("|_______|_______|_______|___|_|  |__|\n"); 
    printf("=====[ Login Menu PURRMART ]=====\n");
    printf("    1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("    2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("    3. PROFILE -> Cek profile akun\n");
    printf("    4. Back -> Balik ke setting\n");
}

void displayHelpMain(){
    printf(" __   __ _______ ___ __    _ \n");
    printf("|  |_|  |   _   |   |  |  | |\n");
    printf("|       |  |_|  |   |   |_| |\n");
    printf("|       |       |   |       |\n");
    printf("|       |       |   |  _    |\n");
    printf("| ||_|| |   _   |   | | |   |\n");
    printf("|_|   |_|__| |__|___|_|  |__|\n");
    printf("=====[ Menu PURRMART ]=====\n");
    printf("    1. WORK -> Untuk bekerja\n");
    printf("    2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf("    3. STORE -> Untuk mengurus toko\n");
    printf("    4. CART -> Untuk membeli barang\n");
    printf("    5. HISTORY -> Untuk melihat sejarah pembelian\n");
    printf("    6. WISHLIST -> Untuk menyimpan wishlist\n");
    printf("    7. LOGOUT -> Untuk keluar dari sesi\n");
    printf("    8. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("    9. Back -> Balik ke setting\n");
}

void displayChallange(){
    printf("  _     _ _______ ______   ___   _                                        \n");
    printf("| | _ | |       |    _ | |   | | |                                       \n");
    printf("| || || |   _   |   | || |   |_| |                                       \n");
    printf("|       |  | |  |   |_||_|      _|                                       \n");
    printf("|       |  |_|  |    __  |     |_                                        \n");
    printf("|   _   |       |   |  | |    _  |                                       \n");
    printf("|__|_|__|_______|___|__|_|___| |_|__     _______ __    _ _______ _______ \n");
    printf("|       |  | |  |   _   |   |   |   |   |       |  |  | |       |       |\n");
    printf("|       |  |_|  |  |_|  |   |   |   |   |    ___|   |_| |    ___|    ___|\n");
    printf("|       |       |       |   |   |   |   |   |___|       |   | __|   |___ \n");
    printf("|      _|       |       |   |___|   |___|    ___|  _    |   ||  |    ___|\n");
    printf("|     |_|   _   |   _   |       |       |   |___| | |   |   |_| |   |___ \n");
    printf("|_______|__| |__|__| |__|_______|_______|_______|_|  |__|_______|_______| \n");
    printf("=====[ Challenge Menu PURRMART ]=====\n");
    printf("    1. Tebak Angka -> mainkan tebak angka\n");
    printf("    2. Wordl3 -> mainkan worle 3\n");
    printf("    3. Back -> Balik ke setting\n"); 
}
void displayStore(){
    printf(" _______ _______ _______ ______   _______ \n");
    printf("|       |       |       |    _ | |       |\n");
    printf("|  _____|_     _|   _   |   | || |    ___|\n");
    printf("| |_____  |   | |  | |  |   |_||_|   |___ \n");
    printf("|_____  | |   | |  |_|  |    __  |    ___|\n");
    printf(" _____| | |   | |       |   |  | |   |___ \n");
    printf("|_______| |___| |_______|___|  |_|_______| \n");
    printf("    1. STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("    2. STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf("    3. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("    4. STORE REMOVE -> Untuk menghapus barang\n");
    printf("    5. Back -> Balik ke setting\n"); 

}
void displayCart(){
    printf(" _______ _______ ______ _______ \n");
    printf("|       |   _   |    _ |       |\n");
    printf("|       |  |_|  |   | ||_     _|\n");
    printf("|       |       |   |_||_|   |  \n");
    printf("|      _|       |    __  |   |  \n");
    printf("|     |_|   _   |   |  | |   |  \n");
    printf("|_______|__| |__|___|  |_|___|   \n");
    printf("    0. DISPLAY STORE -> Mendisplay isi toko\n");
    printf("    1. CART ADD -> Menambahkan barang ke keranjang\n");
    printf("    2. CART REMOVE -> Menggeluarkan barang dari keranjang\n");
    printf("    3. CART SHOW -> Menambahkan isi keranjang\n");    
    printf("    4. CART PAY -> Menampilkan menu bayar\n");
    printf("    5. Back -> Balik ke setting\n"); 

}

void displayWishlist(){
    printf(" _     _ ___ _______ __   __ ___     ___ _______ _______ \n");
    printf("| | _ | |   |       |  | |  |   |   |   |       |       |\n");
    printf("| || || |   |  _____|  |_|  |   |   |   |  _____|_     _|\n");
    printf("|       |   | |_____|       |   |   |   | |_____  |   |  \n");
    printf("|       |   |_____  |       |   |___|   |_____  | |   |  \n");
    printf("|   _   |   |_____| |   _   |       |   |_____| | |   |  \n");
    printf("|__| |__|___|_______|__| |__|_______|___|_______| |___|   \n");
    printf("    0. DISPLAY STORE -> Mendisplay isi toko\n");
    printf("    1. WISHLIST ADD -> Menambahkan barang ke wishlist\n");
    printf("    2. WISHLIST SWAP -> Mengubah posisi barang di wishlist\n");
    printf("    3. WISHLIST REMOVE -> Menghapuskan suatu barang dari wishlist\n");
    printf("    4. WISHLIST CLEAR -> Menghapuskan semua barang dari wishlist\n");
    printf("    5. WISHLIST SHOW -> Menunjukan isi wishlist\n");
    printf("    6. Back -> Balik ke setting\n"); 
}
