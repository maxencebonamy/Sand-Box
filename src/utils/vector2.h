#ifndef SANDBOX_VECTOR2_H
#define SANDBOX_VECTOR2_H

#include <cmath>
#include <cassert>
#include <iostream>
#include "SFML/Graphics.hpp"


class Vector2 {

public:
    // Constructors
    Vector2();
    Vector2(float value);
    Vector2(float x, float y);
    Vector2(const Vector2& vector);
    static Vector2 fromPolar(float norm, float angle);

    // Default vectors
    static Vector2 zero();
    static Vector2 one();
    static Vector2 unitX();
    static Vector2 unitY();

    // Getters
    float getX() const;
    float getY() const;

    // Setters
    void setX(float value);
    void setY(float value);

    // Properties
    float getNorm() const;
    float getAngle() const;
    Vector2 getNormalised() const;
    sf::Vector2f toSFML() const;
    float dot(const Vector2& vector) const;
    float distanceTo(const Vector2& vector) const;

    // Operators
    Vector2& operator=(const Vector2& vector);
    float operator[](int index) const;
    float operator[](char index) const;

    Vector2& operator+=(const Vector2& vector);
    Vector2& operator+=(float scalar);
    Vector2& operator-=(const Vector2& vector);
    Vector2& operator-=(float scalar);
    Vector2& operator*=(const Vector2& vector);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(const Vector2& vector);
    Vector2& operator/=(float scalar);

private:
    // Attributes
    float _x;
    float _y;

};

bool operator==(const Vector2& a, const Vector2& b);
bool operator!=(const Vector2& a, const Vector2& b);

Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator+(const Vector2& vector, float scalar);
Vector2 operator+(float scalar, const Vector2& vector);
Vector2 operator+(const Vector2& vector);

Vector2 operator*(const Vector2& a, const Vector2& b);
Vector2 operator*(const Vector2& vector, float scalar);
Vector2 operator*(float scalar, const Vector2& vector);

Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& vector, float scalar);
Vector2 operator-(float scalar, const Vector2& vector);
Vector2 operator-(const Vector2& vector);

Vector2 operator/(const Vector2& a, const Vector2& b);
Vector2 operator/(const Vector2& vector, float scalar);

std::ostream& operator<<(std::ostream& os, const Vector2& vector);


#endif
