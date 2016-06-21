
//
//	2016.01.31
//	Created by PHJ.
//

#version 330

uniform mat4 uniform_view;
uniform mat4 uniform_proj;
uniform sampler2D uniform_diffuse;

layout(location = 0) in vec3 vert_vertex;
layout(location = 1) in vec2 vert_texcoord;

smooth out vec2 frag_texcoord;

void main()
{
	gl_Position = uniform_proj * uniform_view * vec4(vert_vertex, 1.0);

	frag_texcoord = vert_texcoord;
}