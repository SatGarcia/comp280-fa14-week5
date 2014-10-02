#include <stdio.h>
#include <stdlib.h>

struct List {
	int value;
	struct List *next;
};

typedef struct List List;

void printList(List *l);
void addToEnd(List *l, int new_val);
void removeFromEnd(List *l);

int main() {
	List *ll = calloc(1, sizeof(List));
	ll->value = 1;

	printList(ll);

	addToEnd(ll, 5);
	addToEnd(ll, 10);
	addToEnd(ll, 17);

	printList(ll);

	removeFromEnd(ll); // should remove list entry with 17
	removeFromEnd(ll); // should remove list entry with 10

	printList(ll);

	return 0;
}

void printList(List *l) {
	printf("list: ");

	while (l != NULL) {
		printf("%d ", l->value);
		l = l->next;
	}

	printf("\n");
}

void addToEnd(List *l, int new_val) {
	List *new_entry = calloc(1, sizeof(List));
	// TODO: set entry's value

	List *last_entry = l;
	while (last_entry->next != NULL) {
		last_entry = last_entry->next;
	}

	// invariant: last_entry will now be the last entry in the current list
	
	// TODO:  update list so that new_entry is the last entry now
}

void removeFromEnd(List *l) {
	List *last_entry = l;
	List *next_to_last_entry = l;

	// set last_entry to be the last entry
	while (last_entry->next != NULL) {
		last_entry = last_entry->next;
	}

	// set next_to_last_entry to correct entry
	while (next_to_last_entry->next != NULL) {
		next_to_last_entry = next_to_last_entry->next;
	}

	// TODO: update next_to_last_entry's next value
	
	free(last_entry);
	last_entry = NULL;
}
