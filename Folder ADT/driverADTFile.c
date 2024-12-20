#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADTFile.h"
#include "ADTLinkedList.h"
#include "ADTStack.h"
#include "ADTUser.h"
#include "ADTItem.h"


void populateList(DinamicItemList *itemList, StaticUserList *userList) {
    initDinamicItemList(itemList);
    addItem(itemList, 50, "Geoculus");
    addItem(itemList, 100, "Mint Jelly");

    initStaticUserList(userList);
    Stack history_pembelian;
    CreateEmptyS(&history_pembelian);
    Push(&history_pembelian, 200, "Almond_Tofu");

    List wishlist;
    CreateEmptyLL(&wishlist);
    InsVLast(&wishlist, "Anemoculus");

    addUser(userList, 100, "kazuha", "kaedehara", &history_pembelian, &wishlist);
}

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
    printf("Hasil dari fungsi readline:\n%s\n", buffer); //akan print kalimat yang ada di file ujicobafile.txt
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
   

    printf("---uji fungsi writeToFile ---\n");
    StaticUserList userListData;
    DinamicItemList itemListData;

    initDinamicItemList(&itemListData);
    initStaticUserList(&userListData);
    populateList(&itemListData, &userListData);

    const char *filePath = "ujicoba_writeToFile.txt";

    FILE *fileWriter = fopen(filePath, "w");
    if (fileWriter == NULL) {
        printf("Gagal membuka file untuk menulis: %s\n", filePath);
        return 1;
    }
    writeToFile(fileWriter, &itemListData, &userListData);
    fclose(fileWriter);
    printf("Data telah berhasil ditulis ke file: %s\n", filePath);

    FILE *fileReader = fopen(filePath, "r");
    if (fileReader == NULL) {
        printf("Gagal membuka file untuk membaca: %s\n", filePath);
        return 1;
    }

    printf("Isi file '%s':\n", filePath);
    char c;
    while ((c = fgetc(fileReader)) != EOF) {
        putchar(c);
    }
    fclose(fileReader);

    return 0;
}