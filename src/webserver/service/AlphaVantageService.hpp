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
    AlphaVantageService(AlphaVantageAPI apiKey) : m_alphaVantageAPI(apiKey) {}

    // Core Stock APIs
    oatpp::Object<StatusDto> getIntraday(const std::string& symbol, const std::string& interval);
    oatpp::Object<StatusDto> getDaily(const std::string& symbol);
    oatpp::Object<StatusDto> getDailyAdjusted(const std::string& symbol);
    oatpp::Object<StatusDto> getWeekly(const std::string& symbol);
    oatpp::Object<StatusDto> getWeeklyAdjusted(const std::string& symbol);
    oatpp::Object<StatusDto> getMonthly(const std::string& symbol);
    oatpp::Object<StatusDto> getMonthlyAdjusted(const std::string& symbol);
    oatpp::Object<StatusDto> getQuote(const std::string& symbol);
    oatpp::Object<StatusDto> searchTicker(const std::string& keywords);
    oatpp::Object<StatusDto> getGlobalMarketStatus();

    // Options Data APIs
    oatpp::Object<StatusDto> getRealtimeOptions(const std::string& symbol);
    oatpp::Object<StatusDto> getHistoricalOptions(const std::string& symbol);

    // Alpha Intelligence™
    oatpp::Object<StatusDto> getNewsSentiments(const std::string& symbol);
    oatpp::Object<StatusDto> getTopGainersLosers();
    oatpp::Object<StatusDto> getAnalytics(const std::string& symbol, const std::string& interval);
    oatpp::Object<StatusDto> getSlidingWindowAnalytics(const std::string& symbol, const std::string& interval);

    // Fundamental Data
    oatpp::Object<StatusDto> getCompanyOverview(const std::string& symbol);
    oatpp::Object<StatusDto> getDividends(const std::string& symbol);
    oatpp::Object<StatusDto> getSplits(const std::string& symbol);
    oatpp::Object<StatusDto> getIncomeStatement(const std::string& symbol);
    oatpp::Object<StatusDto> getBalanceSheet(const std::string& symbol);
    oatpp::Object<StatusDto> getCashFlow(const std::string& symbol);
    oatpp::Object<StatusDto> getEarnings(const std::string& symbol);
    oatpp::Object<StatusDto> getListingDelistingStatus();
    oatpp::Object<StatusDto> getEarningsCalendar();
    oatpp::Object<StatusDto> getIPOCalendar();

    // Forex (FX)
    oatpp::Object<StatusDto> getForexExchangeRates(const std::string& fromCurrency, const std::string& toCurrency);
    oatpp::Object<StatusDto> getForexIntraday(const std::string& fromSymbol, const std::string& toSymbol, const std::string& interval);
    oatpp::Object<StatusDto> getForexDaily(const std::string& fromSymbol, const std::string& toSymbol);
    oatpp::Object<StatusDto> getForexWeekly(const std::string& fromSymbol, const std::string& toSymbol);
    oatpp::Object<StatusDto> getForexMonthly(const std::string& fromSymbol, const std::string& toSymbol);

    // Cryptocurrencies
    oatpp::Object<StatusDto> getCryptoExchangeRates(const std::string& symbol);
    oatpp::Object<StatusDto> getCryptoIntraday(const std::string& symbol, const std::string& market, const std::string& interval);
    oatpp::Object<StatusDto> getCryptoDaily(const std::string& symbol, const std::string& market);
    oatpp::Object<StatusDto> getCryptoWeekly(const std::string& symbol, const std::string& market);
    oatpp::Object<StatusDto> getCryptoMonthly(const std::string& symbol, const std::string& market);

    // Commodities
    oatpp::Object<StatusDto> getCommodity(const std::string& symbol);

    // Economic Indicators
    oatpp::Object<StatusDto> getEconomicIndicator(const std::string& function);

    // Technical Indicators
    oatpp::Object<StatusDto> getTechnicalIndicator(const std::string& symbol, const std::string& indicator, const std::string& interval, const std::string& timePeriod);

};

#endif // ALPHAVANTAGE_SERVICE_HPP
