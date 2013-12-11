//Last Edit 12/11/2013
//Will Gilstrap
/////////////////////
#ifndef _MATRIX_H_
#define _MATRIX_H_

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

#include <iostream>
#include "ComMath.h"
#include "Vector3.h"
#include "Vector4.h"

class Matrix3
{
public:
	float m_aMatrix[3][3];

	//Constructor
	Matrix3()
	{
		m_aMatrix[0][0] = 0;
		m_aMatrix[0][1] = 0;
		m_aMatrix[0][2] = 0;
		m_aMatrix[1][0] = 0;
		m_aMatrix[1][1] = 0;
		m_aMatrix[1][2] = 0;
		m_aMatrix[2][0] = 0;
		m_aMatrix[2][1] = 0;
		m_aMatrix[2][2] = 0;
	}

	//Set Matrix
	static Matrix3 SetMatrix(vector3 &a, vector3 &b, vector3 &c)
	{
		Matrix3 temp;
		temp.m_aMatrix[0][0] = a.x;
		temp.m_aMatrix[0][1] = a.y;
		temp.m_aMatrix[0][2] = a.z;
		temp.m_aMatrix[1][0] = b.x;
		temp.m_aMatrix[1][1] = b.y;
		temp.m_aMatrix[1][2] = b.z;
		temp.m_aMatrix[2][0] = c.x;
		temp.m_aMatrix[2][1] = c.y;
		temp.m_aMatrix[2][2] = c.z;
		return temp;
	}

	// matrix multiplication
	static Matrix3 Multi(Matrix3 &a, Matrix3 &b)
	{
		Matrix3 temp;
		float product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

		for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 3; inner++) {
				product[row][col] += a.m_aMatrix[row][inner] * b.m_aMatrix[inner][col];
            }
            //std::cout << product[row][col] << "  ";
        }
        //std::cout << "\n";
		}

		temp.m_aMatrix[0][0] = product[0][0];
		temp.m_aMatrix[0][1] = product[0][1];
		temp.m_aMatrix[0][2] = product[0][2];
		temp.m_aMatrix[1][0] = product[1][0];
		temp.m_aMatrix[1][1] = product[1][1];
		temp.m_aMatrix[1][2] = product[1][2];
		temp.m_aMatrix[2][0] = product[2][0];
		temp.m_aMatrix[2][1] = product[2][1];
		temp.m_aMatrix[2][2] = product[2][2];

		return temp;
	}

	// Create Identity
	static Matrix3 CreateIdentity()
	{
		Matrix3 temp;
		temp.m_aMatrix[0][0] = 1;
		temp.m_aMatrix[1][1] = 1;
		temp.m_aMatrix[2][2] = 1;
		return temp;
	}

	// Create Rotation
	static Matrix3 CreateRotation(float &angle)
	{	
		float newAngle = Math::ToRadian(angle);
		
		Matrix3 temp = Matrix3::CreateIdentity();
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= -sinf(newAngle);
		temp.m_aMatrix[1][0] *= sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	// Create Translation
	static Matrix3 CreateTranslation(vector3 &v)
	{
		Matrix3 temp = Matrix3::CreateIdentity();
		temp.m_aMatrix[0][2] = v.x;
		temp.m_aMatrix[1][2] = v.y;
		temp.m_aMatrix[2][2] = v.z;
		return temp;
	}

	// Get Translation
	static vector3 GetTranslation(Matrix3 &m)
	{
		vector3 temp = {temp.x = m.m_aMatrix[0][2], temp.y = m.m_aMatrix[1][2], temp.z = m.m_aMatrix[2][2]};
		return temp;
	}

	// Get Rotation
	static float GetRotation(Matrix3 &m)
	{

	}

	// Set Translation
	static Matrix3 Translation(Matrix3 &m, vector3 &v)
	{
		Matrix3 temp = m;

		temp.m_aMatrix[0][2] = v.x;
		temp.m_aMatrix[1][2] = v.y;
		temp.m_aMatrix[2][2] = v.z;
		return temp;
	}

	// Set Rotation
	static Matrix3 Rotation(Matrix3 &m, float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix3 temp = m;
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= -sinf(newAngle);
		temp.m_aMatrix[1][0] *= sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	Matrix3 operator* (const Matrix3 &w)
	{
		Matrix3 temp;
		float product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

		for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 3; inner++) {
				product[row][col] += this->m_aMatrix[row][inner] * w.m_aMatrix[inner][col];
            }
            //std::cout << product[row][col] << "  ";
        }
        //std::cout << "\n";
		}

		temp.m_aMatrix[0][0] = product[0][0];
		temp.m_aMatrix[0][1] = product[0][1];
		temp.m_aMatrix[0][2] = product[0][2];
		temp.m_aMatrix[1][0] = product[1][0];
		temp.m_aMatrix[1][1] = product[1][1];
		temp.m_aMatrix[1][2] = product[1][2];
		temp.m_aMatrix[2][0] = product[2][0];
		temp.m_aMatrix[2][1] = product[2][1];
		temp.m_aMatrix[2][2] = product[2][2];

		return temp;
	}

};

