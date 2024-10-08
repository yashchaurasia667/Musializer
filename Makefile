CC = gcc
CFLAGS = -Wall 
LIBFLAGS = -lglfw -lGL

default: main

main: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/main main.c $(LIBFLAGS)
	./build/main

windows: main.c
	$(CC) $(CFLAGS) -o build/main main.c -IGLFW -LGLFW .\GLFW\glfw3.dll -lopengl32 -lgdi32 -lglfw3

clean:
	rm -rf build