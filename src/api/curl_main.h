//
// Created by Wh Kang on 22/6/24.
//

#ifndef CURL_MAIN_H
#define CURL_MAIN_H


#include <string>

class CurlMain {
public:
    CurlMain() = delete;

    // Constructor with API_URL as a parameter
    explicit CurlMain(std::string  apiUrl);

    std::string callAPI(const std::string &endpoint);

private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data);
    const std::string apiUrl;
};


#endif //CURL_MAIN_H
