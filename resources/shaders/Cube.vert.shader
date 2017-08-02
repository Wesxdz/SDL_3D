#version 430

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;

out vec4 color;

uniform mat4 transform;
uniform vec3 tint;

void main()
{
	vec4 pos = transform * vec4(vPosition, 1.0);
	gl_Position = pos;
	color = vec4(tint, 0.4 + pos.z * 2);
}