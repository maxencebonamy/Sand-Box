#include "utils/vector2.h"


// Constructors

Vector2::Vector2() : _x(0), _y(0) {}

Vector2::Vector2(float value) : _x(value), _y(value) {}

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::Vector2(const Vector2& vector) : _x(vector.getX()), _y(vector.getY()) {}

Vector2 Vector2::fromPolar(float norm, float angle) { return {norm * std::cos(angle), norm * std::sin(angle)}; }


// Default vectors

Vector2 Vector2::zero() { return {}; }

Vector2 Vector2::one() { return {1}; }

Vector2 Vector2::unitX() { return {1, 0}; }

Vector2 Vector2::unitY() { return {0, 1}; }


// Getters

float Vector2::getX() const { return _x; }

float Vector2::getY() const { return _y; }


// Setters

void Vector2::setX(float value) { _x = value; }

void Vector2::setY(float value) { _y = value; }


// Properties

float Vector2::getNorm() const { return std::hypot(_x, _y); }

float Vector2::getAngle() const { return std::atan2(_y, _x); }

Vector2 Vector2::getNormalised() const { return *this / this->getNorm(); }

sf::Vector2f Vector2::toSFML() const { return {_x, _y}; }

float Vector2::dot(const Vector2& vector) const { return _x * vector.getX() + _y * vector.getY(); }

float Vector2::distanceTo(const Vector2& vector) const { return (*this - vector).getNorm(); }


// Operators

Vector2& Vector2::operator=(const Vector2& vector) {
    _x = vector.getX();
    _y = vector.getY();
    return *this;
}
float Vector2::operator[](int index) const {
    assert(index == 0 || index == 1);
    if (index == 0) return _x;
    else return _y;
}
float Vector2::operator[](char index) const {
    assert(index == 'x' || index == 'y');
    if (index == 'x') return _x;
    else return _y;
}

Vector2& Vector2::operator+=(const Vector2& vector) {
    *this = *this + vector;
    return *this;
}
Vector2& Vector2::operator+=(float scalar) {
    *this = *this + scalar;
    return *this;
}
Vector2& Vector2::operator-=(const Vector2& vector) {
    *this = *this - vector;
    return *this;
}
Vector2& Vector2::operator-=(float scalar) {
    *this = *this - scalar;
    return *this;
}
Vector2& Vector2::operator*=(const Vector2& vector) {
    *this = *this * vector;
    return *this;
}
Vector2& Vector2::operator*=(float scalar) {
    *this = *this * scalar;
    return *this;
}
Vector2& Vector2::operator/=(const Vector2& vector) {
    *this = *this / vector;
    return *this;
}
Vector2& Vector2::operator/=(float scalar) {
    *this = *this / scalar;
    return *this;
}

bool operator==(const Vector2& a, const Vector2& b) { return a.getX() == b.getX() && a.getY() == b.getY(); }

bool operator!=(const Vector2& a, const Vector2& b) { return !(a == b); }


Vector2 operator+(const Vector2& a, const Vector2& b) { return {a.getX() + b.getX(), a.getY() + b.getY()}; }

Vector2 operator+(const Vector2& vector, float scalar) { return {vector.getX() + scalar, vector.getY() + scalar}; }

Vector2 operator+(float scalar, const Vector2& vector) { return {vector.getX() + scalar, vector.getY() + scalar}; }

Vector2 operator+(const Vector2& vector) { return Vector2::zero() + vector; }


Vector2 operator*(const Vector2& a, const Vector2& b) { return {a.getX() * b.getX(), a.getY() * b.getY()}; }

Vector2 operator*(const Vector2& vector, float scalar) { return {vector.getX() * scalar, vector.getY() * scalar}; }

Vector2 operator*(float scalar, const Vector2& vector) { return {vector.getX() * scalar, vector.getY() * scalar}; }


Vector2 operator-(const Vector2& a, const Vector2& b) { return a + (-1) * b; }

Vector2 operator-(const Vector2& vector, float scalar) { return vector + (-1) * scalar; }

Vector2 operator-(float scalar, const Vector2& vector) { return vector + (-1) * scalar; }

Vector2 operator-(const Vector2& vector) { return Vector2::zero() - vector; }


Vector2 operator/(const Vector2& a, const Vector2& b) { return {a.getX() / b.getX(), a.getY() / b.getY()}; }

Vector2 operator/(const Vector2& vector, float scalar) { return vector * (1 / scalar); }


std::ostream& operator<<(std::ostream& os, const Vector2& vector) {
    os << "Vector2(" << vector.getX() << ", " << vector.getY() << ")";
    return os;
}