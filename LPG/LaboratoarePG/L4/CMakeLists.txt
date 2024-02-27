include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l40 main0.cpp)
target_link_libraries(l40 freeglut)

add_executable(l41 main1.cpp)
target_link_libraries(l41 freeglut)

add_executable(l42 main2.cpp)
target_link_libraries(l42 freeglut)

add_executable(l43 main3.cpp)
target_link_libraries(l43 freeglut)







