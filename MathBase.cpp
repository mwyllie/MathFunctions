/**
 * Title: MathBase
 * Description: Base object for all math objects.
 * @author Mary Wyllie
 */

#include "MathBase.h"
#include "Math.h"

bool MathBase::m_IsDegrees = true;
double MathBase::m_Epsilon = 0.0000001;

/**
 * Get Epsilon value for this object.
 * @return Epsilon value which defines how close is equal.
 */
const double 
MathBase::GetGlobalEpsilon()
{
	return(m_Epsilon);
}

/**
 * Set Epsilon value for this object.
 * @param epsilon (input) Value which defines how close is equal.
 */
void 
MathBase::SetGlobalEpsilon(double epsilon)
{
	m_Epsilon = epsilon;
}

/**
 * Get angle mode value for this object - radians (f)/degrees(t)).
 * @return Angle mode determines if angles are in degrees or radians.
 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 */
const bool 
MathBase::GetGlobalAngleMode()
{
	return(m_IsDegrees);
}

/**
 * Set angle mode value for this object - radians (f)/degrees(t)).
 * @param angelMode (input) Angles are in degrees or radians.
 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 */
void 
MathBase::SetGlobalAngleMode(
	bool angleMode)
{
	m_IsDegrees = angleMode;
}

/**
 * Base object for math objects
 */

/**
 * Constructor. No parameters. Relies on singleton epsilon/angle mode.
 */
MathBase::MathBase() : 
	m_MathSetting(NULL) 
{
}

/**
 * Constructor. Passes setting with alternate epsilon/angle mode.
 */
MathBase::MathBase(
	MathSetting *setting) : 
	m_MathSetting(setting)
{
}

/**
 * Destructor.
 */
MathBase::~MathBase()
{
}

/**
 * Get Epsilon value for this object.
 * @return Epsilon value which defines how close is equal.
 */
const double 
MathBase::GetEpsilon() const 
{
	if( m_MathSetting )
	{
		return(m_MathSetting->GetEpsilon());
	}
	return(m_Epsilon);
}

/**
 * Set Epsilon value for this object.
 * @param epsilon (input) Value which defines how close is equal.
 */
void 
MathBase::SetEpsilon(
	double epsilon)
{
	if( !m_MathSetting )
	{
		m_MathSetting = new MathSetting();
	}
	if( m_MathSetting )
	{
		m_MathSetting->SetEpsilon(epsilon);
	}
}

/**
 * Get angle mode value for this object - radians (f)/degrees(t)).
 * @return Angle mode determines if angles are in degrees or radians.
 * Use GEOMETRY_ANGLES_IN_DEGREES | GEOMETRY_ANGLES_IN_RADIANS.
 */
const bool 
MathBase::GetAngleMode() const 
{
	if( m_MathSetting )
	{
		return(m_MathSetting->GetAngleMode());
	}
	return(m_IsDegrees);
}

/**
 * Set angle mode value for this object - radians (f)/degrees(t)).
 * @param angelMod (input) Determine if angles are in degrees or radians.
 * Use GEOMETRY_ANGLES_IN_DEGREES | GEOMETRY_ANGLES_IN_RADIANS.
 */
void 
MathBase::SetAngleMode( 
	bool angleMode)
{
	if( !m_MathSetting )
	{
		m_MathSetting = new MathSetting();
	}
	if( m_MathSetting)
	{
		m_MathSetting->SetAngleMode(angleMode);
	}
}

/**
 * Set the math setting.
 * @param setting (input) 
 */
void 
MathBase::SetMathSetting( 
	MathSetting* setting)
{
	m_MathSetting = setting;
}

/**
 * Clear the math setting.
 * @param setting (input) 
 */
void 
MathBase::ClearSetting(
	bool remove)
{
	if( remove ) delete m_MathSetting;
	m_MathSetting = NULL;
}

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
MathBase::IsEqual(
	double x, 
	double v, 
	double epsilon) const
{
	double l_epsilon = epsilon ? epsilon : GetEpsilon();

	if( l_epsilon ) 
	{
		double diff = fabs(x-v);
		return(diff < l_epsilon) ? true : false;
	}
	else
	{
		return(x == v);
	}
}	

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
int 
MathBase::QuadraticEquation( 
	double A, 
	double B, 
	double C,
	double *x1, 
	double *x2)
{
	if( A == 0 )
	{
		return(0);
	}
	*x1 = (double) ( -B + sqrt(B*B - 4*A*C) ) / (2*A);
	*x2 = (double) ( -B - sqrt(B*B - 4*A*C) ) / (2*A);
	return(1);
}


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
MathBase::IsGreaterOrEqual(
	double x, 
	double v, 
	double epsilon) const
{
	if( x > v ) { return true; }
	if( IsEqual(x, v)) { return true; }
	return false;
}

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
MathBase::IsLessOrEqual(
	double x, 
	double v, 
	double epsilon) const
{
	if( x < v ) { return true; }
	if( IsEqual(x, v)) { return true; }
	return false;
}

/**
 * Output values from objects.
 * @param stringToPrintObject (input) String value to output.
 * @todo Integrate with logger, check string type to use.
 */
void 
MathBase::PrintObject(char* stringToPrintObject )
{
	if( stringToPrintObject ) 
		std::cerr << stringToPrintObject << std::endl;
} 


