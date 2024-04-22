//
// Created by Xu Siyi on 22/4/24.
//
#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch (std::bad_alloc &e) {
        // Handle memory issues
        return 0;
    }
    return newLength;
}

std::string fetchBtcVolume(const std::string& url) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return readBuffer;
}

//int main() {
//    std::string volume_url = "https://api.binance.com/api/v3/ticker/24hr?symbol=BTCUSDT";
//    std::string result = fetchBtcVolume(url);
//    std::cout << "Response from Binance API: " << result << std::endl;
//    return 0;
//}
