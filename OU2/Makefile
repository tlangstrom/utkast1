CC=gcc
CFLAGS=-Wall -std=c99
TARGET=huffman

all: $(TARGET)

$(TARGET): $(TARGET).c calc_frequency.c huffman_trie.c pqueue.c list.c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c calc_frequency.c huffman_trie.c pqueue.c list.c

.PHONY: clean
clean:
	rm -f $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET) -encode balen.txt loremipsum.txt outputfile.txt

.PHONY: valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET) -encode balen.txt loremipsum.txt outputfile.txt
