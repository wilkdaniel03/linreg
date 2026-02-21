#include <memory>
#include <oatpp/web/server/HttpRequestHandler.hpp>
#include <oatpp/web/protocol/http/outgoing/Request.hpp>
#include <oatpp/web/protocol/http/incoming/Response.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <linreg/dto/MessageDto.hpp>

namespace http = oatpp::web::server;
namespace proto = oatpp::web::protocol::http;
namespace mapping = oatpp::parser::json::mapping;

class StatusHandler : public http::HttpRequestHandler {
	std::shared_ptr<mapping::ObjectMapper> objectMapper;
public:
	StatusHandler() : objectMapper(std::make_shared<mapping::ObjectMapper>()) {}
	std::shared_ptr<proto::outgoing::Response> handle(const std::shared_ptr<proto::incoming::Request>& req) override {
		auto message = MessageDto::createShared();
		message->status = 200;
		message->message = "OK";
		return proto::outgoing::ResponseFactory::createResponse(proto::Status::CODE_200,message,this->objectMapper);
	}
};
