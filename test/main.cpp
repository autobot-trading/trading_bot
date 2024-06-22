//
// Created by Wh Kang on 8/4/24.
//

#include <iostream>
#include <fstream>
#include <filesystem> // For filesystem operations (C++17)
#include <xlsxwriter.h>
#include <sstream>
#include "../src/api/binance/binance_api.h"

namespace fs = std::filesystem;

// Macro to remove "::" from method names
#define REMOVE_SCOPE(x) (std::string(#x).substr(std::string(#x).find_last_of("::") + 1))

void printRes(const std::string& api, const std::string& methodName = "unknown");
void generateExcel(const std::string& response);

#define PRINT_RES(api) printRes(api, REMOVE_SCOPE(api))

int main() {
    PRINT_RES(BinanceAPI::ping());
    PRINT_RES(BinanceAPI::exchangeInfo());
    PRINT_RES(BinanceAPI::depth("BTCUSDT"));
    PRINT_RES(BinanceAPI::trade("BTCUSDT", "5"));
    std::string response = BinanceAPI::klines("BTCUSDT", "1m", "5", "", "", "8");
    PRINT_RES(response);
    generateExcel(response);
    return 0;
}

void printRes(const std::string& api, const std::string& methodName) {
    // Create directory if it doesn't exist
    std::string directory = "json";
    if (!fs::exists(directory))
        fs::create_directory(directory);

    // Write JSON to file in json directory
    std::string filename = directory + "/" + methodName + ".json";
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << api;
        outputFile.close();
        std::cout << "Response written to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open output file" << std::endl;
    }
}

void generateExcel(const std::string& response) {
    // Create a new workbook
    lxw_workbook *workbook = workbook_new("klines.xlsx");

    // Add a worksheet
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    // Write the klines data to the worksheet
    std::istringstream iss(response);
    std::string line;
    int row = 0;
    while (std::getline(iss, line)) {
        std::istringstream lineStream(line);
        std::string cell;
        int col = 0;
        while (std::getline(lineStream, cell, ',')) {
            worksheet_write_string(worksheet, row, col++, cell.c_str(), NULL);
        }
        row++;
    }

    // Close the workbook
    workbook_close(workbook);
}

