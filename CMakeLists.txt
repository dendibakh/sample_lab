cmake_minimum_required(VERSION 2.8)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "-O3 -ffast-math -march=core-avx2 ${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "-O3 -ffast-math -march=core-avx2 ${CMAKE_C_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "/O2 /fp:fast /arch:AVX2 ${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "/O2 /fp:fast /arch:AVX2 ${CMAKE_C_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:2000000")
endif()

add_executable(lab bench.cpp solution.cpp)

if(NOT MSVC)
    target_link_libraries(lab benchmark pthread)
else()
    target_link_libraries(lab benchmark)
endif()
