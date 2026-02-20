#include <iostream>
#include <format>
#include <cstdint>
#include <oatpp/web/server/HttpRouter.hpp>
#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/network/Server.hpp>
#include <oatpp/web/server/HttpRequestHandler.hpp>
#include <oatpp/web/protocol/http/outgoing/Request.hpp>
#include <oatpp/web/protocol/http/incoming/Response.hpp>

namespace http = oatpp::web::server;
namespace net = oatpp::network;;
namespace proto = oatpp::web::protocol::http;

const uint32_t PORT = 8080;

class HelloHandler : public http::HttpRequestHandler {
public:
	std::shared_ptr<proto::outgoing::Response> handle(const std::shared_ptr<proto::incoming::Request>& req) override {
		return proto::outgoing::ResponseFactory::createResponse(proto::Status::CODE_200,"SIEMANO KOLANO");
	}
};

int main(void) {
	auto router = http::HttpRouter::createShared();
	router->route("GET","/hello",std::make_shared<HelloHandler>());
	auto connHandler = http::HttpConnectionHandler::createShared(router);
	auto connProvider = net::tcp::server::ConnectionProvider::createShared({"127.0.0.1",PORT});
	auto server = net::Server(connProvider,connHandler);
	std::cout << std::format("Listenning on port {}...",PORT) << std::endl;
	server.run();
	return 0;
}
