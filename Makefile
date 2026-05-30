# Variables de compilacion
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Ibiblioteca

# Directorio de salida y ejecutable
BIN_DIR = bin
TARGET = $(BIN_DIR)/main.exe

# Archivos fuente (busca todos los .cpp dentro de la carpeta src)
SRCS = $(wildcard src/*.cpp)

# Regla por defecto: compilar el ejecutable
all: $(TARGET)

# Esta regla compila el ejecutable y se asegura de que exista la carpeta bin
$(TARGET): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regla para limpiar los ejecutables y la carpeta bin generada
clean:
	-@rm -rf $(BIN_DIR)

# Regla para compilar y ejecutar de una sola vez
run: all
	./$(TARGET)

.PHONY: all clean run
