#include <stdio.h>
#include "ADTSetMap.h"

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

void InsertMap(Map *M, keytype k, valuetype v){
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsMemberMap(*M,k)){
        int i = 0;
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




// int main(){
//     Map M;
//     CreateEmpty(&M);
//     Insert(&M, "anjay", 1);
//     Insert(&M, "koll", 4);
//     Insert(&M, "ak69", 3);
//     Insert(&M, "orkom", 5);
//     Insert(&M, "kyukurarin", 6);
//     printf("Panjang: %d\n",M.Count);

//     if (IsMember(M,"ak69")){
//             printf("yes bener\n");
//     }
//     else printf("gaada tai\n");
//     printf("ini element S.Count bukan yak : %d\n", M.Elements[M.Count].qty);
//     Delete(&M, "ak69");
//     for(int i = 0; i < M.Count; i++){
//             printf("%d ", M.Elements[i].qty);
//     }
// }