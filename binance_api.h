
//
// Created by Wh Kang on 8/4/24.
//
#ifndef BINANCE_API_H
#define BINANCE_API_H

#include <string>

class BinanceAPI {
public:
    BinanceAPI();
    ~BinanceAPI();
    static std::string ping();

private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data);
};

#endif // BINANCE_API_H
