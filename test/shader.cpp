#include "doctest/doctest.h"

#include "gosh2cpp/gosh2cpp.hpp"

struct Test {
#include "gosh2cpp/class_header.inc"

	shader_type spatial;

	// Testing variable types
	// https://docs.godotengine.org/en/3.5/tutorials/shaders/shader_reference/shading_language.html#data-types

	bool test_var_bool;
	int test_var_int;
	float test_var_float;
	uint test_var_uint;

	vec2 test_var_vec2;
	vec3 test_var_vec3;
	vec4 test_var_vec4;
	bvec2 test_var_bvec2;
	bvec3 test_var_bvec3;
	bvec4 test_var_bvec4;
	ivec2 test_var_ivec2;
	ivec3 test_var_ivec3;
	ivec4 test_var_ivec4;
	mat2 test_var_mat2;
	mat3 test_var_mat3;
	mat4 test_var_mat4;

	sampler2D test_var_sampler2D;
	isampler2D test_var_isampler2D;
	usampler2D test_var_usampler2D;
	sampler2DArray test_var_sampler2DArray;
	isampler2DArray test_var_isampler2DArray;
	usampler2DArray test_var_usampler2DArray;
	sampler3D test_var_sampler3D;
	isampler3D test_var_isampler3D;
	usampler3D test_var_usampler3D;
	samplerCube test_var_samplerCube;

	// Testing precision specifiers (have no effect)
	// https://docs.godotengine.org/en/3.5/tutorials/shaders/shader_reference/shading_language.html#precision

	lowp vec4 test_var_lowp;
	mediump vec4 test_var_mediump;
	highp vec4 test_var_highp;

	// Testing array declaration and inintialization
	// https://docs.godotengine.org/en/3.5/tutorials/shaders/shader_reference/shading_language.html#local-arrays

	vec2 vec2_arr[3] = {vec2(1.0, 1.0), vec2(0.5, 0.5), vec2(0.0, 0.0)}; // third constructor

	float a[3] = {1.0, 0.5, 0.0},
	      b[2] = {1.0, 0.5},
	      c[1] = {0.7},
	      d = 0.0,
	      e[5];

	// Testing function parameters

	void test_function_parameters(in float in_float, out float out_float, inout float inout_float)
	{
		in_float = 10.0;
		out_float = 10.0;
		inout_float = 10.0;
	}

	void test_casting()
	{
		// https://docs.godotengine.org/en/3.5/tutorials/shaders/shader_reference/shading_language.html#casting
		float f1 = 2.0;
		float f2 = float(2);
		int i = 2;
		uint ui = uint(2);
	}

	void vertex()
	{
		vec2 viewport_size = VIEWPORT_SIZE;
		mat4 inv_camera_matrix = INV_CAMERA_MATRIX;
		mat4 camera_matrix = CAMERA_MATRIX;
		bool output_is_rgb = OUTPUT_IS_SRGB;
		int instance_id = INSTANCE_ID;
		vec4 instance_custom = INSTANCE_CUSTOM;

		/* inout */ WORLD_MATRIX = mat4(1.0);
		/* inout */ PROJECTION_MATRIX = mat4(2.0);
		/* inout */ MODELVIEW_MATRIX = mat4(3.0);
		/* inout */ INV_PROJECTION_MATRIX = mat4(4.0);
		/* inout */ VERTEX = vec3(5.0);
		/* inout */ NORMAL = vec3(6.0);
		/* inout */ TANGENT = vec3(7.0);
		/* inout */ BINORMAL = vec3(8.0);
		/* inout */ UV = vec2(9.0);
		/* inout */ UV2 = vec2(10.0);
		/* inout */ COLOR = vec4(11.0);
		/* inout */ POINT_SIZE = float(12.0);
		/* out */ POSITION = vec4(13.0);
		/* out */ ROUGHNESS = float(14.0);
	}

