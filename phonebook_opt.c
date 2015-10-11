#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* version1 */
entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}

// /* version2*/

// /*hash function*/

// hashTable *hashInitial() {
// 	hashTable *ht = NULL;
// 	ht = (hashTable *)malloc(sizeof(hashTable));
// 	ht->list = (entry **)malloc(sizeof(entry *)*sizeTable);

// 	return ht;
// }

// hashf function
// hashIndex hash(char *key) {
// 	unsigned int hashVal = 0;
// 	while (*key != '\0') {
// 		hashVal = (hashVal << 5) + *key++;
// 	}
// 	return hashVal % sizeTable;
// }

// int *hashpaaend(char *key, unsigned int hashVal) {

// }