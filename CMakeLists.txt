cmake_minimum_required(VERSION 3.10)
project(trading_bot)

set(CMAKE_CXX_STANDARD 17)

# Find libcurl
find_package(CURL REQUIRED)

# Add the executable
add_executable(trading_bot test/main.cpp binance_api.cpp
        binance_api.cpp)

# Link against libcurl
target_link_libraries(trading_bot CURL::libcurl)

