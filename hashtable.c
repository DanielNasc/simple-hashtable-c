#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hashtable.h"

typedef struct node
{
    string key;
    string value;
    struct node *next;
} Node;

typedef struct hashtable
{
    Node *list[HASHTABLE_SIZE];
    unsigned int (*hashFunction)(string key);
} Hashtable;

Node *createNode(string key, string value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

Hashtable *initializeHashtable(
    unsigned int (*hashFunction)(string key))
{
    Hashtable *newHashtable = (Hashtable *)malloc(sizeof(Hashtable));

    for (int i = 0; i < HASHTABLE_SIZE; i++)
        newHashtable->list[i] = NULL;

    newHashtable->hashFunction = hashFunction;

    return newHashtable;
}

void insert(Hashtable *hashtable, string key, string value)
{
    const unsigned int index = hashtable->hashFunction(key);
    Node *node = hashtable->list[index];

    if (node == NULL)
    {
        hashtable->list[index] = createNode(key, value);
    }
    else
    {
        while (node)
        {
            if (strcmp(node->key, key) == 0)
            {
                printf("key \"%s\" already exists\n", key);
                return;
            }

            if (node->next == NULL)
            {
                node->next = createNode(key, value);
                break;
            }

            node = node->next;
        }
    }
}

string search(Hashtable *hashtable, string key)
{
    const unsigned int index = hashtable->hashFunction(key);
    Node *node = hashtable->list[index];

    if (node == NULL)
        return NULL;

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return node->value;

        node = node->next;
    }

    return NULL;
}