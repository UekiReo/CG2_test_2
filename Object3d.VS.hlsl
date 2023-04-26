float4 main( float4 pos : POSITION ) : SV_POSITION
{
	return pos;
}

struct VertexShaderOutput
{
	float32_t4 position : SV_POSITION;
};

struct VertexShaderOutput
{
	float32_t4 position : POSITION;
};

VertexShaderOutput main(VertexShaderInput input)
{
	VertexShaderOutput output;
	outout.position = input.position;
	return output;
}