#version 430

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;

out vec3 color;

uniform mat4 MVP;
uniform vec3 tint;

void main()
{
	vec4 pos = MVP * vec4(vPosition, 1.0);
	gl_Position = pos;
	color = vec3(tint);
}