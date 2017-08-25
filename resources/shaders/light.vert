#version 430

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec3 vNormal;

out vec3 color;
out vec3 normal;
out vec3 fragPos;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 tint;

void main()
{
	vec4 pos = Projection * View * Model * vec4(vPosition, 1.0);
	gl_Position = pos;
	color = tint;
	normal = normalize(mat3(Model) * vNormal);
	fragPos = vec3(Model * vec4(vPosition, 1.0));
}