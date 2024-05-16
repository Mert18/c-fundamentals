#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_table.h"

static ht_item* ht_new_item(const char* k, const char* v) {
	ht_item* i = malloc(sizeof(ht_item));
	i->key = strdup(k);
	i->value = strdup(v);
	return i;
}

ht_hash_table* ht_new() {
	printf("Creating new hash table...");
	ht_hash_table* ht = malloc(sizeof(ht_hash_table));

	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
	return ht;
}

static void ht_del_item(ht_item* i) {
	printf("Deleting item with key %c", i->key);
	free(i->key);
	free(i->value);
	free(i);
}

void ht_del_hash_table(ht_hash_table* ht) {
	printf("Deleting hash table...");
	for(int i=0; i<ht->size; i++) {
		ht_item* item = ht->items[i];
		if(item != NULL) {
			ht_del_item(item);
		}
	}
	free(ht->items);
	free(ht);
}
