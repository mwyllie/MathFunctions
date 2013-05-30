/**
 * Title: Point.h
 * Description:  Class for a point in the cartesion coordinate system.
 * @author Mary Wyllie
 */


#ifndef POINT_H 
#define POINT_H

#include "MathBase.h"

/**
 * Point  class for math computations.
 */
class Point : 
	public MathBase
{
public:

	/**
 	 * Constructor.
 	 * @param setting (optional input) setting (optional epsilon/angleMode).
 	 * @return None.
 	 */	
	Point(
		MathSetting *setting = NULL);

	/**
 	 * Constructor.
 	 * @param x (input) X coordinate of point.
 	 * @param y (input) Y coordinate of point.
 	 * @param setting (optional input) setting (optional epsilon/angleMode).
 	 * @return None.
 	 */	
	Point(
		double x, 
		double y,
		MathSetting *setting = NULL);

	/**
 	 * Constructor.
 	 * @param pt (input) Existing point.
 	 * @param setting (optional input) setting (optional epsilon/angleMode).
 	 * @return None.
 	 */	
	Point(
		const Point& pt,
		MathSetting *setting = NULL);

	/**
 	 * GetX
 	 * @return X value of point.
 	 */	
	double 
	GetX(void) const 
		{ return(m_X); };

	/**
 	 * GetY
 	 * @return Y value of point.
 	 */	
	double 
	GetY(void) const 
		{ return(m_Y); };

	/**
 	 * SetX
 	 * @param x (input) X value of point.
 	 */	
	void 
	SetX(double x) 
		{m_X = x;};

	/**
 	 * SetY
 	 * @param y (input) Y value of point.
 	 */	
	void 
	SetY(double y) 
		{m_Y = y;};

	/**
 	 * Set
 	 * @param x (input) X value of point.
 	 * @param y (input) Y value of point.
	 * @param offset (input) Optional point offset to apply.
 	 */	
	void 
	Set(
		double x, 
		double y,
		const Point& offset = Point(0, 0) )
		{ m_X = x + offset.m_X; m_Y = y + offset.m_Y; };

	/**
 	 * SetX
 	 * @param pt (input) Existing point for which to set values.
 	 */	
	void 
	Set(const Point& pt)
		{ m_X = pt.m_X; m_Y = pt.m_Y; };

	/**
	 * operator== Tests equality of x and y values (within epsilon).
 	 * @param rhs (input) Point to test.
 	 */	
	bool 
	operator==(const Point& rhs) const;

	/**
	 * operator!= Tests inequality of x and y values (within epsilon).
 	 * @param rhs (input) Point to test.
 	 */	
	bool 
	operator!=(const Point& rhs) const;

	/**
	 * operator= Assignment of one point to another.
 	 * @param rhs (input) Point to use for values.
 	 */	
	Point& 
	operator=(const Point& rhs);

	/**
	 * operator+= and + Adds two points by adding their x and y values.
 	 * @param rhs (input) Point to add.
	 * @return Sum point.
 	 */	
	Point& 
	operator+=(const Point& rhs);

	Point 
	operator+(const Point& pt);

	/**
	 * operator-= and - Subtracts one point from another by subtracting 
	 * the parameter's x and y values from this.
 	 * @param rhs (input) Point to subtract.
	 * @return Difference point.
 	 */	
	Point&
	operator-=(const Point& rhs);

	Point 
	operator-(const Point& pt); 

	/**
	 * operator- Without a parameter specified, this operator negates
	 * each x and y value.
	 * @return Negated point.
 	 */	
	Point 
	operator-();

	/**
	 * operator*= and * Multiplies each x and y by the scalor value input.
 	 * @param s (input) Value to multiply.
	 * @return Product point.
 	 */	
	Point 
	operator*=(const double s);

	Point 
	operator*(const double s);

	/**
	 * operator/= and / Divides each x and y by the scalor value input.
 	 * @param s (input) Value to divide.
	 * @return Resultant point.
 	 */	
	Point 
	operator/=(const double s);

	Point 
	operator/(const double s);

	/**
	 * Determines the distance from the point to the input point.
 	 * @param pt (input) Point to compare.
	 * @return Distance value.
 	 */	
	double 
	Distance(const Point& pt);

	/**
	 * Determines the distance from the point to the input point, 
	 * specified by individual x and y values.
 	 * @param x (input) X coordinate of point to compare.
 	 * @param y (input) Y coordinate of point to compare.
	 * @return Distance value.
 	 */	
	double 
	Distance(
		double x,
		double y);

	/**
	 * Determines the distance from the point to the input, traversing 
	 * only in vertical or horizontal directions.
 	 * @param pt (input) Point to compare.
	 * @return Distance value.
 	 */	
	double 
	DistanceOrthogonal(
		Point& pt);

	/**
	 * Determines the distance from the point to the input, traversing 
	 * only in vertical or horizontal directions.
 	 * @param x (input) X coordinate of point to compare.
 	 * @param y (input) Y coordinate of point to compare.
	 * @return Distance value.
 	 */	
	double 
	DistanceOrthogonal(
		double x,
		double y);

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
	RotateRadians(
		double angle, 
		const Point& origin = Point(0,0));

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
	RotateDegrees(
		double angle, 
		const Point& origin = Point(0,0));

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
	Rotate(
		double angle, 
		const Point& origin = Point(0,0));

	/**
	 * Creates string output of the object. Output occurs in MathBase.
	 */
	void 
	PrintObject(char* stringToPrintObject = NULL);

	/**
	 * Overload the stream operator for output.
	 * @param output (input/output) The output stream.
	 * @param pt (input) The point to print.
	 */
	friend std::ostream&
	operator<<(std::ostream& output, const Point& pt);


protected:

	/**
 	 * X and Y values of the point
 	 */	
	double m_X, m_Y;

};


#endif
