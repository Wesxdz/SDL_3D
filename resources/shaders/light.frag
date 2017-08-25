#version 430

uniform vec3 lightPos;

in vec3 color;
in vec3 normal;
in vec3 fragPos;

void main()
{
	float ambientLightStrength = 0.6;
	vec3 ambientLightColor = vec3(1.0);
	vec3 ambient = ambientLightStrength * ambientLightColor;

	vec3 lightDir = normalize(lightPos - fragPos);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = diff * vec3(1.0); // Diffuse light color

	gl_FragColor = vec4((ambient + diffuse) * color, 1.0);
}