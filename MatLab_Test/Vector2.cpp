#include "Vector2.h"

vector2::vector2() {x = 0; y = 0;}
	// Gets
	float vector2::GetX() {return x;}
	float vector2::GetY() {return y;}
	// Sets
	void vector2::SetX(float nextX) {this->x = nextX;}
	void vector2::SetY(float nextY) {this->y = nextY;}

	// Dot Product
float vector2::DotProduct(vector2 &a, vector2 &b) 
	{ 
		return (a.x * b.x + a.y * b.y); 
	}

	// Magnitude
float vector2::GetMagnitude(vector2 &v)
	{
		return sqrt(v.x*v.x + v.y*v.y);
	}

	// Normalise
vector2 vector2::GetNormal(vector2 &v) 
	{
		float mag = sqrt(v.x*v.x + v.y*v.y);
		vector2 result;
		result.SetX(v.x/mag);
		result.SetY(v.y/mag);
		return result;
	}

	// Linear Interpolation
vector2 vector2::Lerp(vector2 &a, vector2 &b, float &tX)
	{
		vector2 result;
		result.SetX(a.x + (b.x - a.x) * tX);
		result.SetY(a.y + (b.y - a.y) * tX);

		return result;
	}