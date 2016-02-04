#pragma once
#include <Windows.h>
#include "Vector3D.h"
#include "Matrix.h"

struct Triangle
{
	Triangle()
	{
		vertexIndex[0] = -1;
		vertexIndex[1] = -1;
		vertexIndex[2] = -1;
	}
	Triangle(int index1, int index2, int index3)
	{
		vertexIndex[0] = index1;
		vertexIndex[1] = index2;
		vertexIndex[2] = index3;
	}
	int vertexIndex[3];
};

class Cube
{
public:
	Cube();
	~Cube();

	void Initialize();
	void Render(
		HDC targetDC, 
		const Matrix& view,
		const Matrix& projection, 
		const Matrix& viewport );

protected:
	float rotationAxisX = 0.0f;
	float rotationAxisY = 0.0f;
	
	static const int VERTEX_COUNT = 8;
	static const int TRIANGLE_COUNT = 12;

	Vector3D vertex[VERTEX_COUNT];
	Triangle triangles[TRIANGLE_COUNT];	
};

