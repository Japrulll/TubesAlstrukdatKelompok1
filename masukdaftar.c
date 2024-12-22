#include <stdio.h>
#include <stdlib.h>
#include "masukdaftar.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTUser.h"
#include "./Folder ADT/ADTLinkedList.h"
#include "./Folder ADT/ADTStack.h"
#include "./Folder ADT/ADTSetMap.h"


// Fungsi untuk membandingkan 2 string


// // Fungsi untuk menyalin string
// void copyString(char* src, char* dest) {
//     int i = 0;
//     while (src[i] != '\0') {
//         dest[i] = src[i];
//         i++;
//     }
//     dest[i] = '\0'; // Null terminator
// }

// Fungsi Register
// void registerUser() {
//     char name[MAX_LEN];
//     char password[MAX_LEN];
//     StaticUserList userList;
//     StaticUserList users;

//     printf(">> REGISTER\n");

//     // Input username
//     printf("Username: ");
//     STARTWORD(); // Menggunakan fungsi STARTWORD() dari mesin karakter
//     if (EndWord) {
//         printf("Username tidak boleh kosong. Silakan coba lagi.\n");
//     }
//     // Salin CurrentWord.TabWord ke variabel 'name'
//     copyString(CurrentWord.TabWord, name);

//     // Cek apakah username sudah ada
//     for (int i = 0; i < userList.count; i++) {
//         if (isWordEqual(CurrentWord, userList.users[i].name)) {
//             printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", name);
//             return;
        
//         }
//     }


//     // Input password
//     printf("Password: ");
//     STARTWORD(); // Menggunakan fungsi STARTWORD() dari mesin karakter
//     if (EndWord) { // Validasi input kosong
//         printf("Password tidak boleh kosong. Silakan coba lagi.\n");
//         return;
//     }
//     // Salin CurrentWord.TabWord ke variabel 'password'
//     copyString(CurrentWord.TabWord, password);

//     // Simpan data user baru
//     copyString(userList.users[userList.count].name, name);       // Simpan username
//     copyString(userList.users[userList.count].password, password); // Simpan password
//     userList.users[userList.count].money = 0;                    // Set saldo awal menjadi 0

//     userList.count++; // Tambah jumlah user

//     // Output keberhasilan
//     printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", name);
// }

void registerUser(StaticUserList *userList) {  // Tambahkan parameter userList
    char name[MAX_LEN];
    char password[MAX_LEN];
    
    printf(">> REGISTER\n");
    
    // Input username
    printf("Username: ");
    STARTWORD();
    
    if (compareStrings(CurrentWord.TabWord,"")) {
        printf("Username tidak boleh kosong. Silakan coba lagi.\n");
        return;
    }
    
    // Salin CurrentWord.TabWord ke variabel 'name'
    copyString(CurrentWord.TabWord, name);
    
    // Tambahkan pengecekan userList
    // if (userList == NULL) {
    //     printf("UserList tidak valid\n");
    //     return;
    // }
    
    // // Cek apakah userList sudah penuh
    // if (userList->count >= MAX_USERS) {  // Asumsikan MAX_USERS sudah didefinisikan
    //     printf("Error: Tidak bisa menambah user baru, storage penuh\n");
    // //     return;
    // }
    
    // Cek apakah username sudah ada
    for (int i = 0; i < userList->count; i++) {
        if (compareStrings(name, userList->users[i].name)) {
            printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", name);
            return;
        }
    }
    
    // Input password
    printf("Password: ");
    STARTWORD();
    
    if (compareStrings(CurrentWord.TabWord,"")) {
        printf("Password tidak boleh kosong. Silakan coba lagi.\n");
        return;
    }
    
    // Salin CurrentWord.TabWord ke variabel 'password'
    copyString(CurrentWord.TabWord, password);
    
    // Simpan data user baru
    Stack nill;
    CreateEmptyS(&nill);

    List noll;
    CreateEmptyLL(&noll);
    addUser(userList,0,name,password,&nill,&noll);
    
    // Output keberhasilan
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", name);
}

// Fungsi Login
boolean login(StaticUserList userList,User *change,int *user_index) {
    char username[100] = "";
    char pass[100] = "";

    if (!compareStrings((*change).name,"null")) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", (*change).name);
        return false;
    }

    printf(">> LOGIN\n");
    // Input username
    printf("Username: ");
    AS_WORD(); // Menggunakan fungsi STARTWORD() dari mesin karakter
    if (compareStrings(CurrentWord.TabWord,"")) { // Validasi input kosong
        printf("Username tidak boleh kosong. Silakan coba lagi.\n");
        return false;
    }
    copyString(CurrentWord.TabWord, username); // Salin ke variabel username
    // printf("%s\n",CurrentWord.TabWord);
    // printf("%s\n",username);

    // Memasukkan password
    printf("Password: ");
    AS_WORD(); // Menggunakan fungsi STARTWORD() dari mesin karakter
    if (compareStrings(CurrentWord.TabWord,"")) { // Validasi input kosong
        printf("Password tidak boleh kosong. Silakan coba lagi.\n");
        return false;
    }
    copyString(CurrentWord.TabWord, pass); // Salin ke variabel password
    // printf("%s\n",CurrentWord.TabWord);
    // printf("%s\n",pass);

    for (int i = 0; i < userList.count+1; i++) {
        boolean usernameMatch = compareStrings(username, userList.users[i].name);  
        boolean passwordMatch = compareStrings(pass, userList.users[i].password);  

        if (usernameMatch && passwordMatch) {
            printf("Anda telah login ke PURRMART sebagai %s.\n", userList.users[i].name);
            *change = userList.users[i];
            *user_index = i;
            return true;
        }
    }
    printf("Username atau password salah.\n");

    return false;
}

boolean logout(User *current,int *user_index){
    copyString("null",current->name);
    copyString("null",current->password);
    current->money = -1;
    *user_index = -1;
    CreateEmptyMap(&current->keranjang);
    CreateEmptyS(&current->riwayat_pembelian);
    CreateEmptyLL(&current->wishlist);
    return false;
}