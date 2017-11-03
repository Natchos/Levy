#pragma once
#include "2FloatVector.hpp"


void Vector2D::rotate(double m_rads)
{
	double new_x = this->x;
	double new_y = this->y;
	new_x = this->x * cos(m_rads) - this->y * sin(m_rads);
	new_y = this->x * sin(m_rads) + this->y * cos(m_rads);
	this->x = new_x;
	this->y = new_y;
}

Vector2D Vector2D::rotated(double m_rads)
{
	double new_x = this->x;
	double new_y = this->y;
	new_x = this->x * cos(m_rads) - this->y * sin(m_rads);
	new_y = this->x * sin(m_rads) + this->y * cos(m_rads);
	return Vector2D(new_x, new_y);
}

inline double Vector2D::Dot(const Vector2D& v2)const
{
	return x*v2.x + y*v2.y;
}

enum {clockwise = 1, anticlockwise = -1};

inline int Vector2D::Sign(const Vector2D& v2)const
{
  if (y*v2.x > x*v2.y)
  { 
    return anticlockwise;
  }
  else 
  {
    return clockwise;
  }
}

inline Vector2D Vector2D::Perp(Vector2D vec)
{
  return Vector2D(-vec.y, vec.x);
}

inline double Vector2D::Distance(const Vector2D &v2)const
{
  double ySeparation = v2.y - y;
  double xSeparation = v2.x - x;

  return sqrt(ySeparation*ySeparation + xSeparation*xSeparation);
}

inline double Vector2D::DistanceSq(const Vector2D &v2)const
{
  double ySeparation = v2.y - y;
  double xSeparation = v2.x - x;

  return ySeparation*ySeparation + xSeparation*xSeparation;
}


 double Vector2D::angleBetween(Vector2D vec1, Vector2D vec2)
 {
	 return atan2(vec2.y, vec2.x) - atan2(vec1.y, vec1.x);
 }

inline Vector2D Vector2D::Reflect(const Vector2D& norm)
{
	Vector2D n(norm);
	const double dots = this->Dot(norm);
	return Vector2D(*this - n * dots * 2.f);
}


//inline void Vector2D::Truncate(double max)
//{
//	if (this->Length() > max)
//	{
//	*this = this->Normalize();
//
//	*this *= max;
//  } 
//}

//inline Vector2D Vector2D::Truncate(Vector2D vec, double max)
//{
//	Vector2D res;
//	if (vec.Length() > max)
//	{
//		res = vec.Normalize();
//
//		res *= max;
//	}
//	return res;
//}

inline Vector2D Vector2D::GetReverse(Vector2D vec)
{
  return Vector2D(-vec.x, -vec.y);
}