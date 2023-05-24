CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = bin/game
SRC_DIR = src/app
LIB_SRC_DIR = src/app_lib
TEST_SRC_DIR = tests

SRC = $(SRC_DIR)/main.cpp
OBJ_DIR = obj
OBJ = $(OBJ_DIR)/main.o

LIB_SRC = $(LIB_SRC_DIR)/functions.cpp
LIB_OBJ = $(OBJ_DIR)/functions.o

TEST_SRC = $(TEST_SRC_DIR)/tests.cpp
TEST_OBJ = $(OBJ_DIR)/tests.o

all: $(TARGET) run_tests

$(TARGET): $(OBJ) $(LIB_OBJ)
	mkdir -p bin
	$(CC) $(OBJ) $(LIB_OBJ) -o $(TARGET) $(SFML_LIBS)

$(OBJ): $(SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

$(LIB_OBJ): $(LIB_SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $(LIB_SRC) -o $(LIB_OBJ)

$(TEST_OBJ): $(TEST_SRC)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

run_tests: $(TEST_OBJ) $(LIB_OBJ)
	mkdir -p bin
	$(CC) $(TEST_OBJ) $(LIB_OBJ) -o bin/tests $(SFML_LIBS)

clean:
	rm -rf $(OBJ_DIR) bin
