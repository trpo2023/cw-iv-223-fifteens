# Компилятор и флаги
CC = g++
CXXFLAGS = -std=c++11 -I../lib/thirdparty
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Каталоги
SRC_DIR = src/app
SRC_LIB_DIR = src/app_lib
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

# Имя вашей статической библиотеки
LIB_NAME = myapp_lib.a

# Исходные файлы
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
SRCS_LIB = $(wildcard $(SRC_LIB_DIR)/*.cpp)

# Объектные файлы
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_LIB = $(patsubst $(SRC_LIB_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_LIB))

# Главная цель: сборка приложения
all: $(BIN_DIR)/game

# Сборка приложения
$(BIN_DIR)/game: $(OBJS) $(LIB_DIR)/$(LIB_NAME)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -L$(LIB_DIR) -lmyapp_lib -o $(BIN_DIR)/game $(SFML_LIBS)

# Создание статической библиотеки
$(LIB_DIR)/$(LIB_NAME): $(OBJS_LIB)
	mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Правило компиляции исходных файлов приложения
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Правило компиляции исходных файлов библиотеки
$(OBJ_DIR)/%.o: $(SRC_LIB_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Цель для запуска приложения
run: $(BIN_DIR)/game
	./$(BIN_DIR)/game

# Очистка объектных файлов и бинарных файлов
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

# Запуск тестов
tests: $(OBJ_DIR)/tests.o $(LIB_DIR)/$(LIB_NAME)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_DIR)/tests.o -L$(LIB_DIR) -lmyapp_lib -o $(BIN_DIR)/tests $(SFML_LIBS)

# Правило компиляции тестов
$(OBJ_DIR)/tests.o: tests/tests.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Запуск тестов
run_tests: $(BIN_DIR)/tests
	xvfb-run -a ./$(BIN_DIR)/tests

