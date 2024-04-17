#ifndef HUFFMAN
#define HUFFMAN

#include <stdio.h>
#include <stdlib.h>
#include "calc_frequency.h"
#include "pqueue.h"
#include "huffman_trie.h"



int check_prog_params(int argc, const char *argv[],
                      FILE **frequency_file_p, FILE **process_file_p, FILE **out_file_p);

#endif