#include "Cart.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTSetMap.h"

#include <stdio.h>



void cartadd(Map *cart,DinamicItemList list,char *produk,int jumlah){
    if (isIn(list, produk)){
        valuetype prev = Value(*cart,produk);
        UpdateMap(cart,produk,jumlah+prev);
    }
    else{
        return;
    }
}

void cartremove(Map *cart,DinamicItemList list,char *produk,int jumlah){
    if (IsMemberMap(*cart,produk)){
        valuetype prev = Value(*cart,produk);
        UpdateMap(cart,produk,prev-jumlah);
        if (Value(*cart,produk) <=0){
            Delete(cart,produk);
        }
    }
}

void cartshow(Map cart,DinamicItemList list){
    int total = 0;
    for (int i = 0; i<cart.Count; i++){
        Barang tmpbar = list.items[GetIndex(list,cart.Elements[i].nama_item)];
        valuetype many = cart.Elements[i].qty;
        int multot = tmpbar.price * many;
        total += multot;
        printf("%d %s %d\n",many, tmpbar.name,multot);
        printf("yang harus dibayar adalah %d\n",total);
    }
    
}

int cartpay(Map cart,DinamicItemList list,int money){
    if (IsEmptyMap(cart)){
        printf("nothing here\n");
        return money;
    }
    int total = 0;
    for (int i = 0; i<cart.Count; i++){
        Barang tmpbar = list.items[GetIndex(list,cart.Elements[i].nama_item)];
        valuetype many = cart.Elements[i].qty;
        int multot = tmpbar.price * many;
        total += multot;
        printf("%d %s %d\n",many, tmpbar.name,multot);
        printf("yang harus dibayar adalah %d\n",total);
    }
    // input for pay what
    boolean pay;
    if(total>money){
        printf("no money\n");
    }
    else{
         return money-total;
    }
   
}

