#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash.h"

/*hash function*/
hashTable *hashInitial()
{
    hashTable *ht = NULL;
    ht = (hashTable *)malloc(sizeof(hashTable));
    ht->list = (entry **)malloc(sizeof(entry *)*sizeTable);
    for (int i = 0; i < sizeTable; i++) {
        ht->list[i] = NULL;
    }

    return ht;
}

/*hashf function*/
hashIndex hash(char *key)
{
    unsigned int hashVal = 0;
    while (*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal % sizeTable;
}

int hashappend(char *key, hashTable *ht)
{
    entry *newEntry;
    newEntry = (entry *)malloc(sizeof(entry));
    strcpy(newEntry->lastName, key);
    newEntry->pNext = ht->list[hash(key)];
    ht->list[hash(key)] = newEntry;

    hash(key);
    return 0;
}

entry *hashFindName(char *key, hashTable *ht)
{
    entry *e;
    e = ht->list[hash(key)];
    while (e->pNext != NULL) {
        if (strcasecmp(key, e->lastName) == 0) {
            return NULL;
        }
        e = e->pNext;
    }
    return 0;
}