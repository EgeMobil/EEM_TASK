# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../Abstract_MotorDriver/IMotorDriveError/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcMotorDriverDcmProxy.c \
      ./src/MotorDriverDcmProxy.c \
      ./src/MotorDriverDcmProxy_ruCollect.c \
      ./src/MotorDriverDcmProxy_ruRefresh.c \
      ../Abstract_MotorDriver/IMotorDriveError/src/IMotorDriveError.c \

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

