// imports
#include "help.h"
#include "save.h"
#include "load.h"


// #include "work.h"
// #include "tebak_angka.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/mesinkarakter.h"
#include "masukdaftar.h"
// #include "WORDL3.h"
// #include "StoreList.h"
// #include "barangdin.h"

#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTUser.h"
#include "load.h"
#include "boolean.h"
#include <stdio.h>

// typedef struct{
//     int userid;
//     char *name;
//     char *pass;
//     int money;
// } muser;

// extern DinamicItemList ITEM;
// extern StaticUserList USER;

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
    char filename[MAX_LEN] = "default_save.txt";

    DinamicItemList default_items;
    initDinamicItemList(&default_items);
    
    addItem(&default_items, 10, "AK47");
    addItem(&default_items, 20, "Lalabu");
    addItem(&default_items, 20, "Ayam Goreng Crisbar");


    StaticUserList def_user;
    initStaticUserList(&def_user);
    addUser(&def_user, -1, "null", "-1-1-1-1-1");
    addUser(&def_user, 100, "admin", "alstrukdatkeren");
    addUser(&def_user, 25, "praktikan", "kerenbangetkak");

    constructfilepath(filepath, "./save/", filename);
    *item = default_items;
    *user = def_user;
    savefilename(filename,default_items,def_user);
    // copyString("./save/default_save.txt",filepath);
    // logged = false;
    // loaded = true;
    // initDinamicItemList(&CURRENT_ITEMS);
    // initStaticUserList(&CURRENT_USERS);
    // loadFile(filename);
    // *item = CURRENT_ITEMS;
    // *user = CURRENT_USERS;
}

void quit(){
    

}


// log in
int main(){

    // int idk something for user
    int active = 1;
    int back = 0;
    User current;
    copyString("null",current.name);
    copyString("null",current.password);
    current.money = -1;
    char filepath[100] = "./save/";
    char savename[100] = "null";

    DinamicItemList items;
    initDinamicItemList(&items);
    StaticUserList users;
    initStaticUserList (&users);

    // Antrian antre;
    // CreateQueue(&antre);

    // i need to set up states
    boolean loaded = false;
    boolean logged = false;
    // main loop
    while(active){
        back = 0;
        
        // show options
        printf("===== [ Welcome Menu ]=====\n");
        printf("\n1.save file");
        printf("\n2.login options");
        printf("\n3.main menu");
        printf("\n4.exit app");
        printf("\n5.check user\n");

        // MesinKarakter x;
        // MesinKata choise;
        // startMesinKarakter(&x,stdin);
        // startMesinKata(&x, &choise);
        STARTWORD();

        // printf("%s\n",choise.currentWord);

        if (CurrentWord.TabWord[0] == '1'){
            while (!back){
                back = 0;
                displayHelpWelcome();
                // startMesinKarakter(&x,stdin);
                // startMesinKata(&x, &choise);
                STARTWORD();
                if (CurrentWord.Length == 0){
                    printf("input is empty\n");
                    continue;
                }


                else if(CurrentWord.TabWord[0] == '1'){
                    char filepath[] = "./save/";
                    char filename[MAX_LEN] = "default_save.txt";

                    // DinamicItemList default_items;
                    initDinamicItemList(&items);
                    
                    addItem(&items, 10, "AK47");
                    addItem(&items, 20, "Lalabu");
                    addItem(&items, 20, "Ayam Goreng Crisbar");


                    // StaticUserList def_user;
                    initStaticUserList(&users);
                    addUser(&users, 100, "admin", "alstrukdatkeren");
                    addUser(&users, 25, "praktikan", "kerenbangetkak");

                    constructfilepath(filepath, "./save/", filename);
                    savefilename(filename,items,users);
                    copyString("default_save.txt",savename);
            
                    logged = false;
                    loaded = true;

                }
                else if(CurrentWord.TabWord[0] == '2'){
                    printf("\n\nTuliskan .txt save file mu\n");
                    // startMesinKata(&x, &choise);
                    STARTWORD();
                    copyString(CurrentWord.TabWord,savename);
                    loadFile(savename);
                    if (users.count == 0){
                        loaded = false;
                    }
                    else{
                        loaded = true;
                        logged = false;
                    }
                    
                    // loadFile(filepath);
                    // items = ret_items(filepath);
                    // users = ret_users(filepath);
                    }
                else if(CurrentWord.TabWord[0] == '3'){back=1;}
            }


        }
        else if(CurrentWord.TabWord[0] == '2' && loaded == true){
            while(!back){
                displayHelpLogin();
                // startMesinKata(&x, &choise);
                STARTWORD();
                if(CurrentWord.TabWord[0] == '1'){
                    registerUser(&users);
                }
                else if(CurrentWord.TabWord[0] == '2'){
                    logged = login(users,logged,&current);
                }
                else if(CurrentWord.TabWord[0] == '3'){
                    back=1;
                }
            }

        }
        else if(CurrentWord.TabWord[0] == '3' && loaded == true && logged == true){
            while(!back){
                back = 0;
                displayHelpMain();
                STARTWORD();
                if(CurrentWord.TabWord[0] == '1'){
                    // work(&current.money);
                }
                else if(CurrentWord.TabWord[0] == '2'){
                    while(!back){
                        back = 0;
                        displayChallange();
                        // startMesinKata(&x, &choise);
                        STARTWORD();
                        if (CurrentWord.TabWord[0] == '1'){
                            // current.money = Tebak_Angka(current.money);
                        }
                        else if(CurrentWord.TabWord[0] == '2'){
                            // current.money = W0RDL3(current.money);
                        }
                        else if(CurrentWord.TabWord[0] == '3'){back=1;}
                    }
                }
                else if(CurrentWord.TabWord[0] == '3'){
                    // display(items);
                }
                else if(CurrentWord.TabWord[0] == '4'){
                    // startMesinKata(&x, &choise);
                    // store_request(antre,items,choise);
                }
                else if(CurrentWord.TabWord[0] == '5'){
                    // store_supply(&antre,items);
                }
                else if(CurrentWord.TabWord[0] == '6'){
                    // store_remove(items);
                }
                else if(CurrentWord.TabWord[0] == '7'){
                    // logout(users,current,logged);
                }
                else if(CurrentWord.TabWord[0] == '8'){
                    printf("\nsave file di file baru (y/n)\n");
                    STARTWORD();
                    if (CurrentWord.TabWord[0] == 'y'){
                        printf("input nama file baru : \n");
                        STARTWORD();
                        savefilename(CurrentWord.TabWord,items,users);
                    }
                    
                    // savefilename(filepath,items,users);
                }
                back = 0;
                if(CurrentWord.TabWord[0] == '9'){
                    back=1;
                }
            }
        }
        else if(CurrentWord.TabWord[0] == '4'){
            // logout(users,current,logged);
            printf("would you like to save before quitting (y/n)\n");
            // startMesinKata(&x, &choise);
            STARTWORD();
            if (CurrentWord.TabWord[0] == 'y'){
                savefilename(filepath,items,users);
            }
            active = 0;
        }
        
        else if(CurrentWord.TabWord[0] == '5'){
            printf("\n======[status]======\n");
            printf("current file : %s\n",savename);
            printf("current account : %s\n",current.name);
            printf("current password : %s\n",current.password);
            printf("money amount : %d\n",current.money);
        }
        else if (loaded == false){
            printf("\nfile belum diload\n");
        }

        else if (logged == false){
            printf("\nuser belum login\n");
            // logged = true;
            // copyString("blank",current.name);    
        }

    }


    return 0;
}
