//Last Edit 11/25/2013
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
	static Matrix3 CreateRotation(Matrix3 &m)
	{

	}

	// Create Translation
	static Matrix3 CreateTranslation(Matrix3 &m)
	{

	}

	// Get Translation
	static vector3 GetTranslation(Matrix3 &m)
	{

	}

	// Get Rotation
	static float GetRotation(Matrix3 &m)
	{

	}

	// Set Translation
	static void Translation(Matrix3 &m)
	{

	}

	// Set Rotation
	static void Rotation(Matrix3 &m)
	{

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
	static Matrix4 CreateRotation(Matrix4 &m)
	{

	}

	// Create Translation
	static Matrix4 CreateTranslation(Matrix4 &m)
	{

	}

	// Get Translation
	static vector4 GetTranslation(Matrix4 &m)
	{

	}

	// Get Rotation
	static float GetRotation(Matrix4 &m)
	{

	}

	// Set Translation
	static void Translation(Matrix4 &m)
	{

	}

	// Set Rotation
	static void Rotation(Matrix4 &m)
	{

	}

};

#endif