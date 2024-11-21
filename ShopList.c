#include <stdio.h>
// #include "list.h"
// #include "mesinkata.h"
#include "ShopList.h"


void display_list(char *path){
    FILE *items = fopen(path,"r");
    if (items == NULL){
        printf("Barang Tidak Tersedia");
        return;
    }
    Barang L;
    int retval = fscanf(items,"%s %d", L.name, &L.price);
    while (retval != EOF){
        printf("- %s (Rp %d)\n", L.name, L.price);
        retval = fscanf(items,"%s %d", L.name, &L.price);
    }
    fclose(items);
}

// int main() {
//     // Path file sebagai input
//     char path[] = "Barang.txt";
//     display_list(path);
//     return 0;
// }