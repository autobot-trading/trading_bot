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
            OATPP_COMPONENT(std::shared_ptr<oatpp::web::mime::ContentMappers>, apiContentMappers) // Inject ContentMappers
    ){
        return std::make_shared<AlphaVantageController>(apiContentMappers);
    }

    // Define endpoints

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
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getIntraday(symbol, interval));
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
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getDaily(symbol));
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
        return createDtoResponse(Status::CODE_200, m_alphaVantageService.getDailyAdjusted(symbol));
    }

    // Similar endpoints can be added for other API methods

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* AlphaVantageController_hpp */