	void fragment()
	{
		vec2 viewport_size = VIEWPORT_SIZE;
		vec4 fragcoord = FRAGCOORD;
		mat4 world_matrix = WORLD_MATRIX;
		mat4 inv_camera_matrix = INV_CAMERA_MATRIX;
		mat4 camera_matrix = CAMERA_MATRIX;
		mat4 projection_matrix = PROJECTION_MATRIX;
		mat4 inv_projection_matrix = INV_PROJECTION_MATRIX;
		vec3 vertex = VERTEX;
		vec3 view = VIEW;
		bool front_facing = FRONT_FACING;
		vec2 uv = UV;
		vec2 uv2 = UV2;
		bool output_is_rgb = OUTPUT_IS_SRGB;
		vec4 color = COLOR;
		vec2 screen_uv = SCREEN_UV;
		vec2 point_coord = POINT_COORD;

		/* inout */ NORMAL = vec3(1.0);
		/* inout */ TANGENT = vec3(2.0);
		/* inout */ BINORMAL = vec3(3.0);
		/* out */ NORMALMAP = vec3(4.0);
		/* out */ NORMALMAP_DEPTH = float(5.0);
		/* out */ ALBEDO = vec3(6.0);
		/* out */ ALPHA = float(7.0);
		/* out */ ALPHA_SCISSOR = float(8.0);
		/* out */ METALL = float(9.0);
		/* out */ SPECULAR = float(10.0);
		/* out */ ROUGHNESS = float(11.0);
		/* out */ RIM = float(12.0);
		/* out */ RIM_TINT = float(13.0);
		/* out */ CLEARCOAT = float(14.0);
		/* out */ CLEARCOAT_GLOSS = float(15.0);
		/* out */ ANISOTROPY = float(16.0);
		/* out */ ANISOTROPY_FLOW = vec2(17.0);
		/* out */ SSS_STRENGTH = float(18.0);
		/* out */ TRANSMISSION = vec3(19.0);
		/* out */ EMISSION = vec3(20.0);
		/* out */ AO = float(21.0);
		/* out */ AO_LIGHT_AFFECT = float(22.0);
		/* out */ DEPTH = float(23.0);
	}

	void light()
	{
		vec2 viewport_size = VIEWPORT_SIZE;
		vec4 fragcoord = FRAGCOORD;
		mat4 world_matrix = WORLD_MATRIX;
		mat4 inv_camera_matrix = INV_CAMERA_MATRIX;
		mat4 camera_matrix = CAMERA_MATRIX;
		mat4 projection_matrix = PROJECTION_MATRIX;
		mat4 inv_projection_matrix = INV_PROJECTION_MATRIX;
		vec3 normal = NORMAL;
		vec2 uv = UV;
		vec2 uv2 = UV2;
		vec3 view = VIEW;
		vec3 light = LIGHT;
		vec3 attenuation = ATTENUATION;
		bool output_is_rgb = OUTPUT_IS_SRGB;
		vec3 albedo = ALBEDO;
		vec3 light_color = LIGHT_COLOR;
		float roughness = ROUGHNESS;
		vec3 transmission = TRANSMISSION;

		/* out */ ALPHA = float(1.0);
		/* out */ DIFFUSE_LIGHT = vec3(2.0);
		/* out */ SPECULAR_LIGHT = vec3(3.0);
	}

#include "gosh2cpp/class_footer.inc"

	// Checking correct undefs
  private:
	class Undefs {
		bool test1;
		int test2;
		float test3;

		bool shader_type;

		bool uniform;
		bool varying;
		bool in;
		bool out;
		bool inout;
		bool discard;

		bool flat;
		bool smooth;
		bool lowp;
		bool mediump;
		bool highp;

		void vertex() {}
		void fragment() {}
		void light() {}

		void test_func()
		{
			vertex();
			fragment();
			light();
		}

		// TODO : add undef check for built-in functions
	};
};

