all: geometry
	gcc -Wall -Werror -o geometry geometry.c -lm
claen: 
	rm geometry
run:
	./geometry
