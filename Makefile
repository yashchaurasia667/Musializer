CC= gcc
CFLAGS= -Wall -Wextra
LIBS = -lraylib -lglfw -ldl -lpthread	
DEPENDENCIES=

SRC_DIR=src
BUILD_DIR=build

default: $(BUILD_DIR)/musializer

$(BUILD_DIR)/musializer: $(SRC_DIR)/main.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(DEPENDENCIES) $< $(LIBS)

clean: $(BUILD_DIR)
	rm -rf $(BUILD_DIR)

run: $(BUILD_DIR)/musializer
	$(BUILD_DIR)/musializer
