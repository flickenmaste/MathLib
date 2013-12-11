//class vector 2d
//Last Edit 11/18/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

#include <math.h>
#include <stdlib.h>

class vector2
{
public:
	vector2() {x = 0; y = 0;}
	~vector2(){}
	// Gets
	float GetX() {return x;}
	float GetY() {return y;}
	// Sets
	void SetX(float nextX) {this->x = nextX;}
	void SetY(float nextY) {this->y = nextY;}

	vector2 operator+ (const vector2 &w)
	{
		vector2 temp;
		temp.x = this->x + w.x;
		temp.y = this->y + w.y;
		return temp;
	}

	vector2 operator+ (float s) //scalar add
	{
		vector2 temp;
		temp.x = this->x + s; 
		temp.y = this->y + s;
		return temp;
	}

	vector2 operator- (const vector2 &w)
	{
		vector2 temp;
		temp.x = this->x - w.x;
		temp.y = this->y - w.y;
		return temp;
	}

	vector2 operator- (float s) //scalar sub
	{
		vector2 temp;
		temp.x = this->x - s; 
		temp.y = this->y - s;
		return temp;
	}

	vector2 operator* (float s) //scalar multi
	{
		vector2 temp;
		temp.x = this->x * s; 
		temp.y = this->y * s;
		return temp;
	}

	static float DotProduct(vector2 &a, vector2 &b) 
	{ 
		return (a.x * b.x + a.y * b.y); 
	}

	static vector2 GetNormal(vector2 &v) 
	{
		float mag = sqrt(v.x*v.x + v.y*v.y);
		vector2 result;
		result.SetX(v.x/mag);
		result.SetY(v.y/mag);
		return result;
	}

	// Linear Interpolation
	static float lerp(vector2 &a, vector2 &b, float &tX)
	{	
		return (((tX - a.x)*(b.y - a.y)) 
			/ (b.x - a.x)) + a.y;
	}

	
	static vector2 Lerp(vector2 &a, vector2 &b, float &tX)
	{
		vector2 result;
		result.SetX(a.x + (b.x - a.x) * tX);
		result.SetY(a.y + (b.y - a.y) * tX);
		return result;
	}
	
	
private:
	float x;
	float y;
};

#endif