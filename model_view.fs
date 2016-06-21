
//
//	2016.01.31
//	Created by PHJ.
//

#version 330

uniform mat4 uniform_view;
uniform mat4 uniform_proj;
uniform sampler2D uniform_diffuse;

smooth in vec2 frag_texcoord;

out vec4 frag_color;

void main()
{
	frag_color = vec4(texture2D(uniform_diffuse, frag_texcoord).rgb, 1.0);
}