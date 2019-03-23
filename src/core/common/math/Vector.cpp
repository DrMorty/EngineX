#include "Vector.h"

#include <cmath>

namespace engine
{
    Vector3::Vector3() : x(0), y(0), z(0)
    {
    }

    Vector3::Vector3(float value) : x(value), y(value), z(value)
    {
    }

    Vector3::Vector3(float x, float y) : x(x), y(y), z(0)
    {
    }

    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }  

    Vector3::Vector3(sf::Vector2u vec) : x(vec.x), y(vec.y), z(0)
    {
    }

    Vector3::Vector3(sf::Vector2i vec) : x(vec.x), y(vec.y), z(0)
    {
    }

    Vector3::Vector3(sf::Vector2f vec) : x(vec.x), y(vec.y), z(0)
    {
    }

    float Vector3::len()
    {
        return sqrt(x*x + y*y + z*z);
    }

    void Vector3::normalize()
    {
        float length = len();

        x = x / length;
        y = y / length;
        z = z / length;
    }

    Vector3 Vector3::operator+(const Vector3& vec)
    {
        return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
    }

    Vector3 Vector3::operator-(const Vector3& vec)
    {
        return Vector3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
    }

    Vector3 Vector3::operator*(float value)
    {
        return Vector3(this->x * value, this->y * value, this->z * value);
    }

    Vector3 Vector3::operator/(float value)
    {
        return Vector3(this->x / value, this->y / value, this->z / value);
    }

    Vector3 operator+(const Vector3& v1, const Vector3& v2)
    {
        return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    Vector3 Vector3::operator+=(const Vector3& vec)
    {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;

        return *this + vec;
    }

    Vector3 Vector3::operator-=(const Vector3& vec)
    {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;

        return *this - vec;
    }

    Vector3::operator sf::Vector2f()
    {
        return sf::Vector2f(x, y);
    }
}