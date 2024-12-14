// imports

/*compile paste board
gcc main.c help.c save.c load.c masukdaftar.c work.c tebak_angka.c WORDL3.c StoreList.c "./Folder ADT/ADTFile.c" "./Folder ADT/ADTItem.c" "./Folder ADT/ADTUser.c" "./Folder ADT/mesinkata.c" "./Folder ADT/mesinkarakter.c" "./Folder ADT/queue.c" -o main.exe
*/

// built in module
#include <stdio.h>

// custom modules
//#############
// # display
#include "help.h"

// # file menu and login
#include "save.h"
#include "load.h"
#include "masukdaftar.h"

// # work and games
#include "work.h"
#include "tebak_angka.h"
#include "WORDL3.h"

// # store management
#include "StoreList.h"

// ADT formats and tools
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTUser.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/boolean.h"
#include "./Folder ADT/queue.h"
#include "./Folder ADT/ADTLinkedList.h"
#include "./Folder ADT/ADTStack.h"

// global states
boolean active;
boolean back;
boolean loaded;
boolean logged;

// global file and user variable
DinamicItemList items;
StaticUserList users;
Antrian gudang;

// global users stuff
User current;
int current_index;
char savename[100];


void start(DinamicItemList *item,StaticUserList *user){
    // ======= default start file ==========
    //  3
    //  10 AK47
    //  20 Lalabu
    //  20 Ayam Goreng Crisbar
    //  2
    //  100 admin alstrukdatkeren
    //  25 praktikan kerenbangetkak

    
    addItem(item, 10, "AK47");
    addItem(item, 20, "Lalabu");
    addItem(item, 20, "Ayam Goreng Crisbar");

    Stack riwayat;
    List wishlist;
    CreateEmptyS(&riwayat);
    CreateEmptyLL(&wishlist);
    Push(&riwayat, 40, "AK47");
    Push(&riwayat, 100, "AK47");
    Push(&riwayat, 35, "Lalabu");
    Push(&riwayat, 10, "AK47");
    Push(&riwayat, 500, "Meong");
    Push(&riwayat, 20, "Ayam Goreng Crisbar");
    InsVLast(&wishlist, "Ayam Goreng Crisbar");
    InsVLast(&wishlist, "AK47");
    
    addUser(user, 100, "admin", "alstrukdatkeren", &riwayat, &wishlist);
    Stack riwayat2;
    List wishlist2;
    CreateEmptyS(&riwayat2);
    CreateEmptyLL(&wishlist2);
    InsVLast(&wishlist2, "Meong");
    addUser(user, 25, "praktikan", "kerenbangetkak", &riwayat2, &wishlist2);
    
    savefilename("default_save.txt",item,user);
    loadFile("default_save.txt",item,user);  
}


void quit(){ // this is unnesscesary
    active = false;
    if (loaded == true){
        printf("would you like to save before quitting (y/n)\n");
        STARTWORD();
        if (CurrentWord.TabWord[0] == 'y'){
            users.users[current_index].money = current.money;
            savefilename(savename,&items,&users);
        }
        if (logged == true){
            logged = logout(&current,&current_index);
            printf("you have been logged out\n");
        }
    }
    printf("\ngoodbye\n");
    // active = false;   

}

void inputdelay(){
    printf("\nInput anything to continue:\n");
    STARTWORD();
}
// void ccc(){
//     char filepaths[10] = "./save/";
//     char filenames[MAX_LEN] = "default_save.txt";
//     constructfilepath(filepaths, "./save/", filenames);
// }



