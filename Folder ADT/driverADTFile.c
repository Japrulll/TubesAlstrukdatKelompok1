#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADTFile.h"
#include "ADTLinkedList.h"
#include "ADTStack.h"


int main() {
    printf("---uji fungsi copyString---\n");
    char source[] = "Hello, World!";
    char destination[50];
    copyString(source, destination);
    printf("Hasil copyString: %s\n", destination); //akan print Hello, World!
    
    printf("\n");

    printf("---uji fungsi compareStrings---\n");
    char str1[] = "sama";
    char str2[] = "sama";
    char str3[] = "beda";
    printf("compareStrings(\"sama\", \"sama\"): %d\n", compareStrings(str1, str2)); //akan menghasilkan 1 karena True, kedua string sama
    printf("compareStrings(\"sama\", \"beda\"): %d\n", compareStrings(str1, str3)); //akan menghasilkan 0 karena False, kedua string berbeda

    printf("\n");

    printf("---uji fungsi constructfilepath---\n");
    char basepath[] = "/home/user/";
    char filename[] = "ujicoba.txt";
    char filepath[100];
    constructfilepath(filepath, basepath, filename);
    printf("Hasil dari fungsi constructfilepath: %s\n", filepath); //akan print /home/user/ujicoba.txt

    printf("\n");

    printf("---uji fungsi readline---\n");
    FILE *file = fopen("ujicobafile.txt", "w");
    fprintf(file, "Test 123 kalimat pertama\n");
    fprintf(file, "Test 456 kalimat kedua\n");
    fclose(file);

    file = fopen("ujicobafile.txt", "r");
    char buffer[100];
    readline(file, buffer);
    printf("Hasil dari fungsi readline: %s\n", buffer); //akan print kalimat yang ada di file ujicobafile.txt
    fclose(file);

    printf("\n");

    printf("---uji fungsi generate_random_number---\n");
    printf("Angka random: %d\n", generate_random_number());

    printf("\n");

    printf("---uji fungsi StrToInt---\n");
    char numStr1[] = "12345";
    char numStr2[] = "-6789";
    char numStr3[] = "12a45";
    printf("StrToInt(\"12345\"): %d\n", StrToInt(numStr1)); //akan print 12345
    printf("StrToInt(\"-6789\"): %d\n", StrToInt(numStr2)); //akan print -6789
    printf("StrToInt(\"12a45\"): %d\n", StrToInt(numStr3)); //akan print -1, karena input tidak valid

    printf("\n");
   
    
    printf("---uji fungsi writeToFile---\n");
    
    DinamicItemList itemList;
    itemList.count = 2;
    itemList.items[0].price = 100;
    copyString("itemA", itemList.items[0].name);
    itemList.items[1].price = 200;
    copyString("itemB", itemList.items[1].name);

    StaticUserList userList;
    userList.count = 1;
    userList.users[0].money = 500;
    copyString("user1", userList.users[0].name);
    copyString("password1", userList.users[0].password);
    CreateEmptyS(&userList.users[0].riwayat_pembelian);
    Push(&userList.users[0].riwayat_pembelian, 123, "nama");
    CreateEmptyLL(&userList.users[0].wishlist);
    InsVLast(&userList.users[0].wishlist, "wishlistItem1");

    FILE *file_write = fopen("testWriteToFile.txt", "w");
    if (file_write == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return 1;
    }
    printf("File berhasil dibuka untuk menulis\n");
    
    writeToFile(file_write, &itemList, &userList);
    fclose(file_write);
    printf("Data telah disimpan ke 'testWriteToFile.txt'.\n");

    printf("Isi file testWriteToFile.txt:\n");
    FILE *file_read = fopen("testWriteToFile.txt", "r");
    if (file_read == NULL) {
        printf("Gagal membuka file untuk membaca.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(file_read)) != EOF){
        putchar(c);
    }
    fclose(file_read);

    return 0;
}