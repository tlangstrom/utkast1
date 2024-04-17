#ifndef HUFFMAN_TRIE
#define HUFFMAN_TRIE

    #include <stdio.h>
    #include "pqueue.h"
    #include "calc_frequency.h"
    
    typedef struct trie_node {
        int weight;
	    unsigned char key;
        struct trie_node *left, *right;
    } trie_node;

    pqueue *process_frequency(charFrequency *frequency);
    int cmp_key (void *nodeIn1, void *nodeIn2);
#endif