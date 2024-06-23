//
// Created by Wh Kang on 8/4/24.
//

#include <iostream>
#include <fstream>
#include <filesystem> // For filesystem operations (C++17)
#include <xlsxwriter.h>
#include <sstream>
#include "../src/api/binance/binance_api.h"
#include "alphavantage/alphavantage_api.h"


#include "../binacpp_utils.h"
#include "../binacpp_websocket.h"
#include "../binacpp_logger.h"


namespace fs = std::filesystem;

// Macro to remove "::" from method names
#define REMOVE_SCOPE(x) (std::string(#x).substr(std::string(#x).find_last_of("::") + 1))

void printRes(const std::string& api, const std::string& methodName = "unknown");
void generateExcel(const std::string& response);
void binanceApiTest();
void alphavantageApiTest();

#define PRINT_RES(api) printRes(api, REMOVE_SCOPE(api))

int main() {
    // binanceApiTest();
    alphavantageApiTest();
    return 0;
}

void binanceApiTest() {
    PRINT_RES(BinanceAPI::ping());
    PRINT_RES(BinanceAPI::exchangeInfo());
    PRINT_RES(BinanceAPI::depth("BTCUSDT"));
    PRINT_RES(BinanceAPI::trade("BTCUSDT", "5"));

    // below isn't complete yet
    // PRINT_RES(BinanceAPI::accountInfo("BTCUSDT", "5")); print account info
    
    std::string response = BinanceAPI::klines("BTCUSDT", "1m", "5", "", "", "8");
    PRINT_RES(response);
    generateExcel(response);
}

void alphavantageApiTest() {
    AlphaVantageAPI api("VX2MEZ75W5JNSLFY");

    // Core Stock APIs
    PRINT_RES(api.getIntraday("AAPL", "5min"));
    PRINT_RES(api.getDaily("AAPL"));
    PRINT_RES(api.getDailyAdjusted("AAPL"));
    PRINT_RES(api.getWeekly("AAPL"));
    PRINT_RES(api.getWeeklyAdjusted("AAPL"));
    PRINT_RES(api.getMonthly("AAPL"));
    PRINT_RES(api.getMonthlyAdjusted("AAPL"));
    PRINT_RES(api.getQuote("AAPL"));
    PRINT_RES(api.searchTicker("Apple"));
    PRINT_RES(api.getGlobalMarketStatus());

    // Alpha Intelligence™
    PRINT_RES(api.getNewsSentiments("AAPL"));
    PRINT_RES(api.getTopGainersLosers());
    PRINT_RES(api.getAnalytics("AAPL", "5min"));
    PRINT_RES(api.getSlidingWindowAnalytics("AAPL", "5min"));

    // Fundamental Data
    PRINT_RES(api.getCompanyOverview("AAPL"));
    PRINT_RES(api.getDividends("AAPL"));
    PRINT_RES(api.getSplits("AAPL"));
    PRINT_RES(api.getIncomeStatement("AAPL"));
    PRINT_RES(api.getBalanceSheet("AAPL"));
    PRINT_RES(api.getCashFlow("AAPL"));
    PRINT_RES(api.getEarnings("AAPL"));
    PRINT_RES(api.getListingDelistingStatus());
    PRINT_RES(api.getEarningsCalendar());
    PRINT_RES(api.getIPOCalendar());

    // Forex (FX)
    PRINT_RES(api.getForexExchangeRates("USD", "EUR"));
    PRINT_RES(api.getForexIntraday("EUR", "USD", "5min"));
    PRINT_RES(api.getForexDaily("EUR", "USD"));
    PRINT_RES(api.getForexWeekly("EUR", "USD"));
    PRINT_RES(api.getForexMonthly("EUR", "USD"));

    // Cryptocurrencies
    PRINT_RES(api.getCryptoExchangeRates("BTC"));
    PRINT_RES(api.getCryptoIntraday("BTC", "USD", "5min"));
    PRINT_RES(api.getCryptoDaily("BTC", "USD"));
    PRINT_RES(api.getCryptoWeekly("BTC", "USD"));
    PRINT_RES(api.getCryptoMonthly("BTC", "USD"));

    // Commodities
    PRINT_RES(api.getCommodity("WTI"));
    PRINT_RES(api.getCommodity("BRENT"));

    // Economic Indicators
    PRINT_RES(api.getEconomicIndicator("REAL_GDP"));
    PRINT_RES(api.getEconomicIndicator("REAL_GDP_PER_CAPITA"));
    PRINT_RES(api.getEconomicIndicator("TREASURY_YIELD"));
    PRINT_RES(api.getEconomicIndicator("FEDERAL_FUNDS_RATE"));
    PRINT_RES(api.getEconomicIndicator("CPI"));
    PRINT_RES(api.getEconomicIndicator("INFLATION"));
    PRINT_RES(api.getEconomicIndicator("RETAIL_SALES"));
    PRINT_RES(api.getEconomicIndicator("DURABLE_GOODS"));
    PRINT_RES(api.getEconomicIndicator("UNEMPLOYMENT_RATE"));
    PRINT_RES(api.getEconomicIndicator("NONFARM_PAYROLL"));
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

