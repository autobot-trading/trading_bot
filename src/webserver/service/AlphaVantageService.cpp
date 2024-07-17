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

oatpp::Object<StatusDto> AlphaVantageService::getWeekly(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getWeekly(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getWeeklyAdjusted(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getWeeklyAdjusted(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getMonthly(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getMonthly(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getMonthlyAdjusted(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getMonthlyAdjusted(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getQuote(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getQuote(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::searchTicker(const std::string& keywords) {
    auto response = m_alphaVantageAPI.searchTicker(keywords);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getGlobalMarketStatus() {
    auto response = m_alphaVantageAPI.getGlobalMarketStatus();
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Options Data APIs
oatpp::Object<StatusDto> AlphaVantageService::getRealtimeOptions(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getRealtimeOptions(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getHistoricalOptions(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getHistoricalOptions(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Alpha Intelligence™
oatpp::Object<StatusDto> AlphaVantageService::getNewsSentiments(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getNewsSentiments(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getTopGainersLosers() {
    auto response = m_alphaVantageAPI.getTopGainersLosers();
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getAnalytics(const std::string& symbol, const std::string& interval) {
    auto response = m_alphaVantageAPI.getAnalytics(symbol, interval);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getSlidingWindowAnalytics(const std::string& symbol, const std::string& interval) {
    auto response = m_alphaVantageAPI.getSlidingWindowAnalytics(symbol, interval);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Fundamental Data
oatpp::Object<StatusDto> AlphaVantageService::getCompanyOverview(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getCompanyOverview(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getDividends(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getDividends(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getSplits(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getSplits(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getIncomeStatement(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getIncomeStatement(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getBalanceSheet(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getBalanceSheet(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getCashFlow(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getCashFlow(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getEarnings(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getEarnings(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getListingDelistingStatus() {
    auto response = m_alphaVantageAPI.getListingDelistingStatus();
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getEarningsCalendar() {
    auto response = m_alphaVantageAPI.getEarningsCalendar();
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getIPOCalendar() {
    auto response = m_alphaVantageAPI.getIPOCalendar();
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Forex (FX)
oatpp::Object<StatusDto> AlphaVantageService::getForexExchangeRates(const std::string& fromCurrency, const std::string& toCurrency) {
    auto response = m_alphaVantageAPI.getForexExchangeRates(fromCurrency, toCurrency);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getForexIntraday(const std::string& fromSymbol, const std::string& toSymbol, const std::string& interval) {
    auto response = m_alphaVantageAPI.getForexIntraday(fromSymbol, toSymbol, interval);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getForexDaily(const std::string& fromSymbol, const std::string& toSymbol) {
    auto response = m_alphaVantageAPI.getForexDaily(fromSymbol, toSymbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getForexWeekly(const std::string& fromSymbol, const std::string& toSymbol) {
    auto response = m_alphaVantageAPI.getForexWeekly(fromSymbol, toSymbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getForexMonthly(const std::string& fromSymbol, const std::string& toSymbol) {
    auto response = m_alphaVantageAPI.getForexMonthly(fromSymbol, toSymbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Cryptocurrencies
oatpp::Object<StatusDto> AlphaVantageService::getCryptoExchangeRates(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getCryptoExchangeRates(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getCryptoIntraday(const std::string& symbol, const std::string& market, const std::string& interval) {
    auto response = m_alphaVantageAPI.getCryptoIntraday(symbol, market, interval);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getCryptoDaily(const std::string& symbol, const std::string& market) {
    auto response = m_alphaVantageAPI.getCryptoDaily(symbol, market);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getCryptoWeekly(const std::string& symbol, const std::string& market) {
    auto response = m_alphaVantageAPI.getCryptoWeekly(symbol, market);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

oatpp::Object<StatusDto> AlphaVantageService::getCryptoMonthly(const std::string& symbol, const std::string& market) {
    auto response = m_alphaVantageAPI.getCryptoMonthly(symbol, market);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Commodities
oatpp::Object<StatusDto> AlphaVantageService::getCommodity(const std::string& symbol) {
    auto response = m_alphaVantageAPI.getCommodity(symbol);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Economic Indicators
oatpp::Object<StatusDto> AlphaVantageService::getEconomicIndicator(const std::string& function) {
    auto response = m_alphaVantageAPI.getEconomicIndicator(function);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

// Technical Indicators
oatpp::Object<StatusDto> AlphaVantageService::getTechnicalIndicator(const std::string& symbol, const std::string& indicator, const std::string& interval, const std::string& timePeriod) {
    auto response = m_alphaVantageAPI.getTechnicalIndicator(symbol, indicator, interval, timePeriod);
    auto status = StatusDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = response;
    return status;
}

