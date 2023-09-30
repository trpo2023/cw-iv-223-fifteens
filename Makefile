CC = g++
CXXFLAGS = -std=c++11 -I../lib/thirdparty # Добавьте -I с указанием пути к ctest.h
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

OBJ_DIR = obj
BIN_DIR = bin

all: $(BIN_DIR)/game

$(BIN_DIR)/game: $(OBJ_DIR)/main.o $(OBJ_DIR)/functions.o
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/functions.o -o $(BIN_DIR)/game $(SFML_LIBS)

$(OBJ_DIR)/main.o: src/app/main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c src/app/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/functions.o: src/app_lib/functions.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c src/app_lib/functions.cpp -o $(OBJ_DIR)/functions.o

tests: $(OBJ_DIR)/tests.o $(OBJ_DIR)/functions.o
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_DIR)/tests.o $(OBJ_DIR)/functions.o -o $(BIN_DIR)/tests $(SFML_LIBS) 
	ar rcs lib/mylib.a $(OBJ_DIR)/functions.o

$(OBJ_DIR)/tests.o: tests/tests.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c tests/tests.cpp -o $(OBJ_DIR)/tests.o

run: $(BIN_DIR)/game
	./$(BIN_DIR)/game

run_tests: $(BIN_DIR)/tests
	xvfb-run -a ./$(BIN_DIR)/tests

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
