cmake_minimum_required(VERSION 3.10)
project(trading_bot)

set(CMAKE_CXX_STANDARD 17)

# Find libcurl
find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(Xlsxwriter REQUIRED IMPORTED_TARGET xlsxwriter)

include_directories(src/api)
include_directories(/usr/local/mysql-connector-c++/include)
include_directories(/usr/local/mysql-connector-c++/include/jdbc)

link_directories(/usr/local/mysql-connector-c++/lib64)

# Find OpenSSL package
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# Add the executable
add_executable(
        trading_bot 
        test/main.cpp 
        src/api/binance/binance_api.cpp
        src/api/binance/binance_api.cpp
        src/api/curl_main.cpp
        src/api/alphavantage/alphavantage_api.h
        src/api/alphavantage/alphavantage_api.cpp
        src/db/mysql_test.h
        src/db/mysql_test.cpp)

target_link_libraries(${PROJECT_NAME} PkgConfig::Xlsxwriter)
target_link_libraries(trading_bot CURL::libcurl)
target_link_libraries(trading_bot mysqlcppconn ${OPENSSL_LIBRARIES})




