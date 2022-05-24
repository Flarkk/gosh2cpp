#ifndef GOSH2CPP_VECMAT_H_INCLUDED
#define GOSH2CPP_VECMAT_H_INCLUDED

#include "swizzle.hpp"
#include "traits.hpp"

#include <array>
#include <type_traits>

namespace gosh2cpp {

template <typename T, int N>
class mat;

namespace detail {

template <int N, int... Indexes>
struct swizzle_idx {};

template <int Index, int... Indexes>
struct swizzle_idx<0, Index, Indexes...> {
	static constexpr int value = Index;
};

template <int N, int Index, int... Indexes>
struct swizzle_idx<N, Index, Indexes...> {
	static constexpr int value = swizzle_idx<N - 1, Indexes...>::value;
};

template <int... Indexes>
inline int idx(int vec_idx)
{
	std::array<int, sizeof...(Indexes)> indexes {Indexes...};
	return indexes[vec_idx];
}

template <template <typename, int> class VEC, typename T, int N, int... Indexes>
struct swizzle {
	static constexpr int M = sizeof...(Indexes);
	std::array<T, N> vector;

	swizzle& operator=(const VEC<T, M>& rhs)
	{
		for(int i = 0; i < M; i++) {
			vector[idx<Indexes...>(i)] = rhs[i];
		}
		return *this;
	}

	inline operator VEC<T, M>() const { return VEC<T, M>(vector[Indexes]...); }

	inline T& operator[](int vec_idx) { return vector.at(idx<Indexes...>(vec_idx)); };
	inline const T& operator[](int vec_idx) const { return vector.at(idx<Indexes...>(vec_idx)); };

	template <int M, template <typename, int> class VEC2, typename T2, int N2, int... Indexes2>
	friend T2& get(swizzle<VEC2, T2, N2, Indexes2...>& swizzle);

	template <int M, template <typename, int> class VEC2, typename T2, int N2, int... Indexes2>
	friend const T2& get(const swizzle<VEC2, T2, N2, Indexes2...>& swizzle);
};

template <int M, template <typename, int> class VEC, typename T, int N, int... Indexes>
inline T& get(swizzle<VEC, T, N, Indexes...>& swizzle)
{
	return std::get<swizzle_idx<M, Indexes...>::value>(swizzle.vector);
};

template <int M, template <typename, int> class VEC, typename T, int N, int... Indexes>
inline const T& get(const swizzle<VEC, T, N, Indexes...>& swizzle)
{
	return std::get<swizzle_idx<M, Indexes...>::value>(swizzle.vector);
};

} // namespace detail

template <typename T, int N>
struct vec {};

template <typename T>
struct vec<T, 2> {
	union {
		std::array<T, 2> vector {T(0.0), T(0.0)};
		struct {
			T x, y;
		};
		GOSH2CPP_INSERT_SWIZZLE_2
	};

	inline T& operator[](int idx) { return vector.at(idx); }
	inline const T& operator[](int idx) const { return vector.at(idx); }

	vec() = default;
	explicit vec(const T& val)
	    : vector {val, val} {};
	vec(const T& x, const T& y)
	    : vector {x, y} {};
	template <typename U>
	vec(const vec<U, 2>& source)
	    : vector {T(source.x), T(source.y)} {};
	vec(const vec& source) = default;
	vec(vec&& source) noexcept = default;
	vec& operator=(const vec& source) = default;
	vec& operator=(vec&& source) noexcept = default;
};

template <typename T>
struct vec<T, 3> {
	union {
		std::array<T, 3> vector {T(0.0), T(0.0), T(0.0)};
		struct {
			T x, y, z;
		};
		struct {
			T r, g, b;
		};
		GOSH2CPP_INSERT_SWIZZLE_3
	};

	inline T& operator[](int idx) { return vector.at(idx); }
	inline const T& operator[](int idx) const { return vector.at(idx); }

