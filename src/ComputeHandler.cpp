#include <iostream>
#include <algorithm>
#include <memory>
#include <cstdint>
#include <initializer_list>
#include <sstream>
#include <oatpp/web/server/HttpRequestHandler.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <linreg/regression/LinearRegression.hpp>
#include <linreg/structures/Vector.hpp>

#include "dto/DataDto.hpp"
#include "dto/MessageDto.hpp"

namespace http = oatpp::web::server;
namespace proto = oatpp::web::protocol::http;
namespace mapping = oatpp::parser::json::mapping;

class ComputeHandler : public http::HttpRequestHandler {
	std::shared_ptr<mapping::ObjectMapper> objectMapper;
public:
	ComputeHandler() : objectMapper(std::make_shared<mapping::ObjectMapper>()) {}
	std::shared_ptr<proto::outgoing::Response> handle(const std::shared_ptr<proto::incoming::Request>& req) override {
		auto body = req->readBodyToString();
		auto data = this->objectMapper->readFromString<oatpp::Object<DataDto>>(body);
		linreg::structures::Vector<double> argsVec(data->args->size());
		linreg::structures::Vector<double> valsVec(data->vals->size());
		std::transform(data->args->begin(),data->args->end(),argsVec.begin(),[](const double el) { return el; });
		std::transform(data->vals->begin(),data->vals->end(),valsVec.begin(),[](const double el) { return el; });
		linreg::regression::LinearRegression regression(argsVec,valsVec);
		auto result = regression.Calculate();
		std::stringstream stream;
		for(uint16_t i = 0; i < argsVec.size(); i++) {
			stream << argsVec[i] << "," << result[i] << " ";
		}
		auto message = MessageDto::createShared();
		message->status = 200;
		message->message = [&stream](){ auto res = stream.str(); res.pop_back(); return res; }();
		return proto::outgoing::ResponseFactory::createResponse(proto::Status::CODE_200,message,this->objectMapper);
	}
};
