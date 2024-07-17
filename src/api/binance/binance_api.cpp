#include "binance_api.h"
#include "curl_main.h"

using namespace std;

CurlMain BinanceAPI::curlMain("https://api.binance.com/api/v3/");

std::string BinanceAPI::ping() {
    return curlMain.callAPI("ping");
}

std::string BinanceAPI::exchangeInfo() {
    return curlMain.callAPI("exchangeInfo");
}

std::string BinanceAPI::depth(const std::string& symbol) {
    return curlMain.callAPI("depth?symbol=" + symbol);
}

std::string BinanceAPI::trade(const std::string& symbol, const std::string& limit) {
    return curlMain.callAPI("trades?symbol=" + symbol + "&limit=" + limit);
}

std::string BinanceAPI::klines(const std::string& symbol, const std::string& interval, const std::string& limit,
                               const std::string& startTime /* = "" */, const std::string& endTime /* = "" */,
                               const std::string& timeZone /* = "" */) {
    std::string url = "klines?symbol=" + symbol + "&interval=" + interval + "&limit=" + limit;
    if (!startTime.empty()) {
        url += "&startTime=" + startTime;
    }
    if (!endTime.empty()) {
        url += "&endTime=" + endTime;
    }
    if (!timeZone.empty()) {
        url += "&timeZone=" + timeZone;
    }
    return curlMain.callAPI(url);
}

//std::string BinanceAPI::order(const std::string&symbol, const std::string& side const std:: string&type,
//                              const std::s);

