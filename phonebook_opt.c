#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *hash_table[HASH_TABLE_SIZE];
entry *hash_entry[HASH_TABLE_SIZE];
static inline int hash(char lastname[])
{
    int number = 0;
    while(*lastname)
        number += *lastname++;
    return number % HASH_TABLE_SIZE;
}
entry *findName(char lastname[], entry *pHead)
{
    int hash_value = hash(lastname);
    pHead = hash_table[hash_value];
    while(pHead) {
        if(strcmp(pHead->lastName, lastname) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}
entry *append(char lastname[], entry *e)
{
    int bucket = hash(lastname);
    entry *new_element = (entry *)malloc(sizeof(entry));

    if(hash_table[bucket] == NULL) { //create new entry
        new_element->pNext = NULL;
        strcpy(new_element->lastName, lastname);
        hash_entry[bucket] = new_element;
        hash_table[bucket] = new_element;
        return new_element;
    } else {
        hash_entry[bucket]->pNext = new_element;
        new_element->pNext = NULL;
        strcpy(new_element->lastName, lastname);
        hash_entry[bucket] = new_element;
        return new_element;
    }
}
