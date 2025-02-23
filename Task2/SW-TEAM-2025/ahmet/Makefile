# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./src/main.c ./src/ECUStateManager.c
OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

