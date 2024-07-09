#ifndef ALPHAVANTAGE_SERVICE_HPP
#define ALPHAVANTAGE_SERVICE_HPP

#include "../api/alphavantage/alphavantage_api.h"
#include "../dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/macro/component.hpp"

class AlphaVantageService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    AlphaVantageAPI m_alphaVantageAPI; // Create AlphaVantage API instance
public:

    oatpp::Object<StatusDto> getIntraday(const std::string& symbol, const std::string& interval);
    oatpp::Object<StatusDto> getDaily(const std::string& symbol);
    oatpp::Object<StatusDto> getDailyAdjusted(const std::string& symbol);

    // Add other methods for the API endpoints as needed
    AlphaVantageService(AlphaVantageAPI mAlphaVantageApi);
};

#endif // ALPHAVANTAGE_SERVICE_HPP