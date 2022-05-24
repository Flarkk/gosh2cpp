#ifndef GOSH2CPP_FUNCTIONS_H_INCLUDED
#define GOSH2CPP_FUNCTIONS_H_INCLUDED

#include "traits.hpp"
#include "vecmat.hpp"

#include "boost/qvm/lite.hpp"

#include <numbers>
#include <type_traits>

namespace boost::qvm {
template <typename T, int N>
struct is_vec<gosh2cpp::vec<T, N>> {
	static bool const value = true;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct is_vec<gosh2cpp::detail::swizzle<TT, T, N, Indexes...>> {
	static bool const value = true;
};

template <typename T, int N>
struct is_mat<gosh2cpp::mat<T, N>> {
	static bool const value = true;
};

template <typename T, int N>
struct vec_traits<gosh2cpp::vec<T, N>> : vec_traits_defaults<gosh2cpp::vec<T, N>, T, N> {
	template <int I>
	static inline T& write_element(gosh2cpp::vec<T, N>& v)
	{
		return get<I>(v.vector);
	}

	static inline T& write_element_idx(int i, gosh2cpp::vec<T, N>& v) { return v[i]; }
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct vec_traits<gosh2cpp::detail::swizzle<TT, T, N, Indexes...>> : vec_traits_defaults<gosh2cpp::detail::swizzle<TT, T, N, Indexes...>, T, sizeof...(Indexes)> {
	template <int I>
	static inline T& write_element(gosh2cpp::detail::swizzle<TT, T, N, Indexes...>& v)
	{
		return get<I>(v);
	}

	static inline T& write_element_idx(int i, gosh2cpp::detail::swizzle<TT, T, N, Indexes...>& v) { return v[i]; }
};

template <typename T, int N>
struct mat_traits<gosh2cpp::mat<T, N>> : mat_traits_defaults<gosh2cpp::mat<T, N>, T, N, N> {
	template <int R, int C>
	static inline T& write_element(gosh2cpp::mat<T, N>& m)
	{
		return std::get<C>(m.matrix)[R]; // we store column first to ensure vec x mat operation comply with glsl standard
	}

