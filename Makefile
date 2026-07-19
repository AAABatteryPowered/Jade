.SILENT:

all:
	gcc main.c src/types/dict/dict.c src/types/array/array.c -o main

run: all
	./main