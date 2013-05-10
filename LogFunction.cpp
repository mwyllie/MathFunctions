/**
 * Title: LogFunction
 */

#include "LogFunction.h"
#include <math.h>

/**
 * Constructor.
 */
LogFunction::LogFunction()
{
	m_Operator = MATH_LOG;
	m_Base = NULL;
}

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
LogFunction::LogFunction(
	TOperatorType oper,
	double base)
{
	m_Base = base;
	if(oper == MATH_LN)
	{
		m_Base = MATH_E;
	}
}

/**
 * Constructor.
 */
LogFunction::~LogFunction()
{
}

/**
 * Virtual function to calculate a point for this function.
 * @param x (input) x input value for this function.
 * @return Y value corresponding to the x input.
 */
TMathResult
LogFunction::CalculateY(
	double x,
	double *y)
{
	TMathResult status = MATH_SUCCESS;
	double result = 0;

	if(IsLessOrEqual(x, 0)) return MATH_UNDEFINED;
	if(IsLessOrEqual(m_Base, 0)) return MATH_UNDEFINED;

	//------------------------------------------------------
	// Compute ln if called for. Otherwise use log base 10
	// to compute for all other bases.
	//------------------------------------------------------
	if(m_Operator == MATH_LN)
	{
		//---------------------
		// log function is ln.
		//---------------------
		result = log(x);
	}
	else
	{
		//-----------------------------------------------
		// log base 10
		// If the base is not 10, use the change of base
		// formula to compute the value of the log.
		//-----------------------------------------------
		result = log10(x);
		if(m_Base != 10.0)
		{
			result /= log10(m_Base);
		}
	}

	*y = result;
	return status;
}


