#include "Vector3.h"
#include <math.h>



Vector3::Vector3(float parX, float parY, float parZ) : x(parX), y(parY), z(parZ)
{
}
Vector3::Vector3(Vector3 const& parVector) : x(parVector.x), y(parVector.y), z(parVector.z)
{
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(Vector3 const& parVector)
{
	return Vector3(x + parVector.x, y + parVector.y, z + parVector.z);
}
Vector3 Vector3::operator+=(Vector3 const& parVector)
{
	x += parVector.x;
	y += parVector.y;
	z += parVector.z;
	return *this;
}
Vector3 Vector3::operator-(Vector3 const& parVector)
{
	return Vector3(x - parVector.x, y - parVector.y, z - parVector.z);
}
Vector3 Vector3::operator-=(Vector3 const& parVector)
{
	x -= parVector.x;
	y -= parVector.y;
	z -= parVector.z;
	return *this;
}
Vector3 Vector3::operator*(float parScale)
{
	return Vector3(x * parScale, y * parScale, z * parScale);
}
Vector3 Vector3::operator/(float parScale)
{
	return Vector3(x / parScale, y / parScale, z / parScale);
}
bool Vector3::operator==(Vector3 const& parVector)
{
	return x == parVector.x && y == parVector.y && z == parVector.z;
}
bool Vector3::operator!=(Vector3 const& parVector)
{
	return !(*this == parVector);
}
Vector3 operator*(float parScale, Vector3 const &parVector)
{
	return Vector3(parVector.x * parScale, parVector.y * parScale, parVector.z * parScale);
}
Vector3 operator/(float parScale, Vector3 const &parVector)
{
	return Vector3(parVector.x / parScale, parVector.y / parScale, parVector.z / parScale);
}

float Vector3::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z);
}
void Vector3::Normalize()
{
	float magnitude = Magnitude();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}
Vector3 Vector3::ToNormalized()
{
	return *this / Magnitude();
}
float Vector3::Dot(const Vector3 &parVector) const
{
	return x * parVector.x + y * parVector.y + z * parVector.z;
}
Vector3 Vector3::Cross(const Vector3 &parVector) const
{
	return Vector3(y * parVector.z - z * parVector.y, z * parVector.x - x * parVector.z, x * parVector.y - y * parVector.x);
}
