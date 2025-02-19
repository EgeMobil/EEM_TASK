# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../SpeedControlManager/inc\
		 -I../Abstract_MotorDriver/IRawSpeed/inc\
 		 -I../Abstract_MotorDriver/IIndicatorSpeedStatus/inc \
		 -I../Abstract_MotorDriver/ISpeedStatus/inc \
		 -I../Abstract_MotorDriver/IBrakeAndDirection/inc \
		 -I../Abstract_MotorDriver/IBrakeStatus/inc \
		 -I../Abstract_MotorDriver/IDirectionStatus/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcBrakeAndDirectionManager.c \
      ./src/BrakeAndDirectionManager.c \
      ./src/BrakeAndDirectionManager_ruInitialisation.c \
      ./src/BrakeAndDirectionManager_ruRefresh.c \
	  ../Abstract_MotorDriver/IIndicatorSpeedStatus/src/IIndicatorSpeedStatus.c\
	  ../Abstract_MotorDriver/ISpeedStatus/src/ISpeedStatus.c\
	  ../Abstract_MotorDriver/IRawSpeed/src/IRawSpeed.c\
	  ../SpeedControlManager/src/SpeedControlManager.c \
	  ../SpeedControlManager/src/SpeedControlManager_ruInitialisation.c \
	  ../SpeedControlManager/src/SpeedControlManager_ruBrakeUpdate.c \
	  ../SpeedControlManager/src/SpeedControlManager_ruUpdate.c \
	  ../SpeedControlManager/src/SpeedControlManager_ruRefresh.c \
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