	static inline T& write_element_idx(int r, int c, gosh2cpp::mat<T, N>& m)
	{
		return m.matrix.at(c)[r]; // we store column first to ensure vec x mat operation comply with glsl standard
	}
};

template <typename T, int N>
struct deduce_vec2<gosh2cpp::mat<T, N>, gosh2cpp::vec<T, N>, N> {
	using type = gosh2cpp::vec<T, N>;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct deduce_vec2<gosh2cpp::mat<T, sizeof...(Indexes)>, gosh2cpp::detail::swizzle<TT, T, N, Indexes...>, sizeof...(Indexes)> {
	using type = gosh2cpp::vec<T, sizeof...(Indexes)>;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct deduce_vec2<gosh2cpp::vec<T, sizeof...(Indexes)>, gosh2cpp::detail::swizzle<TT, T, N, Indexes...>, sizeof...(Indexes)> {
	using type = gosh2cpp::vec<T, sizeof...(Indexes)>;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct deduce_vec2<gosh2cpp::detail::swizzle<TT, T, N, Indexes...>, gosh2cpp::vec<T, sizeof...(Indexes)>, sizeof...(Indexes)> {
	using type = gosh2cpp::vec<T, sizeof...(Indexes)>;
};

template <typename T, int N>
struct deduce_vec2<gosh2cpp::vec<T, N>, gosh2cpp::mat<T, N>, N> {
	using type = gosh2cpp::vec<T, N>;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct deduce_vec2<gosh2cpp::detail::swizzle<TT, T, N, Indexes...>, gosh2cpp::mat<T, sizeof...(Indexes)>, sizeof...(Indexes)> {
	using type = gosh2cpp::vec<T, sizeof...(Indexes)>;
};

} // namespace boost::qvm

namespace gosh2cpp {
namespace detail {

inline auto apply(auto const& a, auto f)
{
	return f(a);
}

template <vector V, typename F>
inline auto apply(V const& a, F f)
{
	vec<std::invoke_result_t<F, scalar_type_t<V>>, dimension_v<V>> result;
	for(int i = 0; i < dimension_v<V>; i++) {
		result[i] = f(a[i]);
	}
	return result;
}

template <matrix M, class F>
inline auto apply(M const& a, F f)
{
	mat<std::invoke_result_t<F, scalar_type_t<M>>, dimension_v<M>> result;
	for(int i = 0; i < dimension_v<M>; i++) {
		for(int j = 0; j < dimension_v<M>; j++) {
			result[i][j] = f(a[i][j]);
		}
	}
	return result;
}

inline auto apply(auto const& a, auto const& b, auto f)
{
	return f(a, b);
}

template <vector V, typename T, typename F>
inline auto apply(V const& a, T const& b, F f)
{
	vec<std::invoke_result_t<F, scalar_type_t<V>, T>, dimension_v<V>> result;
	for(int i = 0; i < dimension_v<V>; i++) {
		result[i] = f(a[i], b);
	}
	return result;
}

template <vector U, vector V, class F>
inline auto apply(U const& a, V const& b, F f)
{
	vec<std::invoke_result_t<F, scalar_type_t<U>, scalar_type_t<V>>, dimension_v<V>> result;
	for(int i = 0; i < dimension_v<V>; i++) {
		result[i] = f(a[i], b[i]);
	}
	return result;
}

template <vector V, typename T, class F>
inline auto apply(T const& a, V const& b, F f)
{
	vec<std::invoke_result_t<F, T, scalar_type_t<V>>, dimension_v<V>> result;
	for(int i = 0; i < dimension_v<V>; i++) {
		result[i] = f(a, b[i]);
	}
	return result;
}

template <matrix M, class T, class F>
inline auto apply(M const& a, T const& b, F f)
{
	mat<std::invoke_result_t<F, scalar_type_t<M>, T>, dimension_v<M>> result;
	for(int i = 0; i < dimension_v<M>; i++) {
		for(int j = 0; j < dimension_v<M>; j++) {
			result[i][j] = f(a[i][j], b);
		}
	}
	return result;
}

template <matrix M, class T, class F>
inline auto apply(T const& a, M const& b, F f)
{
	mat<std::invoke_result_t<F, T, scalar_type_t<M>>, dimension_v<M>> result;
	for(int i = 0; i < dimension_v<M>; i++) {
		for(int j = 0; j < dimension_v<M>; j++) {
			result[i][j] = f(a, b[i][j]);
		}
	}
	return result;
}

template <matrix M, class F>
inline auto apply(M const& a, M const& b, F f)
{
	mat<std::invoke_result_t<F, scalar_type_t<M>, scalar_type_t<M>>, dimension_v<M>> result;
	for(int i = 0; i < dimension_v<M>; i++) {
		for(int j = 0; j < dimension_v<M>; j++) {
			result[i][j] = f(a[i][j], b[i][j]);
		}
	}
	return result;
}
} // namespace detail

/******************************************************/
/******************       Bitwise      ****************/
/******************************************************/

auto operator~(const auto& v)
{
	return detail::apply(v, [](auto a) { return ~a; });
}

template <vector U, vector V>
auto operator<<(const U& u, const V& v)
{
	return detail::apply(u, v, [](auto a, auto b) { return a << b; });
}

template <vector U, scalar S>
auto operator<<(const U& u, const S s)
{
	return detail::apply(u, s, [](auto a, auto b) { return a << b; });
}

template <vector U, vector V>
auto operator>>(const U& u, const V& v)
{
	return detail::apply(u, v, [](auto a, auto b) { return a >> b; });
}

template <vector U, scalar S>
auto operator>>(const U& u, const S s)
{
	return detail::apply(u, s, [](auto a, auto b) { return a >> b; });
}

auto operator%(const auto& u, const auto& v)
{
	return detail::apply(u, v, [](auto a, auto b) { return a % b; });
}

auto operator^(const auto& u, const auto& v)
{
	return detail::apply(u, v, [](auto a, auto b) { return a ^ b; });
}

auto operator&(const auto& u, const auto& v)
{
	return detail::apply(u, v, [](auto a, auto b) { return a & b; });
}

auto operator|(const auto& u, const auto& v)
{
	return detail::apply(u, v, [](auto a, auto b) { return a | b; });
}

/******************************************************/
/*******************   Comparison   *******************/
/******************************************************/

inline bool operator!=(auto lhs, const auto& rhs)
{
	return boost::qvm::operator!=(lhs, rhs);
}

inline bool operator==(auto lhs, const auto& rhs)
{
	return boost::qvm::operator==(lhs, rhs);
}

/******************************************************/
/********************   Addition   ********************/
/******************************************************/

//*** vec_or_mat += scalar is not directly supported in boost::qvm. Using a custom element wise implementation instead
template <typename T, scalar S>
auto& operator+=(T& lhs, const S& rhs)
{
	for(int i = 0; i < dimension_v<T>; i++) {
		lhs[i] += rhs;
	}
	return lhs;
}

//*** For all other cases
auto& operator+=(auto& lhs, const auto& rhs)
{
	boost::qvm::operator+=(lhs, cleanup(rhs));
	return lhs;
}

//*** scalar + [vec or mat] is not directly supported in boost::qvm. Using the opposite operation instead
template <scalar S>
auto operator+(S lhs, auto rhs)
{
	rhs += lhs;
	return rhs;
}

//*** For all other cases
auto operator+(auto lhs, const auto& rhs)
{
	lhs += rhs;
	return lhs;
}

/******************************************************/
/******************      Negation      ****************/
/******************************************************/

auto operator-(const auto& a)
{
	return boost::qvm::operator-(a);
}

template <gosh2cpp::vector<bool> V>
auto operator!(const V& v)
{
	return detail::apply(v, [](bool a) { return !a; });
}

/******************************************************/
/******************** Substraction ********************/
/******************************************************/

//*** vec_or_mat -= scalar is not directly supported in boost::qvm. Using a custom element wise implementation instead
template <typename T, scalar S>
auto& operator-=(T& lhs, const S& rhs)
{
	for(int i = 0; i < dimension_v<T>; i++) {
		lhs[i] -= rhs;
	}
	return lhs;
}

//*** For all other cases
auto& operator-=(auto& lhs, const auto& rhs)
{
	boost::qvm::operator-=(lhs, cleanup(rhs));
	return lhs;
}

//*** scalar - [vec or mat] is not directly supported in boost::qvm. Using the opposite operation instead
template <scalar S>
auto operator-(S lhs, auto rhs)
{
	rhs -= lhs;
	return -rhs;
}

//*** For all other cases
auto operator-(auto lhs, const auto& rhs)
{
	lhs -= rhs;
	return lhs;
}

/******************************************************/
/***************** Transpose / Inverse ****************/
/******************************************************/

template <matrix M>
inline auto inverse(const M& mat)
{
	return boost::qvm::inverse(mat);
}

template <matrix M>
inline auto transpose(M mat)
{
	return M(boost::qvm::mat<
	         scalar_type_t<M>,
	         dimension_v<M>,
	         dimension_v<M>>(boost::qvm::transposed(mat)));
}

/******************************************************/
/******************* Multiplication *******************/
/******************************************************/

//*** vec *= vec is not directly supported in boost::qvm. Use a custom element-wise implementation
template <vector U, vector V>
U& operator*=(U& lhs, const V& rhs) requires(dimension_v<U> == dimension_v<V>)
{
	for(int i = 0; i < dimension_v<U>; i++) {
		lhs[i] *= rhs[i];
	}
	return lhs;
}

//*** vec *= mat is not directly supported in boost::qvm. Using the transpose instead
template <vector U, matrix M>
U& operator*=(U& lhs, const M& rhs) requires(dimension_v<U> == dimension_v<M>)
{
	lhs = boost::qvm::operator*(transpose(rhs), cleanup(lhs));
	return lhs;
}

//*** For all other cases
auto& operator*=(auto& lhs, const auto& rhs)
{
	boost::qvm::operator*=(lhs, cleanup(rhs));
	return lhs;
}

//*** vec * mat is not directly supported in boost::qvm. Using the transpose instead
template <vector V, matrix M>
auto operator*(V lhs, const M& rhs)
{
	return boost::qvm::operator*(transpose(rhs), cleanup(lhs));
}

//*** vec * vec is not directly supported in boost::qvm. Use *= operator above
template <vector U, vector V>
auto operator*(U lhs, const V& rhs)
{
	lhs *= cleanup(rhs);
	return lhs;
}

//*** For all other cases
auto operator*(auto lhs, const auto& rhs)
{
	return boost::qvm::operator*(cleanup(lhs), cleanup(rhs));
}

/******************************************************/
/*******************    Division    *******************/
/******************************************************/

//*** vec /= vec is not directly supported in boost::qvm. Use a custom element-wise implementation
template <vector U, vector V>
U& operator/=(U& lhs, const V& rhs) requires(dimension_v<U> == dimension_v<V>)
{
	for(int i = 0; i < dimension_v<U>; i++) {
		lhs[i] /= rhs[i];
	}
	return lhs;
}

//*** mat /= mat is not directly supported in boost::qvm. Use a custom implementation
template <matrix M>
M& operator/=(M& lhs, const M& rhs)
{
	lhs = lhs * inverse(rhs);
	return lhs;
}

//*** For all other cases
auto& operator/=(auto& lhs, const auto& rhs)
{
	boost::qvm::operator/=(lhs, cleanup(rhs));
	return lhs;
}

//*** vec_or_mat / vec_or_mat is not directly supported in boost::qvm. Use custom /= operators above
template <typename T1, typename T2>
requires(vector<T1>&& vector<T2>) || (matrix<T1> && matrix<T2>)auto operator/(T1 lhs, const T2& rhs)
{
	lhs /= cleanup(rhs);
	return lhs;
}

//*** scalar / vec_or_mat is not directly supported in boost::qvm. Use inverse operation
template <scalar S, typename U>
auto operator/(S lhs, const U& rhs)
{
	U ret;
	for(int i = 0; i < dimension_v<U>; i++) {
		ret[i] = lhs / rhs[i];
	}
	return ret;
}

//*** For all other cases
auto operator/(auto lhs, const auto& rhs)
{
	return boost::qvm::operator/(cleanup(lhs), cleanup(rhs));
}

/******************************************************/
/*******************    Functions    ******************/
/******************************************************/

template <typename T>
inline auto radians(const T& vec)
{
	return detail::apply(vec, [](auto a) { return a / 180 * std::numbers::pi_v<scalar_type_t<T>>; });
}

template <typename T>
inline auto degrees(const T& vec)
{
	return detail::apply(vec, [](auto a) { return a * 180 / std::numbers::pi_v<scalar_type_t<T>>; });
}

template <vector V>
inline auto length(const V& vec)
{
	return boost::qvm::mag(vec);
}

template <typename T, typename U>
inline T pow(T a, U b)
{
	return detail::apply(a, b, [](auto a, auto b) { return boost::qvm::pow<std::common_type_t<decltype(a), decltype(b)>>(a, b); });
}

template <typename T>
inline T exp(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::exp(a); });
}

template <typename T>
inline T exp2(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::pow<std::common_type_t<float, decltype(a)>>(2, a); });
}

template <typename T>
inline T log(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::log(a); });
}

template <typename T>
inline T log2(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::log(a) / std::numbers::ln2_v<decltype(a)>; });
}

