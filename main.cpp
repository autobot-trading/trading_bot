//
// Created by Wh Kang on 8/4/24.
//

#include <iostream>
#include "binance_api.h"

int main() {
    BinanceAPI binance;

    std::string response = BinanceAPI::ping();
    std::cout << "Response: " << response << std::endl;

    return 0;
}

