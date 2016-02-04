#include "Cube.h"

Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::Initialize()
{
	vertex[0] = Vector3D(-1, -1, -1);
	vertex[1] = Vector3D(-1, 1, -1);
	vertex[2] = Vector3D(1, 1, -1);
	vertex[3] = Vector3D(1, -1, -1);
	vertex[4] = Vector3D(-1, -1, 1);
	vertex[5] = Vector3D(-1, 1, 1);
	vertex[6] = Vector3D(1, 1, 1);
	vertex[7] = Vector3D(1, -1, 1);

	triangles[0] = Triangle(0, 1, 2);
	triangles[1] = Triangle(0, 2, 3);
	triangles[2] = Triangle(4, 6, 5);
	triangles[3] = Triangle(4, 7, 6);
	triangles[4] = Triangle(4, 5, 1);
	triangles[5] = Triangle(4, 1, 0);
	triangles[6] = Triangle(3, 2, 6);
	triangles[7] = Triangle(3, 6, 7);
	triangles[8] = Triangle(1, 5, 6);
	triangles[9] = Triangle(1, 6, 2);
	triangles[10] = Triangle(4, 0, 3);
	triangles[11] = Triangle(4, 3, 7);
}

void Cube::Render(HDC targetDC,
	const Matrix& view,
	const Matrix& projection,
	const Matrix& viewport)
{
	Matrix viewProj = view * projection;

	for (int i = 0; i < TRIANGLE_COUNT; ++i)
	{
		Vector3D v1 = 
			vertex[triangles[i].vertexIndex[0]];
		Vector3D v2 =
			vertex[triangles[i].vertexIndex[1]];
		Vector3D v3 =
			vertex[triangles[i].vertexIndex[2]];

		v1 = viewProj * viewport * v1;
		v2 = viewProj * viewport * v2;
		v3 = viewProj * viewport * v3;

		//v1 = viewProj * v1;
		////백페이스 컬링
		//v1 = viewport * v1;

		MoveToEx(targetDC, (int)v1.x, (int)v1.y, nullptr);
		LineTo(targetDC, (int)v2.x, (int)v2.y);
		LineTo(targetDC, (int)v3.x, (int)v3.y);
		LineTo(targetDC, (int)v1.x, (int)v1.y);
	}
}