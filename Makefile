OBJS	= Trie.o algo.o bit.o
SOURCE	= Trie.c algo.c bit.c
HEADER	= Trie.h algo.h bit.h
OUT	= Project
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Trie.o: Trie.c
	$(CC) $(FLAGS) Trie.c 

algo.o: algo.c
	$(CC) $(FLAGS) algo.c 

bit.o: bit.c
	$(CC) $(FLAGS) bit.c 


clean:
	rm -f $(OBJS) $(OUT)