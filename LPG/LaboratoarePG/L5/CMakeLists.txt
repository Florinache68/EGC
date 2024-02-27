include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l50 main0.cpp)
target_link_libraries(l50 freeglut)

add_executable(l51 main1.cpp)
target_link_libraries(l51 freeglut)

add_executable(l52 main2.cpp)
target_link_libraries(l52 freeglut)

add_executable(l53 main3.cpp)
target_link_libraries(l53 freeglut)

add_executable(l54 main4.cpp)
target_link_libraries(l54 freeglut)

add_executable(l55 main5.cpp)
target_link_libraries(l55 freeglut)







