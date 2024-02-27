include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l120 main0.cpp)
target_link_libraries(l120 freeglut)

add_executable(l121 main1.cpp)
target_link_libraries(l121 freeglut)



