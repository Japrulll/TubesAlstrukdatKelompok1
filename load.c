#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct {
    User users[MAX_LEN];
    int count;
} StaticUserList;

typedef struct {
    Barang *items;
    int count;
    int capacity;
} DinamicItemList;


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

/*fungsi constructfilepath berfungsi untuk menggabungkan dua string dan membentuk path file*/
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

/*fungsi ini berfungsi untuk membaca file dengan nama file yang diberikan
parameter filename. Apabila berhasil, maka akan diberitahu bahwa save file berhasil terbaca.
Apabila tidak berhasil, maka akan diberitahu bahwa save file tidak berhasil terbaca.*/
void loadFile(char*filename){
    char filepath[300];
    constructfilepath(filepath, "./save/", filename);
    DinamicItemList itemList;
    StaticUserList userList;
    initDinamicItemList(&itemList);
    initStaticUserList(&userList);
    FILE *file = fopen(filepath, "r");
    if (file != NULL){
        
        //bagian ini adalah hanya testing untuk melihat apakah semua isi dalam file sudah terbaca atau tidak
        /*int itemCount;
        int userCount;
        fscanf(file, "%d", &itemCount);
        for(int i = 0; i < itemCount; i++){
            int price;
            char name[MAX_LEN];
            fscanf(file, "%d", &price);
            fgetc(file);
            readline(file, name);
            addItem(&itemList, price, name);
        }
        fscanf(file, "%d", &userCount);
        for (int i = 0; i < userCount; i++){
            int money;
            char user[MAX_LEN];
            char pass[MAX_LEN];
            fscanf(file, "%d %s %s", &money, user, pass);
            addUser(&userList, money, user, pass);
        }
        */
        display(&itemList, &userList);
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        fclose(file);
    }
    else{
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
    }

}



/*int main(){
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
    loadFile(namafile);
}*/