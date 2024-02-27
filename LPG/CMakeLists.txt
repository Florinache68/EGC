cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(LaboratorProcesareGrafica)

set(FreeGlut_INCLUDE "${CMAKE_SOURCE_DIR}/freeglut/include")
set(FreeGlut_DLL "${CMAKE_SOURCE_DIR}/freeglut/bin/x64/freeglut.dll")
set(FreeGlut_LIB "${CMAKE_SOURCE_DIR}/freeglut/lib/x64")

add_subdirectory(L1)
add_subdirectory(L2)
add_subdirectory(L3)
add_subdirectory(L4)
add_subdirectory(L5)
add_subdirectory(L6)
add_subdirectory(L7)
add_subdirectory(L8)
add_subdirectory(L9)
add_subdirectory(L11)
add_subdirectory(L12)