template <typename T>
inline T sqrt(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::sqrt(a); });
}

template <typename T>
inline T inversesqrt(T a)
{
	return detail::apply(a, [](auto a) { return 1 / boost::qvm::sqrt(a); });
}

template <typename T>
inline T sin(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::sin(a); });
}

template <typename T>
inline T asin(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::asin(a); });
}

template <typename T>
inline T cos(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::cos(a); });
}

template <typename T>
inline T acos(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::acos(a); });
}

template <typename T>
inline T tan(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::tan(a); });
}

template <typename T>
inline T atan(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::atan(a); });
}

template <typename T, typename U>
inline T atan(T x, U y)
{
	return detail::apply(x, y, [](auto a, auto b) { return boost::qvm::atan2<std::common_type_t<decltype(a), decltype(b)>>(a, b); });
}

template <typename T>
inline T sinh(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::sinh(a); });
}

template <typename T>
inline T asinh(T a)
{
	return log(a + sqrt(a * a + 1));
}

template <typename T>
inline T cosh(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::cosh(a); });
}

template <typename T>
inline T acosh(T a)
{
	return log(a + sqrt(a * a - 1));
}

template <typename T>
inline T tanh(T a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::tanh(a); });
}

template <typename T>
inline T atanh(T a)
{
	return (log(1 + a) - log(1 - a)) / 2;
}

