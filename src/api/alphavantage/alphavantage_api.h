#ifndef ALPHAVANTAGE_API_H
#define ALPHAVANTAGE_API_H

#include <string>
#include "curl_main.h"

class AlphaVantageAPI {
public:
    AlphaVantageAPI(const std::string& apiKey);

    // Core Stock APIs
    std::string getIntraday(const std::string& symbol, const std::string& interval);
    std::string getDaily(const std::string& symbol);
    std::string getDailyAdjusted(const std::string& symbol);
    std::string getWeekly(const std::string& symbol);
    std::string getWeeklyAdjusted(const std::string& symbol);
    std::string getMonthly(const std::string& symbol);
    std::string getMonthlyAdjusted(const std::string& symbol);
    std::string getQuote(const std::string& symbol);
    std::string searchTicker(const std::string& keywords);
    std::string getGlobalMarketStatus();

    // Options Data APIs
    std::string getRealtimeOptions(const std::string& symbol);
    std::string getHistoricalOptions(const std::string& symbol);

    // Alpha Intelligence™
    std::string getNewsSentiments(const std::string& symbol);
    std::string getTopGainersLosers();
    std::string getAnalytics(const std::string& symbol, const std::string& interval);
    std::string getSlidingWindowAnalytics(const std::string& symbol, const std::string& interval);

    // Fundamental Data
    std::string getCompanyOverview(const std::string& symbol);
    std::string getDividends(const std::string& symbol);
    std::string getSplits(const std::string& symbol);
    std::string getIncomeStatement(const std::string& symbol);
    std::string getBalanceSheet(const std::string& symbol);
    std::string getCashFlow(const std::string& symbol);
    std::string getEarnings(const std::string& symbol);
    std::string getListingDelistingStatus();
    std::string getEarningsCalendar();
    std::string getIPOCalendar();

    // Forex (FX)
    std::string getForexExchangeRates(const std::string& fromCurrency, const std::string& toCurrency);
    std::string getForexIntraday(const std::string& fromSymbol, const std::string& toSymbol, const std::string& interval);
    std::string getForexDaily(const std::string& fromSymbol, const std::string& toSymbol);
    std::string getForexWeekly(const std::string& fromSymbol, const std::string& toSymbol);
    std::string getForexMonthly(const std::string& fromSymbol, const std::string& toSymbol);

    // Cryptocurrencies
    std::string getCryptoExchangeRates(const std::string& symbol);
    std::string getCryptoIntraday(const std::string& symbol, const std::string& market, const std::string& interval);
    std::string getCryptoDaily(const std::string& symbol, const std::string& market);
    std::string getCryptoWeekly(const std::string& symbol, const std::string& market);
    std::string getCryptoMonthly(const std::string& symbol, const std::string& market);

    // Commodities
    std::string getCommodity(const std::string& symbol);

    // Economic Indicators
    std::string getEconomicIndicator(const std::string& function);

    // Technical Indicators
    std::string getTechnicalIndicator(const std::string& symbol, const std::string& indicator, const std::string& interval, const std::string& timePeriod);

private:
    const std::string apiKey;
    const std::string baseUrl = "https://www.alphavantage.co/query?";
    CurlMain curlMain;

    std::string buildUrl(const std::string& function, const std::string& params);
};

#endif // ALPHAVANTAGE_API_H