/**
 * Title: MathBase
 * Description: Base object for math objects.
 * @author Mary Wyllie
 */

#ifndef MathBase_H 
#define MathBase_H 1

#include "MathSetting.h"
#include "MathDefs.h"
#include <iostream>

/**
 * Base object for all math objects
 */
class 
MathBase 
{

public:
	/**
 	 * Get Epsilon value for this object.
	 * @return Epsilon value which defines how close is equal.
 	 */
	static const double 
	GetGlobalEpsilon();

	/**
 	 * Set Epsilon value for this object.
	 * @param epsilon (input) Value which defines how close is equal.
 	 */
	static void 
	SetGlobalEpsilon(double epsilon);

	/**
 	 * Get angle mode value for this object - radians (f)/degrees(t)).
	 * @return Angle mode determines if angles are in degrees or radians.
	 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 	 */
	static const bool 
	GetGlobalAngleMode();

	/**
 	 * Set angle mode value for this object - radians (f)/degrees(t)).
	 * @param angelMode (input) Angles are in degrees or radians.
	 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 	 */
	static void 
	SetGlobalAngleMode(
		bool angleMode);

	/**
	 * Constructor. No parameters. Relies on singleton epsilon/angle mode.
	 */
	MathBase();

	/**
 	 * Constructor. Passes setting with alternate epsilon/angle mode.
 	 */
	MathBase(
		MathSetting *setting);

	/**
	 * Destructor
	 */
	virtual
	~MathBase();

	/**int
 	 * Get Epsilon value for this object.
	 * @return Epsilon value which defines how close is equal.
 	 */
	virtual const double 
	GetEpsilon() const;

	/**
 	 * Set Epsilon value for this object.
	 * @param epsilon (input) Value which defines how close is equal.
 	 */
	virtual void 
	SetEpsilon(double epsilon);

	/**
 	 * Get angle mode value for this object - radians (f)/degrees(t)).
	 * @return Angle mode determines if angles are in degrees or radians.
	 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 	 */
	virtual const bool 
	GetAngleMode() const;

	/**
 	 * Set angle mode value for this object - radians (f)/degrees(t)).
	 * @param angelMode (input) Angles are in degrees or radians.
	 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 	 */
	virtual void 
	SetAngleMode(
		bool angleMode);

	/**
	 * Convert from degrees to radians.
	 * @param degrees (input) Angle in degrees.
	 * @return Angle in radians.
	 */
	inline const double 
	DegreesToRadians(const double degrees)
		{ return((double) (degrees * MATH_PI_OVER_180)); };

	/**
	 * Convert from radians to degrees.
	 * @param radians (input) Angle in radians.
	 * @return Angle in degrees.
	 */
	inline const double 
	RadiansToDegrees(const double radians)
		{ return((double) (radians / MATH_PI_OVER_180)); };

	/**
 	 * Set the math setting.
	 * @param setting (input) 
 	 */
	void 
	SetMathSetting( 
		MathSetting* setting);

	/**
 	 * Get the math setting.
	 * @return setting
 	 */
	MathSetting*
	GetMathSetting()
		{return m_MathSetting;};

	/**
 	 * Clear the math setting.
	 * @param isDeleted (input) Delete the object? This needs
	 * to be optional because multiple objects can share settings.
	 * This is up to the caller to manage.
 	 */
	void 
	ClearSetting(
		bool isDeleted = false);

	/**
 	 * Compare values to determine if they are within epsilon.
	 * @param x (input) First value to compare.
	 * @param v (input) Second value to compare.
	 * @param epsilon (optional input) Compare to within this value. 
	 * If 0, the object's epsilon will be used.
	 * @return True/false
 	 * @todo Description of todo 
 	 */ 
	const bool
	IsEqual(
		double x,
		double v,
		double epsilon = 0) const;

	/**
 	 * Solve for x values of a quadratic equation, given coefficients
	 * A, B and C (Ax^2 + Bx + C).
	 *
 	 * @param A (input) First value to compare.
 	 * @param B (input) Second value to compare.
 	 * @param C (input) Second value to compare.
 	 * @param x1 (output) First x value to compute
 	 * @param x2 (output) Second x value to compute.
	 * @return 1/0 results of computation
 	 */	
	static int 
	QuadraticEquation( 
		double A, 
		double B, 
		double C,
		double *x1,
		double *x2);

	/**
 	 * Compare values to determine if they are within epsilon, or x > v.
	 * @param x (input) First value to compare.
	 * @param v (input) Second value to compare.
	 * @param epsilon (optional input) Compare to within this value. 
	 * If 0, the object's epsilon will be used.
	 * @return True/false
 	 * @todo Description of todo 
 	 */
	const bool 
	IsGreaterOrEqual(
		double x, 
		double v, 
		double epsilon = 0) const;

	/**
 	 * Compare values to determine if they are within epsilon, or x < v.
	 * @param x (input) First value to compare.
	 * @param v (input) Second value to compare.
	 * @param epsilon (optional input) Compare to within this value. 
	 * If 0, the object's epsilon will be used.
	 * @return True/false
 	 * @todo Description of todo 
 	 */
	const bool 
	IsLessOrEqual(
		double x, 
		double v, 
		double epsilon = 0) const;

	/**
 	 * Output values from objects.
	 * @param stringToPrintObject (input) String value to output.
 	 * @todo Integrate with logger, check string type to use.
 	 */
	virtual void 
	PrintObject(char* stringToPrintObject = NULL);


public:

	/**
	 * Determines how close real values need to be to be considered equal.
	 */
	static double m_Epsilon;

	/**
	 * Angles in degrees (true) or radians (false)?
	 */
	static bool m_IsDegrees;

	/**
 	 * Math setting pointer allows alternate epsilon and angle mode.
 	 */
	MathSetting *m_MathSetting;


} ; //end-class MathBase



#endif
