#ifndef diplaylist
#define displaylist

//boolean
#define true 1
#define false 0
#define boolean unsigned char

#define Index int
#define Element char*

#define MAX_LEN 100
#define Mark "hmif"
#define ErrorIndex -1

typedef struct {
  char name[MAX_LEN];
  int price;
} Barang;


// void display_list(Barang L);
void display_list(char *path);

#endif