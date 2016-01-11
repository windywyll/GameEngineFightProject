#ifndef __VECTOR3__
#define __VECTOR3__

class Vector3
{
	//Attributs
public:
	float x;
	float y;
	float z;

	//Methods
public:
	Vector3(float parX = 0.0f, float parY = 0.0f, float parZ = 0.0f);
	Vector3(Vector3 const& parVector);
	~Vector3();

	Vector3 operator+(Vector3 const& parVector);
	Vector3 operator+=(Vector3 const& parVector);
	Vector3 operator-(Vector3 const& parVector);
	Vector3 operator-=(Vector3 const& parVector);
	Vector3 operator*(float parScale);
	Vector3 operator/(float parScale);
	bool operator==(Vector3 const& parVector);
	bool operator!=(Vector3 const& parVector);
	friend Vector3 operator*(float parScale, Vector3 const &vec);
	friend Vector3 operator/(float parScale, Vector3 const &vec);

	float Magnitude() const;
	void Normalize();
	Vector3 ToNormalized();
	float Dot(const Vector3 &parVector) const;
	Vector3 Cross(const Vector3 &parVector) const;
};

#endif __VECTOR3__