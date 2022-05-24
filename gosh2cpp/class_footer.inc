#undef bool
#undef int
#undef float

#undef shader_type

// In and Out parameters

#undef uniform
#undef varying
#undef in
#undef out
#undef inout
#undef discard

// Precision and interpolation

#undef flat
#undef smooth
#undef lowp
#undef mediump
#undef highp

// Built-ins

#undef vertex
#undef fragment
#undef light

// Functions

#undef pow
#undef log
#undef log2
#undef sqrt
#undef sin
#undef asin
#undef cos
#undef acos
#undef tan
#undef atan
#undef atan
#undef sinh
#undef asinh
#undef cosh
#undef acosh
#undef tanh
#undef atanh
#undef min
#undef max
#undef clamp
#undef mix
#undef sign
#undef floor
#undef ceil
#undef trunc
#undef round
#undef fract
#undef abs
#undef smoothstep
#undef dFdx
#undef dFdy
#undef fwidth

// cpp keywords 

#undef alignas
#undef alignof
#undef asm
#undef atomic_cancel
#undef atomic_commit
#undef atomic_noexcept
#undef auto
#undef catch
#undef char
#undef char8_t
#undef char16_t
#undef char32_t
#undef class
#undef concept
#undef consteval
#undef constexpr
#undef constinit
#undef const_cast
#undef continue
#undef co_await
#undef co_return
#undef co_yield
#undef decltype
#undef default
#undef delete
#undef double
#undef dynamic_cast
#undef enum
#undef explicit
#undef export
#undef extern
#undef friend
#undef goto
#undef inline
#undef long
#undef mutable
#undef namespace
#undef new
#undef noexcept
#undef nullptr
#undef operator
#undef private
#undef protected
#undef public
#undef reflexpr
#undef register
#undef reinterpret_cast
#undef requires
#undef short
#undef signed
#undef sizeof
#undef static
#undef static_assert
#undef static_cast
#undef synchronized
#undef template
#undef thread_local
#undef throw
#undef try
#undef typedef
#undef typeid
#undef union
#undef unsigned
#undef virtual
#undef volatile
#undef wchar_t


#ifndef GOSH2CPP_H_INCLUDED
#include "detail/builtins.hpp"
#include "detail/types.hpp"
struct dummy_header {
#endif
	// Builtin variables

	float TIME;

#ifndef GOSH2CPP_H_INCLUDED
};
#endif