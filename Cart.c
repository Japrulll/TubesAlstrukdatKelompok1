#include "Cart.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/map.h"

#include <stdio.h>



void cartadd(Map *cart,DinamicItemList list,char *produk,int jumlah){
    if (isIn(list,produk)){
        valuetype prev = Value(*cart,produk);
        Update(cart,produk,jumlah+prev);
    }
    else{
        return;
    }
}

void cartremove(Map *cart,DinamicItemList list,char *produk,int jumlah){
    if (IsMember(*cart,produk)){
        valuetype prev = Value(*cart,produk);
        Update(cart,produk,prev-jumlah);
        if (Value(*cart,produk) <=0){
            Delete(cart,produk);
        }
    }
}

void cartshow(Map cart,DinamicItemList list){
    valuetype many;
    Barang tmpbar;
    for (int i = 0; i<cart.Count; i++){
        tmpbar = getBarang(list,cart.Elements[i].Key);
        many = cart.Elements[i].Value;
        printf("%d %s %d\n",many, tmpbar.name,tmpbar.price * many);
    }
}

int cartpay(Map *cart,DinamicItemList list,int money){
    if (IsEmptymap(*cart)){
        printf("nothing here\n");
        return money;
    }
    int total=0;
    valuetype many;
    Barang tmpbar;
    for (int i = 0; i<(*cart).Count; i++){
        total += tmpbar.price * many;
        tmpbar = getBarang(list,(*cart).Elements[i].Key);
        many = (*cart).Elements[i].Value;
        printf("%d %s %d\n",many, tmpbar.name,tmpbar.price * many);
    }
    printf("%d\n",total);

    // input for pay what
    boolean pay;
    if(total>money){
        printf("no money\n");
    }
    else{
         return money-total;
    }
   
}

