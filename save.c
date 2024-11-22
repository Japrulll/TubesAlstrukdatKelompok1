#include <stdio.h>
#include <stdlib.h>
#include "save.h"

/*fungsi copyString berfungsi untuk menyalin string dari source ke destination
sebagai pengganti strcpy*/
void copyString(char* src, char* dest){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


/*fungsi iniStaticUserList berfungsi untuk menginisialisasi
struktur data StaticUserList, dibuat daftar kosong*/
void initStaticUserList(StaticUserList *list){
    list->count = 0;
}

/*fungsi initDinamicItemList berfungsi untuk menginisialisasi
struktur data DinamicItemList dengan keterangan mengalokasikan
memori awal array items dengan kapasitas awal 2 dan count 0*/
void initDinamicItemList(DinamicItemList *list){
    list->capacity = 2;
    list->count = 0;
    list->items = (Barang*)malloc(list->capacity * sizeof(Barang));
}

/*fungsi addUser berfungsi untuk menambahkan user baru ke dalam StaticUserList
dengan memastikan jumlah pengguna tidak melebihi batas yang sudah di-define (MAX_LEN)
dan menyimpan data money,name,dan password ke dalam struktur User yang ada di array users*/
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

/*fungsi addItem berfungsi untuk menambahkan barang ke dalam DinamicItemList
jika count barang melebihi kapasitas maka akan diperbesar ukuran array dengan cara 
reallocate */
void addItem(DinamicItemList *list, int price, char*name){
    if(list->count == list->capacity){
        list->capacity *= 2;
        list->items = (Barang*)realloc(list->items, list->capacity * sizeof(Barang));
    }
    list->items[list->count].price = price;
    copyString(name, list->items[list->count].name);
    list->count++;
}

/*fungsi freeDinamicItemList berfungsi untuk menghapus memori yang telah dialokasikan
secara dinamis untuk DinamicItemList, supaya memorinya tidak terbuang sia-sia dan bisa digunakan lagi*/
void freeDinamicItemList(DinamicItemList *list){
    free(list->items);
    list->items = NULL;
    list->capacity = 0;
    list->count = 0;
}
//fungsi constructfilepath berfungsi untuk menggabungkan dua string dan membentuk path file*/
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


/*fungsi untuk menampilkan isi daftar barang dan user ke layar*/
void display(DinamicItemList *itemlist, StaticUserList *userlist){
    for (int i = 0; i < itemlist->count; i++){
        printf("%d %s\n", itemlist->items[i].price, itemlist->items[i].name);
    }
    for (int i = 0; i < userlist->count; i++){
        printf("%d %s %s\n", userlist->users[i].money, userlist->users[i].name, userlist->users[i].password);
    }
}


/*fungsi readline berfungsi untuk membaca file ke buffer string*/
void readline(FILE *file, char *buffer){
    int i = 0;
    char c;
    while((c = fgetc(file))!= EOF && c != '\n'){
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
}

/*fungsi ini berfungsi untuk menyimpan data dari DinamicItemList dan StaticUserList ke file
ditulis detail barang dan detail user ke file*/
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


/*fungsi ini berfungsi untuk save file data*/
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