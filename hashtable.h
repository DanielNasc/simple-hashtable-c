#include "common.h"

typedef char *string;
typedef struct node Node;
typedef struct hashtable Hashtable;

Node *createNode(string key, string value);
Hashtable *initializeHashtable(
    unsigned int (*hashFunction)(string key));

void insert(Hashtable *hashtable, string key, string value);
string search(Hashtable *hashtable, string key);
