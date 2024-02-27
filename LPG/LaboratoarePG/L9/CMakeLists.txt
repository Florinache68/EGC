include_directories(${FreeGlut_INCLUDE})
link_directories(${FreeGlut_LIB})
file(COPY ${FreeGlut_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(l90 main0.cpp)
target_link_libraries(l90 freeglut)

add_executable(l91 main1.cpp ImageLoad.h ImageLoad.cpp)
target_link_libraries(l91 freeglut)


