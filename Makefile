# Variables de compilacion
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Ibiblioteca

# Directorio de salida
BIN_DIR = bin

ifeq ($(OS),Windows_NT)
    # En Windows usamos cmd.exe que siempre está disponible
    # Esto evita errores de CreateProcess cuando las herramientas de compilación no están en el PATH
    MKDIR = cmd.exe /c "if not exist $(BIN_DIR) mkdir $(BIN_DIR)"
    RM = cmd.exe /c "if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)"
    TARGET = $(BIN_DIR)/main.exe
    RUN_CMD = $(TARGET)
else
    # Linux / macOS
    MKDIR = mkdir -p $(BIN_DIR)
    RM = rm -rf $(BIN_DIR)
    TARGET = $(BIN_DIR)/main.exe
    RUN_CMD = ./$(TARGET)
endif

# Archivos fuente (busca todos los .cpp dentro de la carpeta src)
SRCS = $(wildcard src/*.cpp)

# Regla por defecto: compilar el ejecutable
all: $(TARGET)

# Esta regla compila el ejecutable y se asegura de que exista la carpeta bin
$(TARGET): $(SRCS)
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regla para limpiar los ejecutables y la carpeta bin generada
clean:
	-@$(RM)

# Regla para compilar y ejecutar de una sola vez
run: all
	$(RUN_CMD)

.PHONY: all clean run
