#include "doctest/doctest.h"

#include "gosh2cpp/gosh2cpp.hpp"
#include <utility>

using vec_vec = std::pair<gosh2cpp::vec3, gosh2cpp::vec3>;
using vec_swi = std::pair<gosh2cpp::vec3, gosh2cpp::detail::swizzle<gosh2cpp::vec, float, 3, 0, 1, 2>>;
using swi_vec = std::pair<gosh2cpp::detail::swizzle<gosh2cpp::vec, float, 4, 0, 1, 2>, gosh2cpp::vec3>;
using swi_swi = std::pair<gosh2cpp::detail::swizzle<gosh2cpp::vec, float, 3, 0, 1, 2>, gosh2cpp::detail::swizzle<gosh2cpp::vec, float, 3, 0, 1, 2>>;

TEST_CASE("Sub vector construction")
{
	gosh2cpp::vec3 w(gosh2cpp::vec2(1.0, 2.0), 3.0);
	CHECK(w == gosh2cpp::vec3 {1.0, 2.0, 3.0});
}

TEST_CASE_TEMPLATE("Testing vectors and swizzles operations", T, vec_vec, vec_swi, swi_vec, swi_swi)
{
	using vec_a = typename T::first_type;
	using vec_b = typename T::second_type;

	using bvec = gosh2cpp::change_scalar_t<vec_a, bool>;

	auto v = vec_a {1.0, 2.0, 3.0};

	REQUIRE(v[0] == 1.0);
	REQUIRE(v[1] == 2.0);
	REQUIRE(v[2] == 3.0);

	SUBCASE("Default construction")
	{
		vec_a w;
		REQUIRE(w[0] == 0.0);
		REQUIRE(w[1] == 0.0);
		REQUIRE(w[2] == 0.0);
	}

	SUBCASE("Testing assignment and comparison")
	{
		auto w = vec_b {10.0, 20.0, 30.0};

		REQUIRE(v == v);
		REQUIRE(v != w);
		REQUIRE_FALSE(v == w);
		REQUIRE_FALSE(v != v);

		v = w;

		REQUIRE(v == w);
		REQUIRE_FALSE(v != w);
	}

	SUBCASE("Testing unary vec operations")
	{
		CHECK(-v == vec_a {-1.0, -2.0, -3.0});

		bvec vec_bool {true, false, true};
		bvec vec_bool_f {false, false, false};
		bvec vec_bool_t {true, true, true};

		CHECK(not(vec_bool) == bvec {false, true, false});
		CHECK(gosh2cpp::any(vec_bool) == true);
		CHECK_FALSE(gosh2cpp::any(vec_bool_f) == true);
		CHECK(gosh2cpp::all(vec_bool_t) == true);
		CHECK_FALSE(gosh2cpp::all(vec_bool) == true);
	}

	SUBCASE("Testing binary vec operations")
	{
		auto w = vec_b {10.0, 20.0, 30.0};

		auto a = w;
		auto b = w;
		auto c = w;
		auto d = w;

		a += v;
		CHECK(a == vec_b {11.0, 22.0, 33.0});
		CHECK((w + v) == vec_b {11.0, 22.0, 33.0});
		b -= v;
		CHECK(b == vec_b {9.0, 18.0, 27.0});
		CHECK((w - v) == vec_b {9.0, 18.0, 27.0});
		c *= v;
		CHECK(c == vec_b {10.0, 40.0, 90.0});
		CHECK((w * v) == vec_b {10.0, 40.0, 90.0});
		d /= v;
		CHECK(d == vec_b {10.0, 10.0, 10.0});
		CHECK((w / v) == vec_b {10.0, 10.0, 10.0});
	}

	SUBCASE("Testing binary scalar operations")
	{
		auto s = 2.0;

		auto a = v;
		auto b = v;
		auto c = v;
		auto d = v;

		a += s;
		CHECK(a == vec_b {3.0, 4.0, 5.0});
		CHECK((v + s) == vec_b {3.0, 4.0, 5.0});
		CHECK((s + v) == vec_b {3.0, 4.0, 5.0});
		b -= s;
		CHECK(b == vec_b {-1.0, 0.0, 1.0});
		CHECK((v - s) == vec_b {-1.0, 0.0, 1.0});
		CHECK((s - v) == vec_b {1.0, 0.0, -1.0});
		c *= s;
		CHECK(c == vec_b {2.0, 4.0, 6.0});
		CHECK((v * s) == vec_b {2.0, 4.0, 6.0});
		CHECK((s * v) == vec_b {2.0, 4.0, 6.0});
		d /= s;
		CHECK(d == vec_b {0.5, 1.0, 1.5});
		CHECK((v / s) == vec_b {0.5, 1.0, 1.5});
		CHECK((s / v) == vec_b {2.0, 1.0, 2.0 / 3.0});
	}
}

TEST_CASE("Testing swizzling")
{
	auto v = gosh2cpp::vec3(1.0, 2.0, 3.0);

	SUBCASE("Testing construction")
	{
		CHECK(v.z == doctest::Approx(3.0));
		CHECK(v.yyy == gosh2cpp::vec3(2.0, 2.0, 2.0));
		CHECK(v.yx == gosh2cpp::vec2(2.0, 1.0));
		CHECK(v.zyxz == gosh2cpp::vec4(3.0, 2.0, 1.0, 3.0));
	}

	SUBCASE("Testing vec to swizzle assignment")
	{
		v.yzx = gosh2cpp::vec3(1.0, 2.0, 3.0);
		CHECK(v == gosh2cpp::vec3 {3.0, 1.0, 2.0});
	}

	SUBCASE("Testing swizzle to vec assignment")
	{
		gosh2cpp::vec2 v2 = v.zx;
		gosh2cpp::vec3 v3 = v.xyy;
		gosh2cpp::vec4 v4 = v.yzxy;

		CHECK(v2 == gosh2cpp::vec2 {3.0, 1.0});
		CHECK(v3 == gosh2cpp::vec3 {1.0, 2.0, 2.0});
		CHECK(v4 == gosh2cpp::vec4 {2.0, 3.0, 1.0, 2.0});
	}

	SUBCASE("Testing swizzle to vec conversion")
	{
		auto w = gosh2cpp::vec3(v.yzx);
		CHECK(w == gosh2cpp::vec3 {2.0, 3.0, 1.0});
	}
}