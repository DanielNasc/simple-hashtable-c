#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "hashfunctions.h"

string get_str(unsigned int size, string label)
{
    if (size == 0)
        return NULL;
    string new_str = (string)malloc(sizeof(char) * size);
    printf("Provide a %s (max len: %d) >> ", label, size);
    scanf("%s", new_str);
    return new_str;
}

int main()
{
    int choose = 0;

    do
    {
        printf("choose a hash function: \n");
        printf("[1] - djb2 | [2] - sdbm\n");
        scanf("%d", &choose);

        if (choose != 1 && choose != 2)
            printf("no\n");
    } while (choose != 1 && choose != 2);

    Hashtable *hashtable = initializeHashtable(choose == 1 ? *djb2 : *sdbm);

    while (1)
    {

        do
        {
            printf("\nChoose what you want to do:\n");
            printf("[1] - insert\n[2] - search\n[3] - remove\n[4] - print all\n[5] - exit\n");
            scanf("%d", &choose);

            if (choose < 1 || choose > 5)
                printf("no\n");
        } while (choose < 1 || choose > 5);

        string key, value;

        switch (choose)
        {
        case 1:
            key = get_str(20, "key");
            value = get_str(50, "value");

            uint8_t result_insert = insert(hashtable, key, value);
            if (result_insert == 1)
                printf("key \"%s\" already exists\n", key);
            else
                printf("the node has been inserted\n");
            break;
        case 2:
            key = get_str(20, "key");
            string result_search = search(hashtable, key);
            result_search ? printf("value: %s\n", result_search) : printf("there is no node with this key.\n");
        case 3:
            key = get_str(20, "key");

            uint8_t result_rm = removeNode(hashtable, key);
            if (result_rm == 0)
                printf("the node has been removed.\n");
            else
                printf("there is no node with key \"%s\"", key);
        case 4:
            printall(hashtable);
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}