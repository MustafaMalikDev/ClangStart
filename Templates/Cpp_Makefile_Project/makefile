CC := g++
CFLAGS := -Wall -Wextra -I./cli/include -std=c++17 -DRD_DEBUG
# -g

SRC_DIR := ./cli/src
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
BIN := $(BUILD_DIR)/reactdocs

MAIN_SRC := $(SRC_DIR)/main.cpp
SRCS := $(filter-out $(MAIN_SRC), $(shell find $(SRC_DIR) -name '*.cpp'))
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
MAIN_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(MAIN_SRC))

all: $(BIN)

$(BIN): $(OBJS) $(MAIN_OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

fmt:
	ligen2 --license ./ligen.txt --allow include --width 1
	ligen2 --license ./ligen.txt --allow src --width 1
	sh ./format.sh

run:
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR)

install:
	sudo cp ./$(BIN) /usr/local/bin

.PHONY: all clean