template <typename T, typename U>
inline T min(T a, U b)
{
	return detail::apply(a, b, [](auto a, auto b) { return std::min<std::common_type_t<decltype(a), decltype(b)>>(a, b); });
}

template <typename T, typename U>
inline T max(T a, U b)
{
	return detail::apply(a, b, [](auto a, auto b) { return std::max<std::common_type_t<decltype(a), decltype(b)>>(a, b); });
}

template <typename T, typename U, typename V>
inline T clamp(T x, U min_v, V max_v)
{
	return min(max(x, min_v), max_v);
}

template <typename T, typename U, typename V>
inline T mix(const T& a, const U& b, const V& interp)
{
	const V one = V(1);
	return (a * (one - interp)) + (b * interp);
}

template <typename T, typename U>
inline T step(T a, U b)
{
	return detail::apply(a, b, [](auto a, auto b) { return scalar_type_t<T>(b < a ? 0 : 1); });
}

template <typename T, typename U, typename V>
inline auto smoothstep(T edge0, U edge1, V x)
{
	deduce_t<T, V> t;
	t = clamp((x - edge0) / (edge1 - edge0), 0, 1);
	return t * t * (3 - 2 * t);
}

template <typename T>
inline change_scalar_t<T, bool> isnan(T a)
{
	return detail::apply(a, [](auto a) { return a != a; });
}

