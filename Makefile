all: geometry.c
	gcc -Wall -o geometry geometry.c -lm -Werror
clean: 
	rm geometry
run:
	./geometry
