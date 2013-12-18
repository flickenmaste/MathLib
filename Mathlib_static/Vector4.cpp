#include "Vector4.h"

vector4 vector4::Normalise(vector4 &v)
{
	float mag = sqrt(v.t*v.t + v.x*v.x + v.y*v.y + v.z*v.z);
	v.x = v.x/mag;
	v.y = v.y/mag;
	v.z = v.z/mag;
	v.t = v.t/mag;
	return v;
}

vector4 vector4::Hex(int &val)
{
	vector4 temp;
	temp.t = ((val >> 24) & 0xFF) / 255.0;
	temp.x = ((val >> 16) & 0xFF) / 255.0;
	temp.y = ((val >> 8) & 0xFF) / 255.0;
	temp.z = (val & 0xFF) / 255.0;

	return temp;
}