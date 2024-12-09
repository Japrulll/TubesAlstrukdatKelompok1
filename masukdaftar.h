#ifndef MASUKDAFTAR_H
#define MASUKDAFTAR_H

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define MAX_LEN 100

#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTUser.h"
#include "./Folder ADT/boolean.h"

// typedef struct {
//     char username[USERNAME_LEN];
//     char password[PASSWORD_LEN];
//     int userID;
// } User;

// Operasi string
// int compareStrings(const char *str1, const char *str2);
/* Membandingkan dua string str1 dan str2 */
/* I.S.: str1 dan str2 adalah string yang akan dibandingkan */
/* F.S.: Mengembalikan nilai integer */

// void copyString(char *dest, const char *src);
/* Menyalin string dari source ke destination sebagai pengganti strcpy */
/* I.S. src merupakan source dan dest merupakan destination dari source */
/* F.S. src telah disalin ke dest */

// Fungsi utama
void registerUser(StaticUserList *userList);
/* Fungsi untuk registrasi pengguna baru */
/* I.S. Sistem PURRMART berjalan dan siap menerima registrasi */
/* F.S. Akun baru berhasil dibuat jika username belum terdaftar, atau pesan gagal jika username sudah digunakan */

boolean login(StaticUserList userList,User *change,int *user_index);
/* Fungsi untuk login ke sistem PURRMART */
/* I.S. Pengguna belum login, atau ada pengguna lain yang sedang login */
/* F.S. Pengguna berhasil login jika username dan password cocok, atau pesan gagal jika salah */


boolean logout(User *current,int *user_index);
/* Fungsi untuk logout dari sistem PURRMART */
/* I.S. Seorang pengguna sedang login */
/* F.S. Pengguna berhasil logout dan sistem siap untuk login baru */

// void mainMenu();
// /* Fungsi untuk menampilkan menu utama PURRMART */
// /* I.S. Program PURRMART aktif */
// /* F.S. Pengguna memilih opsi dan fungsi terkait dijalankan sesuai pilihan */

// int main();
// /* Fungsi utama untuk menjalankan program PURRMART */
// /* I.S. Program PURRMART belum berjalan */
// /* F.S. Menu utama tampil dan pengguna dapat memilih opsi untuk register, login, logout, atau keluar dari program */

#endif