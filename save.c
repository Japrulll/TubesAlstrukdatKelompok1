#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void writeToFile(FILE *file, DinamicItemList *itemList, StaticUserList *userList){
    if (file != NULL){
        fprintf(file, "%d\n", itemList->count);
        for (int i = 0; i<itemList->count; i++){
            fprintf(file, "%d %s\n", itemList->items[i].price, itemList->items[i].name);
        }

        fprintf(file, "%d\n", userList->count);
        for (int i = 0; i<userList->count; i++){
            fprintf(file, "%d %s %s\n", userList->users[i].money, userList->users[i].name, userList->users[i].password);
        }
        printf("Save file berhasil disimpan.\n");
        fclose(file);
    } else {
        printf("File gagal disave.\n");
    }

}

/*fungsi ini untuk testing dengan add item dan add user, dan melihat apakah kesave atau tidak
void populateList(DinamicItemList *itemList, StaticUserList *userList){
    addItem(itemList, 100, "pikachu");
    addItem(itemList, 29, "pedang");
    addUser(userList, 100, "kazuha", "kaedehara");
}
*/

void savefilename(char* filename){
    char filepath[300];
    constructfilepath(filepath, "./save/", filename);
    DinamicItemList itemList;
    StaticUserList userList;
    initDinamicItemList(&itemList);
    initStaticUserList(&userList);
    //populateList(&itemList, &userList);
    FILE *file = fopen(filepath, "w");
    writeToFile(file, &itemList, &userList);
}

/*int main(){
    savefilename("genshin123.txt");

}
*/