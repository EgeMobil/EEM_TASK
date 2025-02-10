# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../Abstract_MotorDriver/IPwmStep/inc \
		 -I../Abstract_MotorDriver/ISpeedStatus/inc \
		 -I../Abstract_MotorDriver/IBrakeStatus/inc \
		 -I../Abstract_MotorDriver/IDirectionStatus/inc \
		 -I../Abstract_CoreManager \
		 -I../Abstract_CoreManager/IGPIOStatus/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcPWMConfiguration.c \
	  ../Abstract_MotorDriver/IPwmStep/src/IPwmStep.c \
	  ../Abstract_MotorDriver/ISpeedStatus/src/ISpeedStatus.c \
	  ../Abstract_MotorDriver/IBrakeStatus/src/IBrakeStatus.c \
	  ../Abstract_MotorDriver/IDirectionStatus/src/IDirectionStatus.c \
	  ../Abstract_CoreManager/IGPIOStatus/src/IGPIOStatus.c \
	  ../Abstract_CoreManager/IGPIOStatus/src/IGPIOStatus_HAL_Impl.c \
	  ./src/PWMConfiguration.c \
	  ./src/PWMConfiguration_ruInitialisation.c \
	  ./src/PWMConfiguration_ruUpdate.c \
	  ./src/PWMConfiguration_ruRefresh.c 
OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)
# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

