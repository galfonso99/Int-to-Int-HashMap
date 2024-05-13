A Simple Hashmap in C specifically for int to int mapping. It uses an array list under the hood (as opposed to linked-list)

## Example Usage
```
int capacity = 10;
hashmap * map = create_hashmap(capacity);
hashmap_set(map, 5, 25);
hashmap_set(map, 69, 420);
hashmap_set(map, 8, 64);
print_hashmap(map);
int x = hashmap_get(map, 8);
printf("For key 8 the value is: %d\n", x);

hashmap_delete(map, 5);
print_hashmap(map);

if (hashmap_has(map, 5)) {
    printf("The hashmap has an entry with key: 5");
}

/* Using a high order function you can pass it another function to perform tasks on each entry, 
    in this case adding all the values */
int acc = 0;
hashmap_iterate(map, accumulate_entry, &acc);
printf("Sum total: %d\n", acc);

hashmap_free(map);
```
