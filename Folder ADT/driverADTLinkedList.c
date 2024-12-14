#include <stdio.h>
#include <stdlib.h>
#include "ADTFile.h"
#include "ADTLinkedList.h"
#include "boolean.h"
#include "ADTStack.h"

int main(){
    List l1;
    CreateEmptyLL(&l1);
    printf("isEmpty: %d\n", IsEmptyLL(l1)); //should print 1
    InsVLast(&l1, "item1");
    InsVLast(&l1, "item2");
    InsVFirst(&l1, "item3");
    PrintInfoDebug(l1); //[item3, item1, item2]
    address newNode = AlokasiLL("item4");
    address p = SearchLL(l1, "item1");
    InsertAfter(&l1, newNode, p);
    PrintInfoDebug(l1); //[item3, item1, item4, item2]


}