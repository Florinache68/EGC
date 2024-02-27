include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l20 main0.cpp)
target_link_libraries(l20 freeglut)

add_executable(l21 main1.cpp)
target_link_libraries(l21 freeglut)

add_executable(l22 main2.cpp)
target_link_libraries(l22 freeglut)

add_executable(l23 main3.cpp)
target_link_libraries(l23 freeglut)

add_executable(l24 main4.cpp)
target_link_libraries(l24 freeglut)

add_executable(l25 main5.cpp)
target_link_libraries(l25 freeglut)

add_executable(l26 main6.cpp)
target_link_libraries(l26 freeglut)






