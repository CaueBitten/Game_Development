#pragma once
#include <math.h>

class Vector2D
{
private:

	float m_x;
	float m_y;

public:
	
	Vector2D(float x, float y);
	~Vector2D();

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	Vector2D operator+ (const Vector2D& v2) const;
	friend Vector2D& operator+= (Vector2D& v1, const Vector2D& v2) {
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector2D operator- (const Vector2D& v2) const;
	friend Vector2D& operator-= (Vector2D& v1, const Vector2D& v2) {
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	Vector2D operator* (float scalar);
	Vector2D& operator*= (float scalar);

	Vector2D operator/ (float scalar);
	Vector2D& operator/= (float scalar);

	float lenght();

	void normalize();

};

