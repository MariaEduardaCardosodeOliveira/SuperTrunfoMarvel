# Nome do executável
TARGET = bin/super_trunfo

# Diretórios corretos
SRC_DIR = content/src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fonte (pega todos os .c dentro de content/src)
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Arquivos objeto (troca .c por .o e move para obj/)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regra para compilar o executável
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Regra para compilar .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretórios se não existirem
$(BIN_DIR) $(OBJ_DIR):
	mkdir $@

# Limpar arquivos gerados
clean:
	-del /Q $(OBJ_DIR)\*.o $(TARGET) 2>nul
	-rm -f $(OBJ_DIR)/*.o $(TARGET)
