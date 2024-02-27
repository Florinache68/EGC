include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l80 main0.cpp)
target_link_libraries(l80 freeglut)

add_executable(l81 main1.cpp)
target_link_libraries(l81 freeglut)

add_executable(l82 main2.cpp)
target_link_libraries(l82 freeglut)

add_executable(l83 main3.cpp)
target_link_libraries(l83 freeglut)

add_executable(l84 main4.cpp)
target_link_libraries(l84 freeglut)

add_executable(l85 main5.cpp)
target_link_libraries(l85 freeglut)

add_executable(l86 main6.cpp)
target_link_libraries(l86 freeglut)



