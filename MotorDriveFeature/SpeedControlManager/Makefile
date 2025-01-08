# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcSpeedControlManager.c \
	  ./src/SpeedControlManager.c \
      ./src/SpeedControlManager_ruInitialisation.c \
      ./src/SpeedControlManager_ruUpdate.c \
	  ./src/SpeedControlManager_ruRefresh.c 

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

