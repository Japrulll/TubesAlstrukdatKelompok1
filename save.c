#include <stdio.h>
#include <stdlib.h>
#include "save.h"

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