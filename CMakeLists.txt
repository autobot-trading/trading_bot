cmake_minimum_required(VERSION 3.10)
project(trading_bot)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/libxlsxwriter/1.1.7")

# Find libcurl
find_package(CURL REQUIRED)
find_package(libxlsxwriter REQUIRED)

# Add the executable
add_executable(trading_bot test/main.cpp binance_api.cpp
        binance_api.cpp)

# Link against libcurl
target_link_libraries(trading_bot CURL::libcurl)
target_link_libraries(trading_bot libxlsxwriter::libxlsxwriter)