class Matrix4
{
public:
	float m_aMatrix[4][4];

	//Constructor
	Matrix4()
	{
		m_aMatrix[0][0] = 0;
		m_aMatrix[0][1] = 0;
		m_aMatrix[0][2] = 0;
		m_aMatrix[0][3] = 0;
		m_aMatrix[1][0] = 0;
		m_aMatrix[1][1] = 0;
		m_aMatrix[1][2] = 0;
		m_aMatrix[1][3] = 0;
		m_aMatrix[2][0] = 0;
		m_aMatrix[2][1] = 0;
		m_aMatrix[2][2] = 0;
		m_aMatrix[2][3] = 0;
		m_aMatrix[3][0] = 0;
		m_aMatrix[3][1] = 0;
		m_aMatrix[3][2] = 0;
		m_aMatrix[3][3] = 0;
	}

	//Set Matrix
	static Matrix4 SetMatrix(vector4 &a, vector4 &b, vector4 &c, vector4 &d)
	{
		Matrix4 temp;
		temp.m_aMatrix[0][0] = a.t;
		temp.m_aMatrix[0][1] = a.x;
		temp.m_aMatrix[0][2] = a.y;
		temp.m_aMatrix[0][3] = a.z;
		temp.m_aMatrix[1][0] = b.t;
		temp.m_aMatrix[1][1] = b.x;
		temp.m_aMatrix[1][2] = b.y;
		temp.m_aMatrix[1][3] = b.z;
		temp.m_aMatrix[2][0] = c.t;
		temp.m_aMatrix[2][1] = c.x;
		temp.m_aMatrix[2][2] = c.y;
		temp.m_aMatrix[2][3] = c.z;
		temp.m_aMatrix[3][0] = d.t;
		temp.m_aMatrix[3][1] = d.x;
		temp.m_aMatrix[3][2] = d.y;
		temp.m_aMatrix[3][3] = d.z;
		return temp;
	}

