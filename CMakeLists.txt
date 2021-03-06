cmake_minimum_required(VERSION 2.8)
project(particle2d++)
find_package(OpenCV 3.0.0 EXACT REQUIRED )
set( NAME_SRC 
    bee-map.cpp
    logBook.cpp
    map.cpp
    main.cpp    
)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR} )
add_executable( particle2d++ ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( particle2d++ ${OpenCV_LIBS} )