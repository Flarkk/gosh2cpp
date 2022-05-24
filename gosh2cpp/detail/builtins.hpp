#ifndef GOSH2CPP_BUILTINS_H_INCLUDED
#define GOSH2CPP_BUILTINS_H_INCLUDED

#include "vecmat.hpp"
#include "sampler.hpp"

namespace gosh2cpp {

struct SpatialVertexIn {
	vec2 VIEWPORT_SIZE;
	mat4 INV_CAMERA_MATRIX;
	mat4 CAMERA_MATRIX;
	bool OUTPUT_IS_SRGB;
	int INSTANCE_ID;
	vec4 INSTANCE_CUSTOM;
};

struct CanvasItemVertexIn {
	mat4 WORLD_MATRIX;
	mat4 EXTRA_MATRIX;
	mat4 PROJECTION_MATRIX;
	vec4 INSTANCE_CUSTOM;
	bool AT_LIGHT_PASS;
	vec2 TEXTURE_PIXEL_SIZE;
	vec4 MODULATE;
};

struct ParticleVertexIn {
	bool RESTART;
	float LIFETIME;
	float DELTA;
	uint NUMBER;
	int INDEX;
	mat4 EMISSION_TRANSFORM;
	uint RANDOM_SEED;
};

struct SpatialVertexInOut {
	mat4 WORLD_MATRIX;
	mat4 PROJECTION_MATRIX;
	mat4 MODELVIEW_MATRIX;
	mat4 INV_PROJECTION_MATRIX;
	vec3 VERTEX;
	vec3 NORMAL;
	vec3 TANGENT;
	vec3 BINORMAL;
	vec2 UV;
	vec2 UV2;
	vec4 COLOR;
	float POINT_SIZE;
};

struct CanvasItemVertexInOut {
	vec2 VERTEX;
	vec2 UV;
	vec4 COLOR;
	float POINT_SIZE;
};

struct ParticleVertexInOut {
	vec4 COLOR;
	vec3 VELOCITY;
	bool ACTIVE;
	vec4 CUSTOM;
	mat4 TRANSFORM;
};

struct SpatialVertexOut {
	vec4 POSITION;
	float ROUGHNESS;
};

struct CanvasItemVertexOut {
};

struct ParticleVertexOut {
	float MASS;
};

struct SpatialFragmentIn {
	vec2 VIEWPORT_SIZE;
	vec4 FRAGCOORD;
	mat4 WORLD_MATRIX;
	mat4 INV_CAMERA_MATRIX;
	mat4 CAMERA_MATRIX;
	mat4 PROJECTION_MATRIX;
	mat4 INV_PROJECTION_MATRIX;
	vec3 VERTEX;
	vec3 VIEW;
	bool FRONT_FACING;
	vec2 UV;
	vec2 UV2;
	bool OUTPUT_IS_SRGB;
	vec4 COLOR;
	vec2 SCREEN_UV;
	vec2 POINT_COORD;
	sampler2D SCREEN_TEXTURE;
	sampler2D DEPTH_TEXTURE;
};

struct CanvasItemFragmentIn {
	vec4 FRAGCOORD;
	vec2 UV;
	vec4 MODULATE;
	sampler2D TEXTURE;
	sampler2D NORMAL_TEXTURE;
	vec2 TEXTURE_PIXEL_SIZE;
	vec2 SCREEN_UV;
	vec2 SCREEN_PIXEL_SIZE;
	vec2 POINT_COORD;
	bool AT_LIGHT_PASS;
	sampler2D SCREEN_TEXTURE;
};

struct ParticleFragmentIn {
};

struct SpatialFragmentInOut {
	vec3 NORMAL;
	vec3 TANGENT;
	vec3 BINORMAL;
};

struct CanvasItemFragmentInOut {
	vec3 NORMAL;
	float NORMALMAP_DEPTH;
	vec4 COLOR;
};

struct ParticleFragmentInOut {
};

struct SpatialFragmentOut {
	vec3 NORMALMAP;
	float NORMALMAP_DEPTH;
	vec3 ALBEDO;
	float ALPHA;
	float ALPHA_SCISSOR;
	float METALL;
	float SPECULAR;
	float ROUGHNESS;
	float RIM;
	float RIM_TINT;
	float CLEARCOAT;
	float CLEARCOAT_GLOSS;
	float ANISOTROPY;
	vec2 ANISOTROPY_FLOW;
	float SSS_STRENGTH;
	vec3 TRANSMISSION;
	vec3 EMISSION;
	float AO;
	float AO_LIGHT_AFFECT;
	float DEPTH;
};

struct CanvasItemFragmentOut {
	vec3 NORMALMAP;
};

struct ParticleFragmentOut {
};

struct SpatialLightIn {
	vec2 VIEWPORT_SIZE;
	vec4 FRAGCOORD;
	mat4 WORLD_MATRIX;
	mat4 INV_CAMERA_MATRIX;
	mat4 CAMERA_MATRIX;
	mat4 PROJECTION_MATRIX;
	mat4 INV_PROJECTION_MATRIX;
	vec3 NORMAL;
	vec2 UV;
	vec2 UV2;
	vec3 VIEW;
	vec3 LIGHT;
	vec3 ATTENUATION;
	bool OUTPUT_IS_SRGB;
	vec3 ALBEDO;
	vec3 LIGHT_COLOR;
	float ROUGHNESS;
	vec3 TRANSMISSION;
};

struct CanvasItemLightIn {
	vec4 FRAGCOORD;
	vec3 NORMAL;
	vec2 UV;
	vec4 COLOR;
	vec4 MODULATE;
	vec2 TEXTURE_PIXEL_SIZE;
	vec2 SCREEN_UV;
	vec2 POINT_COORD;
	vec2 LIGHT_UV;
};

struct ParticleLightIn {
};

struct SpatialLightInOut {
};

struct CanvasItemLightInOut {
	vec2 LIGHT_VEC;
	vec2 SHADOW_VEC;
	float LIGHT_HEIGHT;
	vec4 LIGHT_COLOR;
	vec4 LIGHT;
};

struct ParticleLightInOut {
};

struct SpatialLightOut {
	float ALPHA;
	vec3 DIFFUSE_LIGHT;
	vec3 SPECULAR_LIGHT;
};

struct CanvasItemLightOut {
	vec4 SHADOW_COLOR;
};

struct ParticleLightOut {
};

} // namespace gosh2cpp

#endif