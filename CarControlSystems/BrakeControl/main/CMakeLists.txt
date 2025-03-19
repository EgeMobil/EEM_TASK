cmake_minimum_required(VERSION 3.10)

# Kaynak dosyaları tanımla
set(SOURCES
    main.c
    brake_control_private.c
    abs_algorithm.c
    brake_control_manager.c
)

# Header dosyalarının bulunduğu dizini belirt
include_directories(${CMAKE_SOURCE_DIR}/main)

# Çıktı olarak "BrakeControl" isimli bir yürütülebilir dosya üret
add_executable(BrakeControl ${SOURCES})