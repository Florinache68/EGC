include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l70 main0.cpp)
target_link_libraries(l70 freeglut)

add_executable(l71 main1.cpp)
target_link_libraries(l71 freeglut)

add_executable(l72 main2.cpp)
target_link_libraries(l72 freeglut)

add_executable(l73 main3.cpp)
target_link_libraries(l73 freeglut)

add_executable(l74 main4.cpp)
target_link_libraries(l74 freeglut)

add_executable(l75 main5.cpp)
target_link_libraries(l75 freeglut)

add_executable(l76 main6.cpp)
target_link_libraries(l76 freeglut)