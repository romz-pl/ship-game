cmake_minimum_required( VERSION 3.0 )

project( ship-game )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

add_subdirectory( src )

file( COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/src/ )
