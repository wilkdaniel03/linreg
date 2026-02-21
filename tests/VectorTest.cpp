#include <cstdint>
#include <gtest/gtest.h>
#include <linreg/structures/Vector.hpp>

class VectorFixture : public ::testing::Test {
public:
	linreg::structures::Vector<uint32_t> vec;
protected:
	void SetUp() override {
		this->vec.clear();
		this->vec = {11,12,13};
	}
};

TEST_F(VectorFixture,VectorScalarAddition) {
	this->vec += 5;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({16,17,18}));
}

TEST_F(VectorFixture,VectorScalarAdditionCopy) {
	auto res = this->vec + 5;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({16,17,18}));
}

TEST_F(VectorFixture,VectorVectorAddition) {
	linreg::structures::Vector vec2(this->vec + 5);
	this->vec += vec2;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({27,29,31}));
}

TEST_F(VectorFixture,VectorVectorAdditionCopy) {
	linreg::structures::Vector vec2(this->vec + 5);
	auto res = this->vec + vec2;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({27,29,31}));
}

TEST_F(VectorFixture,VectorScalarSubtraction) {
	this->vec -= 5;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({6,7,8}));
}

TEST_F(VectorFixture,VectorScalarSubtractionCopy) {
	auto res = this->vec - 5;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({6,7,8}));
}

TEST_F(VectorFixture,VectorVectorSubtraction) {
	linreg::structures::Vector vec2(this->vec - 5);
	this->vec -= vec2;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({5,5,5}));
}

TEST_F(VectorFixture,VectorVectorSubtractionCopy) {
	linreg::structures::Vector vec2(this->vec - 5);
	auto res = this->vec - vec2;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({5,5,5}));
}

TEST_F(VectorFixture,VectorScalarMultiplication) {
	this->vec *= 5;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({55,60,65}));
}

TEST_F(VectorFixture,VectorScalarMultiplicationCopy) {
	auto res = this->vec * 5;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({55,60,65}));
}

TEST_F(VectorFixture,VectorVectorMultiplication) {
	linreg::structures::Vector vec2(this->vec);
	this->vec *= vec2;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({121,144,169}));
}

TEST_F(VectorFixture,VectorVectorMultiplicationCopy) {
	linreg::structures::Vector vec2(this->vec);
	auto res = this->vec * vec2;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({121,144,169}));
}

TEST_F(VectorFixture,VectorScalarDivision) {
	this->vec /= 5;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({2,2,2}));
}

TEST_F(VectorFixture,VectorScalarDivisionCopy) {
	auto res = this->vec / 5;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({2,2,2}));
}

TEST_F(VectorFixture,VectorVectorDivision) {
	linreg::structures::Vector vec2(this->vec);
	this->vec /= vec2;
	EXPECT_EQ(this->vec,linreg::structures::Vector<uint32_t>({1,1,1}));
}

TEST_F(VectorFixture,VectorVectorDivisionCopy) {
	linreg::structures::Vector vec2(this->vec);
	auto res = this->vec / vec2;
	EXPECT_EQ(res,linreg::structures::Vector<uint32_t>({1,1,1}));
}
