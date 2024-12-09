#ifndef LOAD_H
#define LOAD_H

#include <stdio.h>
#include <stdlib.h>
#include "./Folder ADT/ADTUser.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTFile.h"

void loadFile(char*filename,DinamicItemList *itemList,StaticUserList *userList);
/*membaca file dengan nama file yang diberikan parameter filename. 
  I.S. File dengan nama yang diberikan di parameter filename mungkin tersedia di sistem, tetapi belum dibaca
  F.S. Apabila berhasil membaca file dengan nama file yang diberikan parameter filename, 
       maka akan diberitahu bahwa save file berhasil terbaca.
       Apabila tidak berhasil, maka akan diberitahu bahwa save file tidak berhasil terbaca.*/

#endif