cmake_minimum_required(VERSION 3.10)
project(trading_bot)

set(CMAKE_CXX_STANDARD 17)

# Find libcurl
find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
## link libs
find_package(SQLite3 REQUIRED)
find_package(oatpp          1.4.0 REQUIRED)
find_package(oatpp-swagger  1.4.0 REQUIRED)
find_package(oatpp-sqlite   1.4.0 REQUIRED)

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
        src/db/mysql_test.cpp
        src/webserver/App.cpp
        src/webserver/ErrorHandler.cpp
        src/webserver/service/UserService.cpp
        src/webserver/dto/PageDto.hpp
        src/webserver/controller/AlphaVantageController.hpp
        src/webserver/service/AlphaVantageService.hpp
        src/webserver/service/AlphaVantageService.cpp
)

target_link_libraries(${PROJECT_NAME}
        # Oat++
        PUBLIC CURL::libcurl

        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-sqlite
        PUBLIC mysqlcppconn
        PUBLIC ${OPENSSL_LIBRARIES}
        PUBLIC PkgConfig::Xlsxwriter
)

add_definitions(
        ## define path to swagger-ui static resources folder
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        ## SQLite database file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"
        ## SQLite database test file
        -DTESTDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/test-db.sqlite"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(crud-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()



