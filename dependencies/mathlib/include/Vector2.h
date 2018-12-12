#pragma once

class Vector2
{
private:

	float xPos;
	float yPos;

public:

	Vector2();
	Vector2(float x, float y);

	float getX();
	float getY();

	Vector2 operator + (Vector2& rhs);
	Vector2 operator - (Vector2& rhs);

	Vector2 operator * (float& rhs);

	bool operator == (Vector2& rhs);
	bool operator != (Vector2& rhs);

	float magnitude();

	Vector2 normalize();

	float distance(Vector2 other);

};