/**
 * Title: MathOperation
 * Base class for a mathematical operation.
 * @author Mary Wyllie
 */

#ifndef MATHOPERATION_H
#define MATHOPERATION_H

#include <string>
#include "MathBase.h"


/**
 * Base class for a mathematical operation.
 */
class
MathOperation :
	public MathBase
{
public:

	/**
	 * Constructor.
	 */
	MathOperation()
		{};

	/**
	 * Constructor.
	 */
	virtual
	~MathOperation()
		{};

	/**
	 * Sets the operator type.
	 * @param type (input)
	 */
	void
	SetOperatorType(TOperatorType type)
		{m_Operator = type;};
		
	/**
	 * Gets the operator type.
	 * @return Operator type 
	 */
	TOperatorType
	GetOperatorType()
		{return m_Operator;};
		
	/**
	 * Pure virtual function to calculate a point for this fucntion.
	 * @param x (input) x input value for this function.
	 * @return Y value corresponding to the x input.
	 */
	virtual TMathResult
	CalculateY(
		double x, double *y) = 0;

protected:
	/**
	 * The type of this operation
	 */
	TOperatorType m_Operator;

};

#endif
