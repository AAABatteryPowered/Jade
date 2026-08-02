.SILENT:

all:
	gcc main.c src/types/value/value.c src/types/dict/dict.c src/types/array/array.c src/lexer/lexer.c src/parser/parser.c src/serializer/serializer.c -pg -o main

run: all
	./main