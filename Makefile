CC= gcc
CFLAGS= -Wall -Wextra
LIBS = -lraylib -lglfw -ldl -lpthread	
DEPENDENCIES=

default: musializer

musializer: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/musializer $(DEPENDENCIES) main.c $(LIBS)

clean: build
	rm -rf build

run: build/musializer
	build/musializer
