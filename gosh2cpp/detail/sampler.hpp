#ifndef GOSH2CPP_SAMPLER_H_INCLUDED
#define GOSH2CPP_SAMPLER_H_INCLUDED

#include <memory>

namespace gosh2cpp {

template <typename T, int N>
class mat;
template <typename T, int N>
struct vec;

template <typename>
class samplable {};

template <typename S, int D, bool CUBE = false>
class sampler {
	constexpr static int DIM = D + int(CUBE);

	std::unique_ptr<samplable<sampler>> m_texture;

  public:
	template <typename T, typename... ARGS>
	inline void emplace_samplable(ARGS&&... args)
	{
		m_texture = std::make_unique<T>(std::forward<ARGS>(args)...);
	}

	inline vec<int, D> size(int lod) const { return m_texture != nullptr ? m_texture->size(lod) : vec<int, D> {}; }
	inline vec<S, 4> sample(const vec<S, DIM>& uv, float bias) const { return m_texture != nullptr ? m_texture->sample(uv, bias) : vec<S, 4> {}; }
	inline vec<S, 4> sample_lod(const vec<S, DIM>& uv, float lod) const { return m_texture != nullptr ? m_texture->sample_lod(uv, lod) : vec<S, 4> {}; }
	inline vec<S, 4> texel(const vec<int, DIM>& coord, int lod) const { return m_texture != nullptr ? m_texture->texel(coord, lod) : vec<S, 4> {}; }
};

template <typename S, int D, bool CUBE>
class samplable <sampler<S, D, CUBE>>{
	constexpr static int DIM = D + int(CUBE);

  public:
	virtual vec<int, D> size(int lod) = 0;
	virtual vec<S, 4> sample(const vec<S, DIM>& uv, float bias) = 0;
	virtual vec<S, 4> sample_lod(const vec<S, DIM>& uv, float lod) = 0;
	virtual vec<S, 4> texel(const vec<int, DIM>& coord, int lod) = 0;
	virtual ~samplable() = default;
};

template <typename>
struct texture_ops {};

template <typename S, int D, bool CUBE>
struct texture_ops<sampler<S, D, CUBE>> {
	using size = vec<int, D>;
	using uv = vec<S, D + int(CUBE)>;
	using uv_homogenous = vec<S, D + int(CUBE) + 1>;
	using coord = vec<int, D + int(CUBE)>;
	using sample = vec<S, 4>;
};

namespace detail {

template <vector V>
inline auto project(const V& v)
{
	constexpr int last_idx = dimension_v<V> - 1;
	vec<scalar_type_t<V>, last_idx> result;
	for(int i = 0; i < last_idx; i++) {
		result[i] = v[i] / v[last_idx];
	}
	return result;
}

} // namespace detail

template <typename T>
auto textureSize(const T& sampler, int lod) -> typename texture_ops<T>::size
{
	return sampler.size(lod);
}

template <typename T>
auto texture(const T& sampler, typename texture_ops<T>::uv uv, float bias = 0) -> typename texture_ops<T>::sample
{
	return sampler.sample(uv, bias);
}

template <typename T>
auto textureProj(const T& sampler, typename texture_ops<T>::uv_homogenous uvh, float bias = 0) -> typename texture_ops<T>::sample
{
	const auto uv = detail::project(uvh);
	return texture(sampler, uv, bias);
}

template <typename T>
auto textureLod(const T& sampler, typename texture_ops<T>::uv uv, float lod) -> typename texture_ops<T>::sample
{
	return sampler.sample_lod(uv, lod);
}

template <typename T>
auto textureProjLod(const T& sampler, typename texture_ops<T>::uv_homogenous uvh, float lod) -> typename texture_ops<T>::sample
{
	const auto uv = detail::project(uvh);
	return textureLod(sampler, uv, lod);
}

template <typename T>
auto texelFetch(const T& sampler, typename texture_ops<T>::coord coord, int lod) -> typename texture_ops<T>::sample
{
	return sampler.texel(coord, lod);
}

using sampler2D = sampler<float, 2>;
using isampler2D = sampler<int, 2>;
using usampler2D = sampler<unsigned int, 2>;
using sampler2DArray = sampler<float, 3>;
using isampler2DArray = sampler<int, 3>;
using usampler2DArray = sampler<unsigned int, 3>;
using sampler3D = sampler<float, 3>;
using isampler3D = sampler<int, 3>;
using usampler3D = sampler<unsigned int, 3>;
using samplerCube = sampler<float, 2, true>;

} // namespace gosh2cpp

#endif