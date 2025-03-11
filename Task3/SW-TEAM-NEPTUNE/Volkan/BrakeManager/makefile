CC = gcc
CFLAGS = -Wall -Wextra -I./Inc  # Include path düzeltildi

# BrakeManager/Src dosyalarındaki tüm .c dosyalarını ekle
SRC = main.c $(wildcard Src/*.c)

TARGET = output.exe

# Ana hedef
all: $(TARGET)

# Derleme komutu
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Temizleme işlemi
clean:
	if exist output.exe del output.exe || rm -f output.exe