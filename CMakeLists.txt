cmake_minimum_required(VERSION 3.10)
project(trading_bot)

set(CMAKE_CXX_STANDARD 17)

# Find libcurl
find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(Xlsxwriter REQUIRED IMPORTED_TARGET xlsxwriter)

include_directories(src/api)

# Add the executable
add_executable(trading_bot test/main.cpp src/api/binance/binance_api.cpp
        src/api/binance/binance_api.cpp
        test/trade_endpoint.cpp
        src/api/curl_main.cpp
        src/api/alphavantage/alphavantage_api.h
        src/api/alphavantage/alphavantage_api.cpp)

target_link_libraries(${PROJECT_NAME} PkgConfig::Xlsxwriter)
target_link_libraries(trading_bot CURL::libcurl)




