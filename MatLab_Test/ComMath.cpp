#include "ComMath.h"

float Math::ToRadian(float a_degree)
{
	float radian = a_degree * (FPI/180);
	return radian;
}

	// convert radian to degree
float Math::ToDegree(float a_radian)
{
	float degree = a_radian * (180/FPI);
	return degree;
}

	// Shift to next power of 2
unsigned int Math::NextPowerOf2(unsigned int n)
{
	unsigned count = 0;
 
	if (n && !(n&(n-1)))
		return n;
 
	while( n != 0)
	{
		n  >>= 1;
		count += 1;
	}
 
	return 1<<count;
}