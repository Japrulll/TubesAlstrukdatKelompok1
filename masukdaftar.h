#ifndef MASUKDAFTAR_H
#define MASUKDAFTAR_H

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define MAX_LEN 100

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int userID;
} User;

// Operasi string
int compareStrings(const char *str1, const char *str2);
void copyString(char *dest, const char *src);

// Fungsi utama
void registerUser();
void login();
void logout();
void mainMenu();

#endif