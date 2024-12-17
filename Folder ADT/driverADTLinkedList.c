#include <stdio.h>
#include <stdlib.h>
#include "ADTFile.h"
#include "ADTLinkedList.h"
#include "boolean.h"
#include "ADTStack.h"

int main(){
    List l1;
    CreateEmptyLL(&l1);
    printf("isEmpty: %d\n", IsEmptyLL(l1)); //akan print 1
    InsVLast(&l1, "item1");
    InsVLast(&l1, "item2");
    InsVFirst(&l1, "item3");
    PrintInfoDebug(l1); //[item3, item1, item2]
    address newNode = AlokasiLL("item4");
    address p = SearchLL(l1, "item1");
    InsertAfter(&l1, newNode, p);
    PrintInfoDebug(l1); //[item3, item1, item4, item2]
    
    printf("Jumlah elemen dalam list: %d\n", NbElmt(l1));//output 4

    address searchResult = SearchLL(l1, "item4");
    if (searchResult != Nil) {
        printf("item ditemukan di list.\n"); //karena item4 terdapat pada list, maka akan print bahwa item ditemukan
    } else {
        printf("item tidak ditemukan di list.\n");
    }

    searchResult = SearchLL(l1, "item5");
    if (searchResult != Nil) {
        printf("item ditemukan di list.\n");
    } else {
        printf("item tidak ditemukan di list.\n"); //karena item5 TIDAK terdapat pada list, maka akan print item tidak ditemukan
    }
    char deletedItem[10];
    DelVFirst(&l1, deletedItem);
    printf("Elemen pertama yang dihapus: %s\n", deletedItem);//delete item3
    PrintInfoDebug(l1); //[item1, item4, item2]

    DelVLast(&l1, deletedItem);
    printf("Elemen terakhir yang dihapus: %s\n", deletedItem); //delete item2
    PrintInfoDebug(l1);//[item1, item4]

    DelP(&l1, "item1"); //delete item1
    printf("Elemen yang dihapus adalah elemen: item1\n"); //delete item1
    PrintInfoDebug(l1);// [item4]

    printf("isEmpty: %d\n", IsEmptyLL(l1)); //akan print 0 karena di dalam list tidak kosong, ada item4 -> isempty? -> False    
    

    FILE *file;
    List l2;
    CreateEmptyLL(&l2);
    InsVFirst(&l2, "item_satu");
    InsVLast(&l2, "item_tiga");
    InsVLast(&l2, "item_lima");
    InsVFirst(&l2, "item_tujuh");

    PrintInfoDebug(l2); //[item_tujuh, item_satu, item_tiga, item_lima]

    file = fopen("ujicoba.txt", "w");
    if (file == NULL){
        printf("File gagal dibuka\n");
        return 1;
    }
    PrintInfo(l2, file);
    fclose(file);
    printf("Isi dalam list telah dicetak ke file 'ujicoba.txt'\n");


    return 0;
}