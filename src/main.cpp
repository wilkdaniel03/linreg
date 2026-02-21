#include <iostream>
#include <format>
#include <cstdint>
#include <oatpp/web/server/HttpRouter.hpp>
#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/network/Server.hpp>

#include "StatusHandler.cpp"

namespace http = oatpp::web::server;
namespace net = oatpp::network;;

const uint32_t PORT = 8080;

int main(void) {
	auto router = http::HttpRouter::createShared();
	router->route("GET","/status",std::make_shared<StatusHandler>());
	auto connHandler = http::HttpConnectionHandler::createShared(router);
	auto connProvider = net::tcp::server::ConnectionProvider::createShared({"127.0.0.1",PORT,net::Address::IP_4});
	auto server = net::Server(connProvider,connHandler);
	std::cout << std::format("Listenning on port {}...",PORT) << std::endl;
	server.run();
	return 0;
}
