#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADTFile.h"
#include "ADTLinkedList.h"
#include "ADTStack.h"
#include "ADTMap.h"
void copyString(char* src, char* dest){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int compareStrings(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; // Tidak sama
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0'; 
}

void display(DinamicItemList *itemlist, StaticUserList *userlist){
    for (int i = 0; i < itemlist->count; i++){
        printf("%d %s\n", itemlist->items[i].price, itemlist->items[i].name);
    }
    for (int i = 0; i < userlist->count; i++){
        printf("%d %s %s\n", userlist->users[i].money, userlist->users[i].name, userlist->users[i].password);
        // printStack(&userlist->users[i].riwayat_pembelian);
        // PrintInfo(userlist->users[i].wishlist);
    }
}

void constructfilepath(char*filepath, char*basepath, char*filename){
    int i = 0;
    while(basepath[i] != '\0'){
        filepath[i] = basepath[i];
        i++;
    }
    int j = 0;
    while(filename[j] != '\0'){
        filepath[i] = filename[j];
        i++;
        j++;
    }
    filepath[i] = '\0';
}

void readline(FILE *file, char *buffer){
    int i = 0;
    char c;
    while((c = fgetc(file))!= EOF && c != '\n'){
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
}

void writeToFile(FILE *file, DinamicItemList *itemList, StaticUserList *userList){
    if (file != NULL){
        fprintf(file, "%d\n", itemList->count);
        for (int i = 0; i<itemList->count; i++){
            fprintf(file, "%d %s\n", itemList->items[i].price, itemList->items[i].name);
        }

        fprintf(file, "%d\n", userList->count);
        for (int i = 0; i<userList->count; i++){
            fprintf(file, "%d %s %s\n", userList->users[i].money, userList->users[i].name, userList->users[i].password);
            fprintf(file, "%d\n", userList->users[i].riwayat_pembelian.TOP+1);
            printStack(&userList->users[i].riwayat_pembelian, file);
            fprintf(file, "%d\n", NbElmt(userList->users[i].wishlist));
            PrintInfo(userList->users[i].wishlist, file);
        }
        printf("Save file berhasil disimpan.\n");
        fclose(file);
    } else {
        printf("File gagal disave.\n");
    }

}

int generate_random_number() {
    srand(time(NULL)); 
    int angka_target =  rand() % 100;
    return angka_target;
}

int StrToInt(char* num) {
    int out = 0;
    int i = 0;
    int neg = 0;
    if (num[i]=='-'){
        neg = 1;
        i++;
    }
    while (num[i] != '\0'){
        if (num[i]<'0' || num[i]>'9' ){
            return -1;
        }   
        out = out * 10 + (num[i] - '0'); 
        i++;
    }
    if (neg){out = out*-1;}
    return out;
}