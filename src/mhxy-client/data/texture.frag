#version 330 core
//in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Texture samplers
uniform sampler2D outTexture1;
uniform sampler2D outTexture2;
uniform sampler2D outTexture3;
uniform sampler2D outTexture4;
uniform sampler2D outTexture5;

void main()
{
	// Linearly interpolate between both textures (second texture is only slightly combined)
	vec4 color1 = texture(outTexture1, TexCoord);
	vec4 color2 = texture(outTexture2, TexCoord);
	vec4 color3 = texture(outTexture3, TexCoord);
	vec4 color4 = texture(outTexture4, TexCoord);
	vec4 color5 = texture(outTexture5, TexCoord);
	color = color1;
	if(color2.a != 0)
	{
		if(color2.a == 1){
			color = color2;
		} else {
			color = mix(color, color2, color2.a);
		}
	}
	if(color3.a != 0)
	{
		if(color3.a == 1){
			color = color3;
		} else {
			color = mix(color, color3, color3.a);
		}
	}
	if(color4.a != 0)
	{
		if(color4.a == 1){
			color = color4;
		} else {
			color = mix(color, color4, color4.a);
		}
	}
	if(color5.a != 0)
	{
		if(color5.a == 1){
			color = color5;
		} else {
			color = mix(color, color5, color5.a);
		}
	}
}
