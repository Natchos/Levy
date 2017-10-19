#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Vector2D
{
public:
double x;
double y;

Vector2D():x(0.0),y(0.0){}
Vector2D(double m_x, double m_y):x(m_x),y(m_y){}
template<typename T>
Vector2D(sf::Vector2<T>or_orig):x(or_orig.x),y(or_orig.y){}
	
void Zero(){x=0.0; y=0.0;}

Vector2D V_Rotate(double m_rads);

inline double    LengthSq()const;

inline double    Length()const
{
	return sqrt(x * x + y * y);
}

inline void      Normalize()
{ 
  double vector_length = this->Length();

  if (vector_length > std::numeric_limits<double>::epsilon())
  {
    this->x /= vector_length;
    this->y /= vector_length;
  }
}

inline double    Dot(const Vector2D& v2)const;

inline int       Sign(const Vector2D& v2)const;

inline Vector2D  Perp()const;

//adjusts x and y so that the length of the vector does not exceed max
inline void      Truncate(double max);

 //returns the distance between this vector and the one passed as a parameter
inline double    Distance(const Vector2D &v2)const;

 //squared version of above.
inline double    DistanceSq(const Vector2D &v2)const;

inline void      Reflect(const Vector2D& norm);

inline Vector2D  GetReverse()const;
template<typename g_Vec>
const Vector2D& operator+=(const g_Vec &rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

const Vector2D& operator-=(const Vector2D &rhs)
{
	x -= rhs.x;
	y -= rhs.y;

   return *this;
}
	
const Vector2D& operator*=(const double& rhs)
{
	x *= rhs;
	y *= rhs;

	return *this;
}

const Vector2D& operator/=(const double& rhs)
{
	x /= rhs;
	y /= rhs;

	return *this;
}
Vector2D& operator*(const Vector2D& rhs)
{
	return Vector2D(x*rhs.x,y*rhs.y);
}
const Vector2D& operator/(const float& rhs)
{
	return Vector2D(x/rhs,y/rhs);
}
const Vector2D& operator*(const float& rhs)
{
	return Vector2D(x*rhs,y*rhs);
}
bool operator==(const Vector2D& rhs)const
{
	return (x == rhs.x && y == rhs.y );
}
template<typename T>
bool operator==(const sf::Vector2<T>& rhs)
{
	return (x == rhs.x && y == rhs.y);
}
template<typename T>
Vector2D & operator=(const sf::Vector2<T>& rhs)
{
	if (*this == rhs)
		return *this;
	x = rhs.x;
	y = rhs.y;
}
template<typename T>
const Vector2D & operator-(const sf::Vector2<T>& rhs)
{
	return Vector2D(x - rhs.x,y - rhs.y);
}
const Vector2D & operator+(const Vector2D& rhs)
{
	return Vector2D(x + rhs.x , y + rhs.y);
}
const Vector2D & operator-(const Vector2D& rhs)
{
	return Vector2D(x - rhs.x ,y - rhs.y);
}
template<typename T>
const Vector2D & operator+(const sf::Vector2<T>& rhs)
{
	return Vector2D(x + rhs.x,y + rhs.y);
}
bool operator==(const sf::Vector2f& rhs)
{
	return (x == rhs.x && y == rhs.y);
}
Vector2D & operator=(const sf::Vector2f& rhs)
{
	if (*this == rhs)
		return *this;
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}
bool operator!=(const Vector2D& rhs)const
{
	return (x != rhs.x) || (y != rhs.y);
}

template<typename F>
operator sf::Vector2<F>() const
{
	return sf::Vector2<F>(x, y);
};


};
