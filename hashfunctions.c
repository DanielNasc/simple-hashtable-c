#include "hashfunctions.h"

// djb2
unsigned int djb2(string key) {
    unsigned long hash = 5381;
    unsigned int chr;

    while (chr = *key++) { // loop que percorre todos os caracteres da string key
        hash = ((hash << 5) + hash) + chr; // hash * 33 + chr
    }

    return hash % HASHTABLE_SIZE;
}

unsigned int sdbm(string key) {
    unsigned long hash = 0;
    unsigned int chr;

    while (chr = *key++) {
        hash = chr + (hash << 6) + (hash << 16) - hash; // hash * 65599 + chr
    }

    return hash % HASHTABLE_SIZE;
}