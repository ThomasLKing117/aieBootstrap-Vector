#pragma once

class Vector3
{
private:

	float xPos;
	float yPos;
	float zPos;

public:

	Vector3();
	Vector3(float x, float y, float z);

	float getX();
	float getY();
	float getZ();

	Vector3 operator + (Vector3& rhs);
	Vector3 operator - (Vector3& rhs);

	Vector3 operator * (float& rhs);

	bool operator == (Vector3& rhs);
	bool operator != (Vector3& rhs);

	Vector3 operator += (Vector3& other);
	Vector3 operator -= (Vector3& other);

	float magnitude();

	Vector3 normalize();

	float distance(Vector3 other);

	float dotProduct(Vector3 rhs);

	Vector3 crossProduct(Vector3 rhs);

};