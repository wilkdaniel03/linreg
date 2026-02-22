#pragma once

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class DataDto : public oatpp::DTO {
	DTO_INIT(DataDto,DTO)
	DTO_FIELD(Vector<Float64>,args);
	DTO_FIELD(Vector<Float64>,vals);
};

#include OATPP_CODEGEN_END(DTO)
