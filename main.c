// imports
#include "help.h"
#include "save.h"
#include "load.h"
#include "ShopList.h"
#include "work.h"
#include "tebak_angka.h"
#include "mesinkata.h"
#include "masukdaftar.h"
#include "WORDL3.h"
#include "StoreList.h"
#include "barangdin.h"

#include <stdio.h>


typedef struct{
    int userid;
    char *name;
    char *pass;
    int money;
} muser;

void start(DinamicItemList *item,StaticUserList *user){
    // default start file
    //  3
    //  10 AK47
    //  20 Lalabu
    //  20 Ayam Goreng Crisbar
    //  2
    //  100 admin alstrukdatkeren
    //  25 praktikan kerenbangetkak
    char filepath[] = "./save/";
    char filename[] = "default_save.txt";

    DinamicItemList default_items;
    addItem(&default_items, 10, "AK47");
    addItem(&default_items, 20, "Lalabu");
    ddItem(&default_items, 20, "Ayam Goreng Crisbar");


    StaticUserList def_user;
    addUser(&def_user, -1, "null", "-1-1-1-1-1");
    addUser(&def_user, 100, "admin", "alstrukdatkeren");
    addUser(&def_user, 25, "praktikan", "kerenbangetkak");

    constructfilepath(filepath, "./save/", filename);

    writeToFile(&filepath,&default_items,&def_user);

    *item = ret_items(&filepath);

    *user = ret_users(&filepath);
}

void quit(int *x){
    // panggil logout

}

// log in
int main(){

    // int idk something for user
    int active = 1;
    int back = 0;
    User current;
    char filepath[] = "";

    DinamicItemList items;
    initDinamicItemList(&items);
    StaticUserList users;
    initStaticUserList (&users);

    Antrian antre;
    CreateQueue(&antre);

    BarangDin dock;
    dock = MakeBarangDin();

    // i need to set up states
    int loaded = 0;
    int logged = 0;
    
    // main loop
    while(active){
        back = 0;
        
        // show options
        printf("1.save file\n2.login options\n3.main menu\n4.exit app");
        printf("\n");

        // get input

        MesinKarakter x;
        MesinKata choise;
        startMesinKarakter(&x,stdin);
        startMesinKata(&x, &choise);

        // printf("%s\n",choise.currentWord);

        if (choise.currentWord[0] == '1'){
            while (!back){
                back = 0;
                displayHelpWelcome();
                startMesinKata(&x, &choise);

                if(choise.currentWord[0] == '1'){
                    start(&items,&users);
                    copyString(filepath,"./save/default_save.txt");

                }
                else if(choise.currentWord[0] == '2'){
                    printf("\n\nTuliskan .txt file save mu\n");
                    startMesinKata(&x, &choise);
                    copyString(filepath,choise.currentWord);
                    load(&choise.currentWord);
                    items = ret_items(&choise.currentWord);
                    users = ret_users(&choise.currentWord);
                    }
                else if(choise.currentWord[0] == '3'){back=1;}
            }


        }
        else if(choise.currentWord[0] == '2'){
            while(!back){
                displayHelpLogin();
                startMesinKata(&x, &choise);
                if(choise.currentWord[0] == '1'){registerUser(users);}
                else if(choise.currentWord[0] == '2'){current = login(users,logged);}
                else if(choise.currentWord[0] == '3'){back=1;}
            }

        }
        else if(choise.currentWord[0] == '3'){
            while(!back){
                back = 0;
                displayHelpMain();
                if(choise.currentWord[0] == '1'){work(&current.money);}
                else if(choise.currentWord[0] == '2'){
                    while(!back){
                        displayChallange();
                        startMesinKata(&x, &choise);
                        if (choise.currentWord[0] == '1'){current.money = Tebak_Angka(current.money);}
                        else if(choise.currentWord[0] == '2'){current.money = W0RDL3(current.money);}
                        else if(choise.currentWord[0] == '3'){back=1;}
                    }
                }
                else if(choise.currentWord[0] == '3'){display_list(*path);}
                else if(choise.currentWord[0] == '4'){store request}
                else if(choise.currentWord[0] == '5'){store supply}
                else if(choise.currentWord[0] == '6'){store remove}
                else if(choise.currentWord[0] == '7'){logout(users,current,logged);}
                else if(choise.currentWord[0] == '8'){savefilename(filepath,items,users);}
                else if(choise.currentWord[0] == '9'){back=1;}
            }
        }
        else if(choise.currentWord[0] == '4'){
            logout(users,current,logged);
            active = 0;
        }

    }


    return 0;
}