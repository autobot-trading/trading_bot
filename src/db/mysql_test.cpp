//
// Created by Wh Kang on 8/7/24.
//

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include "mysql_test.h"

void mysql_test::test() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

    try {
        // Initialize MySQL driver
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish a connection
        con = driver->connect("tcp://127.0.0.1:3306", "root", "Wertvb700!");

        // Connect to the MySQL test database
        con->setSchema("test");

        // Create a statement object
        stmt = con->createStatement();

        // Execute a query
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");

        // Process the result set
        while (res->next()) {
            std::cout << res->getString("_message") << std::endl;
        }

        // Clean up
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}
