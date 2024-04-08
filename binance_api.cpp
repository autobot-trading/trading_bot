//
// Created by Wh Kang on 8/4/24.
//

#include "binance_api.h"
#include "binance_api.h"
#include <iostream>
#include <curl/curl.h>

const std::string API_URL = "https://api.binance.com/api/v3/";

BinanceAPI::BinanceAPI() = default;

BinanceAPI::~BinanceAPI() = default;

std::string BinanceAPI::ping() {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, (API_URL + "ping").c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl);
    }

    return response;
}

size_t BinanceAPI::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}
