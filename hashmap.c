#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

long resolverColisiones(HashMap* map, int posInicial){
  long pos = posInicial;
  while(map->buckets[pos] != NULL){
    pos = (pos + 1) % map->capacity;
    if(pos == posInicial)
      return -1;    
  }
  return pos;
}

void insertMap(HashMap* map, char * key, void * value) {
  long pos = hash(key, map->capacity);
  Pair * par = createPair(key, value);

  if(map->buckets[pos] != NULL){
    if(is_equal(map->buckets[pos]->key, key) == 1)
      return;
  }

  if(map->buckets[pos] == NULL){
    map->buckets[pos] = par;
  }
  else{
    long posF = resolverColisiones(map, pos);
    map->buckets[posF] = par;
  }
  
  map->size++;
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
  HashMap *map  = (HashMap *)malloc(sizeof(HashMap));
  map->capacity = capacity;
  map->buckets = (Pair **) calloc(map->capacity, sizeof(Pair *));
  map->size = 0;
  map->current = -1;
  return map;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
