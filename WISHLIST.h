#ifndef WISHLIST_H
#define WISHLIST_H

#include <stdio.h>
#include "./Folder ADT/ADTLinkedList.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTStack.h"

void WISHLISTADD (List *wishlist, DinamicItemList items);

void WISHLISTREMOVE (List *wishlist);

void WISHLISTSWAP (List *wishlist);

void WISHLISTCLEAR (List *wishlist);

void WISHLISTSHOW (List *wishlist);

#endif
