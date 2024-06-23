//
// Created by Wh Kang on 22/6/24.
//

#include "alphavantage_api.h"
#include <iostream>
#include <string>

AlphaVantageAPI::AlphaVantageAPI(const std::string& apiKey)
        : apiKey(apiKey), curlMain(baseUrl) {
    std::cout << "AlphaVantageAPI constructor called" << std::endl;
    std::cout << "API Key: " << apiKey << std::endl;
}

std::string AlphaVantageAPI::buildUrl(const std::string& function, const std::string& params) {
    return "function=" + function + "&apikey=" + apiKey + "&" + params;
}

// Core Stock APIs
std::string AlphaVantageAPI::getIntraday(const std::string& symbol, const std::string& interval) {
    std::string endpoint = buildUrl("TIME_SERIES_INTRADAY", "symbol=" + symbol + "&interval=" + interval);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getDaily(const std::string& symbol) {
    std::string endpoint = buildUrl("TIME_SERIES_DAILY", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getDailyAdjusted(const std::string& symbol) {
    std::string endpoint = buildUrl("TIME_SERIES_DAILY_ADJUSTED", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getWeekly(const std::string& symbol) {
    std::string endpoint = buildUrl("TIME_SERIES_WEEKLY", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getWeeklyAdjusted(const std::string& symbol) {
    std::string endpoint = buildUrl("TIME_SERIES_WEEKLY_ADJUSTED", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getMonthly(const std::string& symbol) {
    std::string endpoint = buildUrl("TIME_SERIES_MONTHLY", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getMonthlyAdjusted(const std::string& symbol) {
    std::string endpoint = buildUrl("TIME_SERIES_MONTHLY_ADJUSTED", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getQuote(const std::string& symbol) {
    std::string endpoint = buildUrl("GLOBAL_QUOTE", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::searchTicker(const std::string& keywords) {
    std::string endpoint = buildUrl("SYMBOL_SEARCH", "keywords=" + keywords);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getGlobalMarketStatus() {
    std::string endpoint = buildUrl("GLOBAL_MARKET_STATUS", "");
    return curlMain.callAPI(endpoint);
}

// Options Data APIs
std::string AlphaVantageAPI::getRealtimeOptions(const std::string& symbol) {
    std::string endpoint = buildUrl("OPTION_PREMIUM", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getHistoricalOptions(const std::string& symbol) {
    std::string endpoint = buildUrl("OPTION_HISTORICAL", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

// Alpha Intelligence™
std::string AlphaVantageAPI::getNewsSentiments(const std::string& symbol) {
    std::string endpoint = buildUrl("NEWS_SENTIMENTS", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getTopGainersLosers() {
    std::string endpoint = buildUrl("TOP_GAINERS_LOSERS", "");
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getAnalytics(const std::string& symbol, const std::string& interval) {
    std::string endpoint = buildUrl("ANALYTICS", "symbol=" + symbol + "&interval=" + interval);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getSlidingWindowAnalytics(const std::string& symbol, const std::string& interval) {
    std::string endpoint = buildUrl("ANALYTICS_SLIDING_WINDOW", "symbol=" + symbol + "&interval=" + interval);
    return curlMain.callAPI(endpoint);
}

// Fundamental Data
std::string AlphaVantageAPI::getCompanyOverview(const std::string& symbol) {
    std::string endpoint = buildUrl("OVERVIEW", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getDividends(const std::string& symbol) {
    std::string endpoint = buildUrl("DIVIDEND", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getSplits(const std::string& symbol) {
    std::string endpoint = buildUrl("SPLIT", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getIncomeStatement(const std::string& symbol) {
    std::string endpoint = buildUrl("INCOME_STATEMENT", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getBalanceSheet(const std::string& symbol) {
    std::string endpoint = buildUrl("BALANCE_SHEET", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getCashFlow(const std::string& symbol) {
    std::string endpoint = buildUrl("CASH_FLOW", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getEarnings(const std::string& symbol) {
    std::string endpoint = buildUrl("EARNINGS", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getListingDelistingStatus() {
    std::string endpoint = buildUrl("LISTING_STATUS", "");
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getEarningsCalendar() {
    std::string endpoint = buildUrl("EARNINGS_CALENDAR", "");
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getIPOCalendar() {
    std::string endpoint = buildUrl("IPO_CALENDAR", "");
    return curlMain.callAPI(endpoint);
}

// Forex (FX)
std::string AlphaVantageAPI::getForexExchangeRates(const std::string& fromCurrency, const std::string& toCurrency) {
    std::string endpoint = buildUrl("CURRENCY_EXCHANGE_RATE", "from_currency=" + fromCurrency + "&to_currency=" + toCurrency);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getForexIntraday(const std::string& fromSymbol, const std::string& toSymbol, const std::string& interval) {
    std::string endpoint = buildUrl("FX_INTRADAY", "from_symbol=" + fromSymbol + "&to_symbol=" + toSymbol + "&interval=" + interval);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getForexDaily(const std::string& fromSymbol, const std::string& toSymbol) {
    std::string endpoint = buildUrl("FX_DAILY", "from_symbol=" + fromSymbol + "&to_symbol=" + toSymbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getForexWeekly(const std::string& fromSymbol, const std::string& toSymbol) {
    std::string endpoint = buildUrl("FX_WEEKLY", "from_symbol=" + fromSymbol + "&to_symbol=" + toSymbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getForexMonthly(const std::string& fromSymbol, const std::string& toSymbol) {
    std::string endpoint = buildUrl("FX_MONTHLY", "from_symbol=" + fromSymbol + "&to_symbol=" + toSymbol);
    return curlMain.callAPI(endpoint);
}

// Cryptocurrencies
std::string AlphaVantageAPI::getCryptoExchangeRates(const std::string& symbol) {
    std::string endpoint = buildUrl("CRYPTO_RATING", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getCryptoIntraday(const std::string& symbol, const std::string& market, const std::string& interval) {
    std::string endpoint = buildUrl("CRYPTO_INTRADAY", "symbol=" + symbol + "&market=" + market + "&interval=" + interval);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getCryptoDaily(const std::string& symbol, const std::string& market) {
    std::string endpoint = buildUrl("CRYPTO_DAILY", "symbol=" + symbol + "&market=" + market);
    return curlMain.callAPI(endpoint);
}

std::string AlphaVantageAPI::getCryptoWeekly(const std::string& symbol, const std::string& market) {
    std::string endpoint = buildUrl("CRYPTO_WEEKLY", "symbol=" + symbol + "&market=" + market);
    return curlMain.callAPI(endpoint);
}
std::string AlphaVantageAPI::getCryptoMonthly(const std::string& symbol, const std::string& market) {
    std::string endpoint = buildUrl("CRYPTO_MONTHLY", "symbol=" + symbol + "&market=" + market);
    return curlMain.callAPI(endpoint);
}

// Commodities
std::string AlphaVantageAPI::getCommodity(const std::string& symbol) {
    std::string endpoint = buildUrl("COMMODITY", "symbol=" + symbol);
    return curlMain.callAPI(endpoint);
}

// Economic Indicators
std::string AlphaVantageAPI::getEconomicIndicator(const std::string& function) {
    std::string endpoint = buildUrl(function, "");
    return curlMain.callAPI(endpoint);
}

// Technical Indicators
std::string AlphaVantageAPI::getTechnicalIndicator(const std::string& symbol, const std::string& indicator, const std::string& interval, const std::string& timePeriod) {
    std::string endpoint = buildUrl(indicator, "symbol=" + symbol + "&interval=" + interval + "&time_period=" + timePeriod);
    return curlMain.callAPI(endpoint);
}
