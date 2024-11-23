#ifndef FILE_NAME_H
#define FILE_NAME_H

#include <stdio.h>
#include <stdlib.h>
#include "user_item.h"

void writeToFile(FILE *file, DinamicItemList *itemList, StaticUserList *userList);
/*fungsi ini berfungsi untuk menyimpan data dari DinamicItemList dan StaticUserList ke file
ditulis detail barang dan detail user ke file*/

void savefilename(char* filename);
/*fungsi ini berfungsi untuk save file data*/

#endif