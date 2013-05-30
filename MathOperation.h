/**
 * Title: MathOperation.h
 * Base class for a mathematical operation.
 * @author Mary Wyllie
 */

#ifndef MATHOPERATION_H
#define MATHOPERATION_H

#include <string>
#include <vector>
#include "MathBase.h"

class MathFunction;


/**
 * Base class for a mathematical operation.
 */
class
MathOperation :
	public MathBase
{
public:

	typedef enum TOperatorClass
	{
		MATH_OPERATOR_UNKNOWN = 0,
		MATH_OPERATOR_UNARY = 1,
		MATH_OPERATOR_BINARY = 2,
		MATH_OPERATOR_COEFFICIENTS = 4
	} TOperatorClass;

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
	 * Gets the operator type.
	 * @return Operator type 
	 */
	virtual TOperatorClass
	GetOperatorClass()
		{return MATH_OPERATOR_UNKNOWN;};

	/**
	 * Get Left hand side function.
	 * @return MathFunction*
	 */
	virtual MathFunction*
	GetLhs()
		{return NULL;};

	/**
	 * Get Right hand side function.
	 * @return MathFunction*
	 */
	virtual MathFunction*
	GetRhs()
		{return NULL;};

	/**
	 * Get Left hand side value.
	 * @return double*
	 */
	virtual double*
	GetLeftConstant()
		{return NULL;};

	/**
	 * Get Right hand side value.
	 * @return double*
	 */
	virtual double*
	GetRightConstant()
		{return NULL;};

	/**
	 * Get vector values.
	 * @return double*
	 */
	virtual std::vector<double>*
	GetCoefficients()
		{return NULL;};

	/**
	 * Pure virtual function to calculate a point for this fucntion.
	 * @param x (input) x input value for this function.
	 * @return Y value corresponding to the x input.
	 */
	virtual TMathResult
	CalculateY(
		double x, double *y)
		{return MATH_UNDEFINED;};

protected:
	/**
	 * The type of this operation
	 */
	TOperatorType m_Operator;

};

#endif
