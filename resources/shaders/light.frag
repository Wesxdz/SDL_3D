#version 430

uniform vec3 lightPos;
uniform vec3 viewPos;

in vec3 color;
in vec3 normal;
in vec3 fragPos;

void main()
{
	vec3 lightColor = vec3(1.0);

	float ambientLightStrength = 0.6;
	vec3 ambientLightColor = vec3(1.0);
	vec3 ambient = ambientLightStrength * ambientLightColor;

	vec3 lightDir = normalize(lightPos - fragPos);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	float specularStrength = 2.0;
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3 specular = specularStrength * spec * lightColor;

	gl_FragColor = vec4((ambient + diffuse + specular) * color, 1.0);
}