#version 330 core

out vec4 out_Color;

noperspective in vec3 weights;

void main(void){

	vec3 edgeColor = vec3(0.0);
	vec3 triangleColor = vec3(0, 0, 1);
	
	float dist = min(weights.x, min(weights.y, weights.z));
	dist = smoothstep(0.0, 1.0, dist / 0.002);
	
	vec3 color = mix(edgeColor, triangleColor, dist);
	
	out_Color = vec4(color, 1.0);
	
}
