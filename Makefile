.SILENT:

all:
	gcc main.c src/types/dict/dict.c -o main

run: all
	./main