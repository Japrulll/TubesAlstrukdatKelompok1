// imports

/*compile paste board
gcc main.c help.c save.c load.c masukdaftar.c work.c tebak_angka.c WORDL3.c StoreList.c Cartj.c history.c "./Folder ADT/ADTFile.c" "./Folder ADT/ADTItem.c" "./Folder ADT/ADTUser.c" "./Folder ADT/mesinkata.c" "./Folder ADT/mesinkarakter.c" "./Folder ADT/queue.c" "./Folder ADT/ADTSetMap.c" "./Folder ADT/ADTLinkedlist.c" "./Folder ADT/ADTStack.c" -o main.exe
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

// # store management and shopping
#include "StoreList.h"
#include "Cartj.h"
#include "WISHLIST.c"
#include "history.h"

// ADT formats and tools
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTItem.h"
#include "./Folder ADT/ADTUser.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/boolean.h"
#include "./Folder ADT/queue.h"
#include "./Folder ADT/ADTSetMap.h"
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


    Stack nill;
    CreateEmptyS(&nill);

    List noll;
    CreateEmptyLL(&noll);
    
    addItem(item, 10, "AK47");
    addItem(item, 20, "Lalabu");
    addItem(item, 20, "Ayam Goreng Crisbar");
    

    addUser(user, 10000, "admin", "alstrukdatkeren",&nill,&noll);
    addUser(user, 25, "praktikan", "kerenbangetkak",&nill,&noll);
    
    savefilename("default_save.txt",item,user);
    // loadFile("default_save.txt",item,user);  
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
    while(!EndWord){
        ADVWORD;
    }
    printf("\nInput anything to continue:\n");
    STARTWORD();
}

// void ccc(){
//     char filepaths[10] = "./save/";
//     char filenames[MAX_LEN] = "default_save.txt";
//     constructfilepath(filepaths, "./save/", filenames);
// }

void dis_challenge(){
    while(!back){
        // ############## Challange menu ##################
        displayChallange();
        AS_WORD();
        if (StrToInt(CurrentWord.TabWord) == 1
            || compareStrings(CurrentWord.TabWord,"tebak")
            || compareStrings(CurrentWord.TabWord,"TEBAK")){
            current.money = Tebak_Angka(current.money);
            users.users[current_index].money = current.money;
        }
        else if(StrToInt(CurrentWord.TabWord) == 2
            || compareStrings(CurrentWord.TabWord,"wordl3")
            || compareStrings(CurrentWord.TabWord,"WORDL3")){
            current.money = W0RDL3(current.money);
            users.users[current_index].money = current.money;
        }
        else if(StrToInt(CurrentWord.TabWord) == 3
            || compareStrings(CurrentWord.TabWord,"back")
            || compareStrings(CurrentWord.TabWord,"BACK")){
            back=true;
        }
    }
    back = false; 
}

void dis_store(){
    while(!back){
        displayStore();
        AS_WORD();
        if (StrToInt(CurrentWord.TabWord) == 1
            || compareStrings(CurrentWord.TabWord,"list")
            || compareStrings(CurrentWord.TabWord,"LIST")){
            store_display(items);
        }
        else if(StrToInt(CurrentWord.TabWord) == 2
            || compareStrings(CurrentWord.TabWord,"request")
            || compareStrings(CurrentWord.TabWord,"REQUEST")){
            store_request(&gudang,items);
        }
        else if(StrToInt(CurrentWord.TabWord) == 3
            || compareStrings(CurrentWord.TabWord,"supply")
            || compareStrings(CurrentWord.TabWord,"SUPPLY")){
            store_supply(&gudang,&items);
        }

        else if(StrToInt(CurrentWord.TabWord) == 4
            || compareStrings(CurrentWord.TabWord,"remove")
            || compareStrings(CurrentWord.TabWord,"REMOVE")){
            printf("Tuliskan nama item yang ingin diremove :\n");
            store_remove(&items);
        }

        else if(StrToInt(CurrentWord.TabWord) == 5
            || compareStrings(CurrentWord.TabWord,"back")
            || compareStrings(CurrentWord.TabWord,"BACK")){
            back=true;
        }
    }
    back = false; 
}

void dis_cart(){
    char produk[10];
    int jumlah;
    while(!back){
        displayCart();
        AS_WORD();
        if (StrToInt(CurrentWord.TabWord) == 0
            || compareStrings(CurrentWord.TabWord,"display")
            || compareStrings(CurrentWord.TabWord,"display")){
            store_display(items);
        }
        else if(StrToInt(CurrentWord.TabWord) == 1
            || compareStrings(CurrentWord.TabWord,"add")
            || compareStrings(CurrentWord.TabWord,"ADD")){
            printf("Tuliskan nama item dan jumlah yang ingin ditambahkan dipisahkan dengan spasi:\n");
            AS_WORDBLANKS();
            spitnamaharga(CurrentWord,produk,&jumlah);
            printf("%s",CurrentWord.TabWord);
            printf("%s %d\n",produk,jumlah);
            if (jumlah != -1){
                cartadd(&current.keranjang,items,produk,jumlah);
            }

        }
        
        else if(StrToInt(CurrentWord.TabWord) == 2
            || compareStrings(CurrentWord.TabWord,"remove")
            || compareStrings(CurrentWord.TabWord,"REMOVE")){
            printf("Tuliskan nama barang dan jumlahnya yang ingin diremove dipisah dengan spasi\n");
            AS_WORDBLANKS();
            spitnamaharga(CurrentWord,produk,&jumlah);
            if (jumlah != -1){
                cartremove(&current.keranjang,items,produk,jumlah);
            }
        }

        else if(StrToInt(CurrentWord.TabWord) == 3
            || compareStrings(CurrentWord.TabWord,"show")
            || compareStrings(CurrentWord.TabWord,"SHOW")){
            cartshow(&current.keranjang,items);
        }

        else if(StrToInt(CurrentWord.TabWord) == 4
            || compareStrings(CurrentWord.TabWord,"pay")
            || compareStrings(CurrentWord.TabWord,"PAY")){
            
            current.money = cartpay(&current.keranjang,items,&current.riwayat_pembelian,current.money);
        }
        else if(StrToInt(CurrentWord.TabWord) == 5
            || compareStrings(CurrentWord.TabWord,"back")
            || compareStrings(CurrentWord.TabWord,"BACK")){
            back=true;
        }
    }
    back = false; 
}

void dis_history(Stack *S){
    printf("Tuliskan jumlah history yang ingin diprint :\n");
    AS_WORD();
    history(S,StrToInt(CurrentWord.TabWord));
}


void dis_wishlist(){
    while(!back){
        displayWishlist();
        AS_WORD();
        if (StrToInt(CurrentWord.TabWord) == 0
            || compareStrings(CurrentWord.TabWord,"display")
            || compareStrings(CurrentWord.TabWord,"display")){
            store_display(items);
        }
        else if (StrToInt(CurrentWord.TabWord) == 1
            || compareStrings(CurrentWord.TabWord,"add")
            || compareStrings(CurrentWord.TabWord,"ADD")){
            WISHLISTADD(&current.wishlist,items);
        }
        else if(StrToInt(CurrentWord.TabWord) == 2
            || compareStrings(CurrentWord.TabWord,"swap")
            || compareStrings(CurrentWord.TabWord,"SWAP")){
            WISHLISTSWAP(&current.wishlist);
        }
        else if(StrToInt(CurrentWord.TabWord) == 3
            || compareStrings(CurrentWord.TabWord,"remove")
            || compareStrings(CurrentWord.TabWord,"REMOVE")){
            WISHLISTREMOVE(&current.wishlist);
        }

        else if(StrToInt(CurrentWord.TabWord) == 4
            || compareStrings(CurrentWord.TabWord,"clear")
            || compareStrings(CurrentWord.TabWord,"CLEAR")){
            WISHLISTCLEAR(&current.wishlist);
        }

        else if(StrToInt(CurrentWord.TabWord) == 5
            || compareStrings(CurrentWord.TabWord,"show")
            || compareStrings(CurrentWord.TabWord,"SHOW")){
            WISHLISTSHOW(&current.wishlist);
        }
        else if(StrToInt(CurrentWord.TabWord) == 6
            || compareStrings(CurrentWord.TabWord,"back")
            || compareStrings(CurrentWord.TabWord,"BACK")){
            back=true;
        }
    }
    back = false; 
}

void profile(){
    printf(" _______ ______   _______ _______ ___ ___     _______ \n");
    printf("|       |    _ | |       |       |   |   |   |       |\n");
    printf("|    _  |   | || |   _   |    ___|   |   |   |    ___|\n");
    printf("|   |_| |   |_||_|  | |  |   |___|   |   |   |   |___ \n");
    printf("|    ___|    __  |  |_|  |    ___|   |   |___|    ___|\n");
    printf("|   |   |   |  | |       |   |   |   |       |   |___ \n");
    printf("|___|   |___|  |_|_______|___|   |___|_______|_______| \n");
    printf("============ [Current Account] ==============\n");
    printf("current account : %s\n",current.name);
    printf("current password : %s\n",current.password);
    printf("money amount : %d\n",current.money);
}

void fstatus(){
    printf("\n======[status]======\n");
    printf("current file : %s\n",savename);
    printf("item amount : %d\n",items.count);
    printf("user amount : %d\n",users.count);
}


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
    CreateEmptyMap(&current.keranjang);
    CreateEmptyS(&current.riwayat_pembelian);
    CreateEmptyLL(&current.wishlist);
    // ############################ main loop ###################################
    while(active){
        back = false;
        
        // show options
        displayMainMenu();
        STARTWORD();

        // ########################### file menu ##############################
        if (StrToInt(CurrentWord.TabWord) == 1
            || compareStrings(CurrentWord.TabWord,"file")
            || compareStrings(CurrentWord.TabWord,"FILE")){
            while (!back){
                back = false;
                displayHelpWelcome();
                AS_WORD();
                if (StrToInt(CurrentWord.TabWord) == 1
                    || compareStrings(CurrentWord.TabWord,"start")
                    || compareStrings(CurrentWord.TabWord,"START")){
                    printf("loading default save file\n");
                    start(&items,&users);
                    loaded = true;
                    logged = false;
                    copyString("default_save.txt",savename);
                    inputdelay();
                }
                else if (StrToInt(CurrentWord.TabWord) == 2
                        || compareStrings(CurrentWord.TabWord,"load")
                        || compareStrings(CurrentWord.TabWord,"LOAD")){
                        
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
                else if(StrToInt(CurrentWord.TabWord) == 3
                        || compareStrings(CurrentWord.TabWord,"back")
                        || compareStrings(CurrentWord.TabWord,"BACK")){
                            back=true;
                }
            }
            back = false;
        }
        
        // ################################ login menu ###############################
        else if((StrToInt(CurrentWord.TabWord) == 2
                || compareStrings(CurrentWord.TabWord,"login")
                || compareStrings(CurrentWord.TabWord,"LOGIN"))
                && loaded == true){
            while(!back){
                displayHelpLogin();
                STARTWORD();
                if(StrToInt(CurrentWord.TabWord) == 1
                    || compareStrings(CurrentWord.TabWord,"register")
                    || compareStrings(CurrentWord.TabWord,"REGISTER")){
                    registerUser(&users);
                    inputdelay();
                }
                else if(StrToInt(CurrentWord.TabWord) == 2
                    || compareStrings(CurrentWord.TabWord,"login")
                    || compareStrings(CurrentWord.TabWord,"LOGIN")){
                    logged = login(users,&current,&current_index);
                    inputdelay();
                }
                else if(StrToInt(CurrentWord.TabWord) == 3
                    || compareStrings(CurrentWord.TabWord,"profile")
                    || compareStrings(CurrentWord.TabWord,"PROFILE")){
                    profile();
                    inputdelay();
                }
                else if(StrToInt(CurrentWord.TabWord) == 4
                    || compareStrings(CurrentWord.TabWord,"back")
                    || compareStrings(CurrentWord.TabWord,"BACK")){
                    back=true;
                }
            }
            back = false;
        }

        // ##################################### main menu #############################
        else if((StrToInt(CurrentWord.TabWord) == 3
                || compareStrings(CurrentWord.TabWord,"main")
                || compareStrings(CurrentWord.TabWord,"MAIN"))
                && loaded == true
                && logged == true){
            while(!back){
                displayHelpMain();
                STARTWORD();
                if(StrToInt(CurrentWord.TabWord) == 1
                    || compareStrings(CurrentWord.TabWord,"work")
                    || compareStrings(CurrentWord.TabWord,"WORK")){
                    printf(" _     _ _______ ______   ___   _ \n");
                    printf("| | _ | |       |    _ | |   | | |\n");
                    printf("| || || |   _   |   | || |   |_| |\n");
                    printf("|       |  | |  |   |_||_|      _|\n");
                    printf("|       |  |_|  |    __  |     |_ \n");
                    printf("|   _   |       |   |  | |    _  |\n");
                    printf("|__| |__|_______|___|  |_|___| |_| \n");
                    work(&current.money);
                    users.users[current_index].money = current.money;
                    inputdelay();
                }
                else if(StrToInt(CurrentWord.TabWord) == 2
                    || compareStrings(CurrentWord.TabWord,"challenge")
                    || compareStrings(CurrentWord.TabWord,"CHALLENGE")){
                    dis_challenge();
                }
                else if(StrToInt(CurrentWord.TabWord) == 3
                    || compareStrings(CurrentWord.TabWord,"store")
                    || compareStrings(CurrentWord.TabWord,"STORE")){
                    dis_store();
                }
                
                else if(StrToInt(CurrentWord.TabWord) == 4
                    || compareStrings(CurrentWord.TabWord,"cart")
                    || compareStrings(CurrentWord.TabWord,"CART")){
                    dis_cart();
                }

                else if(StrToInt(CurrentWord.TabWord) == 5
                    || compareStrings(CurrentWord.TabWord,"history")
                    || compareStrings(CurrentWord.TabWord,"HISTORY")){
                    dis_history(&current.riwayat_pembelian);
                    inputdelay();
                }

                else if(StrToInt(CurrentWord.TabWord) == 6
                    || compareStrings(CurrentWord.TabWord,"wishlist")
                    || compareStrings(CurrentWord.TabWord,"WISHLIST")){
                    dis_wishlist();
                }

                else if(StrToInt(CurrentWord.TabWord) == 7
                    || compareStrings(CurrentWord.TabWord,"logout")
                    || compareStrings(CurrentWord.TabWord,"LOGOUT")){
                    logged = logout(&current,&current_index);
                    back = true;
                }
                else if(StrToInt(CurrentWord.TabWord) == 8
                    || compareStrings(CurrentWord.TabWord,"save")
                    || compareStrings(CurrentWord.TabWord,"SAVE")){     
                    users.users[current_index].money = current.money;
                    printf("\nsave file di file baru (y/n)\n");
                    STARTWORD();
                    if (CurrentWord.TabWord[0] == 'y'){
                        printf("input nama file baru : ");
                        STARTWORD();
                        copyString(CurrentWord.TabWord,savename);
                    }
                    users.users[current_index].wishlist = current.wishlist;
                    users.users[current_index].riwayat_pembelian = current.riwayat_pembelian;
                    savefilename(savename,&items,&users);
                    inputdelay();
                }
                
                else if(StrToInt(CurrentWord.TabWord) == 9
                    || compareStrings(CurrentWord.TabWord,"back")
                    || compareStrings(CurrentWord.TabWord,"BACK")){
                    back=true;
                }
            }
            back = false;
        }

        // ##################################### exit menu ##########################################
        else if(CurrentWord.TabWord[0] == '4'){
            quit();
        }
        
        //################################ Status menu #############################
        else if(CurrentWord.TabWord[0] == '5'){
            fstatus();
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
