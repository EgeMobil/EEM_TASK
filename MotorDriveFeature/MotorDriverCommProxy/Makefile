# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../Abstract_MotorDriver/IIndicatorBdrStatus/inc \
		 -I../Abstract_MotorDriver/IIndicatorSpeedStatus/inc \
		 -I../Abstract_MotorDriver/IHALLWheelSpeed/inc \
		 -I../Abstract_VehComManager \
		 -I../Abstract_VehComManager/IIndicator/inc \
		 -I../Abstract_VehComManager/IWheelSpeed/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcMotorDriverCommProxy.c \
	  ./src/MotorDriverCommProxy.c \
      ./src/MotorDriverCommProxy_ruRefresh.c \
      ./src/MotorDriverCommProxy_ruUpdateIndicator.c \
	  ./src/MotorDriverCommProxy_ruUpdateWheelSpeed.c \
	  ../Abstract_MotorDriver/IIndicatorBdrStatus/src/IIndicatorBdrStatus.c \
	  ../Abstract_MotorDriver/IIndicatorSpeedStatus/src/IIndicatorSpeedStatus.c \
	  ../Abstract_MotorDriver/IHALLWheelSpeed/src/IHALLWheelSpeed.c \
	  ../Abstract_VehComManager/IIndicator/src/IIndicator.c \
	  ../Abstract_VehComManager/IWheelSpeed/src/IWheelSpeed.c \

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