	// matrix multiplication
	static Matrix4 Multi(Matrix4 &a, Matrix4 &b)
	{
		Matrix4 temp;
		float product[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

		for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 4; inner++) {
				product[row][col] += a.m_aMatrix[row][inner] * b.m_aMatrix[inner][col];
            }
            //std::cout << product[row][col] << "  ";
        }
        //std::cout << "\n";
		}

		temp.m_aMatrix[0][0] = product[0][0];
		temp.m_aMatrix[0][1] = product[0][1];
		temp.m_aMatrix[0][2] = product[0][2];
		temp.m_aMatrix[0][3] = product[0][3];
		temp.m_aMatrix[1][0] = product[1][0];
		temp.m_aMatrix[1][1] = product[1][1];
		temp.m_aMatrix[1][2] = product[1][2];
		temp.m_aMatrix[1][3] = product[1][3];
		temp.m_aMatrix[2][0] = product[2][0];
		temp.m_aMatrix[2][1] = product[2][1];
		temp.m_aMatrix[2][2] = product[2][2];
		temp.m_aMatrix[2][3] = product[2][3];
		temp.m_aMatrix[3][0] = product[3][0];
		temp.m_aMatrix[3][1] = product[3][1];
		temp.m_aMatrix[3][2] = product[3][2];
		temp.m_aMatrix[3][3] = product[3][3];

		return temp;
	}

	// Create Identity
	static Matrix4 CreateIdentity()
	{
		Matrix4 temp;
		temp.m_aMatrix[0][0] = 1;
		temp.m_aMatrix[1][1] = 1;
		temp.m_aMatrix[2][2] = 1;
		temp.m_aMatrix[3][3] = 1;
		return temp;
	}

	// Create Rotation
	static Matrix4 CreateRotZ(const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= sinf(newAngle);
		temp.m_aMatrix[1][0] *= -sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	static Matrix4 CreateRotX(const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		temp.m_aMatrix[1][2] *= sinf(newAngle);
		temp.m_aMatrix[2][1] *= -sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	static Matrix4 CreateRotY(const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][2] *= -sinf(newAngle);
		temp.m_aMatrix[2][0] *= sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	// Create Translation
	static Matrix4 CreateTranslation(vector3 &v)
	{
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[0][3] = v.x;
		temp.m_aMatrix[1][3] = v.y;
		temp.m_aMatrix[2][3] = v.z;
		return temp;
	}

	// Get Translation
	static vector3 GetTranslation(Matrix4 &m)
	{
		vector3 temp = {temp.x = m.m_aMatrix[0][3], temp.y = m.m_aMatrix[1][3], temp.z = m.m_aMatrix[2][3]};
		return temp;
	}

	// Get Rotation
	static float GetRotation(Matrix4 &m)
	{

	}

	// Set Translation
	static Matrix4 Translation(Matrix4 &m, vector3 &v)
	{
		Matrix4 temp = m;

		temp.m_aMatrix[0][3] = v.x;
		temp.m_aMatrix[1][3] = v.y;
		temp.m_aMatrix[2][3] = v.z;
		return temp;
	}

	// Set Rotation
	static Matrix4 RotZ(Matrix4 &m, const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = m;
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= sinf(newAngle);
		temp.m_aMatrix[1][0] *= -sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	static Matrix4 RotX(Matrix4 &m, const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = m;
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		temp.m_aMatrix[1][2] *= sinf(newAngle);
		temp.m_aMatrix[2][1] *= -sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	static Matrix4 RotY(Matrix4 &m, const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = m;
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][2] *= -sinf(newAngle);
		temp.m_aMatrix[2][0] *= sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	Matrix4 operator* (const Matrix4 &w)
	{
		Matrix4 temp;
		float product[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

		for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 4; inner++) {
				product[row][col] += this->m_aMatrix[row][inner] * w.m_aMatrix[inner][col];
            }
            //std::cout << product[row][col] << "  ";
        }
        //std::cout << "\n";
		}

		temp.m_aMatrix[0][0] = product[0][0];
		temp.m_aMatrix[0][1] = product[0][1];
		temp.m_aMatrix[0][2] = product[0][2];
		temp.m_aMatrix[0][3] = product[0][3];
		temp.m_aMatrix[1][0] = product[1][0];
		temp.m_aMatrix[1][1] = product[1][1];
		temp.m_aMatrix[1][2] = product[1][2];
		temp.m_aMatrix[1][3] = product[1][3];
		temp.m_aMatrix[2][0] = product[2][0];
		temp.m_aMatrix[2][1] = product[2][1];
		temp.m_aMatrix[2][2] = product[2][2];
		temp.m_aMatrix[2][3] = product[2][3];
		temp.m_aMatrix[3][0] = product[3][0];
		temp.m_aMatrix[3][1] = product[3][1];
		temp.m_aMatrix[3][2] = product[3][2];
		temp.m_aMatrix[3][3] = product[3][3];

		return temp;
	}

};

#endif