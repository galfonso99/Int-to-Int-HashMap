#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
    int value;
} kv_pair;

typedef struct {
    kv_pair *** data;
    int capacity;
    int count;
} hashmap;

typedef void (*callback_function) (int key, int value, void * usr_ptr);

hashmap* create_hashmap(int capacity);

void print_hashmap (hashmap * map);

uint32_t hash_function(uint32_t key);

bool hashmap_has (hashmap * map, int key);

void hashmap_update (hashmap * map, int key, int value);

void hashmap_set(hashmap *map, int key, int value);

int hashmap_get(hashmap *map, int key); 

void hashmap_delete (hashmap *map, int key);

void hashmap_free (hashmap * map);

void hashmap_rehash (hashmap * map, int new_capacity);

void hashmap_iterate (hashmap * map, callback_function func, void * usr_ptr);

void print_entry (int key, int value, void * usr_ptr);

void accumulate_entry (int key, int value, void * usr_ptr);

void hashmap_driver ();
#endif
