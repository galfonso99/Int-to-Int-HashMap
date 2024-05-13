#include <stdbool.h>
#include <stdio.h>
#include "../src/hash_map.h"

/* Very important to include the following #define */
#define STB_DS_IMPLEMENTATION
#include "../src/stb_ds.h"

// Example
int main (int argc, char **argv) {
    int capacity = 10;
    hashmap * map = create_hashmap(capacity);
    hashmap_set(map, 5, 25);
    hashmap_set(map, 69, 420);
    hashmap_set(map, 8, 64);
    hashmap_set(map, 634, 6356);
    print_hashmap(map);
    printf("Map count: %d\n", map->count);

    hashmap_set(map, 45, 678);
    hashmap_set(map, 33, 998);
    hashmap_set(map, 123, 546);
    hashmap_set(map, 125, 546);
    int x = hashmap_get(map, 5);
    printf("%d\n\n\n", x);

    hashmap_set(map, 55555, 444);
    hashmap_set(map, 42069, 69420);
    hashmap_delete(map, 69);
    print_hashmap(map);
    printf("Map count: %d\n", map->count);
    /* Using a high order function you can pass it another function to perform tasks on each entry, 
    in this case adding all the values */
    int acc = 0;
    hashmap_iterate(map, accumulate_entry, &acc);
    printf("Sum total: %d\n", acc);
    hashmap_free(map);
}

