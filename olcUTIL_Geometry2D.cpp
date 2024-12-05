#include "olcUTIL_Geometry2D.h"

// Specific constructor

constexpr olc::v_2d::v_2d(float _x, float _y)
    : x(_x)
    , y(_y)
{
}

// Returns magnitude of vector
float olc::v_2d::mag() const
{
    return std::sqrt(x * x + y * y);
}

// Returns rectangular area of vector
constexpr float olc::v_2d::area() const
{
    return x * y;
}

// Returns magnitude squared of vector (useful for fast comparisons)

constexpr float olc::v_2d::mag2() const
{
    return x * x + y * y;
}

// Returns normalised version of vector

olc::v_2d olc::v_2d::norm() const
{
    auto r = 1 / mag();
    return v_2d(x * r, y * r);
}

// Returns vector at 90 degrees to this one

constexpr olc::v_2d olc::v_2d::perp() const
{
    return v_2d(-y, x);
}

// Rounds both components down

constexpr olc::v_2d olc::v_2d::floor() const
{
    return v_2d(std::floor(x), std::floor(y));
}

// Rounds both components up

constexpr olc::v_2d olc::v_2d::ceil() const
{
    return v_2d(std::ceil(x), std::ceil(y));
}

// Returns 'element-wise' max of this and another vector

constexpr olc::v_2d olc::v_2d::max(const v_2d& v) const
{
    return v_2d(std::max(x, v.x), std::max(y, v.y));
}

// Returns 'element-wise' min of this and another vector

constexpr olc::v_2d olc::v_2d::min(const v_2d& v) const
{
    return v_2d(std::min(x, v.x), std::min(y, v.y));
}

// Calculates scalar dot product between this and another vector

constexpr auto olc::v_2d::dot(const v_2d& rhs) const
{
    return this->x * rhs.x + this->y * rhs.y;
}

// Calculates 'scalar' cross product between this and another vector (useful for winding orders)

constexpr auto olc::v_2d::cross(const v_2d& rhs) const
{
    return this->x * rhs.y - this->y * rhs.x;
}

// Treat this as polar coordinate (R, Theta), return cartesian equivalent (X, Y)

constexpr olc::v_2d olc::v_2d::cart() const
{
    return v_2d(std::cos(y) * x, std::sin(y) * x);
}

// Treat this as cartesian coordinate (X, Y), return polar equivalent (R, Theta)

constexpr olc::v_2d olc::v_2d::polar() const
{
    return v_2d(mag(), std::atan2(y, x));
}

// Clamp the components of this vector in between the 'element-wise' minimum and maximum of 2 other vectors

constexpr olc::v_2d olc::v_2d::clamp(const v_2d& v1, const v_2d& v2) const
{
    return this->max(v1).min(v2);
}

// Linearly interpolate between this vector, and another vector, given normalised parameter 't'

constexpr olc::v_2d olc::v_2d::lerp(const v_2d& v1, const float t) const
{
    return (*this) * (1.0f - t) + (v1 * t);
}

// Compare if this vector is numerically equal to another

constexpr bool olc::v_2d::operator==(const v_2d& rhs) const
{
    return (this->x == rhs.x && this->y == rhs.y);
}

// Compare if this vector is not numerically equal to another

constexpr bool olc::v_2d::operator!=(const v_2d& rhs) const
{
    return (this->x != rhs.x || this->y != rhs.y);
}

// Return this vector as a std::string, of the form "(x,y)"

std::string olc::v_2d::str() const
{
    return std::string("(") + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
}

// Assuming this vector is incident, given a normal, return the reflection

constexpr olc::v_2d olc::v_2d::reflect(const v_2d& n) const
{
    return (*this) - 2.0 * (this->dot(n) * n);
}

// Returns rectangular area of vector

// Multiplication operator overloads between vectors and scalars, and vectors and vectors
constexpr olc::v_2d olc::operator*(const float lhs, const v_2d& rhs)
{
    return v_2d(lhs * rhs.x, lhs * rhs.y);
}

