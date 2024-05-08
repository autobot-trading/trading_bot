#include "binance_api.h"
#include <iostream>
#include <curl/curl.h>
using namespace std;

const std::string API_URL = "https://api.binance.com/api/v3/";

BinanceAPI::BinanceAPI() = default;

BinanceAPI::~BinanceAPI() = default;

std::string BinanceAPI::ping() {
    return callAPI("ping");
}

std::string BinanceAPI::exchangeInfo() {
    return callAPI("exchangeInfo");
}

std::string BinanceAPI::depth(const std::string& symbol) {
    return callAPI("depth?symbol=" + symbol);
}

std::string BinanceAPI::trade(const std::string& symbol, const std::string& limit) {
    return callAPI("trades?symbol=" + symbol + "&limit=" + limit);
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
    return callAPI(url);
}

//std::string BinanceAPI::order(const std::string&symbol, const std::string& side const std:: string&type,
//                              const std::s);


std::string BinanceAPI::callAPI(const string& endpoint) {
    CURL *curl = curl_easy_init();
    string response;

    if (curl) { // if curl is not null
        curl_easy_setopt(curl, CURLOPT_URL, (API_URL + endpoint).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

size_t BinanceAPI::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

