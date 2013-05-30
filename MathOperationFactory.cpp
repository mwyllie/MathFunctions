/**
 * Title: MathOperationFactory.cpp
 * Description: Math operation factory for creation of various math functions.
 * @author Mary Wyllie
 */

#include "MathOperationFactory.h"
#include "SimpleOperator.h"
#include "Polynomial.h"
#include "CompositeFunction.h"
#include "LogFunction.h"
#include "TrigFunction.h"

/**
 * This method serves as a factory for the various math
 * operations. All possible parameters are included to
 * provide a single signature.
 * @param type (input) Which math operation.
 * @param lhs (input) Left side function.
 * @param rhs (input) Right side function.
 * @param leftConstant (input) Left value.
 * @param rightValue (input) Right value.
 * @param coefficients (input) Coefficients for polynomial.
 */
MathOperation*
MathOperationFactory::CreateMathOperation(
	TOperatorType type,
	MathFunction *lhs,
	MathFunction *rhs,
	double *leftConstant,
	double *rightConstant,
	std::vector<double> *coefficients)
{
	MathOperation *result = NULL;

	switch(type)
	{
	case MATH_ADD:
	case MATH_SUBTRACT:
	case MATH_MULTIPLY:
	case MATH_DIVIDE:
	case MATH_POWER:
		if(lhs && rhs)
			result = new SimpleOperator(type, lhs, rhs);
		else if(lhs && rightConstant)
        {
            result = new SimpleOperator(type, lhs, *rightConstant);
        }
		else if(rhs && leftConstant)
            result = new SimpleOperator(type, *leftConstant, rhs);
		break;
	case MATH_POLYNOMIAL:
		result = new Polynomial(*coefficients);
		break;
	case MATH_COMPOSITE:
		result = new CompositeFunction(lhs, rhs);
		break;
	case MATH_SIN:
	case MATH_COS:
	case MATH_TAN:
	case MATH_COT:
	case MATH_SEC:
	case MATH_CSC:
		result = new TrigFunction(type);
		break;

	case MATH_LOG:
	case MATH_LN:
		//---------------------------------------------------
		// If the base is non-zero, send it along. Otherwise
		// we want to rely on the default base.
		//---------------------------------------------------
		if(leftConstant)
			result = new LogFunction(type, *leftConstant);
		else
			result = new LogFunction(type);
		break;
	}
	if(result) result->SetOperatorType(type);
	return result;
}

