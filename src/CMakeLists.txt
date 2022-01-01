cmake_minimum_required(VERSION 3.2)
project(compiler)

set(SOURCE_FILES main.cpp analysis/lexer.h analysis/lexer.cpp analysis/token.h analysis/token.cpp)

add_executable(compiler ${SOURCE_FILES} )
install(TARGETS compiler DESTINATION ${SNOW_INSTALL_BIN_DIR})