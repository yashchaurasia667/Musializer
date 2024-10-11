CLFAGS = -Wall -Wextra 
LIBS = -lraylib -lglfw -ldl -lpthread	

default: musializer

musializer: main.c
	gcc $(CFLAGS) -o musializer main.c $(LIBS)