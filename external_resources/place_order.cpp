//
// Created by Xu Siyi on 8/5/24.
//

#include "place_order.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <openssl/hmac.h>
using namespace std;

const int SHA256_DIGEST_LENGTH = 32;

std::string sign_request(const std::string& key, const std::string& data) {
    unsigned char* digest = HMAC(EVP_sha256(), key.c_str(), key.length(), 
            (unsigned char*)data.c_str(), data.length(), NULL, NULL);    
    char mdString[SHA256_DIGEST_LENGTH * 2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    return std::string(mdString);
}

std::string send_request(const std::string& url, 
        const std::string& apiKey, const std::string& signature) {
    CURL *curl = curl_easy_init();
    std::string response;

    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, ("X-MBX-APIKEY: " + apiKey).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, (url + "&signature=" + signature).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
    }
    return response;
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}


int main() {
    std::string apiKey = "put your own API Key here";
    std::string privateKey = "put your own Private Key here";
    std::string url = "https://testnet.binance.vision/api/v3/order?symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=GTC&quantity=1&price=0.2&timestamp=";
    url += std::to_string(time(0) * 1000); // append timestamp
    std::string signature = sign_request(privateKey, url);
    std::string response = send_request(url, apiKey, signature);
    std::cout << "Response: " << response << std::endl;
    return 0;
}