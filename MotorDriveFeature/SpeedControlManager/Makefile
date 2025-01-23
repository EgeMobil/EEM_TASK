# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../Abstract_MotorDriver/IRawSpeed/inc\
 		 -I../Abstract_MotorDriver/IIndicatorSpeedStatus/inc \
		 -I../Abstract_MotorDriver/ISpeedStatus/inc \
 		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcSpeedControlManager.c \
	  ../Abstract_MotorDriver/IRawSpeed/src/IRawSpeed.c\
	  ../Abstract_MotorDriver/IIndicatorSpeedStatus/src/IIndicatorSpeedStatus.c\
	  ../Abstract_MotorDriver/ISpeedStatus/src/ISpeedStatus.c\
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
	rm -f build/*.exe

