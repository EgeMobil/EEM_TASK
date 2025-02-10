# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
         -I./build \
         -I../SpeedControlManager/inc \
         -I../Abstract_MotorDriver/IRawSpeed/inc\
         -I../Abstract_MotorDriver/IIndicatorSpeedStatus/inc \
         -I../Abstract_MotorDriver/ISpeedStatus/inc \
         -I../Abstract_VehComManager \
         -I../Abstract_VehComManager/ISpeed/inc \
         -I../Abstract_VehComManager/IBdr/inc \
         -I../Abstract_MotorDriver \
         -I../Abstract_MotorDriver/IBrakeStatus/inc \
         -I../Abstract_MotorDriver/IBrakeAndDirection/inc \
         -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
      ./build/tcMotorDriverControlManager.c \
      ./src/MotorDriverControlManager.c \
      ./src/MotorDriverControlManager_ruInitialisation.c \
      ./src/MotorDriverControlManager_ruRefresh.c \
      ../Abstract_MotorDriver/IRawSpeed/src/IRawSpeed.c \
      ../Abstract_MotorDriver/IBrakeAndDirection/src/IBrakeAndDirection.c \
      ../Abstract_VehComManager/IBdr/src/IBdr.c \
      ../Abstract_VehComManager/ISpeed/src/ISpeed.c
OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe || echo "No files to delete."

