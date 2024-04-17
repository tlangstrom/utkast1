#include "huffman_trie.h"

pqueue *process_frequency(charFrequency *frequency) {

    pqueue *pq = pqueue_empty(cmp_key);

    for (int i = 0; i < 256; i++) {
        if (frequency[i].frequency > 0) {
            trie_node *new_node = malloc(sizeof(trie_node));
            new_node->weight = frequency[i].frequency;
            new_node->key = frequency[i].character;
            new_node->left = NULL;
            new_node->right = NULL;

            //printf("Inserted node: Key: %c, Weight: %d\n", new_node->key, new_node->weight);

            pqueue_insert(pq, new_node);
            trie_node *test = malloc(sizeof(trie_node));
            
        }
    }

     return pq;
}



int cmp_key (void *nodeIn1, void *nodeIn2) {

	trie_node *node1 = nodeIn1;
	trie_node *node2 = nodeIn2;

	int largest = 0;

	if (node1 -> weight > node2 -> weight) {

		largest = 1;

	} else if (node2 -> weight > node1 -> weight) {

		largest = -1;
	}

	return largest;
}




