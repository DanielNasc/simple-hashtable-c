#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "hashfunctions.h"

string get_str(unsigned int size, string label)
{
    if (size == 0)
        return NULL;
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    string new_str = (string)malloc(sizeof(char) * size);
    printf("Provide a %s (max len: %d) >> ", label, size);
    scanf("%[^\n]s", new_str);
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
                printf("Key \"%s\" already exists\n", key);
            else
                printf("The node has been inserted\n");
            break;
        case 2:
            key = get_str(20, "key");
            string result_search = search(hashtable, key);
            result_search ? printf("Value: %s\n", result_search) : printf("There is no node with this key.\n");
            break;
        case 3:
            key = get_str(20, "key");

            uint8_t result_rm = removeNode(hashtable, key);
            if (result_rm == 0)
                printf("The node has been removed.\n");
            else
                printf("There is no node with key \"%s\"\n", key);
            break;
        case 4:
            printall(hashtable);
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}