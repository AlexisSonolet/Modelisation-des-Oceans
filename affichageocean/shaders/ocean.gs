#version 330 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform mat4 projectionView;
uniform mat4 transform;

noperspective out vec3 weights;

void main()
{
	
	vec4 v0 = projectionView * transform * gl_in[0].gl_Position;
	vec4 v1 = projectionView * transform * gl_in[1].gl_Position;
	vec4 v2 = projectionView * transform * gl_in[2].gl_Position;
	
	vec2 vp0 = v0.xy / v0.w;
	vec2 vp1 = v1.xy / v1.w;
	vec2 vp2 = v2.xy / v2.w;
	
	vec2 e0 = vp0 - vp1;
	vec2 e1 = vp1 - vp2;
	vec2 e2 = vp2 - vp0;

	float area = abs(e0.x*e1.y - e0.y*e1.x);
	
	float d0 = area / length(e1);
	float d1 = area / length(e2);
	float d2 = area / length(e0);
	
    weights = vec3(d0, 0, 0);
	gl_Position = v0;
    EmitVertex();
    
	weights = vec3(0, d1, 0);
	gl_Position = v1;
    EmitVertex();
    
    weights = vec3(0, 0, d2);
	gl_Position = v2;
    EmitVertex();
    
    EndPrimitive();
}
