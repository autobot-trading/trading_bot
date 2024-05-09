cmake_minimum_required(VERSION 3.10)
project(trading_bot)

set(CMAKE_CXX_STANDARD 17)

# Find libcurl
find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(Xlsxwriter REQUIRED IMPORTED_TARGET xlsxwriter)

# Add the executable
add_executable(trading_bot test/main.cpp binance_api.cpp
        binance_api.cpp
        place_order.cpp
        place_order.h
        binacpp.h
        binacpp_websocket.cpp
        binacpp.cpp
)

target_link_libraries(${PROJECT_NAME} PkgConfig::Xlsxwriter)
target_link_libraries(trading_bot CURL::libcurl)
# Add OpenSSL
find_package(OpenSSL REQUIRED)
target_link_libraries(trading_bot OpenSSL::SSL)

# Set the path to the jsoncpp package configuration file
set(jsoncpp_DIR /opt/homebrew/opt/jsoncpp) # Update this line
find_package(jsoncpp REQUIRED)
# target_link_libraries(trading_bot jsoncpp_lib)

#include "json/json.h"




