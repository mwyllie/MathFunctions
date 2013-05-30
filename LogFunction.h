/**
 * Title: LogFunction
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#ifndef LOGFUNCTION_H
#define LOGFUNCTION_H

#include "MathFunction.h"
#include "MathOperation.h"
#include <string>

/**
 * Base class for a mathematical function.
 */
class
LogFunction :
	public MathOperation
{
public:

	/**
	 * Constructor.
	 */
	LogFunction();

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	LogFunction(
		TOperatorType oper,
		double base = 10.0);

	/**
	 * Constructor.
	 */
	virtual
	~LogFunction();

	/**
	 * Gets the operator type.
	 * @return Operator type 
	 */
	virtual TOperatorClass
	GetOperatorClass()
		{return MATH_OPERATOR_BINARY;};

	/**
	 * Get Left hand side value.
	 * @return double*
	 */
	virtual double*
	GetLeftConstant()
		{return &m_Base;};

	/**
	 * Pure virtual function to calculate a point for this fucntion.
	 * @param x (input) x input value for this function.
	 * @return Y value corresponding to the x input.
	 */
	virtual TMathResult
	CalculateY(
		double x,
		double *y);

protected:
	/**
	 * What is the base of this log? Default is base 10.
	 */
	double m_Base;

};

#endif
