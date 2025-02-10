# Compiler ve bayraklar
CC = gcc
CFLAGS = -I../Abstract_SmartGateDriver \
		 -I../Abstract_SmartGateDriver/IDRV8353/inc \
		 -I./inc \
		 -I./build \
		 -I../ECUStateManager/inc \
		 -Wall -Wextra -g

# Kaynak dosyalar ve çıktı dosyası
SRC = ./build/main.c \
	  ./build/tcGateDriverController.c \
	  ./src/GateDriverController.c \
	  ./src/GateDriverController_ruInitialisation.c \
	  ./src/GateDriverController_ruRefresh.c \
	  ../Abstract_SmartGateDriver/IDRV8353/src/IDRV8353.c \
	  
OUT = ./build/main.exe

# Varsayılan hedef
all: $(OUT)

# Çıktı dosyasını oluşturma
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Temizlik
clean:
	if exist build\*.exe del /Q build\*.exe

