#ifndef VECTOR_H
#define VECTOR_H

#include <SFML/System/Vector2.hpp>

namespace engine
{
    class Vector3
    {
    public:

        float x;
        float y;
        float z;

        Vector3();
        Vector3(float value);
        Vector3(float x, float y);
        Vector3(float x, float y, float z);

        Vector3(sf::Vector2u vec);
        Vector3(sf::Vector2i vec);
        Vector3(sf::Vector2f vec);

        Vector3 operator+(const Vector3& vec);
        Vector3 operator-(const Vector3& vec);
        Vector3 operator*(float value);
        Vector3 operator/(float value);

        Vector3 operator-=(const Vector3& vec);
        Vector3 operator+=(const Vector3& vec);

        operator sf::Vector2f();

        float len();
        void normalize();
    };

    Vector3 operator+(const Vector3& v1, const Vector3& v2);
}

#endif