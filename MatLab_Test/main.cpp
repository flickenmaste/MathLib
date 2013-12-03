#include <iostream>
#include "include\ComMath.h"
#include "include\Matrix.h"
#include "include\Vector2.h"
#include "include\Vector3.h"
#include "include\Vector4.h"

void testvec3();
void testcommath();

int main()
{
	std::cout << "******Matrix stuff******" << std::endl;
	
	// Matrix 3 stuff
	Matrix3 hello = Matrix3::CreateIdentity();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << hello.m_aMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	vector3 one = {1, 2, 3};
	vector3 two = {4, 5, 6};
	vector3 three = {7, 8, 9};

	Matrix3 bye = Matrix3::SetMatrix(one,two,three);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << bye.m_aMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	Matrix3 eek = bye * hello;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << eek.m_aMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Matrix 4 stuff
	Matrix4 nice = Matrix4::CreateIdentity();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << nice.m_aMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	vector4 a = {1, 2, 3, 4};
	vector4 b = {5, 6, 7, 8};
	vector4 c = {9, 10, 11, 12};
	vector4 d = {13, 14, 15, 16};

	Matrix4 lol = Matrix4::SetMatrix(a,b,c,d);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << lol.m_aMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	Matrix4 multi = lol * nice;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << multi.m_aMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	testvec3();

	std::cin.get();
	std::cin.get();
	return 0;
}

void testvec3()
{
	std::cout << "******Vector 3 stuff******" << std::endl;

	vector3 first = {1, 2, 3};

	std::cout << "Magnitude: " << vector3::GetMagnitude(first) << std::endl;

	vector3::Normalise(first);

	std::cout << "Normalised vec: " << first.x << " " << first.y << " " << first.z << std::endl;

	first.x = 1; first.y = 2; first.z = 3;

	vector3 second = {4, 5, 6};

	std::cout << "Dot Prod: " << vector3::DotProduct(first, second) << std::endl;

	vector3 cross = vector3::CrossProduct(first, second);

	std::cout << "Cross Prod: " << cross.x << " " << cross.y << " " << cross.z << std::endl;

	std::cout << "Angle: " << vector3::GetAngle(first, second) << std::endl;
	testcommath();
}

void testcommath()
{
	std::cout << "******Com Math stuff******" << std::endl;

	std::cout << "Degree to Radian: " << Math::ToRadian(90) << std::endl;

	float radian = Math::ToRadian(90);

	std::cout << "Radian to Degree: " << Math::ToDegree(radian) << std::endl;

	std::cout << "Next Power of 2: " << Math::NextPowerOf2(20) << std::endl;
}