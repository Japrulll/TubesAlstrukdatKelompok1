#ifndef STORELIST_H
#define STORELIST_H

#include "./Folder ADT/queue.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTItem.h"

void store_display(DinamicItemList list_barang);

void store_request(Antrian *antrian_barang, DinamicItemList list_barang);

void store_request(Antrian *antrian_barang, DinamicItemList list_barang);

void store_supply(Antrian *antrian_barang, DinamicItemList *list_barang);

void store_remove(DinamicItemList *list_barang);


#endif