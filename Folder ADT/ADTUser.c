#include <stdio.h>
#include <stdlib.h>
#include "ADTUser.h"
#include "ADTFile.h"
void initStaticUserList(StaticUserList *list){
    list->count = 0;
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

