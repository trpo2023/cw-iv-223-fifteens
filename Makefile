CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = game
SRC_DIR = src/app
LIB_SRC_DIR = src/app_lib

SRC = $(SRC_DIR)/main.cpp
OBJ = main.o

LIB_SRC = $(LIB_SRC_DIR)/functions.cpp
LIB_OBJ = functions.o

TEST_SRC = $(SRC_DIR)/tests.cpp
TEST_OBJ = tests.o

all: $(TARGET) run_tests

$(TARGET): $(OBJ) $(LIB_OBJ)
	$(CC) $(OBJ) $(LIB_OBJ) -o $(TARGET) $(SFML_LIBS)

main.o: $(SRC)
	$(CC) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

functions.o: $(LIB_SRC)
	$(CC) $(CXXFLAGS) -c $(LIB_SRC) -o $(LIB_OBJ)

tests.o: $(TEST_SRC)
	$(CC) $(CXXFLAGS) -c $(TEST_SRC) -o $(TEST_OBJ)

run_tests: $(TEST_OBJ) $(LIB_OBJ)
	$(CC) $(TEST_OBJ) $(LIB_OBJ) -o tests $(SFML_LIBS)

clean:
	rm -f $(OBJ) $(LIB_OBJ) $(TEST_OBJ) $(TARGET) tests
