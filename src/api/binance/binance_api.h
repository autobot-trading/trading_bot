
//
// Created by Wh Kang on 8/4/24.
//
#ifndef BINANCE_API_H
#define BINANCE_API_H

#include <string>
#include "curl_main.h"

class BinanceAPI {
public:
    BinanceAPI() = default;

    static std::string ping();
    static std::string exchangeInfo();
    static std::string depth(const std::string &symbol);
    static std::string trade(const std::string &symbol, const std::string &limit);
    static std::string klines(const std::string &symbol, const std::string &interval, const std::string &limit,
                               const std::string &startTime,
                               const std::string &endTime, const std::string &timeZone);

//    static std::string fetchVolume(const std::string& url);
//    static std:: void trade (const std::string& url);

private:
    static CurlMain curlMain;

protected:

};

#endif // BINANCE_API_H