template <typename T>
inline change_scalar_t<T, bool> isinf(T a)
{
	return detail::apply(a, [](auto a) { return isinf(a); });
}

template <typename T>
inline change_scalar_t<T, int> floatBitsToInt(T a)
{
	return detail::apply(a, [](auto a) { return *reinterpret_cast<int*>(&a); });
}

template <typename T>
inline change_scalar_t<T, unsigned int> floatBitsToUint(T a)
{
	return detail::apply(a, [](auto a) { return *reinterpret_cast<unsigned int*>(&a); });
}

template <typename T>
inline change_scalar_t<T, float> intBitsToFloat(T a)
{
	return detail::apply(a, [](auto a) { return *reinterpret_cast<float*>(&a); });
}

template <typename T>
inline change_scalar_t<T, float> uintBitsToFloat(T a)
{
	return detail::apply(a, [](auto a) { return *reinterpret_cast<float*>(&a); });
}

template <typename T>
inline T sign(T a)
{
	return detail::apply(a, [](auto a) { return scalar_type_t<T>((0 < a) - (a < 0)); });
}

inline auto floor(auto a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::floor(a); });
}

inline auto ceil(auto a)
{
	return detail::apply(a, [](auto a) { return boost::qvm::ceil(a); });
}

inline auto trunc(auto a)
{
	return detail::apply(a, [](auto a) { return a >= 0.0 ? floor(a) : ceil(a); });
}

