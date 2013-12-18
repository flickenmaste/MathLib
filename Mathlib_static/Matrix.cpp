#include "Matrix.h"

// *****Matrix 3*****

//Constructor
	Matrix3::Matrix3()
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
Matrix3 Matrix3::SetMatrix(vector3 &a, vector3 &b, vector3 &c)
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
Matrix3 Matrix3::Multi(Matrix3 &a, Matrix3 &b)
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
Matrix3 Matrix3::CreateIdentity()
	{
		Matrix3 temp;
		temp.m_aMatrix[0][0] = 1;
		temp.m_aMatrix[1][1] = 1;
		temp.m_aMatrix[2][2] = 1;
		return temp;
	}

	// Create Rotation
Matrix3 Matrix3::CreateRotation(float &angle)
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
Matrix3 Matrix3::CreateTranslation(vector3 &v)
	{
		Matrix3 temp = Matrix3::CreateIdentity();
		temp.m_aMatrix[0][2] = v.x;
		temp.m_aMatrix[1][2] = v.y;
		temp.m_aMatrix[2][2] = v.z;
		return temp;
	}

	// Get Translation
vector3 Matrix3::GetTranslation(Matrix3 &m)
	{
		vector3 temp = {temp.x = m.m_aMatrix[0][2], temp.y = m.m_aMatrix[1][2], temp.z = m.m_aMatrix[2][2]};
		return temp;
	}

	// Get Rotation
float Matrix3::GetRotation(Matrix3 &m)
	{
		// Finish this
		float eek;
		return eek;
	}

	// Set Translation
Matrix3 Matrix3::Translation(Matrix3 &m, vector3 &v)
	{
		Matrix3 temp = m;

		temp.m_aMatrix[0][2] = v.x;
		temp.m_aMatrix[1][2] = v.y;
		temp.m_aMatrix[2][2] = v.z;
		return temp;
	}

	// Set Rotation
