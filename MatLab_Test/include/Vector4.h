//class vector 4d
//Last Edit 11/19/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

#include <math.h> 
#include <stdlib.h>

class vector4
{
public:
	float t;
	float x;
	float y;
	float z;

	static vector4 Normalise(vector4 &v)
	{
		float mag = sqrt(v.t*v.t + v.x*v.x + v.y*v.y + v.z*v.z);
		v.x = v.x/mag;
		v.y = v.y/mag;
		v.z = v.z/mag;
		v.t = v.t/mag;
		return v;
	}
};

#endif