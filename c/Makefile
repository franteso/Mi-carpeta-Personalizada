# Variables de compilacion
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Directorio de salida y ejecutable
BUILD_DIR = build
TARGET = $(BUILD_DIR)/main.exe

# Archivos fuente (busca todos los .c dentro de la carpeta src)
SRCS = $(wildcard src/*.c)

# Regla por defecto: compilar el ejecutable
all: $(TARGET)

# Esta regla compila el ejecutable y se asegura de que exista la carpeta build
$(TARGET): $(SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Regla para limpiar los ejecutables y la carpeta build generada
clean:
	-@rm -rf $(BUILD_DIR)

# Regla para compilar y ejecutar de una sola vez
run: all
	./$(TARGET)

.PHONY: all clean run
