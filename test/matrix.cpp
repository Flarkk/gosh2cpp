#include "doctest/doctest.h"

#include "gosh2cpp/gosh2cpp.hpp"

using gosh2cpp::vec3;
using gosh2cpp::mat3;

TEST_CASE("Testing matrix operations")
{
	auto m = mat3(
	    vec3(1.0, 2.0, 0.0),
	    vec3(0.0, 1.0, 0.0),
	    vec3(3.0, 0.0, 1.0));

	auto m_inv = mat3(
	    vec3(1.0, -2.0, 0.0),
	    vec3(0.0, 1.0, 0.0),
	    vec3(-3.0, 6.0, 1.0));

	auto m_tra = mat3(
	    vec3(1.0, 0.0, 3.0),
	    vec3(2.0, 1.0, 0.0),
	    vec3(0.0, 0.0, 1.0));

	SUBCASE("Testing mat comparison")
	{
		auto n = mat3(
		    vec3(10.0, 20.0, 0.0),
		    vec3(0.0, 10.0, 0.0),
		    vec3(30.0, 0.0, 10.0));

		REQUIRE(m == m);
		REQUIRE(m != n);
	}

	SUBCASE("Testing matrix construction and access")
	{
		SUBCASE("Testing mat component access")
		{
			REQUIRE(m[0][0] == 1.0);
			REQUIRE(m[0][1] == 2.0);
			REQUIRE(m[0][2] == 0.0);
			REQUIRE(m[1][0] == 0.0);
			REQUIRE(m[1][1] == 1.0);
			REQUIRE(m[1][2] == 0.0);
			REQUIRE(m[2][0] == 3.0);
			REQUIRE(m[2][1] == 0.0);
			REQUIRE(m[2][2] == 1.0);
		}

		SUBCASE("Testing mat construction")
		{
			SUBCASE("Default")
			{
				auto m = mat3();
				REQUIRE(m[0] == vec3());
				REQUIRE(m[1] == vec3());
				REQUIRE(m[2] == vec3());
			}

			SUBCASE("By column, rvalue")
			{
				auto m = mat3(
				    vec3(3.0, 1.0, 2.0),
				    vec3(2.0, 1.0, 3.0),
				    vec3(1.0, 3.0, 2.0));
				REQUIRE(m[0] == vec3(3.0, 1.0, 2.0));
				REQUIRE(m[1] == vec3(2.0, 1.0, 3.0));
				REQUIRE(m[2] == vec3(1.0, 3.0, 2.0));
			}

			SUBCASE("By column, lvalue")
			{
				auto v1 = vec3(3.0, 1.0, 2.0);
				auto v2 = vec3(2.0, 1.0, 3.0);
				auto v3 = vec3(1.0, 3.0, 2.0);

				auto m = mat3(v1, v2, v3);
				CHECK(m[0] == vec3(3.0, 1.0, 2.0));
				CHECK(m[1] == vec3(2.0, 1.0, 3.0));
				CHECK(m[2] == vec3(1.0, 3.0, 2.0));
			}

			SUBCASE("By column, swizzle")
			{
				auto v3 = vec3(1.0, 2.0, 3.0);
				auto m = mat3(
				    v3.zxy,
				    v3.yxz,
				    v3.xzy);
				CHECK(m[0] == vec3(3.0, 1.0, 2.0));
				CHECK(m[1] == vec3(2.0, 1.0, 3.0));
				CHECK(m[2] == vec3(1.0, 3.0, 2.0));
			}

			SUBCASE("Diagonal")
			{
				auto m = mat3(5.0);
				CHECK(m[0] == vec3(5.0, 0.0, 0.0));
				CHECK(m[1] == vec3(0.0, 5.0, 0.0));
				CHECK(m[2] == vec3(0.0, 0.0, 5.0));
			}

			SUBCASE("Smaller submatrix")
			{
				auto m = mat3(gosh2cpp::mat2(
				    gosh2cpp::vec2(5.0, 5.0),
				    gosh2cpp::vec2(5.0, 5.0)));
				CHECK(m[0] == vec3(5.0, 5.0, 0.0));
				CHECK(m[1] == vec3(5.0, 5.0, 0.0));
				CHECK(m[2] == vec3(0.0, 0.0, 1.0));
			}

			SUBCASE("Bigger submatrix")
			{
				auto m = mat3(gosh2cpp::mat4(
				    gosh2cpp::vec4(5.0, 5.0, 5.0, 5.0),
				    gosh2cpp::vec4(5.0, 5.0, 5.0, 5.0),
				    gosh2cpp::vec4(5.0, 5.0, 5.0, 5.0),
				    gosh2cpp::vec4(5.0, 5.0, 5.0, 5.0)));
				CHECK(m[0] == vec3(5.0, 5.0, 5.0));
				CHECK(m[1] == vec3(5.0, 5.0, 5.0));
				CHECK(m[2] == vec3(5.0, 5.0, 5.0));
			}
		}

		SUBCASE("Testing mat assignment")
		{
			auto n = m;
			CHECK(n[0][0] == doctest::Approx(1.0));
			CHECK(n[0][1] == doctest::Approx(2.0));
			CHECK(n[0][2] == doctest::Approx(0.0));
		}

		SUBCASE("Testing mat column access")
		{
			CHECK(m[0] == vec3(1.0, 2.0, 0.0));
			CHECK(m[1] == vec3(0.0, 1.0, 0.0));
			CHECK(m[2] == vec3(3.0, 0.0, 1.0));
		}
	}

	SUBCASE("Testing mat inverse and transpose")
	{
		CHECK(gosh2cpp::inverse(m) == m_inv);
		CHECK(gosh2cpp::transpose(m) == m_tra);
	}

	SUBCASE("Testing mat scalar product from lvalues")
	{
		auto result = m * 2.0;
		CHECK(result[0][0] == doctest::Approx(2.0));
		CHECK(result[0][1] == doctest::Approx(4.0));
		CHECK(result[0][2] == doctest::Approx(0.0));
	}

	SUBCASE("Testing scalar mat product from lvalues")
	{
		auto result = 2.0 * m;
		CHECK(result[0][0] == doctest::Approx(2.0));
		CHECK(result[0][1] == doctest::Approx(4.0));
		CHECK(result[0][2] == doctest::Approx(0.0));
	}

	SUBCASE("Testing mat mat operations")
	{
		auto n = mat3(
		    vec3(10.0, 20.0, 0.0),
		    vec3(0.0, 10.0, 0.0),
		    vec3(30.0, 0.0, 10.0));

		SUBCASE("Testing sum assignment")
		{
			n += m;
			CHECK(n[0][2] == doctest::Approx(0.0));
			CHECK(n[1][1] == doctest::Approx(11.0));
			CHECK(n[2][0] == doctest::Approx(33.0));
		}

		SUBCASE("Testing sum")
		{
			n = n + m;
			CHECK(n[0][2] == doctest::Approx(0.0));
			CHECK(n[1][1] == doctest::Approx(11.0));
			CHECK(n[2][0] == doctest::Approx(33.0));
		}

		SUBCASE("Testing difference assignment")
		{
			n -= m;
			CHECK(n[0][2] == doctest::Approx(0.0));
			CHECK(n[1][1] == doctest::Approx(9.0));
			CHECK(n[2][0] == doctest::Approx(27.0));
		}

		SUBCASE("Testing difference")
		{
			n = n - m;
			CHECK(n[0][2] == doctest::Approx(0.0));
			CHECK(n[1][1] == doctest::Approx(9.0));
			CHECK(n[2][0] == doctest::Approx(27.0));
		}

		SUBCASE("Testing product assignment")
		{
			n *= m;
			CHECK(n[0][2] == doctest::Approx(0.0));
			CHECK(n[1][1] == doctest::Approx(10.0));
			CHECK(n[2][0] == doctest::Approx(60.0));
		}

		SUBCASE("Testing product")
		{
			n = n * m;
			REQUIRE(n[0][2] == doctest::Approx(0.0));
			REQUIRE(n[1][1] == doctest::Approx(10.0));
			REQUIRE(n[2][0] == doctest::Approx(60.0));
		}

		auto n_m_inv = n * m_inv;

		SUBCASE("Testing division assignment")
		{
			n /= m;
			CHECK(n[0][2] == doctest::Approx(n_m_inv[0][2]));
			CHECK(n[1][1] == doctest::Approx(n_m_inv[1][1]));
			CHECK(n[2][0] == doctest::Approx(n_m_inv[2][0]));
		}

		SUBCASE("Testing division")
		{
			n = n / m;
			CHECK(n[0][2] == doctest::Approx(n_m_inv[0][2]));
			CHECK(n[1][1] == doctest::Approx(n_m_inv[1][1]));
			CHECK(n[2][0] == doctest::Approx(n_m_inv[2][0]));
		}

		SUBCASE("Testing negate")
		{
			n = -n;
			CHECK(n[0][2] == doctest::Approx(0.0));
			CHECK(n[1][1] == doctest::Approx(-10.0));
			CHECK(n[2][0] == doctest::Approx(-30.0));
		}
	}
}

TEST_CASE_TEMPLATE("Testing mat vec operations", VEC, vec3, gosh2cpp::detail::swizzle<gosh2cpp::vec, float, 3, 0, 1, 2>)
{
	auto m = mat3(
	    vec3(1.0, 2.0, 0.0),
	    vec3(0.0, 1.0, 0.0),
	    vec3(3.0, 0.0, 1.0));

	auto vector = VEC {3.0, 0.0, 0.0};

	SUBCASE("Testing mat vec product from lvalues")
	{
		auto result = m * vector;
		CHECK(result[0] == doctest::Approx(3.0));
		CHECK(result[1] == doctest::Approx(6.0));
		CHECK(result[2] == doctest::Approx(0.0));
	}

	SUBCASE("Testing vec mat product from lvalues")
	{
		auto result = vector * m;
		CHECK(result[0] == doctest::Approx(3.0));
		CHECK(result[1] == doctest::Approx(0.0));
		CHECK(result[2] == doctest::Approx(9.0));
	}
}
