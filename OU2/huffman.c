#include "huffman.h"

int main(int argc, const char *argv[]) {
    FILE *frequency_file_p;
    FILE *process_file_p;
    FILE *out_file_p;

    int wrong_prog_params = check_prog_params(argc, argv, &frequency_file_p, &process_file_p, &out_file_p);

    if (wrong_prog_params) {
        return 0;
    }
    
    charFrequency *frequency = calc_frequency(frequency_file_p);
    pqueue *pq = process_frequency(frequency);

   
    while(pqueue_is_empty(pq) == 0) {
        trie_node *test = pqueue_inspect_first(pq);
        printf("%d %c\n", test->weight, test->key);
        pqueue_delete_first(pq);
    }
    //pqueue_print(pq, print_func);
   // huffTree *tree = fillhuffTree(pq);

    // huffmanTable *table = build_huffman_table(root);

   /* if (strcmp(argv[1], "-encode") == 0) {
        encode_file(process_file_p, out_file_p, table);
    } else if (strcmp(argv[1], "-decode") == 0) {
        decode_file(process_file_p, out_file_p, table);
    }*/
    //test
  
    return 0;
}

int check_prog_params(int argc, const char *argv[],
                      FILE **frequency_file_p, FILE **process_file_p, FILE **out_file_p) {
    if (argc == 5) {
        *frequency_file_p = fopen(argv[2], "r");
        if (*frequency_file_p == NULL){
            fprintf(stderr, "Could not open the file: %s\n", argv[2]);

            return -1;
        }

        if (strcmp(argv[1], "-encode") == 0) {
            *process_file_p = fopen(argv[3], "r");
            if (*process_file_p == NULL){
                fprintf(stderr, "Could not open the file: %s\n", argv[3]);
                fclose(*frequency_file_p);
                
                return -1;
            }

            *out_file_p = fopen(argv[4], "wb");
            if (*out_file_p == NULL){
                fprintf(stderr, "Could not open the file: %s\n", argv[4]);
                fclose(*frequency_file_p);
                fclose(*process_file_p);
                
                return -1;
            }

        } else if(strcmp(argv[1], "-decode") == 0) {
            *process_file_p = fopen(argv[3], "rb");
            if (*process_file_p == NULL){
                fprintf(stderr, "Could not open the file: %s\n", argv[3]);
                fclose(*frequency_file_p);
                
                return -1;
            }
            *out_file_p = fopen(argv[4], "w");
            if (*out_file_p == NULL){
                fprintf(stderr, "Could not open the file: %s\n", argv[4]);
                fclose(*frequency_file_p);
                fclose(*process_file_p);
                
                return -1;
            }
        }
    } else {
        printf("USAGE:\n%s [OPTION] [FILE0] [FILE1] [FILE2]\n", argv[0]);
        printf("Options:\n");
        printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
        printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
        
        return -1;
    }
    return 0;
}