TEST_CASE("Shader usage")
{
	Test shader;

	SUBCASE("Testing in, out, inout function arguments")
	{
		float in_float = 1.0;
		float out_float = 1.0;
		float inout_float = 1.0;

		shader.test_function_parameters(in_float, out_float, inout_float);

		CHECK(in_float == 1.0);
		CHECK(out_float == 10.0);
		CHECK(inout_float == 10.0);
	}

	SUBCASE("Testing vertex()")
	{
		using gosh2cpp::mat4;
		using gosh2cpp::vec2;
		using gosh2cpp::vec3;
		using gosh2cpp::vec4;

		gosh2cpp::SpatialVertexInOut vertex_inout;
		gosh2cpp::SpatialVertexOut vertex_out;
		shader.vertex(gosh2cpp::SpatialVertexIn(), vertex_inout, vertex_out);

		CHECK(vertex_inout.WORLD_MATRIX == mat4(1.0));
		CHECK(vertex_inout.PROJECTION_MATRIX == mat4(2.0));
		CHECK(vertex_inout.MODELVIEW_MATRIX == mat4(3.0));
		CHECK(vertex_inout.INV_PROJECTION_MATRIX == mat4(4.0));
		CHECK(vertex_inout.VERTEX == vec3(5.0));
		CHECK(vertex_inout.NORMAL == vec3(6.0));
		CHECK(vertex_inout.TANGENT == vec3(7.0));
		CHECK(vertex_inout.BINORMAL == vec3(8.0));
		CHECK(vertex_inout.UV == vec2(9.0));
		CHECK(vertex_inout.UV2 == vec2(10.0));
		CHECK(vertex_inout.COLOR == vec4(11.0));
		CHECK(vertex_inout.POINT_SIZE == float(12.0));
		CHECK(vertex_out.POSITION == vec4(13.0));
		CHECK(vertex_out.ROUGHNESS == float(14.0));
	}

	SUBCASE("Testing fragment()")
	{
		using gosh2cpp::vec2;
		using gosh2cpp::vec3;

		gosh2cpp::SpatialFragmentInOut fragment_inout;
		gosh2cpp::SpatialFragmentOut fragment_out;
		shader.fragment(gosh2cpp::SpatialFragmentIn(), fragment_inout, fragment_out);

		CHECK(fragment_inout.NORMAL == vec3(1.0));
		CHECK(fragment_inout.TANGENT == vec3(2.0));
		CHECK(fragment_inout.BINORMAL == vec3(3.0));
		CHECK(fragment_out.NORMALMAP == vec3(4.0));
		CHECK(fragment_out.NORMALMAP_DEPTH == float(5.0));
		CHECK(fragment_out.ALBEDO == vec3(6.0));
		CHECK(fragment_out.ALPHA == float(7.0));
		CHECK(fragment_out.ALPHA_SCISSOR == float(8.0));
		CHECK(fragment_out.METALL == float(9.0));
		CHECK(fragment_out.SPECULAR == float(10.0));
		CHECK(fragment_out.ROUGHNESS == float(11.0));
		CHECK(fragment_out.RIM == float(12.0));
		CHECK(fragment_out.RIM_TINT == float(13.0));
		CHECK(fragment_out.CLEARCOAT == float(14.0));
		CHECK(fragment_out.CLEARCOAT_GLOSS == float(15.0));
		CHECK(fragment_out.ANISOTROPY == float(16.0));
		CHECK(fragment_out.ANISOTROPY_FLOW == vec2(17.0));
		CHECK(fragment_out.SSS_STRENGTH == float(18.0));
		CHECK(fragment_out.TRANSMISSION == vec3(19.0));
		CHECK(fragment_out.EMISSION == vec3(20.0));
		CHECK(fragment_out.AO == float(21.0));
		CHECK(fragment_out.AO_LIGHT_AFFECT == float(22.0));
		CHECK(fragment_out.DEPTH == float(23.0));
	}

	SUBCASE("Testing light()")
	{
		using gosh2cpp::vec3;

		gosh2cpp::SpatialLightInOut light_inout;
		gosh2cpp::SpatialLightOut light_out;
		shader.light(gosh2cpp::SpatialLightIn(), light_inout, light_out);

		CHECK(light_out.ALPHA == float(1.0));
		CHECK(light_out.DIFFUSE_LIGHT == vec3(2.0));
		CHECK(light_out.SPECULAR_LIGHT == vec3(3.0));
	}
}
