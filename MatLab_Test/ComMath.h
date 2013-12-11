//Last Edit 11/19/2013
//Will Gilstrap
/////////////////////
#ifndef _COMMATH_H_
#define _COMMATH_H_
#define FPI 3.14159265358979323846

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

#include <math.h>
#include <stdlib.h>


class Math
{
public:
	// convert degree to radian
	static float ToRadian(float a_degree)
	{
		float radian = a_degree * (FPI/180);
		return radian;
	}

	// convert radian to degree
	static float ToDegree(float a_radian)
	{
		float degree = a_radian * (180/FPI);
		return degree;
	}

	// Shift to next power of 2
	static unsigned int NextPowerOf2(unsigned int n)
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

};

#endif