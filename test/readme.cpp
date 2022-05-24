#include "gosh2cpp/gosh2cpp.hpp" // Include gosh2cpp main header

struct MyGodotSpatialShader {        // Define a struct (or class)
#include "gosh2cpp/class_header.inc" // Include gosh2cpp class header

	// Include your shader code
	shader_type spatial;
	uniform sampler2D sampler_object;
	varying float some_varying;
	int some_user_defined_function(float arg) { return 0; }
	void vertex() {}

#include "gosh2cpp/class_footer.inc" // Include gosh2cpp class footer
};

void readme_example()
{
	MyGodotSpatialShader shader; // Instantiate the shader

	auto var = shader.some_varying;                       // Access any user-defined variable
	shader.TIME = 10.0;                                   // Set the global built-in variable TIME
	auto result = shader.some_user_defined_function(var); // Call any user-defined function

	// Prepare the call to vertex() special function :
	// 1. Initialize "in" built-in variables
	gosh2cpp::SpatialVertexIn vertex_in {
	    .VIEWPORT_SIZE = gosh2cpp::vec2(2080.0, 1024.0),
	    .INV_CAMERA_MATRIX = gosh2cpp::mat4(1.0),
	    .CAMERA_MATRIX = gosh2cpp::mat4(1.0),
	    .OUTPUT_IS_SRGB = true,
	    .INSTANCE_ID = 0,
	    .INSTANCE_CUSTOM = gosh2cpp::vec4()};

	// 2. Instantiate "inout" built-in variables and initialize a few of them
	gosh2cpp::SpatialVertexInOut vertex_inout;
	vertex_inout.VERTEX = gosh2cpp::vec3(1.0, 2.0, 3.0);
	vertex_inout.NORMAL = gosh2cpp::vec3(4.0, 5.0, 6.0);

	// 3. Instantiate "out" built-in variables
	gosh2cpp::SpatialVertexOut vertex_out;

	// 4. Call the vertex() special function
	shader.vertex(vertex_in, vertex_inout, vertex_out);

	// Use some outputs of the vertex() call
	auto calculation = vertex_out.POSITION * 5.0;
	auto vector = vertex_inout.VERTEX;
}

void readme_sampler()
{
	// 1. Derive a class from provided 'samplable' abstract template
	class dummy : public gosh2cpp::samplable<gosh2cpp::sampler2D> {
		const gosh2cpp::ivec2 custom_size;

	  public:
		// 2. Provide customized behaviors by overriding the 4 virual member functions below :
		// NOTE : return types and argument types may differ depending on the sampler type you're working with

		gosh2cpp::ivec2 size(int lod) override { return custom_size; }                                                                             // Invoked on textureSize() calls
		gosh2cpp::vec4 sample(const gosh2cpp::vec2& uv, float bias) override { return gosh2cpp::vec4 {uv, 1.0, 0.5}; }                             // Invoked on texture() and textureProj() calls
		gosh2cpp::vec4 sample_lod(const gosh2cpp::vec2& uv, float lod) override { return gosh2cpp::vec4 {uv, 1.0, 0.5}; }                          // Invoked on textureLod() and textureProjLod() calls
		gosh2cpp::vec4 texel(const gosh2cpp::ivec2& coord, int lod) override { return gosh2cpp::vec4 {float(coord.x), float(coord.y), 1.0, 0.5}; } // Invoked on texelFetch() calls

		dummy(int size_x, int size_y)
		    : custom_size {size_x, size_y} {}
	};

	// 3. Emplace an instance of your class into the sampler object (usually an uniform) from the shader

	MyGodotSpatialShader shader;
	shader.sampler_object.emplace_samplable<dummy>(512, 512);

	// ... and you're done ! Any use of this sample_object will now return above customized results !
	// You also can even test your custom functions by calling sampling functions directly :

	gosh2cpp::vec2 uv {0.8, 0.2};
	gosh2cpp::vec3 uvh {0.8, 0.2, 5.2};
	gosh2cpp::ivec2 coord {50, 60};

	auto size = gosh2cpp::textureSize(shader.sampler_object, 0);
	auto sample = gosh2cpp::texture(shader.sampler_object, uv, 0.0);
	auto sample_proj = gosh2cpp::textureProj(shader.sampler_object, uvh, 0.0);
	auto sample_lod = gosh2cpp::textureLod(shader.sampler_object, uv, 1);
	auto sample_proj_lod = gosh2cpp::textureProjLod(shader.sampler_object, uvh, 1.0);
	auto texel = gosh2cpp::texelFetch(shader.sampler_object, coord, 2);
}