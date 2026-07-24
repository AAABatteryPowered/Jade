.SILENT:

all:
	gcc main.c src/types/dict/dict.c src/types/array/array.c src/lexer/lexer.c src/parser/parser.c -o main

run: all
	./main