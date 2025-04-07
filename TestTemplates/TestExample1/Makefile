CC = gcc

COVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -Wall -Iinc -Iexternal/CUnit/Headers $(COVFLAGS)
LDFLAGS = $(COVFLAGS) -lgcov

BUILD_DIR = build
TARGET = $(BUILD_DIR)/test_runner.exe

SRC = src/math.c
TEST = test/main.c
CUNIT_SRC = \
  external/CUnit/Sources/Framework/TestDB.c \
  external/CUnit/Sources/Framework/TestRun.c \
  external/CUnit/Sources/Framework/MyMem.c \
  external/CUnit/Sources/Framework/Util.c \
  external/CUnit/Sources/Framework/CUError.c \
  external/CUnit/Sources/Automated/Automated.c \
  external/CUnit/Sources/Console/Console.c \
  external/CUnit/Sources/Basic/Basic.c

ALL_SRC = $(SRC) $(TEST) $(CUNIT_SRC)

# .c -> .o dönüşümü (hepsi build/ altında olacak)
OBJS = $(ALL_SRC:%.c=$(BUILD_DIR)/%.o)

all: prepare_dirs $(TARGET)

# object dosyaları build dizinine yazılır
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# linkleme işlemi
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# klasörleri manuel oluştur
prepare_dirs:
	@if not exist build\src mkdir build\src
	@if not exist build\test mkdir build\test
	@if not exist build\external\CUnit\Sources\Framework mkdir build\external\CUnit\Sources\Framework
	@if not exist build\external\CUnit\Sources\Basic mkdir build\external\CUnit\Sources\Basic
	@if not exist build\external\CUnit\Sources\Console mkdir build\external\CUnit\Sources\Console
	@if not exist build\external\CUnit\Sources\Automated mkdir build\external\CUnit\Sources\Automated

cunit_xml:
	./build/test_runner.exe

coverage_xml:
	python -m gcovr --root . --object-directory build --xml -o build/coverage_report.xml

coverage_gcov:
	gcov -o build/src src/math.c
	gcov -o build/test test/main.c
	if exist math.c.gcov move /Y math.c.gcov build\\
	if exist main.c.gcov move /Y main.c.gcov build\\

report: cunit_xml coverage_xml coverage_gcov

# temizleme
clean:
	@if exist build\*.exe del /Q build\*.exe
	@if exist build\*.o del /Q build\*.o
	@if exist build\src\*.o del /Q build\src\*.o
	@if exist build\test\*.o del /Q build\test\*.o
	@if exist build\external\CUnit\Sources\Framework\*.o del /Q build\external\CUnit\Sources\Framework\*.o
	@if exist build\external\CUnit\Sources\Basic\*.o del /Q build\external\CUnit\Sources\Basic\*.o
	@if exist build\external\CUnit\Sources\Automated\*.o del /Q build\external\CUnit\Sources\Automated\*.o
	@if exist build\external\CUnit\Sources\Console\*.o del /Q build\external\CUnit\Sources\Console\*.o
	@if exist build\*.gcda del /Q build\*.gcda
	@if exist build\*.gcno del /Q build\*.gcno
	@if exist build\*.gcov del /Q build\*.gcov
	@if exist build\*.xml del /Q build\*.xml
	@if exist build\src\*.gc* del /Q build\src\*.gc*
	@if exist build\test\*.gc* del /Q build\test\*.gc*

