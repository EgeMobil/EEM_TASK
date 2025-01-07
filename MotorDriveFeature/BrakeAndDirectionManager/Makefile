# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../Abstract_MotorDriver/IBrakeAndDirection/inc \
		 -I../Abstract_MotorDriver/IBrakeStatus/inc \
		 -I../Abstract_MotorDriver/IDirectionStatus/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcBrakeAndDirectionManager.c \
      ./src/BrakeAndDirectionManager.c \
      ./src/BrakeAndDirectionManager_ruInitialisation.c \
      ./src/BrakeAndDirectionManager_ruUpdate.c \
      ../Abstract_MotorDriver/IBrakeAndDirection/src/IBrakeAndDirection.c \
	  ../Abstract_MotorDriver/IBrakeStatus/src/IBrakeStatus.c \
	  ../Abstract_MotorDriver/IDirectionStatus/src/IDirectionStatus.c

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