int main(){

    // program states
    active = true;
    back = false;
    loaded = false;
    logged = false;

    // file and user variable
    initDinamicItemList(&items);
    initStaticUserList (&users);
    CreateQueue(&gudang);

    // users stuff
    current_index=-1;
    copyString("null",current.name);
    copyString("null",current.password);
    current.money = -1;
    copyString("null",savename);

    // ############################ main loop ###################################
    while(active){
        back = false;
        
        // show options
        printf("====== [ Welcome Menu ]======\n");
        printf("\n1.File Menu");
        printf("\n2.Login and Register");
        printf("\n3.Main Menu");
        printf("\n4.exit");
        printf("\n5.Check Status\n");
        STARTWORD();

        // ########################### file menu ##############################
        if (CurrentWord.TabWord[0] == '1'){
            while (!back){
                back = false;
                displayHelpWelcome();
                STARTWORD();
                if(CurrentWord.TabWord[0] == '1'){
                    printf("loading default save file\n");
                    start(&items,&users);
                    loaded = true;
                    logged = false;
                    copyString("default_save.txt",savename);
                    inputdelay();
                }
                else if(CurrentWord.TabWord[0] == '2'){
                        printf("\nTuliskan .txt save file mu\n");
                        STARTWORD();
                        
                        loadFile(CurrentWord.TabWord,&items,&users);
                        if (users.count == 0 && items.count == 0){
                            loaded = false;
                            copyString("null",savename);
                        }
                        else{
                            copyString(CurrentWord.TabWord,savename);
                            loaded = true;
                            logged = false;
                        }
                        inputdelay();
                    }
                else if(CurrentWord.TabWord[0] == '3'){back=true;}
                
                else {back = false;}
            }
        }
        
        // ################################ login menu ###############################
        else if(CurrentWord.TabWord[0] == '2' && loaded == true){
            while(!back){
                displayHelpLogin();
                STARTWORD();
                if(CurrentWord.TabWord[0] == '1'){
                    registerUser(&users);
                    inputdelay();
                }
                else if(CurrentWord.TabWord[0] == '2'){
                    logged = login(users,&current,&current_index);
                    inputdelay();
                }
                else if(CurrentWord.TabWord[0] == '3'){back=true;}

                else {back = false;}
            }

        }

        // ##################################### main menu #############################
        else if(CurrentWord.TabWord[0] == '3' && loaded == true && logged == true){
            while(!back){
                displayHelpMain();
                STARTWORD();
                if(CurrentWord.TabWord[0] == '1'){
                    work(&current.money);
                    users.users[current_index].money = current.money;
                    inputdelay();
                }
                else if(CurrentWord.TabWord[0] == '2'){
                    while(!back){
                        // ############## Challange menu ##################
                        displayChallange();
                        STARTWORD();
                        if (CurrentWord.TabWord[0] == '1'){
                            current.money = Tebak_Angka(current.money);
                            users.users[current_index].money = current.money;
                        }
                        else if(CurrentWord.TabWord[0] == '2'){
                            current.money = W0RDL3(current.money);
                            users.users[current_index].money = current.money;
                        }
                        else if(CurrentWord.TabWord[0] == '3'){back=true;}

                        else {back = false;}
                    }
                    back = false;
                }
                else if(CurrentWord.TabWord[0] == '3'){
                    store_display(items);
                    inputdelay();
                }
                else if(CurrentWord.TabWord[0] == '4'){
                    store_request(&gudang,items);
                }
                else if(CurrentWord.TabWord[0] == '5'){
                    store_supply(&gudang,&items);
                }
                else if(CurrentWord.TabWord[0] == '6'){
                    printf("Tuliskan nama item yang ingin diremove :");
                    store_remove(&items);
                }
                else if(CurrentWord.TabWord[0] == '7'){
                    logged = logout(&current,&current_index);
                    back = true;
                }
                else if(CurrentWord.TabWord[0] == '8'){
                    users.users[current_index].money = current.money;
                    printf("\nsave file di file baru (y/n)\n");
                    STARTWORD();
                    if (CurrentWord.TabWord[0] == 'y'){
                        printf("input nama file baru : ");
                        STARTWORD();
                        copyString(CurrentWord.TabWord,savename);
                    }
                    savefilename(savename,&items,&users);
                    inputdelay();
                }
                
                else if(CurrentWord.TabWord[0] == '9'){back=true;}
                
                else{back = false;}
            }
        }

        // ##################################### exit menu ##########################################
        else if(CurrentWord.TabWord[0] == '4'){
            quit();
        }
        
        //################################ Status menu #############################
        else if(CurrentWord.TabWord[0] == '5'){
            printf("\n======[status]======\n");
            printf("current file : %s\n",savename);
            printf("item amount : %d\n",items.count);
            printf("user amount : %d\n",users.count);
            printf("current account : %s\n",current.name);
            printf("current password : %s\n",current.password);
            printf("money amount : %d\n",current.money);

            inputdelay();

        }

        // loop around
        else if (loaded == false){
            printf("\nfile belum diload\n");
        }

        // loop around
        else if (logged == false){
            printf("\nuser belum login\n");  
        }

    }


    return 0;
}