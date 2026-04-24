# ─────────────────────────────────────────────
#  Makefile — Compilateur MiniAlgo
# ─────────────────────────────────────────────
CC      = gcc
CFLAGS  = -Wall -Wno-unused-function

all: minialgo

minialgo: minialgo.tab.c minialgo.tab.h lex.yy.c symtable.c quad.c main.c
	$(CC) $(CFLAGS) -o minialgo minialgo.tab.c lex.yy.c symtable.c quad.c main.c

# Générer le parser Bison
minialgo.tab.c minialgo.tab.h: minialgo.y
	bison -d minialgo.y -o minialgo.tab.c

# Générer l'analyseur lexical Flex
lex.yy.c: minialgo.l minialgo.tab.h
	flex -o lex.yy.c minialgo.l

clean:
	rm -f minialgo minialgo.tab.c minialgo.tab.h lex.yy.c *.o output.asm

# Lancer avec un fichier test
run: minialgo
	./minialgo test.mga

.PHONY: all clean run
