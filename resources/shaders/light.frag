#version 430

in vec3 color;

void main()
{
	float ambientLightStrength = 0.8;
	vec3 ambientLightColor = vec3(1.0);
	vec3 ambient = ambientLightStrength * ambientLightColor;
	gl_FragColor = vec4(ambient * color, 1.0);
}