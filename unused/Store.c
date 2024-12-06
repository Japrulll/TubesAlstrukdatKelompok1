#include <stdio.h>
#include "Store.h"

int CharToInt() {
    int tebak = 0;
 
    STARTWORD();
    while ( !EndWord ) {
        ADVWORD();
    }
 
    for (int i=0; i<CurrentWord.Length;i++) {
        if (CurrentWord.TabWord[i]<'0' || CurrentWord.TabWord[i]>'9' ){
            return -1;
        }
        tebak = tebak * 10 + (CurrentWord.TabWord[i] - '0');
    }
    return tebak;
}

void display_barang(DinamicItemList list_barang){
    if (!IsEmpty(list_barang)){
        for (int i = 0; i < Length(list_barang); i++){
            printf("%d. %s %d\n", i+1, list_barang.items[i].name, list_barang.items[i].price);
        }
    }
} 

void store_request(Antrian *antrian_barang, DinamicItemList list_barang) {
    printf("Nama barang yang diminta: ");
    STARTWORD();
    while (!EndWord) {
        ADVWORD();
    }

    if (isIn(CurrentWord, list_barang)) {
        printf("Barang %.*s sudah ada di store!\n", CurrentWord.Length, CurrentWord.TabWord);
    } else {
        Barang new_item;
        for (int i = 0; i < CurrentWord.Length; i++) {
            new_item.name[i] = CurrentWord.TabWord[i];
        }
        new_item.name[CurrentWord.Length] = '\0'; 
        new_item.price = -1;
        enqueue(antrian_barang, new_item);
        printf("Barang %.*s telah ditambahkan ke antrean.\n", CurrentWord.Length, CurrentWord.TabWord);
    }
}

void store_supply(Antrian *antrian_barang, DinamicItemList *list_barang) {
    while (!IsEmptyQ(*antrian_barang)) {
        Barang val;
        dequeue(antrian_barang, &val);

        printf("Apakah kamu ingin menambahkan barang %s (Tunda/Terima/Tolak)? ", val.name);
        STARTWORD();
        while (!EndWord) {
            ADVWORD();
        }

        if (isWordEqual(CurrentWord, "Tunda")) {
            enqueue(antrian_barang, val);
            printf("%s dikembalikan ke antrian.\n", val.name);
        } else if (isWordEqual(CurrentWord, "Terima")) {
            printf("Harga Barang: ");
            val.price = CharToInt();
            InsertAt(list_barang, val, list_barang->count);
        } else if (isWordEqual(CurrentWord, "Tolak")) {
            printf("Barang %s Dihapus dari Antrian!\n", val.name);
        } else {
            enqueue(antrian_barang, val);
            printf("Kembali ke menu.\n");
            break;
        }
    }

    if (IsEmptyQ(*antrian_barang)) {
        printf("Antrian Kosong!\n");
    }
}

void store_remove(DinamicItemList *list_barang) {
    int i = 0;
    STARTWORD();
    while (!EndWord) {
        ADVWORD();
    }

    while (i < Length(*list_barang)) {
        if (isWordEqual(CurrentWord, (*list_barang).items[i].name)) {
            break;
        }
        i++;
    }

    if (i < Length(*list_barang)) {
        DeleteAt(list_barang, i);
        printf("Barang %.*s berhasil dihapus.\n", CurrentWord.Length, CurrentWord.TabWord);
    } else {
        printf("Toko tidak menjual %.*s\n", CurrentWord.Length, CurrentWord.TabWord);
    }
}

// int main() {
//     DinamicItemList list_barang = MakeDinamicItemList(); // Membuat list barang kosong
//     Antrian antrian_barang;                  // Membuat antrian barang kosong
//     CreateQueue(&antrian_barang);       // Inisialisasi antrian

//     // Menambahkan 3 barang ke dalam store
//     Barang barang1 = {"Laptop", 5000000};
//     Barang barang2 = {"Smartphone", 3000000};
//     Barang barang3 = {"Headphone", 1000000};
//     InsertAt(&list_barang, barang1, list_barang.count);
//     InsertAt(&list_barang, barang2, list_barang.count);
//     InsertAt(&list_barang, barang3, list_barang.count);
//     printf(" Ada %d barang", Length(list_barang));

//     // Menambahkan 1 barang ke dalam antrian
//     Barang barang_antrian = {"Tablet", -1};
//     enqueue(&antrian_barang, barang_antrian);

//     int pilihan;
//     do {
//         printf("\nMenu:\n");
//         printf("1. Lihat Daftar Barang\n");
//         printf("2. Tambahkan Barang ke Store\n");
//         printf("3. Proses Supply Barang\n");
//         printf("4. Hapus Barang dari Store\n");
//         printf("5. Keluar\n");
//         printf("Pilih opsi: ");
//         scanf("%d", &pilihan);
//         getchar();  // Untuk menangkap newline setelah input angka

//         switch (pilihan) {
//             case 1:
//                 // Lihat Daftar Barang
//                 display_barang(list_barang);
//                 break;
//             case 2:
//                 // Tambahkan Barang ke Store
//                 store_request(&antrian_barang, list_barang);
//                 break;
//             case 3:
//                 // Proses Supply Barang
//                 store_supply(&antrian_barang, &list_barang);
//                 break;
//             case 4:
//                 // Hapus Barang dari Store
//                 store_remove(&list_barang);
//                 break;
//             case 5:
//                 // Keluar
//                 printf("Terima kasih!\n");
//                 break;
//             default:
//                 printf("Opsi tidak valid, silakan coba lagi.\n");
//                 break;
//         }
//     } while (pilihan != 5);

//     // Membersihkan memori
//     DeallocateDinamicItemList(&list_barang);
    
//     return 0;
// }
