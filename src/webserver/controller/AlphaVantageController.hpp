#ifndef AlphaVantageController_hpp
#define AlphaVantageController_hpp

#include "../service/AlphaVantageService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/mime/ContentMappers.hpp"
#include "oatpp/macro/codegen.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * AlphaVantage REST controller.
 */
class AlphaVantageController : public oatpp::web::server::api::ApiController {
public:
    AlphaVantageController(OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers),
                           const std::string& apiKey = "")
            : oatpp::web::server::api::ApiController(apiContentMappers),
              m_alphaVantageService(apiKey.empty() ? AlphaVantageAPI("VX2MEZ75W5JNSLFY") : AlphaVantageAPI(apiKey)) {}
private:
    AlphaVantageService m_alphaVantageService; // Create AlphaVantage Service instance
public:

    static std::shared_ptr<AlphaVantageController> createShared(
            OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers), // Inject ContentMappers
            const std::string& apiKey = ""
    ){
        return std::make_shared<AlphaVantageController>(apiContentMappers, apiKey);
    }

    // Core Stock APIs
    ENDPOINT_INFO(getIntraday) {
        info->summary = "Get Intraday Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
        info->queryParams["interval"].description = "Time Interval";
    }
    ENDPOINT("GET", "alphavantage/intraday", getIntraday,
             QUERY(String, symbol),
             QUERY(String, interval))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getIntraday(
                *symbol, *interval));
    }

    ENDPOINT_INFO(getDaily) {
        info->summary = "Get Daily Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/daily", getDaily,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getDaily(*symbol));
    }

    ENDPOINT_INFO(getDailyAdjusted) {
        info->summary = "Get Daily Adjusted Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/daily-adjusted", getDailyAdjusted,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getDailyAdjusted(*symbol));
    }

    ENDPOINT_INFO(getWeekly) {
        info->summary = "Get Weekly Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/weekly", getWeekly,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getWeekly(*symbol));
    }

    ENDPOINT_INFO(getWeeklyAdjusted) {
        info->summary = "Get Weekly Adjusted Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/weekly-adjusted", getWeeklyAdjusted,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getWeeklyAdjusted(*symbol));
    }

    ENDPOINT_INFO(getMonthly) {
        info->summary = "Get Monthly Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/monthly", getMonthly,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getMonthly(*symbol));
    }

    ENDPOINT_INFO(getMonthlyAdjusted) {
        info->summary = "Get Monthly Adjusted Stock Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/monthly-adjusted", getMonthlyAdjusted,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getMonthlyAdjusted(*symbol));
    }

    ENDPOINT_INFO(getQuote) {
        info->summary = "Get Stock Quote";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/quote", getQuote,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getQuote(*symbol));
    }

    ENDPOINT_INFO(searchTicker) {
        info->summary = "Search Stock Ticker";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["keywords"].description = "Search Keywords";
    }
    ENDPOINT("GET", "alphavantage/search-ticker", searchTicker,
             QUERY(String, keywords))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.searchTicker(*keywords));
    }

    ENDPOINT_INFO(getGlobalMarketStatus) {
        info->summary = "Get Global Market Status";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "alphavantage/global-market-status", getGlobalMarketStatus)
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getGlobalMarketStatus());
    }

    // Options Data APIs
    ENDPOINT_INFO(getRealtimeOptions) {
        info->summary = "Get Realtime Options Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/realtime-options", getRealtimeOptions,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getRealtimeOptions(*symbol));
    }

    ENDPOINT_INFO(getHistoricalOptions) {
        info->summary = "Get Historical Options Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/historical-options", getHistoricalOptions,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getHistoricalOptions(*symbol));
    }

    // Alpha Intelligence™
    ENDPOINT_INFO(getNewsSentiments) {
        info->summary = "Get News Sentiments";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/news-sentiments", getNewsSentiments,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getNewsSentiments(*symbol));
    }

    ENDPOINT_INFO(getTopGainersLosers) {
        info->summary = "Get Top Gainers and Losers";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "alphavantage/top-gainers-losers", getTopGainersLosers)
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getTopGainersLosers());
    }

    ENDPOINT_INFO(getAnalytics) {
        info->summary = "Get Analytics";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
        info->queryParams["interval"].description = "Time Interval";
    }
    ENDPOINT("GET", "alphavantage/analytics", getAnalytics,
             QUERY(String, symbol),
             QUERY(String, interval))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getAnalytics(*symbol, *interval));
    }

    ENDPOINT_INFO(getSlidingWindowAnalytics) {
        info->summary = "Get Sliding Window Analytics";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
        info->queryParams["interval"].description = "Time Interval";
    }
    ENDPOINT("GET", "alphavantage/sliding-window-analytics", getSlidingWindowAnalytics,
             QUERY(String, symbol),
             QUERY(String, interval))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getSlidingWindowAnalytics(*symbol, *interval));
    }

    // Fundamental Data
    ENDPOINT_INFO(getCompanyOverview) {
        info->summary = "Get Company Overview";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/company-overview", getCompanyOverview,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCompanyOverview(*symbol));
    }

    ENDPOINT_INFO(getDividends) {
        info->summary = "Get Dividends";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/dividends", getDividends,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getDividends(*symbol));
    }

    ENDPOINT_INFO(getSplits) {
        info->summary = "Get Stock Splits";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/splits", getSplits,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getSplits(*symbol));
    }

    ENDPOINT_INFO(getIncomeStatement) {
        info->summary = "Get Income Statement";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/income-statement", getIncomeStatement,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getIncomeStatement(*symbol));
    }

    ENDPOINT_INFO(getBalanceSheet) {
        info->summary = "Get Balance Sheet";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/balance-sheet", getBalanceSheet,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getBalanceSheet(*symbol));
    }

    ENDPOINT_INFO(getCashFlow) {
        info->summary = "Get Cash Flow Statement";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/cash-flow", getCashFlow,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCashFlow(*symbol));
    }

    ENDPOINT_INFO(getEarnings) {
        info->summary = "Get Earnings Report";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
    }
    ENDPOINT("GET", "alphavantage/earnings", getEarnings,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getEarnings(*symbol));
    }

    ENDPOINT_INFO(getListingDelistingStatus) {
        info->summary = "Get Listing/Delisting Status";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "alphavantage/listing-delisting-status", getListingDelistingStatus)
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getListingDelistingStatus());
    }

    ENDPOINT_INFO(getEarningsCalendar) {
        info->summary = "Get Earnings Calendar";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "alphavantage/earnings-calendar", getEarningsCalendar)
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getEarningsCalendar());
    }

    ENDPOINT_INFO(getIPOCalendar) {
        info->summary = "Get IPO Calendar";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "alphavantage/ipo-calendar", getIPOCalendar)
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getIPOCalendar());
    }

    // Forex (FX)
    ENDPOINT_INFO(getForexExchangeRates) {
        info->summary = "Get Forex Exchange Rates";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["fromCurrency"].description = "From Currency";
        info->queryParams["toCurrency"].description = "To Currency";
    }
    ENDPOINT("GET", "alphavantage/forex-exchange-rates", getForexExchangeRates,
             QUERY(String, fromCurrency),
             QUERY(String, toCurrency))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getForexExchangeRates(*fromCurrency, *toCurrency));
    }

    ENDPOINT_INFO(getForexIntraday) {
        info->summary = "Get Forex Intraday Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["fromSymbol"].description = "From Symbol";
        info->queryParams["toSymbol"].description = "To Symbol";
        info->queryParams["interval"].description = "Time Interval";
    }
    ENDPOINT("GET", "alphavantage/forex-intraday", getForexIntraday,
             QUERY(String, fromSymbol),
             QUERY(String, toSymbol),
             QUERY(String, interval))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getForexIntraday(*fromSymbol, *toSymbol, *interval));
    }

    ENDPOINT_INFO(getForexDaily) {
        info->summary = "Get Forex Daily Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["fromSymbol"].description = "From Symbol";
        info->queryParams["toSymbol"].description = "To Symbol";
    }
    ENDPOINT("GET", "alphavantage/forex-daily", getForexDaily,
             QUERY(String, fromSymbol),
             QUERY(String, toSymbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getForexDaily(*fromSymbol, *toSymbol));
    }

    ENDPOINT_INFO(getForexWeekly) {
        info->summary = "Get Forex Weekly Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["fromSymbol"].description = "From Symbol";
        info->queryParams["toSymbol"].description = "To Symbol";
    }
    ENDPOINT("GET", "alphavantage/forex-weekly", getForexWeekly,
             QUERY(String, fromSymbol),
             QUERY(String, toSymbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getForexWeekly(*fromSymbol, *toSymbol));
    }

    ENDPOINT_INFO(getForexMonthly) {
        info->summary = "Get Forex Monthly Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["fromSymbol"].description = "From Symbol";
        info->queryParams["toSymbol"].description = "To Symbol";
    }
    ENDPOINT("GET", "alphavantage/forex-monthly", getForexMonthly,
             QUERY(String, fromSymbol),
             QUERY(String, toSymbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getForexMonthly(*fromSymbol, *toSymbol));
    }

    // Cryptocurrencies
    ENDPOINT_INFO(getCryptoExchangeRates) {
        info->summary = "Get Crypto Exchange Rates";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Cryptocurrency Symbol";
    }
    ENDPOINT("GET", "alphavantage/crypto-exchange-rates", getCryptoExchangeRates,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCryptoExchangeRates(*symbol));
    }

    ENDPOINT_INFO(getCryptoIntraday) {
        info->summary = "Get Crypto Intraday Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Cryptocurrency Symbol";
        info->queryParams["market"].description = "Market";
        info->queryParams["interval"].description = "Time Interval";
    }
    ENDPOINT("GET", "alphavantage/crypto-intraday", getCryptoIntraday,
             QUERY(String, symbol),
             QUERY(String, market),
             QUERY(String, interval))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCryptoIntraday(*symbol, *market, *interval));
    }

    ENDPOINT_INFO(getCryptoDaily) {
        info->summary = "Get Crypto Daily Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Cryptocurrency Symbol";
        info->queryParams["market"].description = "Market";
    }
    ENDPOINT("GET", "alphavantage/crypto-daily", getCryptoDaily,
             QUERY(String, symbol),
             QUERY(String, market))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCryptoDaily(*symbol, *market));
    }

    ENDPOINT_INFO(getCryptoWeekly) {
        info->summary = "Get Crypto Weekly Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Cryptocurrency Symbol";
        info->queryParams["market"].description = "Market";
    }
    ENDPOINT("GET", "alphavantage/crypto-weekly", getCryptoWeekly,
             QUERY(String, symbol),
             QUERY(String, market))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCryptoWeekly(*symbol, *market));
    }

    ENDPOINT_INFO(getCryptoMonthly) {
        info->summary = "Get Crypto Monthly Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Cryptocurrency Symbol";
        info->queryParams["market"].description = "Market";
    }
    ENDPOINT("GET", "alphavantage/crypto-monthly", getCryptoMonthly,
             QUERY(String, symbol),
             QUERY(String, market))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCryptoMonthly(*symbol, *market));
    }

    // Commodities
    ENDPOINT_INFO(getCommodity) {
        info->summary = "Get Commodity Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Commodity Symbol";
    }
    ENDPOINT("GET", "alphavantage/commodity", getCommodity,
             QUERY(String, symbol))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getCommodity(*symbol));
    }

    // Economic Indicators
    ENDPOINT_INFO(getEconomicIndicator) {
        info->summary = "Get Economic Indicator Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["function"].description = "Economic Indicator Function";
    }
    ENDPOINT("GET", "alphavantage/economic-indicator", getEconomicIndicator,
             QUERY(String, function))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getEconomicIndicator(*function));
    }

    // Technical Indicators
    ENDPOINT_INFO(getTechnicalIndicator) {
        info->summary = "Get Technical Indicator Data";
        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->queryParams["symbol"].description = "Stock Symbol";
        info->queryParams["indicator"].description = "Technical Indicator";
        info->queryParams["interval"].description = "Time Interval";
        info->queryParams["timePeriod"].description = "Time Period";
    }
    ENDPOINT("GET", "alphavantage/technical-indicator", getTechnicalIndicator,
             QUERY(String, symbol),
             QUERY(String, indicator),
             QUERY(String, interval),
             QUERY(String, timePeriod))
    {
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getTechnicalIndicator(*symbol, *indicator, *interval, *timePeriod));
    }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* AlphaVantageController_hpp */