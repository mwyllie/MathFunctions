/**
 * Title: Point.h
 * Description: Math object for points.
 * @author Mary Wyllie
 */

#include "Point.h"
#include "MathBase.h"
#include <math.h>

/**
 * Point class for math computations.
 */

/**
 * Constructor.
 * @param setting (optional input) setting (optional epsilon/angleMode).
 * @return None.
 */	
Point::Point(
	MathSetting *setting) : 
	MathBase(setting), m_X(0), m_Y(0)
{
}

/**
 * Constructor.
 * @param x (input) X coordinate of point.
 * @param y (input) Y coordinate of point.
 * @param setting (optional input) setting (optional epsilon/angleMode).
 * @return None.
 */	
Point::Point(
	double x, 
	double y,
	MathSetting *setting) : 
	MathBase(setting), m_X(x), m_Y(y)
{
}

/**
 * Constructor.
 * @param pt (input) Existing point.
 * @param setting (optional input) setting (optional epsilon/angleMode).
 * @return None.
 */	
Point::Point(
	const Point& pt,
	MathSetting *setting) : 
	MathBase(setting), m_X(pt.m_X), m_Y(pt.m_Y)
{
}

/**
 * operator== doubleests equality of x and y values (within epsilon).
 * @param rhs (input) Point to test.
 */	
bool 
Point::operator==(const Point& rhs) const 
{
	if( &rhs == this) {return(true);}
	return( IsEqual(this->m_X, rhs.m_X) && IsEqual(this->m_Y, rhs.m_Y) );
}

/**
 * operator!= doubleests inequality of x and y values (within epsilon).
 * @param rhs (input) Point to test.
 */	
bool 
Point::operator!= (const Point& rhs) const 
{
	return( ! (*this == rhs) );
}

/**
 * operator= Assignment of one point to another.
 * @param rhs (input) Point to use for values.
 */	
Point& 
Point::operator=(const Point& rhs) 
{
	if(&rhs != this) {
		m_X = rhs.m_X;  m_Y = rhs.m_Y; 
	}
	return *this;
}

/**
 * operator+= and + Adds two points by adding their x and y values.
 * @param rhs (input) Point to add.
 * @return Sum point.
 */	
Point& 
Point::operator+=(const Point& rhs) 
{
	m_X = m_X + rhs.m_X;
	m_Y = m_Y + rhs.m_Y;
	return *this;
}

Point 
Point::operator+(const Point& pt) 
{
	Point r = *this;
	r += pt;
	return r;
}

/**
 * operator-= and - Subtracts one point from another by subtracting 
 * the parameter's x and y values from this.
 * @param rhs (input) Point to subtract.
 * @return Difference point.
 */	
Point& 
Point::operator-=(const Point& rhs) 
{
	m_X = m_X - rhs.m_X;
	m_Y = m_Y - rhs.m_Y;
	return *this;
}

Point 
Point::operator-(const Point& pt) 
{
	Point r = *this;
	r -= pt;
	return r;
}

/**
 * operator- Without a parameter specified, this operator negates
 * each x and y value.
 * @return Negated point.
 */	
Point 
Point::operator-() 
{
	Point r = *this;
	r.m_X = -r.m_X;
	r.m_Y = -r.m_Y;
	return r;
}

/**
 * operator*= and * Multiplies each x and y by the scalor value input.
 * @param s (input) Value to multiply.
 * @return Product point.
 */	
Point 
Point::operator*=(const double s) 
{
	Point r = *this;
	m_X *= s;
	m_Y *= s;
	return r;
}

Point 
Point::operator*(const double s) 
{
	Point r = *this;
	r *= s;
	return r;
}

/**
 * operator/= and / Divides each x and y by the scalor value input.
 * @param s (input) Value to divide.
 * @return Resultant point.
 */	
Point 
Point::operator/=(const double s) 
{
	Point r = *this;
	m_X /= s;
	m_Y /= s;
	return r;
}

