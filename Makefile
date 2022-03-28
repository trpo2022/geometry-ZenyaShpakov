CFLAGS = -Wall -Wextra -Werror
CCFLAGS = -Wall -Wextra -Wconversion -Wredundant-decls -Wshadow -Wno-unused-parameter

all: geometry

geometry: bin/geometry

test: bin/test

obj/test/main.o: test/main.cpp
	        g++ -c $(CCFLAGS) -o $@ $< -lm

obj/test/shapes_test.o: test/shapes_test.cpp
	        g++ -c $(CCFLAGS) -o $@ $< -lm
		        
bin/test: obj/test/main.o obj/test/shapes_test.o obj/test/shapes.o
	        g++ $(LDFLAGS) obj/test/main.o obj/test/shapes_test.o obj/test/shapes.o -o bin/test -lm

obj/test/shapes.o: src/statlib/shapes.cpp
	 g++ -c -I src $(CFLAGS) -o $@ $< -lm

bin/geometry: obj/src/geometry/main.o obj/src/statlib/statlib.a
	        g++ $(CFLAGS) -o $@ $^ -lm

obj/src/geometry/main.o: src/geometry/main.cpp
	        g++ -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/statlib/statlib.a: obj/src/statlib/shapes.o obj/src/statlib/fileread.o
	        ar rcs $@ $^

obj/src/statlib/fileread.o: src/statlib/fileread.cpp
	        g++ -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/statlib/shapes.o: src/statlib/shapes.cpp
	        g++ -c -I src $(CFLAGS) -o $@ $< -lm




.PHONY: clean

clean:
	        rm obj/test/*.o bin/test obj/src/statlib/*.a obj/src/statlib/*.o obj/src/geometry/*.o bin/geometry
