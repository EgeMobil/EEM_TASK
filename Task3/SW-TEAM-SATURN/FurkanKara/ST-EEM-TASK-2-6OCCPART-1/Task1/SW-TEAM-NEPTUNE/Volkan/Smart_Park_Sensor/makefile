CC = gcc
CFLAGS = -Wall -Wextra -IParkingAssistant/Inc  # Include yolu ekleniyor

# ParkingAssistant klasöründeki tüm .c dosyalarını bul ve listele
SRC = main.c $(wildcard ParkingAssistant/Src/*.c)
TARGET = output.exe

# Makefile'daki ana hedef
all: $(TARGET)

# Doğrudan .c dosyalarından executable oluştur
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Temizleme işlemi (sadece output.exe'yi siler)
clean:
	del output.exe 2> NUL || rm -f output.exe