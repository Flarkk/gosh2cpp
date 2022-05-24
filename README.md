Godot shader to C++ 
===================
Include and use any shader code written in [Godot shading language](https://docs.godotengine.org/en/3.4/tutorials/shaders/shader_reference/shading_language.html) into a c++ codebase, as if it was a regular c++ piece of code.

gosh2cpp is especially useful for :
- unit testing individual functions defined inside a shader
- executing shader functions on CPU while not having to reimplement the whole logic in c++

Benefits
--------
- No change required to your shader code : it's as simple as just including it
- Nothing to build : gosh2cpp is a header-only library.

Shading language versions support
---------------------------------
Currently supports all shading language versions up to Godot 3.4.

However, a few specific features of the language have limited to no support at all.
See [Limitations](#Limitations) and [Unsupported shader features](#Unsupported-shader-features) sections below.

Dependencies
------------
- [Boost QVM](https://github.com/boostorg/qvm)
- Requires c++20
- Unit tests depend on [Doctest](https://github.com/doctest/doctest)

Licence
-------
gosh2cpp is provided under the MIT licence terms.

Quick start
-----------
### Step 1 : include your shader code
```c++
#include "gosh2cpp/gosh2cpp.hpp" // Include gosh2cpp main header

struct MyGodotSpatialShader { // Define a struct or class
    #include "gosh2cpp/class_header.inc" // Include gosh2cpp class header
    #include "path/to/your/godot/shader/code.shader" // Include your shader code
    #include "gosh2cpp/class_footer.inc" // Include gosh2cpp class footer
};
```
### Step 2 : use your shader code

```c++
MyGodotSpatialShader shader; // Instantiate the shader

auto var = shader.some_varying; // Access any user-defined variable
shader.TIME = 10.0; // Set the global built-in variable TIME
auto result = shader.some_user_defined_function(var); // Call any user-defined function

// Prepare the call to vertex() special function :
// 1. Initialize "in" built-in variables
gosh2cpp::SpatialVertexIn vertex_in {
    .VIEWPORT_SIZE = gosh2cpp::vec2(2080.0, 1024.0),
    .INV_CAMERA_MATRIX = gosh2cpp::mat4(1.0),
    .CAMERA_MATRIX = gosh2cpp::mat4(1.0),
    .OUTPUT_IS_SRGB = true,
    .INSTANCE_ID = 0,
    .INSTANCE_CUSTOM = gosh2cpp::vec4() 
};

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
```
Advanced use
------------
### Using samplers and sampling functions
By default, all samplers always return zero vectors (and zero size) when accessed through sampling functions.
You can change that behaviour and provide a custom logic for any single sampler instance declared in your shader code.

Instances from all 10 sampler types can be customized that way (`sampler2D`, `isampler2D`, `usampler2D`, `sampler2DArray`, `isampler2DArray`, `usampler2DArray`, `sampler3D`, `isampler3D`, `usampler3D`,`samplerCube`).
Your customized logic will be called whenever the shader invokes one of the 6 sampling built-in functions `textureSize()`, `texture()`, `textureProj()`, `textureLod()`, `textureProjLod()` or `texelFetch()`.

Below code shows how to customize a `sampler2D` instance :
```c++
// 1. Derive a class from provided 'samplable' abstract template
class dummy : public gosh2cpp::samplable<gosh2cpp::sampler2D> {
    const gosh2cpp::ivec2 custom_size;

    public:
    // 2. Provide customized behaviors by overriding the 4 virual member functions below :
    // NOTE : return types and argument types may differ depending on the sampler type you're working with

    gosh2cpp::ivec2 size(int lod) override { return custom_size; }                                                    // Invoked on textureSize() calls
    gosh2cpp::vec4 sample(const gosh2cpp::vec2& uv, float bias) override { return gosh2cpp::vec4 {uv, 1.0, 0.5}; }    // Invoked on texture() and textureProj() calls
    gosh2cpp::vec4 sample_lod(const gosh2cpp::vec2& uv, float lod) override { return gosh2cpp::vec4 {uv, 1.0, 0.5}; } // Invoked on textureLod() and textureProjLod() calls
    gosh2cpp::vec4 texel(const gosh2cpp::ivec2& coord, int lod) override { return gosh2cpp::vec4 {float(coord.x), float(coord.y), 1.0, 0.5}; } // Invoked on texelFetch() calls

    dummy(int size_x, int size_y)
        : custom_size {size_x, size_y} {}
};

// 3. Emplace an instance of your class into the sampler object (usually an uniform) from the shader

MyGodotSpatialShader shader;
shader.sampler_object.emplace_samplable<dummy>(512, 512);

// ... and you're done ! Any further use of sample_object will now return above customized results.
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

```


Limitations
-----------
The following Godot shader language features do not behave the same way when used through gosh2cpp compared to regular GPU execution.

### Floating point precision
`lowp`, `mediump` and `highp` keywords have no effect.
All types involving floating point are standard C++ `float` 32 bits types.

### Derivative functions
`dFdx()`, `dFdy()` and `fwidth()` functions always return 0.0.

### Variables named like c++ keywords
These variables are renamed with 3 leading underscores (example : `private` becomes `___private`).
A few keywords are however not supported at all (see below).

Unsupported shader features
---------------------------
The following Godot shader language features break compilation with gosh2cpp. If you use one of these features in your shader code, you will have to modify it in order to make it compile with gosh2cpp.

### Array initialization syntax
Only 1 flavour of array initialization syntax is supported :
```c++
vec2 vec2_arr[3] = {vec2(1.0, 1.0), vec2(0.5, 0.5), vec2(0.0, 0.0)}; // supported syntax (type and size on left size, initialization list on right side)
```
The 3 other ones allowed by Godot shading language will generate compile-time errors :
```c++
int int_arr[3] = int[](2, 1, 0); // unsupported (c++ built-in type on right side, plus presence of square brackets, plus parenthesis)
float float_arr[3] = float[3](1.0, 0.5, 0.0); // unsupported (c++ built-in type on right side, plus presence of square brackets, plus parenthesis)
bool bool_arr[] = {true, true, false}; // unsupported (size deduction)
```

### Length of an array
The `.length()` array member function is not supported.
```c++
float arr[3] = {1.0, 2.0, 3.0};
float dist = arr.length(); // Not supported
```

### Hints for uniforms
Hints for uniforms are not supported
```c++
uniform vec4 color : hint_color;  // Not supported
uniform float amount : hint_range(0, 1); // Not supported
uniform vec4 other_color : hint_color = vec4(1.0); // Not supported
```

### User-defined `struct` as function argument
Using user-defined `struct`s as `out` or `inout` function arguments is not supported.

However, using it as `in` or regular arguments (without qualifier) is supported.
```c++
struct Custom {};
void function_1(Custom arg);  // Supported
void function_2(in Custom arg);  // Supported
void function_3(out Custom arg);  // Not supported because of the 'out'
void function_4(inout Custom arg);  // Not supported because of the 'inout'
```

### Variables names
Variables can't take a name that belongs to the following list :
`and`, `and_eq`, `bitand`, `bitor`, `compl`, `not`, `not_eq`, `or`, `or_eq`, `this`,  `typename`, `using`, `xor`, `xor_eq`

How to contribute
-----------------
- To report bugs : please open an issue in the current github project.
- To propose new features : please open an issue to allow room for discussion first. Eventually submit a pull request then.
