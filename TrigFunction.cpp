/**
 * Title: TrigFunction
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#include "TrigFunction.h"
#include "MathFunction.h"
#include <math.h>

/**
 * Class for a trig functions.
 */

/**
 * Constructor.
 */
TrigFunction::TrigFunction()
{
}

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
TrigFunction::TrigFunction(
	TOperatorType function)
{
}

/**
 * Destructor.
 */
TrigFunction::~TrigFunction()
{
}

/**
 * Virtual function to calculate a point for this fucntion.
 * @param x (input) x input value for this function.
 * @return Y value corresponding to the x input.
 */
TMathResult
TrigFunction::CalculateY(
	double x,
	double *y)
{
	TMathResult status = MATH_SUCCESS;
	double result = 0;
	double angle = x;
	if(GetAngleMode() == MATH_ANGLES_IN_DEGREES)
	{
		angle = DegreesToRadians(x);
	}

	switch(GetOperatorType())
	{
	case MATH_SIN:
		result = sin(angle);
		break;
	case MATH_COS:
		result = cos(angle);
		break;
	case MATH_TAN:
		result = tan(angle);
		break;
	case MATH_COT:
		result = tan(angle);
		if(!IsEqual(result, 0))
			result = 1/result;
		else
			status = MATH_UNDEFINED;
		break;
	case MATH_SEC:
		result = cos(angle);
		if(!IsEqual(result, 0))
			result = 1/result;
		else
			status = MATH_UNDEFINED;
		break;
	case MATH_CSC:
		result = sin(angle);
		if(!IsEqual(result, 0))
			result = 1/result;
		else
			status = MATH_UNDEFINED;
		break;
	}

	if(status == MATH_SUCCESS)
		*y = result;

	return status;
}

