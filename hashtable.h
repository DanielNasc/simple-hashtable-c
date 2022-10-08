#include <inttypes.h>
#include "common.h"

typedef char *string;
typedef struct node Node;
typedef struct hashtable Hashtable;

Node *createNode(string key, string value);
Hashtable *initializeHashtable(
    unsigned int (*hashFunction)(string key));

uint8_t insert(Hashtable *hashtable, string key, string value);
uint8_t removeNode(Hashtable *hashtable, string key);
string search(Hashtable *hashtable, string key);
void printall(Hashtable *hashtable);