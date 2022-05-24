#ifndef GOSH2CPP_TRAITS_H_INCLUDED
#define GOSH2CPP_TRAITS_H_INCLUDED

#include <type_traits>

namespace gosh2cpp {

template <typename T, int N>
class mat;
template <typename T, int N>
struct vec;
namespace detail {

template <template <typename, int> typename, typename, int, int...>
struct swizzle;

template <typename T>
struct cleanup_type {
	using type = std::conditional_t<
	    std::is_same_v<T, double>,
	    float,
	    T>;
};

} // namespace detail

template <typename T>
inline auto cleanup(const T& a) -> typename detail::cleanup_type<T>::type
{
	return a;
}

template <typename T>
struct dimension {
	static constexpr int value = 1;
};

template <typename T, int N>
struct dimension<vec<T, N>> {
	static constexpr int value = N;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct dimension<detail::swizzle<TT, T, N, Indexes...>> {
	static constexpr int value = sizeof...(Indexes);
};

template <typename T, int N>
struct dimension<mat<T, N>> {
	static constexpr int value = N;
};

template <typename T>
constexpr int dimension_v = dimension<T>::value;

template <typename T>
struct scalar_type {
	using type = T;
};

template <typename T, int N>
struct scalar_type<vec<T, N>> {
	using type = T;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes>
struct scalar_type<detail::swizzle<TT, T, N, Indexes...>> {
	using type = T;
};

template <typename T, int N>
struct scalar_type<mat<T, N>> {
	using type = T;
};

template <typename T>
using scalar_type_t = typename scalar_type<T>::type;

template <typename T>
struct is_scalar {
	static constexpr bool value = std::is_floating_point_v<T> || std::is_integral_v<T>;
};

template <typename T>
concept scalar = is_scalar<T>::value;

template <typename T, typename = scalar_type_t<T>, int = dimension_v<T>>
struct is_vec {
	static constexpr bool value = false;
	using type = void;
};

template <scalar T, int N, scalar S, int D>
struct is_vec<vec<T, N>, S, D> {
	static constexpr bool value = std::is_same_v<T, S> && N == D;
	using type = vec<T, N>;
};

template <template <typename, int> typename TT, typename T, int N, int... Indexes, scalar S, int D>
struct is_vec<detail::swizzle<TT, T, N, Indexes...>, S, D> {
	static constexpr bool value = std::is_same_v<T, S> && sizeof...(Indexes) == D;
	using type = vec<T, sizeof...(Indexes)>;
};

template <typename T, typename S = scalar_type_t<T>, int D = dimension_v<T>>
concept vector = is_vec<T, S, D>::value;

template <int, typename, typename...>
struct is_mat_row {
	static constexpr bool value = false;
	using type = void;
};

template <int N, typename T, typename U>
struct is_mat_row<N, T, U> {
	static constexpr bool value = is_vec<U>::value && dimension_v<U> == N && std::is_same_v<scalar_type_t<U>, T>;
	using type = std::conditional_t<value, typename is_vec<U>::type, void>;
};

template <int N, typename T, typename U, typename... Us>
struct is_mat_row<N, T, U, Us...> {
	static constexpr bool value = is_vec<U>::value && dimension_v<U> == N && std::is_same_v<scalar_type_t<U>, T> && is_mat_row<N, T, Us...>::value;
	using type = std::conditional_t<value, typename is_vec<U>::type, void>;
};

template <int N, typename T, typename... Ts>
concept mat_row = is_mat_row<N, T, Ts...>::value;

template <typename T>
struct is_mat {
	static constexpr bool value = false;
};

template <typename T, int N>
struct is_mat<mat<T, N>> {
	static constexpr bool value = true;
};

template <typename T>
concept matrix = is_mat<T>::value;

template <typename, scalar>
struct change_scalar {};

template <scalar S, scalar T>
struct change_scalar<S, T> {
	using type = T;
};

template <template <typename, int> typename TT, scalar T, int N, int... Indexes, scalar S>
struct change_scalar<detail::swizzle<TT, T, N, Indexes...>, S> {
	using type = detail::swizzle<TT, S, N, Indexes...>;
};

template <scalar T, int N, scalar S>
struct change_scalar<vec<T, N>, S> {
	using type = vec<S, N>;
};

template <matrix M, scalar S>
struct change_scalar<M, S> {
	using type = mat<S, dimension_v<M>>;
};

template <typename T, scalar S>
using change_scalar_t = typename change_scalar<T, S>::type;

template <typename T, typename U>
struct deduce {};

template <typename T, typename U>
using deduce_t = typename deduce<T, U>::type;

template <typename T>
struct deduce<T, T> {
	using type = T;
};

template <matrix M, vector V>
struct deduce<M, V> {
	using type = V;
};

template <matrix M, vector V>
struct deduce<V, M> {
	using type = V;
};

template <matrix M, typename T>
struct deduce<M, T> {
	using type = M;
};

template <matrix M, typename T>
struct deduce<T, M> {
	using type = M;
};

template <vector V, typename T>
struct deduce<V, T> {
	using type = V;
};

template <vector V, typename T>
struct deduce<T, V> {
	using type = V;
};

} // namespace gosh2cpp

#endif