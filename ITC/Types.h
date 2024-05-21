#pragma once

//consider replacing with a library (glm, eigen)

struct Vector2
{
	float x;
	float y;

	Vector2(float x = 0, float y = 0)
		: x(x), y(y)
	{
	}

	Vector2 operator+(const Vector2& a) const
	{
		return Vector2(a.x + x, a.y + y);
	}
};