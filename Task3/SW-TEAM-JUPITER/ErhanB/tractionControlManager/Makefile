# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
		./build/traction_control_manager.c \
		./src/traction_control.c

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\.exe del /Q build\.exe