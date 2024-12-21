#include <stdio.h>
#include "ADTMap.h"
#include "ADTUser.h"
#include "ADTFile.h"

void copy_string(char *from, char *to) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}
boolean string_compare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') { // Bandingkan karakter demi karakter
        if (str1[i] != str2[i]) {
            return false; // Jika ada karakter berbeda, return false (0)
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0'); // True jika panjang sama dan semua karakter cocok
}

void CreateEmptyMap(Map *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
    (*M).Count = NilMap;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return (M.Count == NilMap);
}
boolean IsFullMap(Map M){
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return (M.Count == 100);
}
/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    int i = 0;
    while (i < M.Count){
        if (string_compare(k,M.Elements[i].nama_item)){
            return M.Elements[i].qty;
        }
        i++;
    }
    return Undefined;
}
boolean IsMemberMap(Map M, keytype k){
/* Mengembalikan true jika k adalah member dari M */
    int i = 0;
    while (i < M.Count ){
        if (string_compare(k,M.Elements[i].nama_item) ){
            return true;
        }
        i++;
    }
    return false;
}

void InsertMap(Map *M, keytype k, valuetype v){
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMemberMap(*M,k)){
        //int i = 0;
        copy_string(k, (*M).Elements[(*M).Count].nama_item);
        (*M).Elements[(*M).Count].qty = v;
        (*M).Count += 1;
    }
}

void DeleteMap(Map *M, keytype k){
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    if (IsMemberMap(*M,k)){
        int i = 0;
        while (!string_compare(k,(*M).Elements[i].nama_item)){
            i++;
        }
        for (int z = i; z < (*M).Count; z++){
            (*M).Elements[z].qty = (*M).Elements[z+1].qty;
            copy_string((*M).Elements[z+1].nama_item, (*M).Elements[z].nama_item);
        }
        (*M).Count -= 1;
    }
}



void UpdateMap(Map *M, keytype k, valuetype v){
    addressMap idx = 0;
    boolean isin = false;  
    while (idx < M->Count) {
        if (string_compare(M->Elements[idx].nama_item,k)) {
            M->Elements[idx].qty = v;
            isin = true;
        }
        idx++;
    }
    if (!isin && (*M).Count < 100 /*maxel*/){
        copy_string(k,M->Elements[M->Count].nama_item);
        // M->Elements[M->Count].Key = k;

        M->Elements[M->Count].qty = v;
        M->Count++;
    }    
}

void bubbleSort_Map(Map *map){
    for (int i = 0; i < map->Count; i++){
        for (int j = 0; j < map->Count-i-1; j++){
            if (map->Elements[j].qty < map->Elements[j+1].qty){
                infotype temp = map->Elements[j];
                map->Elements[j] = map->Elements[j+1];
                map->Elements[j+1] = temp;
            }
            else if (map->Elements[j].qty == map->Elements[j+1].qty){
                if     ((map->Elements[j].nama_item[0] >= 97 && map->Elements[j].nama_item[0] <= 122) 
                    && (map->Elements[j+1].nama_item[0] >= 65 && map->Elements[j].nama_item[0] <= 90)){
                        int char_to_upper = map->Elements[j].nama_item[0] - 97 + 65;
                    if (char_to_upper > map->Elements[j+1].nama_item[0]){
                        infotype temp = map->Elements[j];
                        map->Elements[j] = map->Elements[j+1];
                        map->Elements[j+1] = temp;
                    }
                }
                else if ((map->Elements[j].nama_item[0] >= 65 && map->Elements[j].nama_item[0] <= 90) 
                    &&  (map->Elements[j+1].nama_item[0] >= 97 && map->Elements[j].nama_item[0] <= 122)){
                        int char_to_upper = map->Elements[j+1].nama_item[0] - 97 + 65;
                        if (char_to_upper < map->Elements[j].nama_item[0]){
                        infotype temp = map->Elements[j+1];
                        map->Elements[j+1] = map->Elements[j];
                        map->Elements[j] = temp;
                         
                    }
                }
                else {
                    if (map->Elements[j].nama_item[0] > map->Elements[j+1].nama_item[0]){
                        infotype temp = map->Elements[j];
                        map->Elements[j] = map->Elements[j+1];
                        map->Elements[j+1] = temp;
                    }
                }
            }
        }
    }
}



// int main(){
//     Map M;
//     CreateEmptyMap(&M);
//     InsertMap(&M, "anjay", 1);
//     InsertMap(&M, "koll", 4);
//     InsertMap(&M, "ak69", 3);
//     InsertMap(&M, "orkom", 6);
//     InsertMap(&M, "Kyukurarin", 6);
//     printf("Panjang: %d\n",M.Count);

//     if (IsMemberMap(M,"ak69")){
//             printf("yes bener\n");
//     }
//     else printf("gaada tai\n");
//     printf("ini element S.Count bukan yak : %d\n", M.Elements[M.Count].qty);
//     DeleteMap(&M, "ak69");
//     for(int i = 0; i < M.Count; i++){
//             printf("%s %d\n",M.Elements[i].nama_item, M.Elements[i].qty);
//     }
//     printf("sekarang bubble\n");
//     bubbleSort_Map(&M);
//     for(int i = 0; i < M.Count; i++){
//             printf("%s %d\n",M.Elements[i].nama_item, M.Elements[i].qty);
//     }
// }