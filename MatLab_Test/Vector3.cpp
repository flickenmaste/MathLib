#include "Vector3.h"

// Magnitude
float vector3::GetMagnitude(vector3 &v)
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	// Normalise
vector3 vector3::Normalise(vector3 &v)
	{
		float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		v.x = v.x/mag;
		v.y = v.y/mag;
		v.z = v.z/mag;
		return v;
	}
	
	// Normalise
vector3 vector3::GetNormal(vector3 &v) 
	{
		float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		vector3 result = {v.x/mag, v.y/mag, v.z/mag};
		return result;
	}
	
	// Dot Product
float vector3::DotProduct(vector3 &a, vector3 &b) 
	{ 
		return (a.x * b.x + a.y * b.y + a.z * b.z); 
	}

	// Cross Product
vector3 vector3::CrossProduct(vector3 &a, vector3 &c)
	{
		vector3 temp;
		temp.y = a.y * c.z - a.z * c.y,
		temp.z = a.z * c.x - a.x * c.z,
		temp.x = a.x * c.y - a.y * c.x;
		return temp;
	}

	// calc angle
float vector3::GetAngle(vector3 &a, vector3 &b)
	{
		float scalar = DotProduct(a, b);
		float aMag = GetMagnitude(a);
		float bMag = GetMagnitude(b);
		float timeMag = aMag * bMag;

		float angle = acosf(scalar / timeMag);

		return angle;
	}

	// Linear Interpolation
vector3 vector3::Lerp(vector3 &a, vector3 &b, float &tX)
	{
		vector3 result;
		result.x = (a.x + (b.x - a.x) * tX);
		result.y = (a.y + (b.y - a.y) * tX);
		result.z = (a.z + (b.z - a.z) * tX);
		return result;
	}
