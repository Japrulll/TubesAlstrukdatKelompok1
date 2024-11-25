#include <stdio.h>
#include <stdlib.h>
#include "ADTItem.h"
#include "ADTFile.h"

void initDinamicItemList(DinamicItemList *list){
    list->capacity = 2;
    list->count = 0;
    list->items = (Barang*)malloc(list->capacity * sizeof(Barang));
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