Point 
Point::operator/(const double s) 
{
	Point r = *this;
	r /= s;
	return r;
}

/**
 * Determines the distance from the point to the input point.
 * @param pt (input) Point to compare.
 * @return Distance value.
 */	
double 
Point::Distance(const Point& pt) 
{
	Point delta = *this - pt;
	double len = sqrt((double)((delta.m_X*delta.m_X) + 
			(delta.m_Y*delta.m_Y)));
	return( (double) len);
}

/**
 * Determines the distance from the point to the input point, 
 * specified by individual x and y values.
 * @param x (input) X coordinate of point to compare.
 * @param y (input) Y coordinate of point to compare.
 * @return Distance value.
 */	
double 
Point::Distance(
	double x, 
	double y) 
{
	Point pt(x, y);
	return Distance(pt);
}

/**
 * Determines the distance from the point to the input, traversing 
 * only in vertical or horizontal directions.
 * 
 * @param pt (input) Point to compare.
 * @return Distance value.
 */	
double 
Point::DistanceOrthogonal(Point& pt) 
{
	Point delta = *this - pt;
	double len = fabs(delta.m_X) + fabs(delta.m_Y);
	return( (double) len);
}

/**
 * Determines the distance from the point to the input, traversing 
 * only in vertical or horizontal directions.
 * @param x (input) X coordinate of point to compare.
 * @param y (input) Y coordinate of point to compare.
 * @return Distance value.
 */	
double 
Point::DistanceOrthogonal(
	double x, 
	double y) 
{
	Point pt(x, y);
	return DistanceOrthogonal(pt);
}

/**
 * Rotates a point the specified angle. An optional origin about 
 * which to rotate the point can also be specified.
 * @param angle (input) Angle of rotation, measure +CCW/-CW from the 
 * x axis in radians.
 * @param origin (optional input) An alternate point about which to 
 * rotate the point.
 * @return Rotated point
 */	
Point 
Point::RotateRadians(
	double angle, 
	const Point& origin)
{
	double angleCos = (double) cos(angle);
	double angleSin = (double) sin(angle);
	double A = m_X - origin.m_X;
	double B = m_Y - origin.m_Y;
	m_X = A*angleCos - B*angleSin + origin.m_X;
	m_Y = B*angleCos + A*angleSin + origin.m_Y;
	return *this;
}

/**
 * Rotates a point the specified angle. An optional origin about 
 * which to rotate the point can also be specified.
 * @param angle (input) Angle of rotation, measure +CCW/-CW from the 
 * x axis in degrees.
 * @param origin (optional input) An alternate point about which to 
 * rotate the point.
 * @return Rotated point
 */	
Point 
Point::RotateDegrees(
	double angle, 
	const Point& origin)
{
	return(RotateRadians((angle * (double) MATH_PI)/ 
		(double) 180.0, origin));
}

/**
 * Rotates a point the specified angle. An optional origin about 
 * which to rotate the point can also be specified.
 * @param angle (input) Angle of rotation, measure +CCW/-CW from the 
 * x axis. Degrees/Radians determined by angleMode value.
 * @param origin (optional input) An alternate point about which to 
 * rotate the point.
 * @return Rotated point
 */	
Point 
Point::Rotate(
	double angle , 
	const Point& origin)
{
	if(Point::GetAngleMode() == MATH_ANGLES_IN_DEGREES) 
	{

		return RotateDegrees(angle, origin);
	}
	else {
		return RotateRadians(angle, origin);
	}
}

/**
 * Creates string output of the object. Output occurs in MathBase.
 */
void 
Point::PrintObject(char* stringToPrintObject)
{
	if( stringToPrintObject ) {
		MathBase::PrintObject(stringToPrintObject);
	}
	else {
		char buff[100];
		sprintf(buff, "(%f, %f)", GetX(), GetY());
		MathBase::PrintObject(buff);
	}
}

