#ifndef GOSH2CPP_H_INCLUDED
#include "detail/vecmat.hpp"
#include "detail/builtins.hpp"
struct dummy_header {
#endif

private:

// Base types

using bool_type = bool;
using int_type = int;
using float_type = float;

using uint = unsigned int;

using vec2 = gosh2cpp::vec2;
using vec3 = gosh2cpp::vec3;
using vec4 = gosh2cpp::vec4;
using bvec2 = gosh2cpp::bvec2;
using bvec3 = gosh2cpp::bvec3;
using bvec4 = gosh2cpp::bvec4;
using ivec2 = gosh2cpp::ivec2;
using ivec3 = gosh2cpp::ivec3;
using ivec4 = gosh2cpp::ivec4;

using mat2 = gosh2cpp::mat2;
using mat3 = gosh2cpp::mat3;
using mat4 = gosh2cpp::mat4;


struct ref {
	using bool_type = bool_type&;
	using int_type = int_type&;
	using float_type = float_type&;

	using uint = uint&;

	using vec2 = vec2&;
	using vec3 = vec3&;
	using vec4 = vec4&;
	using bvec2 = bvec2&;
	using bvec3 = bvec3&;
	using bvec4 = bvec4&;
	using ivec2 = ivec2&;
	using ivec3 = ivec3&;
	using ivec4 = ivec4&;

