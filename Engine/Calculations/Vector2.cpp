#include "Vector2.hpp"

Vector2::Vector2() {
	x = 0.0F;
	y = 0.0F;
}
Vector2::Vector2(const Vector2& vec) {
	x = vec.x;
	y = vec.y;
}
Vector2::Vector2(float _x, float _y) {
	x = _x;
	y = _y;
}
Vector2& Vector2::operator = (const Vector2& other) {
	x = other.x;
	y = other.y;
	return *this;
}
Vector2 Vector2::operator + (const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}
Vector2 Vector2::operator - (const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}
Vector2 Vector2::operator * (const Vector2& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}
Vector2 Vector2::operator * (float number) {
	x *= number;
	y *= number;
	return *this;
}
Vector2 Vector2::operator / (const Vector2& other) {
	if (other.x != 0 || other.y != 0)
	{
		x *= 1 / other.x;
		y *= 1 / other.y;
	}
	else
		printf("Vector2 DEVIDED BY vec 0!\n");
	return *this;
}
Vector2 Vector2::operator / (float number) {
	if (number != 0.0F)
	{
		x *= 1 / number;
		y *= 1 / number;
	}
	else
		printf("Vector2 DEVIDED BY num 0!\n");
	return *this;
}
bool Vector2::operator == (const Vector2& other) {
	return (x == other.x && y == other.y);
}
bool Vector2::operator != (const Vector2& other) {
	return !(*this == other);
}


Vector2 Vector2::operator+=(const Vector2 & other)
{
	return *this + other;
}
Vector2 Vector2::operator-=(const Vector2 & other)
{
	return *this - other;
}
Vector2 Vector2::operator*=(const Vector2 & other)
{
	return (*this) * other;
}
Vector2 Vector2::operator*=(float number)
{
	return (*this) * number;
}
Vector2 Vector2::operator/=(const Vector2 & other)
{
	return (*this) / other;
}
Vector2 Vector2::operator/=(float number)
{
	return (*this) / number;
}

std::ostream & operator<<(std::ostream & os, const Vector2 & vec)
{
	os << '[' << vec.x << ',' << vec.y << ',' << ']';
	return os;
}