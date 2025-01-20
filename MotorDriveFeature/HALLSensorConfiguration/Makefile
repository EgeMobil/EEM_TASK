# Compiler ve bayraklar
CC = gcc
CFLAGS = -I../Abstract_MotorDriver/IHALLA/inc \
		 -I../Abstract_MotorDriver/IHALLB/inc \
		 -I../Abstract_MotorDriver/IHALLC/inc \
		 -I../Abstract_MotorDriver/IPwmStep/inc \
		 -I../Abstract_MotorDriver \
		 -I./inc \
		 -I./build \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcHALLSensorConfiguration.c \
	  ./src/HALLSensorConfiguration.c \
	  ./src/HALLSensorConfiguration_ruUpdateA.c \
	  ./src/HALLSensorConfiguration_ruUpdateB.c \
	  ./src/HALLSensorConfiguration_ruUpdateC.c \
	  ./src/HALLSensorConfiguration_ruInitialisation.c \
	  ../Abstract_MotorDriver/IHALLA/src/IHALLA.c \
	  ../Abstract_MotorDriver/IHALLB/src/IHALLB.c \
	  ../Abstract_MotorDriver/IHALLC/src/IHALLC.c \
	  ../Abstract_MotorDriver/IPwmStep/src/IPwmStep.c \

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

