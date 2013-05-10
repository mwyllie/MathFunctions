/**
 * Title: SimpleOperator
 */

#include "SimpleOperator.h"
#include <math.h>

/**
 * Constructor.
 */
SimpleOperator::SimpleOperator()
{
	m_Operator = MATH_ADD;
	m_Lhs = NULL;
	m_Rhs = NULL;
	m_RightConstant = NULL;
	m_LeftConstant = NULL;
}

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
SimpleOperator::SimpleOperator(
	TOperatorType oper,
	MathFunction* lhs,
	MathFunction* rhs)
{
	m_Lhs = lhs;
	m_Rhs = rhs;
}

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
SimpleOperator::SimpleOperator(
    TOperatorType oper,
	MathFunction* lhs,
	double rightConstant)
{
	m_Lhs = lhs;
	m_Rhs = NULL;
	m_RightConstant = new double(rightConstant);
	m_LeftConstant = NULL;
}

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
SimpleOperator::SimpleOperator(
	TOperatorType oper,
	double leftConstant,
	MathFunction* rhs)
{
	m_Lhs = NULL;
	m_LeftConstant = new double(leftConstant);
	m_Rhs = rhs;
	m_RightConstant = NULL;
	m_Operator = oper;
}

/**
 * Destructor.
 */
SimpleOperator::~SimpleOperator()
{
	if(m_RightConstant) delete m_RightConstant;
	if(m_LeftConstant) delete m_LeftConstant;
}

/**
 * Pure virtual function to calculate a point for this fucntion.
 * @param x (input) x input value for this function.
 * @return Y value corresponding to the x input.
 */
TMathResult
SimpleOperator::CalculateY(
	double x,
	double *y)
{
	TMathResult status = MATH_SUCCESS;
	double result = 0;
	double left = 0, right = 0;

	//------------------------------------------------
	// Determine the left hand side of the operation.
	//------------------------------------------------
	if(m_Lhs)
	{
		status = m_Lhs->CalculateY(x, &left);
	}
	else if(m_LeftConstant)
	{
		left = *m_LeftConstant;
	}

	//------------------------------------------------
	// Determine the right hand side of the operation.
	//------------------------------------------------
	if(status == MATH_SUCCESS)
	{
		if(m_Rhs)
			status = m_Rhs->CalculateY(x, &right);
		else if(m_RightConstant)
			right = *m_RightConstant;
	}
	if(status != MATH_SUCCESS) return status;

	//----------------------
	// Apply the operator.
	//----------------------
	switch(GetOperatorType())
	{
	case MATH_ADD:
		result = left + right;
		break;
	case MATH_SUBTRACT:
		result = left - right;
		break;
	case MATH_MULTIPLY:
		result = left * right;
		break;
	case MATH_DIVIDE:
		if(!IsEqual(right, 0))
			result = left / right;
		else
			status = MATH_UNDEFINED;
		break;
	case MATH_POWER:
		//------------------------------------------------
		// In the case of the power, left hand side will
		// be the base, and right hand side the exponent.
		//------------------------------------------------
		result = pow(left, right);
		break;
	}

	if(status == MATH_SUCCESS)
		*y = result;

	return status;
}


