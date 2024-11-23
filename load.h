#ifndef FILE_NAME_H
#define FILE_NAME_H

#include <stdio.h>
#include <stdlib.h>
#include "user_item.h"

void loadFile(char*filename);
/*membaca file dengan nama file yang diberikan parameter filename. 
  I.S. File dengan nama yang diberikan di parameter filename mungkin tersedia di sistem, tetapi belum dibaca
  F.S. Apabila berhasil membaca file dengan nama file yang diberikan parameter filename, 
       maka akan diberitahu bahwa save file berhasil terbaca.
       Apabila tidak berhasil, maka akan diberitahu bahwa save file tidak berhasil terbaca.*/

#endif