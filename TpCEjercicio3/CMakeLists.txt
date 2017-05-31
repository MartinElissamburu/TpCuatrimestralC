cmake_minimum_required(VERSION 3.6)
project(TpCEjercicio3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/main.c src/Library.h src/Library.c src/Material.c src/Material.h src/Person.c src/Person.h src/Loan.c src/Loan.h)
add_executable(TpCEjercicio3 ${SOURCE_FILES})