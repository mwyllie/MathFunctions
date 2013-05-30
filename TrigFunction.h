/**
 * Title: TrigFunction
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#ifndef TRIGFUNCTION_H
#define TRIGFUNCTION_H

#include "MathFunction.h"
#include "MathOperation.h"
#include <string>

/**
 * Base class for a mathematical function.
 */
class
TrigFunction :
	public MathOperation
{
public:

	/**
	 * Constructor.
	 */
	TrigFunction();

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	TrigFunction(
		TOperatorType oper);

	/**
	 * Destructor.
	 */
	virtual
	~TrigFunction();

	/**
	 * Gets the operator type.
	 * @return Operator type 
	 */
	virtual TOperatorClass
	GetOperatorClass()
		{return MATH_OPERATOR_UNARY;};

	/**
	 * Virtual function to calculate a point for this fucntion.
	 * @param x (input) x input value for this function.
	 * @return Y value corresponding to the x input.
	 */
	virtual TMathResult
	CalculateY(
		double x,
		double *y);

protected:

};

#endif
