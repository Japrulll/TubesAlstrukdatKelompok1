#include <stdio.h>
#include <stdlib.h>
#include "ADTUser.h"
#include "ADTFile.h"
#include "ADTStack.h"
void initStaticUserList(StaticUserList *list){
    list->count = 0;
}

void addUser(StaticUserList *list, int money, char*name, char*password, Stack * riwayat_pembelian, List*wishlist){
    if(list->count < 100){
        list->users[list->count].money = money;
        copyString(name, list->users[list->count].name);
        copyString(password, list->users[list->count].password);
        CreateEmptyS(&list->users[list->count].riwayat_pembelian);
        copyStack(&list->users[list->count].riwayat_pembelian, riwayat_pembelian);
        CreateEmptyLL(&list->users[list->count].wishlist);
        list->users[list->count].wishlist.First = wishlist->First;
        list->count++;
    }
    else{
        printf("error user list sudah penuh.\n");
    }
}