constexpr olc::v_2d olc::operator*(const v_2d& lhs, const float rhs)
{
    return rhs * lhs;
}

constexpr olc::v_2d olc::operator*(const v_2d& lhs, const v_2d& rhs)
{
    return v_2d(lhs.x * rhs.x, lhs.y * rhs.y);
}

constexpr olc::v_2d olc::operator*=(v_2d& lhs, const float& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

// Division operator overloads between vectors and scalars, and vectors and vectors
constexpr olc::v_2d olc::operator/(const float lhs, const v_2d& rhs)
{
    return olc::v_2d(lhs / rhs.x, lhs / rhs.y);
}

constexpr olc::v_2d olc::operator/(const v_2d& lhs, const float rhs)
{
    return olc::v_2d(lhs.x / rhs, lhs.y / rhs);
}

constexpr olc::v_2d olc::operator/(const v_2d& lhs, const v_2d& rhs)
{
    return olc::v_2d(lhs.x / rhs.x, lhs.y / rhs.y);
}

constexpr olc::v_2d olc::operator/=(v_2d& lhs, const float rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

// Unary Addition operator (pointless but i like the platinum trophies)
constexpr olc::v_2d olc::operator+(const v_2d& lhs)
{
    return v_2d(+lhs.x, +lhs.y);
}

// Addition operator overloads between vectors and scalars, and vectors and vectors
constexpr olc::v_2d olc::operator+(const float lhs, const v_2d& rhs)
{
    return v_2d(lhs + rhs.x, lhs + rhs.y);
}

constexpr olc::v_2d olc::operator+(const v_2d& lhs, const float rhs)
{
    return v_2d(lhs.x + rhs, lhs.y + rhs);
}

constexpr olc::v_2d olc::operator+(const v_2d& lhs, const v_2d& rhs)
{
    return v_2d(lhs.x + rhs.x, lhs.y + rhs.y);
}

constexpr olc::v_2d olc::operator+=(v_2d& lhs, const float rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

constexpr olc::v_2d olc::operator+=(v_2d& lhs, const v_2d& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

// Unary negation operator overoad for inverting a vector
constexpr olc::v_2d olc::operator-(const v_2d& lhs)
{
    return v_2d(-lhs.x, -lhs.y);
}

// Subtraction operator overloads between vectors and scalars, and vectors and vectors
constexpr olc::v_2d olc::operator-(const float lhs, const v_2d& rhs)
{
    return v_2d(lhs - rhs.x, lhs - rhs.y);
}

constexpr olc::v_2d olc::operator-(const v_2d& lhs, const float rhs)
{
    return v_2d(lhs.x - rhs, lhs.y - rhs);
}

constexpr olc::v_2d olc::operator-(const v_2d& lhs, const v_2d& rhs)
{
    return v_2d(lhs.x - rhs.x, lhs.y - rhs.y);
}

constexpr olc::v_2d olc::operator-=(v_2d& lhs, const float rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

constexpr bool olc::operator>(const v_2d& lhs, const v_2d& rhs)
{
    return (lhs.y < rhs.y) || (lhs.y == rhs.y && lhs.x < rhs.x);
}

constexpr bool olc::operator>(const v_2d& lhs, const v_2d& rhs)
{
    return (lhs.y > rhs.y) || (lhs.y == rhs.y && lhs.x > rhs.x);
}

// Allow olc::v_2d to play nicely with std::cout
std::ostream& olc::operator<<(std::ostream& os, const v_2d& rhs)
{
    os << rhs.str();
    return os;
}

std::vector<olc::v_2d> olc::utils::geom2d::internal::filter_duplicate_points(const std::vector<olc::v_2d>& points)
{
    std::vector<olc::v_2d> filtered_points;

    for (const auto& point : points)
    {
        bool is_duplicate = false;

        for (const auto& filtered_point : filtered_points)
        {
            if (std::abs(point.x - filtered_point.x) < epsilon && std::abs(point.y - filtered_point.y) < epsilon)
            {
                is_duplicate = true;
                break;
            }
        }

        if (!is_duplicate)
        {
            filtered_points.push_back(point);
        }
    }

    return filtered_points;
}

olc::utils::geom2d::line::line(const olc::v_2d& s, const olc::v_2d& e)
    : start(s)
    , end(e)
{
}

// Get vector pointing from start to end

constexpr olc::v_2d olc::utils::geom2d::line::vector() const
{
    return (end - start);
}

// Get length of line

constexpr float olc::utils::geom2d::line::length()
{
    return vector().mag();
}

// Get length of line^2

constexpr float olc::utils::geom2d::line::length2()
{
    return vector().mag2();
}

// Given a real distance, get point along line

constexpr olc::v_2d olc::utils::geom2d::line::rpoint(const float distance) const
{
    return start + vector().norm() * distance;
}

// Given a unit distance, get point along line

constexpr olc::v_2d olc::utils::geom2d::line::upoint(const float distance) const
{
    return start + vector() * distance;
}

// Return which side of the line does a point lie

constexpr int32_t olc::utils::geom2d::line::side(const olc::v_2d& point) const
{
    double d = vector().cross(point - start);
    if (d < 0)
        return -1;
    else if (d > 0)
        return 1;
    else
        return 0;
}

// Returns line equation "mx + a" coefficients where:
// x: m
// y: a
// NOTE: Returns {inf, inf} if std::abs(end.x - start.x) < epsilon:

constexpr olc::v_2d olc::utils::geom2d::line::coefficients() const
{
    double x1 = start.x;
    double x2 = end.x;
    double y1 = start.y;
    double y2 = end.y;

    // check if line is vertical or close to vertical
    if (std::abs(x2 - x1) < epsilon)
    {
        return olc::v_2d{std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
    }

    double m = (y2 - y1) / (x2 - x1);
    return olc::v_2d{m, -m * x1 + y1};
}

inline olc::utils::geom2d::rect::rect(const olc::v_2d& p, const olc::v_2d& s)
    : pos(p)
    , size(s)
{
}

inline olc::v_2d olc::utils::geom2d::rect::middle() const
{
    return pos + (size * double(0.5));
}

// Get line segment from top side of rectangle

inline line olc::utils::geom2d::rect::top() const
{
    return {pos, {pos.x + size.x, pos.y}};
}

// Get line segment from bottom side of rectangle

inline line olc::utils::geom2d::rect::bottom() const
{
    return {{pos.x, pos.y + size.y}, pos + size};
}

// Get line segment from left side of rectangle

inline line olc::utils::geom2d::rect::left() const
{
    return {pos, {pos.x, pos.y + size.y}};
}

// Get line segment from right side of rectangle

inline line olc::utils::geom2d::rect::right() const
{
    return {{pos.x + size.x, pos.y}, pos + size};
}

// Get a line from an indexed side, starting top, going clockwise

inline line olc::utils::geom2d::rect::side(const size_t i) const
{
    if ((i & 0b11) == 0)
        return top();
    if ((i & 0b11) == 1)
        return right();
    if ((i & 0b11) == 2)
        return bottom();
    // if ((i & 0b11) == 3) return left(); // Dumb compilers cant fathom this
    return left();
}

// Get area of rectangle

inline constexpr float olc::utils::geom2d::rect::area() const
{
    return size.x * size.y;
}

// Get perimeter of rectangle

inline constexpr float olc::utils::geom2d::rect::perimeter() const
{
    return 2.0f * (size.x + size.y);
}

// Returns side count: 4

inline constexpr size_t olc::utils::geom2d::rect::side_count() const
{
    return 4;
}

inline olc::utils::geom2d::circle::circle(const olc::v_2d& p, const float r)
    : pos(p)
    , radius(r)
{
}

// Get area of circle

inline constexpr float olc::utils::geom2d::circle::area() const
{
    return pi * radius * radius;
}

// Get circumference of circle

inline constexpr float olc::utils::geom2d::circle::perimeter() const
{
    return 2.0 * pi * radius;
}

// Get circumference of circle

inline constexpr float olc::utils::geom2d::circle::circumference() const
{
    return perimeter();
}
