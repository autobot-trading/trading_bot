//
// Created by Wh Kang on 22/6/24.
//

#include "alphavantage_api.h"
// alphavantage_api.cpp
#include "alphavantage_api.h"
#include <iostream>
#include <string>

AlphaVantageAPI::AlphaVantageAPI(const std::string& apiKey)
        : apiKey(apiKey), curlMain(baseUrl) {
    std::cout << "AlphaVantageAPI constructor called" << std::endl;
    std::cout << "API Key: " << apiKey << std::endl;
}

std::string AlphaVantageAPI::getTimeSeriesDaily(const std::string& symbol) {
    std::string endpoint = "function=TIME_SERIES_DAILY&symbol=" + symbol + "&apikey=" + apiKey;
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getTimeSeriesIntraday(const std::string& symbol, const std::string& interval) {
    std::string endpoint = "function=TIME_SERIES_INTRADAY&symbol=" + symbol + "&interval=" + interval + "&apikey=" + apiKey;
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getQuoteEndpoint(const std::string& symbol) {
    std::string endpoint = "function=GLOBAL_QUOTE&symbol=" + symbol + "&apikey=" + apiKey;
    return curlMain.callAPI(endpoint);
}
