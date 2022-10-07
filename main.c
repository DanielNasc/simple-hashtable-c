#include <stdio.h>

#include "hashtable.h"
#include "hashfunctions.h"

int main()
{
    Hashtable *hashtableDjb2 = initializeHashtable(*djb2);

    insert(hashtableDjb2, "teste", "pei");
    insert(hashtableDjb2, "teste", "pei"); // test error mssg

    string pei = search(hashtableDjb2, "teste"),
           pow = search(hashtableDjb2, "pow");

    printf("teste -> %s\n", pei);

    if (!pow)
        printf("pow -> NULL\n");

    return 0;
}