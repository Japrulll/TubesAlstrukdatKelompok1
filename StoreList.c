#include <stdio.h>
#include "barangdin.h"
#include "mesinkatajaprul.h"

void display(BarangDin list_barang){
    if (!IsEmpty(list_barang)){
        for (int i = 0; i < Length(list_barang); i++){
            printf("%d. %s %d", i+1, list_barang.A[i].name, list_barang.A[i].price);
        }
    }
} 

void store_request(Antrian *antrian_barang, BarangDin list_barang, ElType val){
    int i = 0;
    while (i < Length(list_barang)){
        if (list_barang.A[i].name == val.name){
            break;
        }
        i++;
    }
    if (i > length(*antrian_barang)){
        enqueue(antrian_barang, val);
    }
}

void store_supply(Antrian *antrian_barang, BarangDin list_barang){
    while(!isEmpty(*antrian_barang)){
        ElType *val;
        dequeue(antrian_barang,val);
        printf("Apakah kamu ingin menambahkan barang %s: ", val->name);
        STARTWORD();
        while(!EndWord){
            ADVWORD;
        }
        if (CurrentWord.TabWord == "Tunda"){
            enqueue(antrian_barang, *val);
            printf("%s dikembalikan ke antrian.", val->name);
        }
        else if (CurrentWord.TabWord == "Terima"){
            printf("Harga Barang : ");
            scanf("%d", val->price);
            InsertAt(&list_barang, *val, Length(list_barang) - 1);
        }
        else if (CurrentWord.TabWord == "Tolak"){
            printf("Barang Dihapus dari Antrian!");
        }
        else {
            printf("<Balik ke Menu>");
            break;
        }
    }
    if (isEmpty(*antrian_barang)){
        printf("Antrian Kosong!");
    }
}
void store_remove(BarangDin list_barang){
    int i = 0;
    STARTWORD();
    while(!EndWord){
        ADVWORD;
    }
    while(i < Length(list_barang) && list_barang.A[i].name != CurrentWord.TabWord){
        i++;
    }
    if (i < Length(list_barang) && list_barang.A[i].name == CurrentWord.TabWord){
        DeleteAt(&list_barang,i);
    }
    else printf("Toko tidak menjual %s",CurrentWord.TabWord);
}
