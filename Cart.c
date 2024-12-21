#include "Cartj.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTSetMap.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/ADTStack.h"
#include "./Folder ADT/ADTFile.h"
#include <stdio.h>



void cartadd(Map *cart,DinamicItemList list,char *produk,int jumlah){
    if (isIn(list,produk)){
        valuetype prev = Value(*cart,produk);
        UpdateMap(cart,produk,jumlah+prev);
        printf("barang berhasi ditambahkan ke keranjang\n");
    }
    else{
        printf("barang gagal\n");
        return;
    }
}

void cartremove(Map *cart,DinamicItemList list,char *produk,int jumlah){
    if (IsMemberMap(*cart,produk)){
        valuetype prev = Value(*cart,produk);
        UpdateMap(cart,produk,prev-jumlah);
        if (Value(*cart,produk) <=0){
            DeleteMap(cart,produk);
        }
    }
}

void cartshow(Map *cart,DinamicItemList list){
    int total = 0;
    Barang tmpbar;
    valuetype many;
    int multot;
    bubbleSort_Map(cart);
    for (int i = 0; i<(*cart).Count; i++){
        tmpbar = list.items[GetIndex(list,(*cart).Elements[i].nama_item)];
        many = (*cart).Elements[i].qty;
        multot = tmpbar.price * many;
        total += multot;
        printf("%d %s %d\n",many, tmpbar.name,multot);
    }
    printf("yang harus dibayar adalah %d\n",total);
    
}

int cartpay(Map *cart,DinamicItemList list,Stack *out,int money){
    if (IsEmptyMap(*cart)){
        printf("nothing here\n");
        return money;
    }
    int total = 0;
    int compare = -999;
    bubbleSort_Map(cart);
    Barang tmpbar;
    valuetype many;
    for (int i = 0; i<(*cart).Count; i++){
        tmpbar = list.items[GetIndex(list,(*cart).Elements[i].nama_item)];
        many = (*cart).Elements[i].qty;
        int multot = tmpbar.price * many;
        total += multot;
        if (multot > compare){
            compare = multot;
        }
        printf("%d %s %d\n",many, tmpbar.name,multot);   
    }
    printf("yang harus dibayar adalah %d\n",total);
    // input for pay what
    boolean pay;
    if(total>money){
        printf("no money\n");
        return money;
    }
    else{  
        printf("confirm payment (y/n)]\n");
        AS_WORD();
        if (CurrentWord.TabWord[0] == 'y'){
            CreateEmptyMap(cart);
            Push(out, compare, (*cart).Elements[0].nama_item);
            return money-total;
            
        }
        else{
            return money;
        }
    }
    
   
}
