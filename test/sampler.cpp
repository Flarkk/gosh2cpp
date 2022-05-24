#include "doctest/doctest.h"

#include "gosh2cpp/gosh2cpp.hpp"

TEST_CASE_TEMPLATE("Testing samplers", SAMPLER, gosh2cpp::sampler2D, gosh2cpp::isampler2D, gosh2cpp::usampler2D, gosh2cpp::sampler2DArray, gosh2cpp::isampler2DArray, gosh2cpp::usampler2DArray, gosh2cpp::sampler3D, gosh2cpp::isampler3D, gosh2cpp::usampler3D, gosh2cpp::samplerCube)
{

	using size_ret = typename gosh2cpp::texture_ops<SAMPLER>::size;
	using sample_ret = typename gosh2cpp::texture_ops<SAMPLER>::sample;
	using uv_param = typename gosh2cpp::texture_ops<SAMPLER>::uv;
	using uvh_param = typename gosh2cpp::texture_ops<SAMPLER>::uv_homogenous;
	using coord_param = typename gosh2cpp::texture_ops<SAMPLER>::coord;

	class dummy : public gosh2cpp::samplable<SAMPLER> {
	  public:
		size_ret size(int lod) override { return size_ret {10.0 + lod}; }
		sample_ret sample(const uv_param& uv, float bias) override { return sample_ret {uv.x * 10 + bias}; }
		sample_ret sample_lod(const uv_param& uv, float lod) override { return sample_ret {uv.x * 10 + lod}; }
		sample_ret texel(const coord_param& coord, int lod) override { return sample_ret {coord.x * 100 + lod}; }
	};

	SAMPLER sampler;
    sampler.template emplace_samplable<dummy>();

	const uv_param uv {3.0};
	const uvh_param uvh {3.0};
	const coord_param coord {7.0};

	CHECK(gosh2cpp::textureSize(sampler, 7) == size_ret {17.0});
	CHECK(gosh2cpp::texture(sampler, uv, 1.0) == sample_ret {31.0});
	CHECK(gosh2cpp::textureProj(sampler, uvh, 1.0) == sample_ret {11.0});
	CHECK(gosh2cpp::textureLod(sampler, uv, 3.0) == sample_ret {33.0});
	CHECK(gosh2cpp::textureProjLod(sampler, uvh, 3.0) == sample_ret {13.0});
	CHECK(gosh2cpp::texelFetch(sampler, coord, 5) == sample_ret {705.0});
}