	vec() = default;
	explicit vec(const T& val)
	    : vector {val, val, val} {};
	vec(const T& x, const T& y, const T& z)
	    : vector {x, y, z} {};
	vec(const T& x, const vec<T, 2>& yz)
	    : vector {x, yz.x, yz.y} {};
	vec(const vec<T, 2>& xy, const T& z)
	    : vector {xy.x, xy.y, z} {};
	template <typename U>
	vec(const vec<U, 3>& source)
	    : vector {T(source.x), T(source.y), T(source.z)} {};
	vec(const vec& source) = default;
	vec(vec&& source) noexcept = default;
	vec& operator=(const vec& source) = default;
	vec& operator=(vec&& source) noexcept = default;
};

template <typename T>
struct vec<T, 4> {
	union {
		std::array<T, 4> vector {T(0.0), T(0.0), T(0.0), T(0.0)};
		struct {
			T x, y, z, w;
		};
		struct {
			T r, g, b, a;
		};
		GOSH2CPP_INSERT_SWIZZLE_4
	};

	inline T& operator[](int idx) { return vector.at(idx); }
	inline const T& operator[](int idx) const { return vector.at(idx); }

	vec() = default;
	explicit vec(const T& val)
	    : vector {val, val, val, val} {};
	vec(const T& x, const T& y, const T& z, const T& w)
	    : vector {x, y, z, w} {};
	vec(const T& x, const vec<T, 3>& yzw)
	    : vector {x, yzw.x, yzw.y, yzw.z} {};
	vec(const vec<T, 2>& xy, const vec<T, 2>& zw)
	    : vector {xy.x, xy.y, zw.x, zw.y} {};
	vec(const vec<T, 2>& xy, const T& z, const T& w)
	    : vector {xy.x, xy.y, z, w} {};
	vec(const T& x, const T& y, const vec<T, 2>& zw)
	    : vector {x, y, zw.x, zw.y} {};
	vec(const vec<T, 3>& xyz, const T& w)
	    : vector {xyz.x, xyz.y, xyz.z, w} {};
	vec(const T& x, const vec<T, 2>& yz, const T& w)
	    : vector {x, yz.x, yz.y, w} {};
	template <typename U>
	vec(const vec<U, 4>& source)
	    : vector {T(source.x), T(source.y), T(source.z), T(source.w)} {};
	vec(const vec& source) = default;
	vec(vec&& source) noexcept = default;
	vec& operator=(const vec& source) = default;
	vec& operator=(vec&& source) noexcept = default;
};

template <typename T, int N>
struct mat {
	std::array<vec<T, N>, N> matrix;

	inline vec<T, N>& operator[](int idx) { return matrix.at(idx); }
	inline const vec<T, N>& operator[](int idx) const { return matrix.at(idx); }

	mat() = default;
	template <typename... Us>
	requires mat_row<N, T, Us...> &&(sizeof...(Us) == N) explicit mat(Us... cols)
	{
		constexpr int nb_cols = sizeof...(cols);
		const std::array<typename is_mat_row<N, T, Us...>::type, nb_cols> cols_array {cleanup(cols)...};
		for(int col = 0; col < nb_cols; col++) {
			matrix.at(col) = cols_array.at(col);
		}
	}

	explicit mat(const T& val)
	{
		for(int d = 0; d < N; d++) {
			matrix.at(d)[d] = val;
		}
	}

	template <int M>
	explicit mat(const mat<T, M>& m)
	{
		constexpr int min_d = N < M ? N : M;
		constexpr int max_d = N > M ? N : M;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(i < min_d && j < min_d) {
					matrix.at(i)[j] = m[i][j];
				} else {
					matrix.at(i)[j] = i == j ? 1 : 0;
				}
			}
		}
	}
	mat(const mat& source) = default;
	mat(mat&& source) noexcept = default;
	mat& operator=(const mat& source) = default;
	mat& operator=(mat&& source) noexcept = default;
};

using vec2 = vec<float, 2>;
using vec3 = vec<float, 3>;
using vec4 = vec<float, 4>;
using bvec2 = vec<bool, 2>;
using bvec3 = vec<bool, 3>;
using bvec4 = vec<bool, 4>;
using ivec2 = vec<int, 2>;
using ivec3 = vec<int, 3>;
using ivec4 = vec<int, 4>;
using mat2 = mat<float, 2>;
using mat3 = mat<float, 3>;
using mat4 = mat<float, 4>;

} // namespace gosh2cpp

#endif