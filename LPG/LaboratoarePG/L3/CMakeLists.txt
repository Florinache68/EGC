include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l30 main0.cpp)
target_link_libraries(l30 freeglut)

add_executable(l31 main1.cpp)
target_link_libraries(l31 freeglut)

add_executable(l32 main2.cpp)
target_link_libraries(l32 freeglut)

add_executable(l33 main3.cpp)
target_link_libraries(l33 freeglut)






