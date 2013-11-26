//class vector 3d
//Last Edit 11/25/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

#include <math.h> 
#include <stdlib.h>

class vector3
{
public:
	float x;
	float y;
	float z;

	// operators
	vector3 operator+ (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x + w.x;
		temp.y = this->y + w.y;
		temp.z = this->z + w.z;
		return temp;
	}

	vector3 operator+= (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x += w.x;
		temp.y = this->y += w.y;
		temp.z = this->z += w.z;
		return temp;
	}

	vector3 operator+ (float s) //scalar add
	{
		vector3 temp;
		temp.x = this->x + s; 
		temp.y = this->y + s;
		temp.z = this->z + s;
		return temp;
	}

	vector3 operator- (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x - w.x;
		temp.y = this->y - w.y;
		temp.z = this->z - w.z;
		return temp;
	}

	vector3 operator-= (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x -= w.x;
		temp.y = this->y -= w.y;
		temp.z = this->z -= w.z;
		return temp;
	}

	vector3 operator- (float s) //scalar sub
	{
		vector3 temp;
		temp.x = this->x - s; 
		temp.y = this->y - s;
		temp.z = this->z - s;
		return temp;
	}

	vector3 operator* (float s) //scalar multi
	{
		vector3 temp;
		temp.x = this->x * s; 
		temp.y = this->y * s;
		temp.z = this->z * s;
		return temp;
	}

	vector3 operator*= (float s) //scalar multi *=
	{
		vector3 temp;
		temp.x = this->x *= s; 
		temp.y = this->y *= s;
		temp.z = this->z *= s;
		return temp;
	}

	vector3 operator/ (float s) //scalar divide
	{
		vector3 temp;
		temp.x = this->x / s; 
		temp.y = this->y / s;
		temp.z = this->z / s;
		return temp;
	}

	vector3 operator/= (float s) //scalar divide /=
	{
		vector3 temp;
		temp.x = this->x /= s; 
		temp.y = this->y /= s;
		temp.z = this->z /= s;
		return temp;
	}
	
	// functions
	static float GetMagnitude(vector3 &v)
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	static vector3 Normalise(vector3 &v)
	{
		float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		v.x = v.x/mag;
		v.y = v.y/mag;
		v.z = v.z/mag;
		return v;
	}
	
	static vector3 GetNormal(vector3 &v) 
	{
		float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		vector3 result = {v.x/mag, v.y/mag, v.z/mag};
		return result;
	}
	
	static float DotProduct(vector3 &a, vector3 &b) 
	{ 
		return (a.x * b.x + a.y * b.y + a.z * b.z); 
	}

	static vector3 CrossProduct(vector3 &a, vector3 &c)
	{
		vector3 temp;
		temp.y = a.y * c.z - a.z * c.y,
		temp.z = a.z * c.x - a.x * c.z,
		temp.x = a.x * c.y - a.y * c.x;
		return temp;
	}

	// calc angle
	static float GetAngle(vector3 &a, vector3 &b)
	{
		float scalar = DotProduct(a, b);
		float aMag = GetMagnitude(a);
		float bMag = GetMagnitude(b);
		float timeMag = aMag * bMag;

		float angle = acosf(scalar / timeMag);

		return angle;
	}

};

#endif