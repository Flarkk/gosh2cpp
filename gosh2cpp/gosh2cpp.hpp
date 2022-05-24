#ifndef GOSH2CPP_H_INCLUDED
#define GOSH2CPP_H_INCLUDED

#include "detail/functions.hpp"
#include "detail/builtins.hpp"
#include "detail/sampler.hpp"

namespace gosh2cpp {
namespace detail {
struct spatial {};
struct canvas_item {};
struct particle {};

/***********************************************************************
*******************         vertex() bindings        *******************
***********************************************************************/

template <typename>
struct vertex_traits {};

template <>
struct vertex_traits<spatial> {
	using in_struct = SpatialVertexIn;
	using inout_struct = SpatialVertexInOut;
	using out_struct = SpatialVertexOut;
	using WORLD_MATRIX = mat4&;      // inout
	using PROJECTION_MATRIX = mat4&; // inout
	using VERTEX = vec3&;            // inout
};

inline void vertex_bind(
    auto& shader,
    const SpatialVertexIn& vertex_in,
    SpatialVertexInOut& vertex_inout,
    SpatialVertexOut& vertex_out)
{
	/* inout */ vec3 VELOCITY;
	/* inout */ bool ACTIVE;
	/* inout */ vec4 CUSTOM;
	/* inout */ mat4 TRANSFORM;
	/* out */ float MASS;

	shader.vertex_raw(
	    vertex_in.VIEWPORT_SIZE,
	    vertex_in.INV_CAMERA_MATRIX,
	    vertex_in.CAMERA_MATRIX,
	    vertex_in.OUTPUT_IS_SRGB,
	    vertex_in.INSTANCE_ID,
	    vertex_in.INSTANCE_CUSTOM,
	    /* in */ mat4(),  // EXTRA_MATRIX
	    /* in */ bool(),  // AT_LIGHT_PASS
	    /* in */ vec2(),  // TEXTURE_PIXEL_SIZE
	    /* in */ vec4(),  // MODULATE
	    /* in */ bool(),  // RESTART
	    /* in */ float(), // LIFETIME
	    /* in */ float(), // DELTA
	    /* in */ uint(),  // NUMBER
	    /* in */ int(),   // INDEX
	    /* in */ mat4(),  // EMISSION_TRANSFORM
	    /* in */ int(),   // RANDOM_SEED
	    vertex_inout.WORLD_MATRIX,
	    vertex_inout.PROJECTION_MATRIX,
	    vertex_inout.MODELVIEW_MATRIX,
	    vertex_inout.INV_PROJECTION_MATRIX,
	    vertex_inout.VERTEX,
	    vertex_inout.NORMAL,
	    vertex_inout.TANGENT,
	    vertex_inout.BINORMAL,
	    vertex_inout.UV,
	    vertex_inout.UV2,
	    vertex_inout.COLOR,
	    vertex_inout.POINT_SIZE,
	    /* inout */ VELOCITY,
	    /* inout */ ACTIVE,
	    /* inout */ CUSTOM,
	    /* inout */ TRANSFORM,
	    vertex_out.POSITION,
	    vertex_out.ROUGHNESS,
	    /* out */ MASS);
}

template <>
struct vertex_traits<canvas_item> {
	using in_struct = CanvasItemVertexIn;
	using inout_struct = CanvasItemVertexInOut;
	using out_struct = CanvasItemVertexOut;
	using WORLD_MATRIX = const mat4&;      // in
	using PROJECTION_MATRIX = const mat4&; // in
	using VERTEX = vec2&;                  // inout
};

inline void vertex_bind(
    auto& shader,
    const CanvasItemVertexIn& canvas_item_in,
    CanvasItemVertexInOut& canvas_item_inout,
    CanvasItemVertexOut& /* canvas_item_inout */)
{
	/* inout */ mat4 WORLD_MATRIX;
	/* inout */ mat4 PROJECTION_MATRIX;
	/* inout */ mat4 MODELVIEW_MATRIX;
	/* inout */ mat4 INV_PROJECTION_MATRIX;
	/* inout */ vec3 NORMAL;
	/* inout */ vec3 TANGENT;
	/* inout */ vec3 BINORMAL;
	/* inout */ vec2 UV2;
	/* inout */ vec3 VELOCITY;
	/* inout */ bool ACTIVE;
	/* inout */ vec4 CUSTOM;
	/* inout */ mat4 TRANSFORM;
	/* out */ vec4 POSITION;
	/* out */ float ROUGHNESS;
	/* out */ float MASS;

	shader.vertex_raw(
	    /* in */ vec2(), // VIEWPORT_SIZE
	    /* in */ mat4(), // INV_CAMERA_MATRIX
	    /* in */ mat4(), // CAMERA_MATRIX
	    /* in */ bool(), // OUTPUT_IS_SRGB
	    /* in */ int(),  // INSTANCE_ID
	    canvas_item_in.INSTANCE_CUSTOM,
	    canvas_item_in.EXTRA_MATRIX,
	    canvas_item_in.AT_LIGHT_PASS,
	    canvas_item_in.TEXTURE_PIXEL_SIZE,
	    canvas_item_in.MODULATE,
	    /* in */ bool(),  // RESTART
	    /* in */ float(), // LIFETIME
	    /* in */ float(), // DELTA
	    /* in */ uint(),  // NUMBER
	    /* in */ int(),   // INDEX
	    /* in */ mat4(),  // EMISSION_TRANSFORM
	    /* in */ int(),   // RANDOM_SEED
	    /* inout */ WORLD_MATRIX,
	    /* inout */ PROJECTION_MATRIX,
	    /* inout */ MODELVIEW_MATRIX,
	    /* inout */ INV_PROJECTION_MATRIX,
	    canvas_item_inout.VERTEX,
	    /* inout */ NORMAL,
	    /* inout */ TANGENT,
	    /* inout */ BINORMAL,
	    canvas_item_inout.UV,
	    /* inout */ UV2,
	    canvas_item_inout.COLOR,
	    canvas_item_inout.POINT_SIZE,
	    /* inout */ VELOCITY,
	    /* inout */ ACTIVE,
	    /* inout */ CUSTOM,
	    /* inout */ TRANSFORM,
	    /* out */ POSITION,
	    /* out */ ROUGHNESS,
	    /* out */ MASS);
}

template <>
struct vertex_traits<particle> {
	using in_struct = ParticleVertexIn;
	using inout_struct = ParticleVertexInOut;
	using out_struct = ParticleVertexOut;
	using WORLD_MATRIX = mat4&;      // inout
	using PROJECTION_MATRIX = mat4&; // inout
	using VERTEX = vec3&;            // inout
};

inline void vertex_bind(
    auto& shader,
    const ParticleVertexIn& particle_in,
    ParticleVertexInOut& particle_inout,
    ParticleVertexOut& particle_out)
{
	/* inout */ mat4 WORLD_MATRIX;
	/* inout */ mat4 PROJECTION_MATRIX;
	/* inout */ mat4 MODELVIEW_MATRIX;
	/* inout */ mat4 INV_PROJECTION_MATRIX;
	/* inout */ vec3 VERTEX;
	/* inout */ vec3 NORMAL;
	/* inout */ vec3 TANGENT;
	/* inout */ vec3 BINORMAL;
	/* inout */ vec2 UV;
	/* inout */ vec2 UV2;
	/* inout */ float POINT_SIZE;
	/* out */ vec4 POSITION;
	/* out */ float ROUGHNESS;

	shader.vertex_raw(
	    /* in */ vec2(), // VIEWPORT_SIZE
	    /* in */ mat4(), // INV_CAMERA_MATRIX
	    /* in */ mat4(), // CAMERA_MATRIX
	    /* in */ bool(), // OUTPUT_IS_SRGB
	    /* in */ int(),  // INSTANCE_ID
	    /* in */ vec4(), // INSTANCE_CUSTOM
	    /* in */ mat4(), // EXTRA_MATRIX
	    /* in */ bool(), // AT_LIGHT_PASS
	    /* in */ vec2(), // TEXTURE_PIXEL_SIZE
	    /* in */ vec4(), // MODULATE
	    particle_in.RESTART,
	    particle_in.LIFETIME,
	    particle_in.DELTA,
	    particle_in.NUMBER,
	    particle_in.INDEX,
	    particle_in.EMISSION_TRANSFORM,
	    particle_in.RANDOM_SEED,
	    /* inout */ WORLD_MATRIX,
	    /* inout */ PROJECTION_MATRIX,
	    /* inout */ MODELVIEW_MATRIX,
	    /* inout */ INV_PROJECTION_MATRIX,
	    /* inout */ VERTEX,
	    /* inout */ NORMAL,
	    /* inout */ TANGENT,
	    /* inout */ BINORMAL,
	    /* inout */ UV,
	    /* inout */ UV2,
	    particle_inout.COLOR,
	    /* inout */ POINT_SIZE,
	    particle_inout.VELOCITY,
	    particle_inout.ACTIVE,
	    particle_inout.CUSTOM,
	    particle_inout.TRANSFORM,
	    /* out */ POSITION,
	    /* out */ ROUGHNESS,
	    particle_out.MASS);
}

/***********************************************************************
*******************        fragment() bindings       *******************
***********************************************************************/

template <typename>
struct fragment_traits {};

template <>
struct fragment_traits<spatial> {
	using in_struct = SpatialFragmentIn;
	using inout_struct = SpatialFragmentInOut;
	using out_struct = SpatialFragmentOut;
	using COLOR = const vec4&; // in
};

inline void fragment_bind(
    auto& shader,
    const SpatialFragmentIn& fragment_in,
    SpatialFragmentInOut& fragment_inout,
    SpatialFragmentOut& fragment_out)
{
	shader.fragment_raw(
	    /* in */ fragment_in.VIEWPORT_SIZE,         // vec2
	    /* in */ fragment_in.FRAGCOORD,             // vec4
	    /* in */ fragment_in.WORLD_MATRIX,          // mat4
	    /* in */ fragment_in.INV_CAMERA_MATRIX,     // mat4
	    /* in */ fragment_in.CAMERA_MATRIX,         // mat4
	    /* in */ fragment_in.PROJECTION_MATRIX,     // mat4
	    /* in */ fragment_in.INV_PROJECTION_MATRIX, // mat4
	    /* in */ fragment_in.VERTEX,                // vec3
	    /* in */ fragment_in.VIEW,                  // vec3
	    /* in */ fragment_in.FRONT_FACING,          // bool
	    /* in */ fragment_in.UV,                    // vec2
	    /* in */ fragment_in.UV2,                   // vec2
	    /* in */ fragment_in.OUTPUT_IS_SRGB,        // bool
	    /* in */ fragment_in.COLOR,                 // typenam
	    /* in */ fragment_in.SCREEN_UV,             // vec2
	    /* in */ fragment_in.POINT_COORD,           // vec2
	    /* in */ vec4(),                            // MODULATE
	    /* in */ sampler2D(),                       // TEXTURE
	    /* in */ sampler2D(),                       // NORMAL_TEXTURE
	    /* in */ vec2(),                            // TEXTURE_PIXEL_SIZE
	    /* in */ vec2(),                            // SCREEN_PIXEL_SIZE
	    /* in */ bool(),                            // AT_LIGHT_PASS
	    /* in */ sampler2D(),                       // SCREEN_TEXTURE
	    /* inout */ fragment_inout.NORMAL,          // vec3
	    /* inout */ fragment_inout.TANGENT,         // vec3
	    /* inout */ fragment_inout.BINORMAL,        // vec3
	    /* out */ fragment_out.NORMALMAP,           // vec3
	    /* (in)out */ fragment_out.NORMALMAP_DEPTH, // float
	    /* out */ fragment_out.ALBEDO,              // vec3
	    /* out */ fragment_out.ALPHA,               // float
	    /* out */ fragment_out.ALPHA_SCISSOR,       // float
	    /* out */ fragment_out.METALL,              // float
	    /* out */ fragment_out.SPECULAR,            // float
	    /* out */ fragment_out.ROUGHNESS,           // float
	    /* out */ fragment_out.RIM,                 // float
	    /* out */ fragment_out.RIM_TINT,            // float
	    /* out */ fragment_out.CLEARCOAT,           // float
	    /* out */ fragment_out.CLEARCOAT_GLOSS,     // float
	    /* out */ fragment_out.ANISOTROPY,          // float
	    /* out */ fragment_out.ANISOTROPY_FLOW,     // vec2
	    /* out */ fragment_out.SSS_STRENGTH,        // float
	    /* out */ fragment_out.TRANSMISSION,        // vec3
	    /* out */ fragment_out.EMISSION,            // vec3
	    /* out */ fragment_out.AO,                  // float
	    /* out */ fragment_out.AO_LIGHT_AFFECT,     // float
	    /* out */ fragment_out.DEPTH                // float
	);
}

template <>
struct fragment_traits<canvas_item> {
	using in_struct = CanvasItemFragmentIn;
	using inout_struct = CanvasItemFragmentInOut;
	using out_struct = CanvasItemFragmentOut;
	using COLOR = vec4&; // inout
};

inline void fragment_bind(
    auto& shader,
    const CanvasItemFragmentIn& fragment_in,
    CanvasItemFragmentInOut& fragment_inout,
    CanvasItemFragmentOut& fragment_out)
{
	/* inout */ vec3 TANGENT;
	/* inout */ vec3 BINORMAL;
	/* out */ vec3 ALBEDO;
	/* out */ float ALPHA;
	/* out */ float ALPHA_SCISSOR;
	/* out */ float METALL;
	/* out */ float SPECULAR;
	/* out */ float ROUGHNESS;
	/* out */ float RIM;
	/* out */ float RIM_TINT;
	/* out */ float CLEARCOAT;
	/* out */ float CLEARCOAT_GLOSS;
	/* out */ float ANISOTROPY;
	/* out */ vec2 ANISOTROPY_FLOW;
	/* out */ float SSS_STRENGTH;
	/* out */ vec3 TRANSMISSION;
	/* out */ vec3 EMISSION;
	/* out */ float AO;
	/* out */ float AO_LIGHT_AFFECT;
	/* out */ float DEPTH;

	shader.fragment_raw(
	    /* in */ vec2(),                         // VIEWPORT_SIZE
	    /* in */ fragment_in.FRAGCOORD,          // vec4
	    /* in */ mat4(),                         // WORLD_MATRIX
	    /* in */ mat4(),                         // INV_CAMERA_MATRIX
	    /* in */ mat4(),                         // CAMERA_MATRIX
	    /* in */ mat4(),                         // PROJECTION_MATRIX
	    /* in */ mat4(),                         // INV_PROJECTION_MATRIX
	    /* in */ vec3(),                         // VERTEX
	    /* in */ vec3(),                         // VIEW
	    /* in */ bool(),                         // FRONT_FACING
	    /* in */ fragment_in.UV,                 // vec2
	    /* in */ vec2(),                         // UV2
	    /* in */ bool(),                         // OUTPUT_IS_SRGB
	    /* inout */ fragment_inout.COLOR,        // vec4
	    /* in */ fragment_in.SCREEN_UV,          // vec2
	    /* in */ fragment_in.POINT_COORD,        // vec2
	    /* in */ fragment_in.MODULATE,           // vec4
	    /* in */ fragment_in.TEXTURE,            // sampler2D
	    /* in */ fragment_in.NORMAL_TEXTURE,     // sampler2D
	    /* in */ fragment_in.TEXTURE_PIXEL_SIZE, // vec2
	    /* in */ fragment_in.SCREEN_PIXEL_SIZE,  // vec2
	    /* in */ fragment_in.AT_LIGHT_PASS,      // bool
	    /* in */ fragment_in.SCREEN_TEXTURE,     // sampler2D
	    /* inout */ fragment_inout.NORMAL,       // vec3
	    /* inout */ TANGENT,
	    /* inout */ BINORMAL,
	    /* out */ fragment_out.NORMALMAP,           // vec3
	    /* inout */ fragment_inout.NORMALMAP_DEPTH, // float
	    /* out */ ALBEDO,
	    /* out */ ALPHA,
	    /* out */ ALPHA_SCISSOR,
	    /* out */ METALL,
	    /* out */ SPECULAR,
	    /* out */ ROUGHNESS,
	    /* out */ RIM,
	    /* out */ RIM_TINT,
	    /* out */ CLEARCOAT,
	    /* out */ CLEARCOAT_GLOSS,
	    /* out */ ANISOTROPY,
	    /* out */ ANISOTROPY_FLOW,
	    /* out */ SSS_STRENGTH,
	    /* out */ TRANSMISSION,
	    /* out */ EMISSION,
	    /* out */ AO,
	    /* out */ AO_LIGHT_AFFECT,
	    /* out */ DEPTH);
}

template <>
struct fragment_traits<particle> {
	using in_struct = ParticleFragmentIn;
	using inout_struct = ParticleFragmentInOut;
	using out_struct = ParticleFragmentOut;
	using COLOR = vec4&; // unused
};

inline void fragment_bind(
    auto& shader,
    const ParticleFragmentIn& fragment_in,
    ParticleFragmentInOut& fragment_inout,
    ParticleFragmentOut& fragment_out)
{
	// No fragment shader for particles
}

/***********************************************************************
*******************          light() bindings        *******************
***********************************************************************/

template <typename>
struct light_traits {};

template <>
struct light_traits<spatial> {
	using in_struct = SpatialLightIn;
	using inout_struct = SpatialLightInOut;
	using out_struct = SpatialLightOut;
	using LIGHT = const vec3&;       // in
	using LIGHT_COLOR = const vec3&; // in
};

inline void light_bind(
    auto& shader,
    const SpatialLightIn& light_in,
    SpatialLightInOut& light_inout,
    SpatialLightOut& light_out)
{
	/* inout */ vec2 LIGHT_VEC;
	/* inout */ vec2 SHADOW_VEC;
	/* inout */ float LIGHT_HEIGHT;
	/* out */ vec4 SHADOW_COLOR;

	shader.light_raw(
	    /* in */ light_in.VIEWPORT_SIZE,         // vec2
	    /* in */ light_in.FRAGCOORD,             // vec4
	    /* in */ light_in.WORLD_MATRIX,          // mat4
	    /* in */ light_in.INV_CAMERA_MATRIX,     // mat4
	    /* in */ light_in.CAMERA_MATRIX,         // mat4
	    /* in */ light_in.PROJECTION_MATRIX,     // mat4
	    /* in */ light_in.INV_PROJECTION_MATRIX, // mat4
	    /* in */ light_in.NORMAL,                // vec3
	    /* in */ light_in.UV,                    // vec2
	    /* in */ light_in.UV2,                   // vec2
	    /* in */ light_in.VIEW,                  // vec3
	    /* in */ light_in.LIGHT,                 // vec3
	    /* in */ light_in.ATTENUATION,           // vec3
	    /* in */ light_in.OUTPUT_IS_SRGB,        // bool
	    /* in */ light_in.ALBEDO,                // vec3
	    /* in */ light_in.LIGHT_COLOR,           // vec3
	    /* in */ light_in.ROUGHNESS,             // float
	    /* in */ light_in.TRANSMISSION,          // vec3
	    /* in */ vec4(),                         // COLOR
	    /* in */ vec4(),                         // MODULATE
	    /* in */ sampler2D(),                    // TEXTURE
	    /* in */ vec2(),                         // TEXTURE_PIXEL_SIZE
	    /* in */ vec2(),                         // SCREEN_UV
	    /* in */ vec2(),                         // POINT_COORD
	    /* in */ vec2(),                         // LIGHT_UV
	    /* inout */ LIGHT_VEC,
	    /* inout */ SHADOW_VEC,
	    /* inout */ LIGHT_HEIGHT,
	    /* out */ light_out.ALPHA,          // float
	    /* out */ light_out.DIFFUSE_LIGHT,  // vec3
	    /* out */ light_out.SPECULAR_LIGHT, // vec3
	    /* out */ SHADOW_COLOR);
}

template <>
struct light_traits<canvas_item> {
	using in_struct = CanvasItemLightIn;
	using inout_struct = CanvasItemLightInOut;
	using out_struct = CanvasItemLightOut;
	using LIGHT = vec4&;       // inout
	using LIGHT_COLOR = vec4&; // inout
};

inline void light_bind(
    auto& shader,
    const CanvasItemLightIn& light_in,
    CanvasItemLightInOut& light_inout,
    CanvasItemLightOut& light_out)
{
	/* out */ float ALPHA;
	/* out */ vec3 DIFFUSE_LIGHT;
	/* out */ vec3 SPECULAR_LIGHT;

	shader.light_raw(
	    /* in */ vec2(),                      // VIEWPORT_SIZE
	    /* in */ light_in.FRAGCOORD,          // vec4
	    /* in */ mat4(),                      // WORLD_MATRIX
	    /* in */ mat4(),                      // INV_CAMERA_MATRIX
	    /* in */ mat4(),                      // CAMERA_MATRIX
	    /* in */ mat4(),                      // PROJECTION_MATRIX
	    /* in */ mat4(),                      // INV_PROJECTION_MATRIX
	    /* in */ light_in.NORMAL,             // vec3
	    /* in */ light_in.UV,                 // vec2
	    /* in */ vec2(),                      // UV2
	    /* in */ vec3(),                      // VIEW
	    /* inout */ light_inout.LIGHT,        // vec3
	    /* in */ vec3(),                      // ATTENUATION
	    /* in */ bool(),                      // OUTPUT_IS_SRGB
	    /* in */ vec3(),                      // ALBEDO
	    /* inout */ light_inout.LIGHT_COLOR,  // vec4
	    /* in */ float(),                     // ROUGHNESS
	    /* in */ vec3(),                      // TRANSMISSION
	    /* in */ light_in.COLOR,              // vec4
	    /* in */ light_in.MODULATE,           // vec4
	    /* in */ sampler2D(),                 // TEXTURE
	    /* in */ light_in.TEXTURE_PIXEL_SIZE, // vec2
	    /* in */ light_in.SCREEN_UV,          // vec2
	    /* in */ light_in.POINT_COORD,        // vec2
	    /* in */ light_in.LIGHT_UV,           // vec2
	    /* inout */ light_inout.LIGHT_VEC,    // vec2
	    /* inout */ light_inout.SHADOW_VEC,   // vec2
	    /* inout */ light_inout.LIGHT_HEIGHT, // float
	    /* out */ ALPHA,
	    /* out */ DIFFUSE_LIGHT,
	    /* out */ SPECULAR_LIGHT,
	    /* out */ light_out.SHADOW_COLOR // vec4
	);
}

template <>
struct light_traits<particle> {
	using in_struct = ParticleLightIn;
	using inout_struct = ParticleLightInOut;
	using out_struct = ParticleLightOut;
	using LIGHT = vec4&; // unused
};

inline void light_bind(
    auto& shader,
    const ParticleLightIn& light_in,
    ParticleLightInOut& light_inout,
    ParticleLightOut& light_out)
{
	// light() does not exist for particle shaders
}

} // namespace detail
} // namespace gosh2cpp

#endif