	using mat2 = mat2&;
	using mat3 = mat3&;
	using mat4 = mat4&;
};


#define bool bool_type
#define int int_type
#define float float_type

using sampler2D = gosh2cpp::sampler2D;
using isampler2D = gosh2cpp::isampler2D;
using usampler2D = gosh2cpp::usampler2D;
using sampler2DArray = gosh2cpp::sampler2DArray;
using isampler2DArray = gosh2cpp::isampler2DArray;
using usampler2DArray = gosh2cpp::usampler2DArray;
using sampler3D = gosh2cpp::sampler3D;
using isampler3D = gosh2cpp::isampler3D;
using usampler3D = gosh2cpp::usampler3D;
using samplerCube = gosh2cpp::samplerCube;

// In and Out parameters

#define uniform
#define varying
#define in
#define out ref::
#define inout ref::
#define discard return

// Precision and interpolation

#define flat
#define smooth
#define lowp
#define mediump
#define highp

// Built-ins

#define vertex() \
	vertex( \
	    const typename gosh2cpp::detail::vertex_traits<shader_tag>::in_struct& vertex_in, \
	    typename gosh2cpp::detail::vertex_traits<shader_tag>::inout_struct& vertex_inout, \
	    typename gosh2cpp::detail::vertex_traits<shader_tag>::out_struct& vertex_out) \
	{ \
		gosh2cpp::detail::vertex_bind(*this, vertex_in, vertex_inout, vertex_out); \
	} \
	 \
	void vertex_raw( \
		/* in */ const vec2& VIEWPORT_SIZE, \
		/* in */ const mat4& INV_CAMERA_MATRIX, \
		/* in */ const mat4& CAMERA_MATRIX, \
		/* in */ const bool& OUTPUT_IS_SRGB, \
		/* in */ const int& INSTANCE_ID, \
		/* in */ const vec4& INSTANCE_CUSTOM, \
		/* in */ const mat4& EXTRA_MATRIX, \
		/* in */ const bool& AT_LIGHT_PASS, \
		/* in */ const vec2& TEXTURE_PIXEL_SIZE, \
		/* in */ const vec4& MODULATE, \
		/* in */ const bool& RESTART, \
		/* in */ const float& LIFETIME, \
		/* in */ const float& DELTA, \
		/* in */ const uint& NUMBER, \
		/* in */ const int& INDEX, \
		/* in */ const mat4& EMISSION_TRANSFORM, \
		/* in */ const int& RANDOM_SEED, \
		/* trait */ typename gosh2cpp::detail::vertex_traits<shader_tag>::WORLD_MATRIX WORLD_MATRIX, \
		/* inout */ typename gosh2cpp::detail::vertex_traits<shader_tag>::PROJECTION_MATRIX PROJECTION_MATRIX, \
		/* inout */ mat4& MODELVIEW_MATRIX, \
		/* inout */ mat4& INV_PROJECTION_MATRIX, \
		/* inout */ typename gosh2cpp::detail::vertex_traits<shader_tag>::VERTEX VERTEX, \
		/* inout */ vec3& NORMAL, \
		/* inout */ vec3& TANGENT, \
		/* inout */ vec3& BINORMAL, \
		/* inout */ vec2& UV, \
		/* inout */ vec2& UV2, \
		/* inout */ vec4& COLOR, \
		/* inout */ float& POINT_SIZE, \
		/* inout */ vec3& VELOCITY, \
		/* inout */ bool& ACTIVE, \
		/* inout */ vec4& CUSTOM, \
		/* inout */ mat4& TRANSFORM, \
		/* out */ vec4& POSITION, \
		/* out */ float& ROUGHNESS, \
		/* out */ float& MASS \
	)

#define fragment() \
	fragment( \
	    const typename gosh2cpp::detail::fragment_traits<shader_tag>::in_struct& fragment_in, \
	    typename gosh2cpp::detail::fragment_traits<shader_tag>::inout_struct& fragment_inout, \
	    typename gosh2cpp::detail::fragment_traits<shader_tag>::out_struct& fragment_out) \
	{ \
		gosh2cpp::detail::fragment_bind(*this, fragment_in, fragment_inout, fragment_out); \
	} \
	 \
	void fragment_raw( \
		/* in */ const vec2& VIEWPORT_SIZE, \
		/* in */ const vec4& FRAGCOORD, \
		/* in */ const mat4& WORLD_MATRIX, \
		/* in */ const mat4& INV_CAMERA_MATRIX, \
		/* in */ const mat4& CAMERA_MATRIX, \
		/* in */ const mat4& PROJECTION_MATRIX, \
		/* in */ const mat4& INV_PROJECTION_MATRIX, \
		/* in */ const vec3& VERTEX, \
		/* in */ const vec3& VIEW, \
		/* in */ const bool& FRONT_FACING, \
		/* in */ const vec2& UV, \
		/* in */ const vec2& UV2, \
		/* in */ const bool& OUTPUT_IS_SRGB, \
		/* in */ typename gosh2cpp::detail::fragment_traits<shader_tag>::COLOR COLOR, \
		/* in */ const vec2& SCREEN_UV, \
		/* in */ const vec2& POINT_COORD, \
		/* in */ const vec4& MODULATE, \
		/* in */ const sampler2D& TEXTURE, \
		/* in */ const sampler2D& NORMAL_TEXTURE, \
		/* in */ const vec2& TEXTURE_PIXEL_SIZE, \
		/* in */ const vec2& SCREEN_PIXEL_SIZE, \
		/* in */ const bool& AT_LIGHT_PASS, \
		/* in */ const sampler2D& SCREEN_TEXTURE, \
		/* inout */ vec3& NORMAL, \
		/* inout */ vec3& TANGENT, \
		/* inout */ vec3& BINORMAL, \
		/* out */ vec3& NORMALMAP, \
		/* (in)out */ float& NORMALMAP_DEPTH, \
		/* out */ vec3& ALBEDO, \
		/* out */ float& ALPHA, \
		/* out */ float& ALPHA_SCISSOR, \
		/* out */ float& METALL, \
		/* out */ float& SPECULAR, \
		/* out */ float& ROUGHNESS, \
		/* out */ float& RIM, \
		/* out */ float& RIM_TINT, \
		/* out */ float& CLEARCOAT, \
		/* out */ float& CLEARCOAT_GLOSS, \
		/* out */ float& ANISOTROPY, \
		/* out */ vec2& ANISOTROPY_FLOW, \
		/* out */ float& SSS_STRENGTH, \
		/* out */ vec3& TRANSMISSION, \
		/* out */ vec3& EMISSION, \
		/* out */ float& AO, \
		/* out */ float& AO_LIGHT_AFFECT, \
		/* out */ float& DEPTH \
	)

#define light() \
	light( \
	    const typename gosh2cpp::detail::light_traits<shader_tag>::in_struct& light_in, \
	    typename gosh2cpp::detail::light_traits<shader_tag>::inout_struct& light_inout, \
	    typename gosh2cpp::detail::light_traits<shader_tag>::out_struct& light_out) \
	{ \
		gosh2cpp::detail::light_bind(*this, light_in, light_inout, light_out); \
	} \
	 \
	void light_raw( \
		/* in */ const vec2& VIEWPORT_SIZE, \
		/* in */ const vec4& FRAGCOORD, \
		/* in */ const mat4& WORLD_MATRIX, \
		/* in */ const mat4& INV_CAMERA_MATRIX, \
		/* in */ const mat4& CAMERA_MATRIX, \
		/* in */ const mat4& PROJECTION_MATRIX, \
		/* in */ const mat4& INV_PROJECTION_MATRIX, \
		/* in */ const vec3& NORMAL, \
		/* in */ const vec2& UV, \
		/* in */ const vec2& UV2, \
		/* in */ const vec3& VIEW, \
		/* in */ const vec3& LIGHT, \
		/* in */ const vec3& ATTENUATION, \
		/* in */ const bool& OUTPUT_IS_SRGB, \
		/* in */ const vec3& ALBEDO, \
		/* in(out) */ typename gosh2cpp::detail::light_traits<shader_tag>::LIGHT_COLOR LIGHT_COLOR, \
		/* in */ const float& ROUGHNESS, \
		/* in */ const vec3& TRANSMISSION, \
		/* in */ const vec4& COLOR, \
		/* in */ const vec4& MODULATE, \
		/* in */ const sampler2D& TEXTURE, \
		/* in */ const vec2& TEXTURE_PIXEL_SIZE, \
		/* in */ const vec2& SCREEN_UV, \
		/* in */ const vec2& POINT_COORD, \
		/* in */ const vec2& LIGHT_UV, \
		/* inout */ vec2& LIGHT_VEC, \
		/* inout */ vec2& SHADOW_VEC, \
		/* inout */ float& LIGHT_HEIGHT, \
		/* out */ float& ALPHA, \
		/* out */ vec3& DIFFUSE_LIGHT, \
		/* out */ vec3& SPECULAR_LIGHT, \
		/* out */ vec4& SHADOW_COLOR \
	)

// Functions that can take scalar arguments

#define pow gosh2cpp::pow
#define log gosh2cpp::log
#define log2 gosh2cpp::log2
#define sqrt gosh2cpp::sqrt
#define sin gosh2cpp::sin
#define asin gosh2cpp::asin
#define cos gosh2cpp::cos
#define acos gosh2cpp::acos
#define tan gosh2cpp::tan
#define atan gosh2cpp::atan
#define atan gosh2cpp::atan
#define sinh gosh2cpp::sinh
#define asinh gosh2cpp::asinh
#define cosh gosh2cpp::cosh
#define acosh gosh2cpp::acosh
#define tanh gosh2cpp::tanh
#define atanh gosh2cpp::atanh
#define min gosh2cpp::min
#define max gosh2cpp::max
#define clamp gosh2cpp::clamp
#define mix gosh2cpp::mix
#define sign gosh2cpp::sign
#define floor gosh2cpp::floor
#define ceil gosh2cpp::ceil
#define trunc gosh2cpp::trunc
#define round gosh2cpp::round
#define fract gosh2cpp::fract
#define abs gosh2cpp::abs
#define smoothstep gosh2cpp::smoothstep
#define dFdx gosh2cpp::dFdx
#define dFdy gosh2cpp::dFdy
#define fwidth gosh2cpp::fwidth

// Shader type and render mode

using render_mode = bool;

using spatial = gosh2cpp::detail::spatial;
using canvas_item = gosh2cpp::detail::canvas_item;
using particle = gosh2cpp::detail::particle;
#define shader_type using shader_tag =

public: ///////// Public Access from that point /////////

// cpp keywords that are not part of Godot shading language

#define alignas ___alignas
#define alignof ___alignof
#define asm ___asm
#define atomic_cancel ___atomic_cancel
#define atomic_commit ___atomic_commit
#define atomic_noexcept ___atomic_noexcept
#define auto ___auto
#define catch ___catch
#define char ___char
#define char8_t ___char8_t
#define char16_t ___char16_t
#define char32_t ___char32_t
#define class ___class
#define concept ___concept
#define consteval ___consteval
#define constexpr ___constexpr
#define constinit ___constinit
#define const_cast ___const_cast
#define continue ___continue
#define co_await ___co_await
#define co_return ___co_return
#define co_yield ___co_yield
#define decltype ___decltype
#define default ___default
#define delete ___delete
#define double ___double
#define dynamic_cast ___dynamic_cast
#define enum ___enum
#define explicit ___explicit
#define export ___export
#define extern ___extern
#define friend ___friend
#define goto ___goto
#define inline ___inline
#define long ___long
#define mutable ___mutable
#define namespace ___namespace
#define new ___new
#define noexcept ___noexcept
#define nullptr ___nullptr
#define operator ___operator
#define private ___private
#define protected ___protected
#define public ___public
#define reflexpr ___reflexpr
#define register ___register
#define reinterpret_cast ___reinterpret_cast
#define requires ___requires
#define short ___short
#define signed ___signed
#define sizeof ___sizeof
#define static ___static
#define static_assert ___static_assert
#define static_cast ___static_cast
#define synchronized ___synchronized
#define template ___template
#define thread_local ___thread_local
#define throw ___throw
#define try ___try
#define typedef ___typedef
#define typeid ___typeid
#define union ___union
#define unsigned ___unsigned
#define virtual ___virtual
#define volatile ___volatile
#define wchar_t ___wchar_t

#ifndef GOSH2CPP_H_INCLUDED
};
#endif