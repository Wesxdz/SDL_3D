#version 430

layout(location = 0) in vec3 vPosition;

out vec3 color;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 tint;

void main()
{
	vec4 pos = Projection * View * Model * vec4(vPosition, 1.0);
	gl_Position = pos;
	color = tint;
}