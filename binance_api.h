
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
    static std::string exchangeInfo();
    static std::string depth(const std::string &symbol);
    static std::string trade(const std::string &symbol, const std::string &limit);
    static std::string klines(const std::string &symbol, const std::string &interval, const std::string &limit,
                               const std::string &startTime,
                               const std::string &endTime, const std::string &timeZone);
    static std::string accountInfo();

//    static std::string fetchVolume(const std::string& url);
//    static std:: void trade (const std::string& url);


private:
    static std::string callAPI(const std::string &endpoint);
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data);

protected:

};

#endif // BINANCE_API_H
