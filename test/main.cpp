//
// Created by Wh Kang on 8/4/24.
//

#include <iostream>
#include <fstream>
#include <filesystem> // For filesystem operations (C++17)
#include "../binance_api.h"

namespace fs = std::__fs::filesystem;

#define STRINGIFY(x) #x

void printRes(const std::string& api, const std::string& methodName = "unknown");

#define PRINT_RES(api) printRes(api, "1")

int main() {
    PRINT_RES(BinanceAPI::ping());
    PRINT_RES(BinanceAPI::exchangeInfo());
    PRINT_RES(BinanceAPI::depth("BTCUSDT"));
    PRINT_RES(BinanceAPI::trade("BTCUSDT", "5"));
    PRINT_RES(BinanceAPI::klines("BTCUSDT", "1m", "5", "", "", "8"));

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

