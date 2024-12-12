#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "./Folder ADT/ADTUser.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTLinkedList.h"
#include "./Folder ADT/ADTStack.h"


void loadFile(char*filename,DinamicItemList *itemList,StaticUserList *userList){
    char filepath[300];
    constructfilepath(filepath, "./save/", filename);

    initDinamicItemList(itemList);
    initStaticUserList(userList);
    FILE *file = fopen(filepath, "r");
    if (file != NULL){
        
        //bagian ini adalah hanya testing untuk melihat apakah semua isi dalam file sudah terbaca atau tidak
        int itemCount;
        int userCount;
        fscanf(file, "%d", &itemCount);
        for(int i = 0; i < itemCount; i++){
            int price;
            char name[MAX_LEN];
            fscanf(file, "%d", &price);
            fgetc(file);
            readline(file, name);
            addItem(itemList, price, name);
        }
        //display(itemList, userList);
        fscanf(file, "%d", &userCount);
        for (int i = 0; i < userCount; i++){
            int money;
            char user[MAX_LEN];
            char pass[MAX_LEN];
            int riwayatCount;
            int wishlistCount;
            int riwayatHarga;
            char riwayatBarang[MAX_LEN];
            char wishlistBarang[MAX_LEN];
            Stack riwayat;
            List wishlist;
            CreateEmptyLL(&wishlist);
            CreateEmptyS(&riwayat);
            fscanf(file, "%d %s %s", &money, user, pass);
            //printf("%d %s %s\n", money, user, pass);
            fscanf(file, "%d", &riwayatCount);
            for (int j = 0; j < riwayatCount; j++){
                fscanf(file, "%d", &riwayatHarga);
                fgetc(file);
                readline(file, riwayatBarang);
                printf("%d %s\n", riwayatHarga, riwayatBarang);
                Push(&riwayat, riwayatHarga, riwayatBarang);
            }
            printStack(&riwayat);
            fscanf(file, "%d", &wishlistCount);
            fgetc(file);
            for (int j = 0; j < wishlistCount; j++){
                readline(file, wishlistBarang);
                printf("%s\n", wishlistBarang);
                InsVLast(&wishlist, wishlistBarang);
            }
            PrintInfo(wishlist);
            addUser(userList, money, user, pass, &riwayat, &wishlist);
        }
        
        
       // display(itemList, userList);
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        //freeDinamicItemList(itemList);
        fclose(file);
    }
    else{
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
    }

}



int main(){
    char input[MAX_LEN];
    char namafile[MAX_LEN];
    readline(stdin, input);
    int i = 0;
    while(input[i] != ' '){
        i++;
    }
    i++;
    int j = 0;
    while(input[i] != '\0'){
        namafile[j] = input[i];
        j++;
        i++;
    }
    namafile[j] = '\0';
    //printf("%s", namafile);
    StaticUserList userList;
    DinamicItemList itemList;
    loadFile(namafile, &itemList, &userList);
}
