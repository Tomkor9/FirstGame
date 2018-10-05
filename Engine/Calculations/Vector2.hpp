#ifndef FIRSTGAME_VECTOR2
#define FIRSTGAME_VECTOR2
#include <ostream>

struct Vector2 {
	float x;
	float y;
	
	Vector2();
	Vector2(float _x, float _y);
	Vector2(const Vector2& vec);

	Vector2& operator = (const Vector2& other);
	Vector2 operator + (const Vector2& other);
	Vector2 operator - (const Vector2& other);
	Vector2 operator * (const Vector2& other);
	Vector2 operator * (float number);
	Vector2 operator / (const Vector2& other);
	Vector2 operator / (float number);
	
	Vector2 operator += (const Vector2& other);
	Vector2 operator -= (const Vector2& other);
	Vector2 operator *= (const Vector2& other);
	Vector2 operator *= (float number);
	Vector2 operator /= (const Vector2& other);
	Vector2 operator /= (float number);
	
	bool operator == (const Vector2& other);
	bool operator != (const Vector2& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
};

#endif //FIRSTGAME_VECTOR2