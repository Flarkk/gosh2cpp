#include "doctest/doctest.h"

#include "gosh2cpp/gosh2cpp.hpp"

#include <numbers>
#include <utility>

using sca = float;
using vec = gosh2cpp::vec<float, 3>;
using swi = gosh2cpp::detail::swizzle<gosh2cpp::vec, float, 3, 0, 1, 2>;
using mat = gosh2cpp::mat<float, 3>;

template <typename T>
bool approx_equals(const T& a, const T& b)
{
	return std::abs(float(a) - float(b)) < 1e-5;
}

template <>
bool approx_equals<vec>(const vec& a, const vec& b)
{
	for(int i = 0; i < 3; i++) {
		if(!approx_equals(a[i], b[i])) {
			return false;
		}
	}
	return true;
}

template <>
bool approx_equals<swi>(const swi& a, const swi& b)
{
	return approx_equals(vec(a), vec(b));
}

template <>
bool approx_equals<mat>(const mat& a, const mat& b)
{
	for(int i = 0; i < 3; i++) {
		if(!approx_equals(a[i][i], b[i][i])) {
			return false;
		}
	}
	return true;
}

TEST_CASE_TEMPLATE("Testing single typed functions", T, sca, vec, mat)
{
	T var_e {std::numbers::e_v<float>};
	T var_pi_half {std::numbers::pi_v<float> / 2.0};
	T var_pi_quarter {std::numbers::pi_v<float> / 4.0};
	T var_0 {0.0};
	T var_1 {1.0};
	T var_2 {2.0};
	T var_3 {3.0};
	T var_4 {4.0};
	T var_5 {5.0};
	T var_10 {10.0};

	CHECK(approx_equals(gosh2cpp::degrees(var_pi_half), T {90.0}));
	CHECK(approx_equals(gosh2cpp::degrees(var_pi_quarter), T {45.0}));

	CHECK(approx_equals(gosh2cpp::radians(T {90.0}), var_pi_half));
	CHECK(approx_equals(gosh2cpp::radians(T {45.0}), var_pi_quarter));

	CHECK(approx_equals(gosh2cpp::exp(var_0), var_1));
	CHECK(approx_equals(gosh2cpp::exp(var_1), var_e));

	CHECK(approx_equals(gosh2cpp::exp2(var_0), var_1));
	CHECK(approx_equals(gosh2cpp::exp2(var_1), var_2));

	CHECK(approx_equals(gosh2cpp::log(var_1), var_0));
	CHECK(approx_equals(gosh2cpp::log(var_e), var_1));

	CHECK(approx_equals(gosh2cpp::log2(var_1), var_0));
	CHECK(approx_equals(gosh2cpp::log2(var_2), var_1));

	CHECK(approx_equals(gosh2cpp::sqrt(var_1), var_1));
	CHECK(approx_equals(gosh2cpp::sqrt(var_4), var_2));

	CHECK(approx_equals(gosh2cpp::inversesqrt(var_1), var_1));
	CHECK(approx_equals(gosh2cpp::inversesqrt(var_4), T {0.5}));

	CHECK(approx_equals(gosh2cpp::sin(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::sin(var_pi_half), var_1));

	CHECK(approx_equals(gosh2cpp::asin(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::asin(var_1), var_pi_half));

	CHECK(approx_equals(gosh2cpp::cos(var_0), var_1));
	CHECK(approx_equals(gosh2cpp::cos(var_pi_half), var_0));

	CHECK(approx_equals(gosh2cpp::acos(var_1), var_0));
	CHECK(approx_equals(gosh2cpp::acos(var_0), var_pi_half));

	CHECK(approx_equals(gosh2cpp::tan(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::tan(var_pi_quarter), var_1));

	CHECK(approx_equals(gosh2cpp::atan(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::atan(var_1), var_pi_quarter));

	CHECK(approx_equals(gosh2cpp::atan(var_0, var_1), var_0));
	CHECK(approx_equals(gosh2cpp::atan(var_2, var_2), var_pi_quarter));

	CHECK(approx_equals(gosh2cpp::sinh(gosh2cpp::log(var_1)), var_0));
	CHECK(approx_equals(gosh2cpp::sinh(gosh2cpp::log(var_2)), var_3 / var_4));

	CHECK(approx_equals(gosh2cpp::asinh(var_0), gosh2cpp::log(var_1)));
	CHECK(approx_equals(gosh2cpp::asinh(var_3 / var_4), gosh2cpp::log(var_2)));

	CHECK(approx_equals(gosh2cpp::cosh(gosh2cpp::log(var_1)), var_1));
	CHECK(approx_equals(gosh2cpp::cosh(gosh2cpp::log(var_2)), var_5 / var_4));

	CHECK(approx_equals(gosh2cpp::acosh(var_1), gosh2cpp::log(var_1)));
	CHECK(approx_equals(gosh2cpp::acosh(var_5 / var_4), gosh2cpp::log(var_2)));

	CHECK(approx_equals(gosh2cpp::tanh(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::tanh(gosh2cpp::log(var_2)), var_3 / var_5));

	CHECK(approx_equals(gosh2cpp::atanh(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::atanh(var_3 / var_5), gosh2cpp::log(var_2)));

	CHECK(approx_equals(gosh2cpp::min(var_0, -var_1), -var_1));
	CHECK(approx_equals(gosh2cpp::min(var_10, var_2), var_2));

	CHECK(approx_equals(gosh2cpp::max(var_0, -var_1), var_0));
	CHECK(approx_equals(gosh2cpp::max(var_10, var_2), var_10));

	CHECK(approx_equals(gosh2cpp::clamp(var_4, -var_1, var_2), var_2));
	CHECK(approx_equals(gosh2cpp::clamp(-var_2, -var_10, var_2), -var_2));

	CHECK(approx_equals(gosh2cpp::mix(var_0, var_2, T {0.8}), T {1.6}));
	CHECK(approx_equals(gosh2cpp::mix(var_1, var_2, T {0.1}), T {1.1}));

	CHECK(approx_equals(gosh2cpp::step(var_0, var_2), var_1));
	CHECK(approx_equals(gosh2cpp::step(var_2, var_1), var_0));

	CHECK(approx_equals(gosh2cpp::smoothstep(var_0, var_1, T {0.8}), T {T {0.8} * T {0.8} * (3 - 2 * T {0.8})}));
	CHECK(approx_equals(gosh2cpp::smoothstep(var_0, var_10, var_5), T {0.5}));
	{
		int niv = -10;
		auto nan = gosh2cpp::change_scalar_t<T, float>(*reinterpret_cast<float*>(&niv));

		CHECK(gosh2cpp::isnan(T {nan}) == gosh2cpp::change_scalar_t<T, bool>(true));
		CHECK(gosh2cpp::isnan(var_1) == gosh2cpp::change_scalar_t<T, bool>(false));
	}

	{
		int iv = 10;
		float fv = -10;
		unsigned int uiv = 10;
		CHECK(gosh2cpp::floatBitsToInt(T {fv}) == gosh2cpp::change_scalar_t<T, int>(*reinterpret_cast<int*>(&fv)));
		CHECK(gosh2cpp::floatBitsToUint(T {fv}) == gosh2cpp::change_scalar_t<T, unsigned int>(*reinterpret_cast<unsigned int*>(&fv)));
		CHECK(gosh2cpp::intBitsToFloat(gosh2cpp::change_scalar_t<T, int> {iv}) == gosh2cpp::change_scalar_t<T, float>(*reinterpret_cast<float*>(&iv)));
		CHECK(gosh2cpp::uintBitsToFloat(gosh2cpp::change_scalar_t<T, unsigned int> {uiv}) == gosh2cpp::change_scalar_t<T, float>(*reinterpret_cast<float*>(&uiv)));
	}

	CHECK(approx_equals(gosh2cpp::sign(var_10), var_1));
	CHECK(approx_equals(gosh2cpp::sign(var_0), var_0));
	CHECK(approx_equals(gosh2cpp::sign(-var_1), -var_1));

	CHECK(approx_equals(gosh2cpp::floor(T {1.8}), T {1.0}));
	CHECK(approx_equals(gosh2cpp::floor(T {-1.8}), T {-2.0}));

	CHECK(approx_equals(gosh2cpp::ceil(T {1.8}), T {2.0}));
	CHECK(approx_equals(gosh2cpp::ceil(T {-1.8}), T {-1.0}));

	CHECK(approx_equals(gosh2cpp::trunc(T {1.8}), T {1.0}));
	CHECK(approx_equals(gosh2cpp::trunc(T {-1.8}), T {-1.0}));

	CHECK(approx_equals(gosh2cpp::round(T {1.8}), T {2.0}));
	CHECK(approx_equals(gosh2cpp::round(T {1.2}), T {1.0}));
	CHECK(approx_equals(gosh2cpp::round(T {-1.8}), T {-2.0}));

	CHECK(approx_equals(gosh2cpp::roundEven(T {1.8}), T {2.0}));
	CHECK(approx_equals(gosh2cpp::roundEven(T {1.2}), T {2.0}));
	CHECK(approx_equals(gosh2cpp::roundEven(T {-1.8}), T {-2.0}));

	CHECK(approx_equals(gosh2cpp::fract(T {1.8}), T {0.8}));
	CHECK(approx_equals(gosh2cpp::fract(T {-1.8}), T {0.2}));

	CHECK(approx_equals(gosh2cpp::abs(var_1), var_1));
	CHECK(approx_equals(gosh2cpp::abs(-var_1), var_1));

	CHECK(approx_equals(gosh2cpp::mod(var_5, var_2), var_1));
	CHECK(approx_equals(gosh2cpp::mod(-var_5, var_3), var_1));

	{
		T var_out;
		CHECK(approx_equals(gosh2cpp::modf(T {1.8}, var_out), var_1));
		CHECK(approx_equals(var_out, T {0.8}));
		CHECK(approx_equals(gosh2cpp::modf(T {-1.8}, var_out), -var_2));
		CHECK(approx_equals(var_out, T {0.2}));
	}
}

using ivec = gosh2cpp::vec<int, 3>;
using uvec = gosh2cpp::vec<unsigned int, 3>;

TEST_CASE_TEMPLATE("Testing single typed functions", T, int, unsigned int, ivec, uvec)
{
	T var_0 {0};
	T var_1 {1};
	T var_2 {2};
	T var_3 {3};
	T var_4 {4};
	T var_5 {5};
	T var_10 {10};

	// Bitwise operations are just checked against compilation for now
	auto test1 = ~var_1;

	auto test2 = var_1 << var_1;
	auto test3 = var_1 << 1;

	auto test4 = var_1 >> var_1;
	auto test5 = var_1 >> 1;

	auto test61 = var_1 ^ var_2;
	auto test62 = var_1 ^ 2;

	auto test71 = var_1 & var_2;
	auto test72 = var_1 & 2;

	auto test81 = var_1 | var_2;
	auto test82 = var_1 | 2;

	CHECK(var_5 % var_2 == var_1);

	CHECK(gosh2cpp::min(var_0, var_1) == var_0);
	CHECK(gosh2cpp::min(var_10, var_2) == var_2);

	CHECK(gosh2cpp::max(var_0, var_1) == var_1);
	CHECK(gosh2cpp::max(var_10, var_2) == var_10);

	CHECK(gosh2cpp::clamp(var_4, var_1, var_2) == var_2);
	CHECK(gosh2cpp::clamp(var_0, var_1, var_2) == var_1);

	CHECK(gosh2cpp::step(var_0, var_2) == var_1);
	CHECK(gosh2cpp::step(var_2, var_1) == var_0);

	CHECK(gosh2cpp::sign(var_10) == var_1);
	CHECK(gosh2cpp::sign(var_0) == var_0);

	CHECK(gosh2cpp::abs(var_1) == var_1);
}

using bvec = gosh2cpp::vec<bool, 3>;

TEST_CASE_TEMPLATE("Testing single typed functions", T, bool, bvec)
{
	T var_false {false};
	T var_true {true};

	CHECK(!var_false == var_true);
}

using vec_vec = std::pair<vec, vec>;
using vec_swi = std::pair<vec, swi>;
using swi_vec = std::pair<swi, vec>;
using swi_swi = std::pair<swi, swi>;

TEST_CASE_TEMPLATE("Testing vector only functions", T, vec_vec, vec_swi, swi_vec, swi_swi)
{
	typename T::first_type vec_a {2.0, 4.0, 0.0};
	typename T::second_type vec_b {1.0, 3.0, 2.0};

	gosh2cpp::mat<
	    gosh2cpp::scalar_type_t<typename T::first_type>,
	    gosh2cpp::dimension_v<typename T::first_type>>
	    outer_p {
	        typename T::first_type {2.0, 6.0, 4.0},
	        typename T::first_type {4.0, 12.0, 8.0},
	        typename T::first_type {0.0, 0.0, 0.0}};

	CHECK(gosh2cpp::length(vec_a) == doctest::Approx(2 * gosh2cpp::sqrt(5.0)));
	CHECK(gosh2cpp::distance(vec_a, vec_b) == doctest::Approx(gosh2cpp::sqrt(6.0)));
	CHECK(gosh2cpp::dot(vec_a, vec_b) == 14.0);
	CHECK(gosh2cpp::cross(vec_a, vec_b) == typename T::first_type {8.0, -4.0, 2.0});
	gosh2cpp::reflect(vec_a, vec_b);
	gosh2cpp::refract(vec_a, vec_b, 20.0);

	auto norm = gosh2cpp::normalize(vec_b);
	CHECK(norm[0] == doctest::Approx(1 / gosh2cpp::sqrt(14.0)));
	CHECK(norm[1] == doctest::Approx(3 / gosh2cpp::sqrt(14.0)));
	CHECK(norm[2] == doctest::Approx(gosh2cpp::sqrt(2.0 / 7.0)));

	CHECK(gosh2cpp::faceforward(vec_a, vec_b, vec_a * 2.0) == -vec_a);
	CHECK(gosh2cpp::outerProduct(vec_a, vec_b) == outer_p);

	using bvec = gosh2cpp::change_scalar_t<typename T::first_type, bool>;
	CHECK(gosh2cpp::lessThan(vec_a, vec_b) == bvec {false, false, true});
	CHECK(gosh2cpp::greaterThan(vec_a, vec_b) == bvec {true, true, false});
	CHECK(gosh2cpp::lessThanEqual(vec_a - 1.0, vec_b) == bvec {true, true, true});
	CHECK(gosh2cpp::greaterThanEqual(vec_a - 1.0, vec_b) == bvec {true, true, false});
	CHECK(gosh2cpp::equal(vec_a - 1.0, vec_b) == bvec {true, true, false});
	CHECK(gosh2cpp::notEqual(vec_a - 1.0, vec_b) == bvec {false, false, true});
}

using ivec_ivec = std::pair<ivec, ivec>;
using uvec_uvec = std::pair<uvec, uvec>;

TEST_CASE_TEMPLATE("Testing integer vector only functions", T, ivec_ivec, uvec_uvec)
{
	typename T::first_type vec_a {2, 4, 2};
	typename T::second_type vec_b {1, 3, 2};

	using bvec = gosh2cpp::change_scalar_t<typename T::first_type, bool>;

	CHECK(gosh2cpp::lessThan(vec_a, vec_b) == bvec {false, false, false});
	CHECK(gosh2cpp::greaterThan(vec_a, vec_b) == bvec {true, true, false});
	CHECK(gosh2cpp::lessThanEqual(vec_a, vec_b) == bvec {false, false, true});
	CHECK(gosh2cpp::greaterThanEqual(vec_a, vec_b) == bvec {true, true, true});
	CHECK(gosh2cpp::equal(vec_a, vec_b) == bvec {false, false, true});
	CHECK(gosh2cpp::notEqual(vec_a, vec_b) == bvec {true, true, false});
}

TEST_CASE("Testing ivector only functions")
{
	using bvec = gosh2cpp::vec<bool, 3>;
	bvec vec_a {true, true, false};
	bvec vec_b {true, false, false};

	CHECK(gosh2cpp::equal(vec_a, vec_b) == bvec {true, false, true});
	CHECK(gosh2cpp::notEqual(vec_a, vec_b) == bvec {false, true, false});
}

TEST_CASE("Testing matrix only functions")
{
	using mat3 = gosh2cpp::mat3;
	using vec3 = gosh2cpp::vec3;

	auto m = mat3(
	    vec3(1.0, 2.0, 0.0),
	    vec3(0.0, 1.0, 0.0),
	    vec3(3.0, 0.0, 1.0));

	auto n = mat3(
	    vec3(10.0, 20.0, 0.0),
	    vec3(0.0, 10.0, 0.0),
	    vec3(30.0, 0.0, 10.0));

	CHECK(gosh2cpp::matrixCompMult(m, n) == mat3(vec3(10.0, 40.0, 0.0), vec3(0.0, 10.0, 0.0), vec3(90.0, 0.0, 10.0)));
	CHECK(gosh2cpp::determinant(m) == 1.0f);
}