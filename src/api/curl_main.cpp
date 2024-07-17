//
// Created by Wh Kang on 22/6/24.
//

#include "curl_main.h"
#include <iostream>
#include <utility>
#include <curl/curl.h>

// constructor CurlMain with API_URL as parameter
CurlMain::CurlMain(std::string  api) : apiUrl(std::move(api)) {
    std::cout << "CurlMain constructor called" << std::endl;
    std::cout << "API URL: " << apiUrl << std::endl;
}

std::string CurlMain::callAPI(const std::string& endpoint) {
    std::cout << "Calling API: " << apiUrl + endpoint << std::endl;

    CURL *curl = curl_easy_init();
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, (apiUrl + endpoint).c_str());
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

size_t CurlMain::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}