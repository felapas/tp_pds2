# Compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Estrutura de diretórios
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
INC_DIR = include

# Arquivos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/main

# Regras
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
