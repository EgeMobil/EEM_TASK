# Derleyici
CC = gcc

# Derleyici bayrakları
CFLAGS = -Wall -Wextra -Werror -I./inc

# Çıktı çalıştırılabilir dosya adı (build klasörüne çıkarılacak)
TARGET = ./build/steering_control.exe

# Kaynak dosya
SRC_DIR = ./src
SRCS = $(SRC_DIR)/steering_control.c

# Nesne dosyası (build klasörüne çıkarılacak)
OBJ_DIR = ./build
OBJS = $(OBJ_DIR)/steering_control.o

# Başlık dosyaları
INC_FILES = ./inc/definition.h ./inc/steering_control_private.h ./inc/steering_control_public.h

# Varsayılan hedef: programı derle
all: $(TARGET)

# Nesne dosyasını oluşturma kuralı
$(OBJS): $(SRCS) $(INC_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Çalıştırılabilir dosyayı oluşturma kuralı
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Derlenmiş dosyaları temizleme kuralı
clean:
	rm -rf $(OBJ_DIR)