CFLAGS = -Wall -Wextra -Werror 

CC = g++

all: geometry test

geometry: bin/geometry

bin/geometry: obj/src/geometry/main.o obj/src/statlib/statlib.a
	                $(CC) $(CFLAGS) -o $@ $^ -lm

obj/src/geometry/main.o: src/geometry/main.cpp
	                $(CC) -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/statlib/statlib.a: obj/src/statlib/shapes.o obj/src/statlib/fileread.o
	                ar rcs $@ $^

obj/src/statlib/shapes.o: src/statlib/shapes.cpp
	                $(CC) -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/statlib/fileread.o: src/statlib/fileread.cpp
	                $(CC) -c -I src $(CFLAGS) -o $@ $< -lm
test: bin/test

bin/test: obj/test/main.o obj/test/shapes_test.o
	$(CC) -I src  $(CFLAGS) -o $@ $< -lm

obj/test/main.o: test/main.cpp
	$(CC) -c -I src  $(CFLAGS) -o $@ $<

obj/test/shapes_test.o: test/shapes_test.cpp
	$(CC) -c -I src  $(CFLAGS) -o $@ $< -lm

.PHONY: clean

clean:
	                rm obj/src/statlib/*.a obj/src/statlib/*.o obj/src/geometry/*.o bin/geometry bin/test obj/test/*.o 
