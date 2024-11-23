#include <stdio.h>
#include <stdlib.h>
#include "user_item.h"

void copyString(char* src, char* dest){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void initStaticUserList(StaticUserList *list){
    list->count = 0;
}

void initDinamicItemList(DinamicItemList *list){
    list->capacity = 2;
    list->count = 0;
    list->items = (Barang*)malloc(list->capacity * sizeof(Barang));
}


void addUser(StaticUserList *list, int money, char*name, char*password){
    if(list->count < 100){
        list->users[list->count].money = money;
        copyString(name, list->users[list->count].name);
        copyString(password, list->users[list->count].password);
        list->count++;
    }
    else{
        printf("error user list sudah penuh.\n");
    }
}


void addItem(DinamicItemList *list, int price, char*name){
    if(list->count == list->capacity){
        list->capacity *= 2;
        list->items = (Barang*)realloc(list->items, list->capacity * sizeof(Barang));
    }
    list->items[list->count].price = price;
    copyString(name, list->items[list->count].name);
    list->count++;
}


void freeDinamicItemList(DinamicItemList *list){
    free(list->items);
    list->items = NULL;
    list->capacity = 0;
    list->count = 0;
}

void display(DinamicItemList *itemlist, StaticUserList *userlist){
    for (int i = 0; i < itemlist->count; i++){
        printf("%d %s\n", itemlist->items[i].price, itemlist->items[i].name);
    }
    for (int i = 0; i < userlist->count; i++){
        printf("%d %s %s\n", userlist->users[i].money, userlist->users[i].name, userlist->users[i].password);
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