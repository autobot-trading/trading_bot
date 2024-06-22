// alphavantage_api.h
#ifndef ALPHAVANTAGE_API_H
#define ALPHAVANTAGE_API_H

#include <string>
#include "curl_main.h"

class AlphaVantageAPI {
public:
    AlphaVantageAPI(const std::string& apiKey);

    std::string getTimeSeriesDaily(const std::string& symbol);
    std::string getTimeSeriesIntraday(const std::string& symbol, const std::string& interval);
    std::string getQuoteEndpoint(const std::string& symbol);

private:
    const std::string apiKey;
    const std::string baseUrl = "https://www.alphavantage.co/query?";
    CurlMain curlMain;
};

#endif // ALPHAVANTAGE_API_H