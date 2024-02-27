include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l60 main0.cpp)
target_link_libraries(l60 freeglut)

add_executable(l61 main1.cpp)
target_link_libraries(l61 freeglut)

add_executable(l62 main2.cpp)
target_link_libraries(l62 freeglut)

add_executable(l63 main3.cpp)
target_link_libraries(l63 freeglut)

add_executable(l64 main4.cpp)
target_link_libraries(l64 freeglut)

add_executable(l65 main5.cpp)
target_link_libraries(l65 freeglut)

add_executable(l66 main6.cpp)
target_link_libraries(l66 freeglut)