Matrix3 Matrix3::Rotation(Matrix3 &m, float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix3 temp = m;
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= -sinf(newAngle);
		temp.m_aMatrix[1][0] *= sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	// Transform Vector
vector3 Matrix3::TransformVec(Matrix3 &m, const vector3 &point)
	{
		vector3 temp;
        temp.x = point.x * m.m_aMatrix[0][0] + point.y * m.m_aMatrix[1][0] + point.z * m.m_aMatrix[2][0];
        temp.y = point.x * m.m_aMatrix[0][1] + point.y * m.m_aMatrix[1][1] + point.z * m.m_aMatrix[2][1];
        temp.z = point.x * m.m_aMatrix[0][2] + point.y * m.m_aMatrix[1][2] + point.z * m.m_aMatrix[2][2];
        return temp;
	}

vector4 Matrix3::TransformVec(Matrix3 &m, const vector4 &point)
	{
		vector4 temp;
        temp.x = point.x * m.m_aMatrix[0][0] + point.y * m.m_aMatrix[1][0] + point.z * m.m_aMatrix[2][0];
        temp.y = point.x * m.m_aMatrix[0][1] + point.y * m.m_aMatrix[1][1] + point.z * m.m_aMatrix[2][1];
        temp.z = point.x * m.m_aMatrix[0][2] + point.y * m.m_aMatrix[1][2] + point.z * m.m_aMatrix[2][2];
		temp.t = point.t;
        return temp;
	}

// Scale
vector4 Matrix3::Scale(Matrix3 &m, const vector4 &vec)
        {
                vector4 temp;
                
                temp.x = vec.x * m.m_aMatrix[0][0] + vec.y * 0 + vec.z * 0;
                temp.y = vec.x * 0 + vec.y * m.m_aMatrix[1][1] + vec.z * 0;
                temp.z = vec.x * 0 + vec.y * 0 + vec.z * m.m_aMatrix[2][2];
                temp.t = vec.t;
                return temp;
        }

        vector3 Matrix3::Scale(Matrix3 &m, const vector3 &vec)
        {
                vector3 temp;
                temp.x = vec.x * m.m_aMatrix[0][0] + vec.y * 0 + vec.z * 0;
                temp.y = vec.x * 0 + vec.y * m.m_aMatrix[1][1] + vec.z * 0;
                temp.z = vec.x * 0 + vec.y * 0 + vec.z * m.m_aMatrix[2][2];
                return temp;
        }

// *****Matrix 4*****

	//Constructor
	Matrix4::Matrix4()
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
Matrix4 Matrix4::SetMatrix(vector4 &a, vector4 &b, vector4 &c, vector4 &d)
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
Matrix4 Matrix4::Multi(Matrix4 &a, Matrix4 &b)
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
Matrix4 Matrix4::CreateIdentity()
	{
		Matrix4 temp;
		temp.m_aMatrix[0][0] = 1;
		temp.m_aMatrix[1][1] = 1;
		temp.m_aMatrix[2][2] = 1;
		temp.m_aMatrix[3][3] = 1;
		return temp;
	}

	// Create Rotation Z
Matrix4 Matrix4::CreateRotZ(const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= sinf(newAngle);
		temp.m_aMatrix[1][0] *= -sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	// Create Rot X
Matrix4 Matrix4::CreateRotX(const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		temp.m_aMatrix[1][2] *= sinf(newAngle);
		temp.m_aMatrix[2][1] *= -sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	// Create Rot Y
Matrix4 Matrix4::CreateRotY(const float &angle)
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
Matrix4 Matrix4::CreateTranslation(vector3 &v)
	{
		Matrix4 temp = Matrix4::CreateIdentity();
		temp.m_aMatrix[0][3] = v.x;
		temp.m_aMatrix[1][3] = v.y;
		temp.m_aMatrix[2][3] = v.z;
		return temp;
	}

	// Get Translation
vector3 Matrix4::GetTranslation(Matrix4 &m)
	{
		vector3 temp = {temp.x = m.m_aMatrix[0][3], temp.y = m.m_aMatrix[1][3], temp.z = m.m_aMatrix[2][3]};
		return temp;
	}

	// Get Rotation
float Matrix4::GetRotation(Matrix4 &m)
	{
		// Finish this
		float eek;
		return eek;
	}

	// Set Translation
Matrix4 Matrix4::Translation(Matrix4 &m, vector3 &v)
	{
		Matrix4 temp = m;

		temp.m_aMatrix[0][3] = v.x;
		temp.m_aMatrix[1][3] = v.y;
		temp.m_aMatrix[2][3] = v.z;
		return temp;
	}

	// Rot Z
Matrix4 Matrix4::RotZ(Matrix4 &m, const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = m;
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][1] *= sinf(newAngle);
		temp.m_aMatrix[1][0] *= -sinf(newAngle);
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		return temp;
	}

	// Rot X
Matrix4 Matrix4::RotX(Matrix4 &m, const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = m;
		temp.m_aMatrix[1][1] *= cosf(newAngle);
		temp.m_aMatrix[1][2] *= sinf(newAngle);
		temp.m_aMatrix[2][1] *= -sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	// Rot Y
Matrix4 Matrix4::RotY(Matrix4 &m, const float &angle)
	{
		float newAngle = Math::ToRadian(angle);
		
		Matrix4 temp = m;
		temp.m_aMatrix[0][0] *= cosf(newAngle);
		temp.m_aMatrix[0][2] *= -sinf(newAngle);
		temp.m_aMatrix[2][0] *= sinf(newAngle);
		temp.m_aMatrix[2][2] *= cosf(newAngle);
		return temp;
	}

	// Transform point
vector4 Matrix4::TransformPoint(Matrix4 &m, const vector4 &point)
	{
		vector4 temp;

		temp.x = point.x * m.m_aMatrix[0][0] + point.y * m.m_aMatrix[1][0] + point.y * m.m_aMatrix[2][0] + point.t * m.m_aMatrix[3][0];
        temp.y = point.x * m.m_aMatrix[0][1] + point.y * m.m_aMatrix[1][1] + point.y * m.m_aMatrix[2][1] + point.t * m.m_aMatrix[3][1];
        temp.z = point.x * m.m_aMatrix[0][2] + point.y * m.m_aMatrix[1][2] + point.y * m.m_aMatrix[2][2] + point.t * m.m_aMatrix[3][2];
        temp.t = point.x * m.m_aMatrix[0][3] + point.y * m.m_aMatrix[1][3] + point.t * m.m_aMatrix[2][3] + point.t * m.m_aMatrix[3][3];
                
        if (temp.t != 1 && temp.t != 0)
        {
			temp.x /= temp.t;
            temp.y /= temp.t;
            temp.x /= temp.t;
            temp.t /= temp.t;
        }

                return temp;
	}

	// Transform vector
vector3 Matrix4::TransformVec(Matrix4 &m, const vector3 &point)
	{
		vector3 temp;
        temp.x = point.x * m.m_aMatrix[0][0] + point.y * m.m_aMatrix[1][0] + point.z * m.m_aMatrix[2][0];
        temp.y = point.x * m.m_aMatrix[0][1] + point.y * m.m_aMatrix[1][1] + point.z * m.m_aMatrix[2][1];
        temp.z = point.x * m.m_aMatrix[0][2] + point.y * m.m_aMatrix[1][2] + point.z * m.m_aMatrix[2][2];

        return temp;
	}

	// Transform vector
vector4 Matrix4::TransformVec(Matrix4 &m, const vector4 &point)
	{
		vector4 temp;
        temp.x = point.x * m.m_aMatrix[0][0] + point.y * m.m_aMatrix[1][0] + point.z * m.m_aMatrix[2][0] + point.t * m.m_aMatrix[3][0];
        temp.y = point.x * m.m_aMatrix[0][1] + point.y * m.m_aMatrix[1][1] + point.z * m.m_aMatrix[2][1] + point.t * m.m_aMatrix[3][1];
        temp.z = point.x * m.m_aMatrix[0][2] + point.y * m.m_aMatrix[1][2] + point.z * m.m_aMatrix[2][2] + point.t * m.m_aMatrix[3][2];
        temp.t = point.x * m.m_aMatrix[0][3] + point.y * m.m_aMatrix[1][3] + point.z * m.m_aMatrix[2][3] + point.t * m.m_aMatrix[3][3];

                return temp;
	}

	// Scale
vector3 Matrix4::Scale(Matrix4 &m, const vector3 &vec)
	{
		vector3 temp;
        temp.x = vec.x * m.m_aMatrix[0][0] + vec.y * 0 + vec.z * 0;
        temp.y = vec.x * 0 + vec.y * m.m_aMatrix[1][1] + vec.z * 0;
        temp.z = vec.x * 0 + vec.y * 0 + vec.z * m.m_aMatrix[2][2];
        return temp;
	}

	// Scale
vector4 Matrix4::Scale(Matrix4 &m, const vector4 &vec)
	{
		vector4 temp;
        temp.x = vec.x * m.m_aMatrix[0][0] + vec.y * 0 + vec.z * 0 + vec.t * 0;
        temp.y = vec.x * 0 + vec.y * m.m_aMatrix[1][1] + vec.z * 0 + vec.t * 0;
        temp.z = vec.x * 0 + vec.y * 0 + vec.z * m.m_aMatrix[2][2] + vec.t * 0;
        temp.t = vec.x * 0 + vec.y * 0 + vec.z * 0 + vec.t * m.m_aMatrix[3][3];
        return temp;
	}

// Ortho
Matrix4 Matrix4::OGLOrthoMatrix(float Left, float Right, float Top, float Bottom, float Far, float Near)
        {
                Matrix4 Ortho;

				Ortho = Matrix4::CreateIdentity();

                Ortho.m_aMatrix [0][0] = 2 / (Right - Left);
                Ortho.m_aMatrix [0][3] = -( (Right + Left) / (Right - Left));

                Ortho.m_aMatrix [1][1] = 2 / (Top - Bottom);
                Ortho.m_aMatrix [1][3] = -( (Top + Bottom) / (Top - Bottom));

                Ortho.m_aMatrix [2][2] = -2 / (Far - Near);
                Ortho.m_aMatrix [2][3] = -( (Far + Near) / (Far - Near));
                
                return Ortho;
        }

// Ortho
        Matrix4 Matrix4::OrthoMatrix(float Left, float Right, float Top, float Bottom, float Far, float Near)
        {
                Matrix4 Ortho;

                Ortho = Matrix4::CreateIdentity();

                Ortho.m_aMatrix [0][0] = 2 / (Right - Left);
                

                Ortho.m_aMatrix [1][1] = 2 / (Top - Bottom);
                

                Ortho.m_aMatrix [2][2] = -1 / (Far - Near);

                Ortho.m_aMatrix [3][0] = -( (Right + Left) / (Right - Left));
                Ortho.m_aMatrix [3][1] = -( (Top + Bottom) / (Top - Bottom));
                Ortho.m_aMatrix [3][2] = Near / (Far - Near);
                
                return Ortho;
        }