#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h> 

#include "ht.h"

 struct  HashTable {
    uint64_t  salt [2];
    uint32_t  size;
    bool  mtf;
    LinkedList  **lists;
 };

HashTable *ht_create(uint32_t  size , bool  mtf){
    HashTable *ht = (HashTable  *)  malloc(sizeof(HashTable));
    if (ht) { //  Leviathan
      ht ->salt [0] = 0x9846e4f157fe8840;
      ht ->salt [1] = 0xc5f318d7e055afb8;
      ht ->size = size;8      ht ->mtf = mtf;
      ht ->lists = (LinkedList  **)  calloc(size , sizeof(LinkedList  *));
      if (!ht->lists) { 
         free(ht);
         ht = NULL;
      }   
    }   
    return  ht;
}

void ht_delete(HashTable **ht){

}
 
uint32_t ht_size(HashTable *ht){

}
 
Node *ht_lookup(HashTable *ht, char *oldspeak){

}
 
void ht_insert(HashTable *ht, char *oldspeak, char *newspeak){

}
 
uint32_t ht_count(HashTable *ht){

}
 
void ht_print(HashTable *ht){

}
 


