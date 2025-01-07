# Compiler ve bayraklar
CC = gcc
CFLAGS = -I./inc \
		 -I./build \
		 -I../Abstract_MotorDriver \
		 -I../Abstract_MotorDriver/IHALLA/inc \
		 -I../Abstract_MotorDriver/IHALLB/inc \
		 -I../Abstract_MotorDriver/IHALLC/inc \
		 -I../Abstract_CoreManager \
		 -I../Abstract_CoreManager/IExternalInterruptStatus/inc \
		 -I../Abstract_CoreManager/ITimerInterruptStatus/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcInterruptHandlerManager.c \
      ../Abstract_MotorDriver/IHALLA/src/IHALLA.c \
	  ../Abstract_MotorDriver/IHALLB/src/IHALLB.c \
	  ../Abstract_MotorDriver/IHALLC/src/IHALLC.c \
	  ../Abstract_CoreManager/IExternalInterruptStatus/src/IExternalInterruptStatus.c \
	  ../Abstract_CoreManager/ITimerInterruptStatus/src/ITimerInterruptStatus.c \
	  ./src/InterruptHandlerManager.c \
      ./src/InterruptHandlerManager_ruExternalTrigger.c \
      ./src/InterruptHandlerManager_ruTimerTrigger.c 

OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

