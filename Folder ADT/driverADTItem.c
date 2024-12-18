#include <stdio.h>
#include <stdlib.h>
#include "ADTItem.h"
#include "ADTFile.h"
#include "ADTStack.h"
#include "ADTLinkedList.h"
#include "boolean.h"


//Fungsi ini hanya untuk debug, untuk mencetak isi list
void printItemList(DinamicItemList list) {
    if (IsEmpty(list)) {
        printf("List kosong.\n");
        return;
    }
    for (int i = 0; i < list.count; i++) {
        printf("Item %d: Nama = %s, Harga = %d\n", i, list.items[i].name, list.items[i].price);
    }
    printf("\n");
}

int main() {
    DinamicItemList itemList;
    Barang item;

    printf("---uji fungsi initDinamicItemList---\n");
    initDinamicItemList(&itemList);
    printf("List diinisialisasi dengan kapasitas: %d\n", itemList.capacity); //kapasitas awal adalah 2
    printf("Jumlah item: %d\n", itemList.count); //akan print 0 karena belum add item

    printf("\n");

    printf("---uji fungsi IsEmpty---\n");
    printItemList(itemList);
    if(IsEmpty(itemList)){
        printf("IsEmpty: True, list kosong\n"); //akan print isEmpty True karena list kosong
    }
    else{
        printf("IsEmpty: False, list tidak kosong\n");
    }

    printf("\n");

    printf("---uji fungsi addItem---\n");
    addItem(&itemList, 100, "Dango Milk");
    addItem(&itemList, 250, "Sweet Madame");
    addItem(&itemList, 500, "Almond Tofu");
    printf("Item berhasil ditambahkan:\n");
    printItemList(itemList); 
    //Item 0: Nama = Dango Milk, Harga = 100
    //Item 1: Nama = Sweet Madame, Harga = 250
    //Item 2: Nama = Almond Tofu, Harga = 500

    printf("---uji fungsi Length dan IsEmpty---\n");
    printf("Jumlah item dalam list: %d\n", Length(itemList)); //akan printf 3 karena di dalam list sudah terdapat 3 item
    if(IsEmpty(itemList)){
        printf("IsEmpty: True, list kosong\n");
    }
    else{
        printf("IsEmpty: False, list tidak kosong\n"); //akan print IsEmpty False karena sudah ada item pada list
    }

    printf("\n");

    printf("---uji fungsi isIn---\n");
    if (isIn("Almond Tofu", itemList)){
        printf("Apakah ada 'Almond Tofu' dalam list? : Ada\n");//akan print bagian ini karena Almond Tofu terdapat dalam list
    }
    else{
        printf("Apakah ada 'Almond Tofu' dalam list? : Tidak ada\n");
    }
    if (isIn("Onigiri", itemList)){
        printf("Apakah ada 'Onigiri' dalam list? : Ya\n");
    }
    else{
        printf("Apakah ada 'Onigiri' dalam list? : Tidak ada\n");//akan print bagian ini karena Onigiri TIDAK terdapat dalam list
    }

    printf("\n");

    printf("---uji fungsi InsertAt---\n");
    item.price = 300;
    copyString("Mint Salad", item.name);
    InsertAt(&itemList, item, 1); //insert di bagian index 1
    printf("Setelah melakukan insertAt pada index 1:\n"); 
    printItemList(itemList);//Item 1: Mint Salad, Item 2: Sweet Madame, dst.


    printf("---uji fungsi DeleteAt---\n");
    DeleteAt(&itemList, 2); //delete item pada index 2, yaitu Sweet Madame
    printf("Setelah menghapus item pada index 2:\n");
    printItemList(itemList); //item 0: dango milk, item 1: mint salad, item 2: almond tofu, item sweet madame dihapus


    printf("---uji freeDinamicItemList---\n");
    freeDinamicItemList(&itemList);
    printf("List berhasil dibebaskan memory sehingga Kapasitas: %d, Jumlah item: %d\n\n", itemList.capacity, itemList.count); //kapasitas 0, jumlah item 0

    return 0;
}