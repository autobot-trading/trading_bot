


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <exception>

#include <openssl/hmac.h> // Include the OpenSSL HMAC header.
#include <openssl/ssl.h> 

// #include <json/json.h> // Include the "json/json.h" header file.

// #include <libwebsockets.h>


#define BINANCE_WS_HOST "stream.binance.com"
#define BINANCE_WS_PORT 9443


using namespace std;

typedef int (*CB)(Json::Value &json_value );

const std::string jsonText = R"({
	"id": "e2a85d9f-07a5-4f94-8d5f-789dc3deb097",
	"method": "order.place",
	"params": {
		"symbol": "BTCUSDT",
		"side": "BUY",
		"type": "LIMIT",
		"price": "0.1",
		"quantity": "10",
		"timeInForce": "GTC",
		"timestamp": 1655716096498,
		"apiKey": "T59MTDLWlpRW16JVeZ2Nju5A5C98WkMm8CSzWC4oqynUlTm1zXOxyauT8LmwXEv9",
		"signature": "5942ad337e6779f2f4c62cd1c26dba71c91514400a24990a3e7f5edec9323f90"
	}
})";

class BinaCPP_websocket {


	static struct lws_context *context;
	static struct lws_protocols protocols[]; 

	static map <struct lws *,CB> handles ;
	
	public:
		static int  event_cb( struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len );
		static void connect_endpoint(
			CB user_cb,
			const char* path
		);
		static void init();
		static void enter_event_loop();


};
