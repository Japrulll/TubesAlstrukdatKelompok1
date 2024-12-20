#ifndef CART_H
#define CART_H
#include "./Folder ADT/ADTSetMap.h"
#include "./Folder ADT/ADTItem.h"

#include <stdio.h>

// add to cart with num
void cartadd(Map *cart,DinamicItemList list,char *produk,int jumlah);

// remove stuff from cart with num
void cartremove(Map *cart,DinamicItemList list,char *produk,int jumlah);

// show cart
void cartshow(Map cart,DinamicItemList list);

// give pay stuff
int cartpay(Map *cart,DinamicItemList list,int money);

#endif