template <typename T>
inline T round(T a)
{
	return detail::apply(a, [](auto a) { return scalar_type_t<T>((a >= 0.0) ? floor(a + 0.5f) : ceil(a - 0.5f)); });
}

inline auto roundEven(auto a)
{
	return round(a / 2) * 2;
}

inline auto fract(auto a)
{
	return a - floor(a);
}

inline auto mod(auto a, auto b)
{
	return a - b * floor(a / b);
}

inline auto modf(auto a, auto& b)
{
	b = fract(a);
	return floor(a);
}

inline auto abs(auto a)
{
	return a * sign(a);
}

inline auto dot(const auto& a, const auto& b)
{
	return boost::qvm::dot(a, b);
}

template <vector U, vector V>
inline auto cross(const U& a, const V& b)
{
	return boost::qvm::cross(a, b);
}

template <vector U, vector V>
inline auto reflect(const U& a, const V& b)
{
	return a - 2.0 * dot(b, a) * b;
}

template <vector U, vector V>
inline auto refract(const U& a, const V& b, float eta)
{
	const float k = 1.0 - eta * eta * (1.0 - dot(b, a) * dot(b, a));
	return k < 0.0 ? U {0} : eta * a - (eta * dot(b, a) + sqrt(k)) * b;
}

template <vector V>
inline auto normalize(const V& a)
{
	return boost::qvm::normalized(a);
}

template <vector U, vector V, vector W>
inline auto faceforward(const U& a, const V& b, const W& c)
{
	return dot(c, b) < 0 ? a : -a;
}

template <vector U, vector V>
inline auto distance(const U& a, const V& b)
{
	return boost::qvm::mag(b - a);
}

template <matrix M, matrix N>
inline auto matrixCompMult(const M& m, const N& n)
{
	return detail::apply(m, n, [](auto m, auto n) { return m * n; });
}

template <vector U, vector V>
inline auto outerProduct(const U& c, const V& r)
{
	mat<scalar_type_t<U>, dimension_v<U>> result;
	for(int i = 0; i < dimension_v<U>; i++) {
		for(int j = 0; j < dimension_v<U>; j++) {
			result[i][j] = c[i] * r[j];
		}
	}
	return result;
}

template <matrix M>
inline auto determinant(const M& m)
{
	return boost::qvm::determinant(m);
}

template <vector U, vector V>
inline auto lessThan(const U& a, const V& b)
{
	return detail::apply(a, b, [](auto a, auto b) { return a < b; });
}

template <vector U, vector V>
inline auto greaterThan(const U& a, const V& b)
{
	return detail::apply(a, b, [](auto a, auto b) { return a > b; });
}

template <vector U, vector V>
inline auto lessThanEqual(const U& a, const V& b)
{
	return detail::apply(a, b, [](auto a, auto b) { return a <= b; });
}

template <vector U, vector V>
inline auto greaterThanEqual(const U& a, const V& b)
{
	return detail::apply(a, b, [](auto a, auto b) { return a >= b; });
}

template <vector U, vector V>
inline auto equal(const U& a, const V& b)
{
	return detail::apply(a, b, [](auto a, auto b) { return a == b; });
}

template <vector U, vector V>
inline auto notEqual(const U& a, const V& b)
{
	return detail::apply(a, b, [](auto a, auto b) { return a != b; });
}

template <vector<bool> V>
inline auto all(const V& v)
{
	for(int i = 0; i < dimension_v<V>; i++) {
		if(!v[i]) {
			return false;
		}
	}
	return true;
}

template <vector<bool> V>
inline auto any(const V& v)
{
	for(int i = 0; i < dimension_v<V>; i++) {
		if(v[i]) {
			return true;
		}
	}
	return false;
}

template <typename T>
inline T dFdx(T /* a */)
{
	return {0.0};
}

template <typename T>
inline T dFdy(T /* a */)
{
	return {0.0};
}

template <typename T>
inline T fwidth(T /* a */)
{
	return {0.0};
}

} // namespace gosh2cpp

#endif