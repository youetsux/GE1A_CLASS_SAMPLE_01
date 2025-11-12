#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float _x, float _y)
	:x(_x), y(_y)
{
}

Vector2D Vector2D::Add(const Vector2D& _v)
{   //tmp => temporaly ˆêŽž“I‚È‚à‚Ì
	Vector2D tmp(x + _v.x, y + _v.y);
	//tmp.x = x + _v.x;
	//tmp.y = y + _v.y;
	return tmp;
}

float Vector2D::Distance(const Vector2D& _v)
{
	float dist2 = (_v.x - x)* (_v.x - x) + (_v.y - y)* (_v.y - y);

	return sqrt(dist2);
}
