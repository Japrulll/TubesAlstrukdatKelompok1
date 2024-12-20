#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    printf("Masukkan teks: ");
    
    START();
    printf("---uji fungsi START---\n");
    printf("Karakter pertama: %c\n", GetCC());
    if(IsEOP()){
        printf("EOP: True, karakter pertama adalah MARK\n");
    }else{
        printf("EOP: False, karakter pertama bukan MARK\n");
    }
    
    printf("\n");

    printf("---uji fungsi ADV---\n");
    while(!IsEOP()){
        printf("Karakter saat ini: %c\n", GetCC());
        ADV();
    }
    printf("EOP tercapai.\n");

    printf("\n");

    printf("---uji fungsi IsEOP---\n");
    if(IsEOP()){
        printf("EOP: True, akhir pita tercapai\n");
    }else{
        printf("EOP: False, belum mencapai akhir pita\n");
    }
    return 0;
}
