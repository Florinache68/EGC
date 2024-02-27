include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l110 main0.cpp)
target_link_libraries(l110 freeglut)

add_executable(l111 main1.cpp)
target_link_libraries(l111 freeglut)