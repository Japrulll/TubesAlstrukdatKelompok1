#include <stdio.h>
#include "./Folder ADT/ADTLinkedList.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTStack.h"
#include "./Folder ADT/ADTItem.h"


void WISHLISTADD (List *wishlist, DinamicItemList items){
    char barang[100];
    printf("Masukkan nama barang yang ingin ditambah : ");
    STARTWORDBLANKS();
    while ( !EndWord ) {
        ADVWORDBLANKS();
    }

    for (int i=0;i<CurrentWord.Length;i++){
        barang[i] = CurrentWord.TabWord[i];
    }
    barang[CurrentWord.Length] = '\0';

    if(!isIn(items, barang)){
        printf("Tidak ada barang dengan nama %s\n",barang);
    }
    else{
        if (IsEmptyLL(*wishlist)){
            InsVFirst(wishlist,barang);
            addressLL P = First(*wishlist);
            printf("Berhasil menambahkan ");
            printf("%s", Info(P));
            printf(" ke dalam wishlist!\n");
        }
        else {
            if((SearchLL(*wishlist, barang))==NilList){
                InsVLast(wishlist,barang);
                addressLL P = SearchLL(*wishlist, barang);
                printf("Berhasil menambahkan ");
                printf("%s", Info(P));
                printf(" ke dalam wishlist.\n");
            }
            else{
                addressLL P = SearchLL(*wishlist, barang);
                printf("%s", Info(P));
                printf(" sudah ada di dalam wishlist!\n");
            }   
        }
    }
}


void WISHLISTREMOVE (List *wishlist){
    char barang[100];
    int indeks = 0;
    if(IsEmptyLL(*wishlist)){
        printf("Wishlist anda sudah kosong!\n");
    }
    else {
        if (EndWord){
            STARTWORDBLANKS();
        }
        while ( !EndWord ) {
            ADVWORDBLANKS();
        }

        indeks = StrToInt(CurrentWord.TabWord);
        
        if (indeks==-1){
            for (int i=0;i<CurrentWord.Length;i++){
                barang[i] = CurrentWord.TabWord[i];
            }
            barang[CurrentWord.Length] = '\0';    
        
            if((SearchLL(*wishlist, barang))==NilList){
                printf("Penghapusan gagal dilakukan! ");
                printf("%s", barang);
                printf(" tidak ditemukan di dalam wishlist.\n");
            }
            else{
                DelP(wishlist,barang);
                printf("%s", barang);
                printf(" berhasil dihapus dari wishlist!\n");
            }
        }
        
        else {
            while(indeks > NbElmt(*wishlist) || indeks < 1){
                printf("Masukkan indeks barang yang ingin dihapus : ");
                STARTWORDBLANKS();
                while ( !EndWord ) {
                    ADVWORDBLANKS();
                }
                indeks = StrToInt(CurrentWord.TabWord);
                if (indeks > NbElmt(*wishlist) || indeks < 1){
                    printf("Input anda tidak valid. Silakan ulang! ");
                }
            }
            addressLL P = First(*wishlist);
            int idx = 1;
            while (idx < indeks) {
                P = Next(P);
                idx++;
            }
            printf("%s", Info(P));
            printf(" berhasil dihapus dari wishlist!\n");
            DelP(wishlist,Info(P));
        }
    }
}


void WISHLISTSWAP (List *wishlist){
    int i=0,j=0,k=0;

    if(NbElmt(*wishlist) == 1 || NbElmt(*wishlist) == 0){
        printf("Anda tidak dapat melakukan wishlist swap saat ini\n");
        printf("karena wishlist anda kosong atau hanya berisi 1 barang!\n");
    }
    else{

        AS_WORD();
        if (!EndWord) {
            i = StrToInt(CurrentWord.TabWord);
            ADVWORD();
            j = StrToInt(CurrentWord.TabWord);
        }

        if(i>NbElmt(*wishlist) || i<1 || j>NbElmt(*wishlist) || j<1){
            printf("indeks i atau j atau keduanya tidak valid.\n");
            return;
        }
        else {
            addressLL P1 = First(*wishlist);
            addressLL P2 = First(*wishlist);
            int idx = 1;
            // Cari elemen ke-i
            while (P1 != NilList && idx < i) {
                P1 = Next(P1);
                idx++;
            }
            // Reset indeks dan cari elemen ke-j
            idx = 1;
            while (P2 != NilList && idx < j) {
                P2 = Next(P2);
                idx++;
            }
            char temp[100];
            int k;
            for (k = 0; k < 100; k++) {
                temp[k] = P1->info[k];
            }
            for (k = 0; k < 100; k++) {
                P1->info[k] = P2->info[k];
            }
            for (k = 0; k < 100; k++) {
                P2->info[k] = temp[k];
            }
            printf("Berhasil menukar barang pada indeks %d dan %d!\n", i, j);
        }
    }
}


void WISHLISTCLEAR (List *wishlist){
    CreateEmptyLL (wishlist);
    printf("Wishlist telah dikosongkan!\n");
}


void WISHLISTSHOW (List *wishlist){
    if (IsEmptyLL(*wishlist)){
        printf("Wishlist kamu kosong!\n");
    }
    else{
        addressLL P = First(*wishlist);
        int nomor=1;
        printf("Berikut ini adalah isi wishlist kamu: \n");
        while (P != NilList){
            printf("%d ",nomor);
            printf("%s\n", Info(P));
            nomor++;
            P = Next(P);
        }
    }
}


/*
int main(){
    List wishlist;

    DinamicItemList Items;
    initDinamicItemList(&Items);
    addItem(&Items, 20, "AK47");
    addItem(&Items, 20, "Lalabu");
    addItem(&Items, 20, "Ayam Goreng Crisbar");
    addItem(&Items, 20, "Ayam Katsu Spesial");
    addItem(&Items, 20, "Ice Tea");

    CreateEmptyLL (&wishlist);
    int mulai = 1;
    while (mulai==1){
        int masukan;
        printf("mau apa? : ");
        scanf("%d",&masukan);
        getchar();
        if (masukan==1){
            WISHLISTADD (&wishlist,Items);
        }
        else if (masukan==2){
            WISHLISTREMOVE (&wishlist);
        }
        else if (masukan==3){
            WISHLISTSHOW (&wishlist);
        }
        else if (masukan==4){
            WISHLISTSWAP (&wishlist);
        }
        else if (masukan==4){
            mulai = 0;
        }
        else{
            printf("input tidak valid. Masukkan ulang!");
            mulai=0;
        }
    }

    return 0;
}
*/
