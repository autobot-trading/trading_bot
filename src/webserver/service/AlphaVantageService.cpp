#include "AlphaVantageService.hpp"

oatpp::Object<StatusDto> AlphaVantageService::getIntraday(const std::string& symbol, const std::string& interval) {
    auto response = m_alphaVantageAPI.getIntraday(symbol, interval);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getDaily(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getDaily(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getDailyAdjusted(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getDailyAdjusted(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

AlphaVantageService::AlphaVantageService(AlphaVantageAPI mAlphaVantageApi) : m_alphaVantageAPI(mAlphaVantageApi) {

}

// Add implementations for other methods as needed