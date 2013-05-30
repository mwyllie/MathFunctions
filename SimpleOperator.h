/**
 * Title: SimpleOperator
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#ifndef SIMPLEOPERATOR_H 
#define SIMPLEOPERATOR_H 

#include "MathFunction.h"
#include "MathOperation.h"
#include <string>

/**
 * Base class for a mathematical function.
 */
class
SimpleOperator :
	public MathOperation
{
public:

	/**
	 * Constructor.
	 */
	SimpleOperator();

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	SimpleOperator(
		TOperatorType oper,
		MathFunction* lhs,
		MathFunction* rhs);

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	SimpleOperator(
		TOperatorType oper,
		double leftConstant,
		MathFunction* rhs);

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	SimpleOperator(
		TOperatorType oper,
		MathFunction* lhs,
		double rightConstant);

	/**
	 * Constructor.
	 */
	virtual
	~SimpleOperator();

	/**
	 * Get Left hand side function.
	 * @return MathFunction*
	 */
	virtual MathFunction*
	GetLhs()
		{return m_Lhs;};

	/**
	 * Get Right hand side function.
	 * @return MathFunction*
	 */
	virtual MathFunction*
	GetRhs()
		{return m_Rhs;};

	/**
	 * Get Left hand side value.
	 * @return double*
	 */
	virtual double*
	GetLeftConstant()
		{return m_LeftConstant;};

	/**
	 * Get Right hand side value.
	 * @return double*
	 */
	virtual double*
	GetRightConstant()
		{return m_RightConstant;};

	/**
	 * Gets the operator type.
	 * @return Operator type 
	 */
	virtual TOperatorClass
	GetOperatorClass()
		{return MATH_OPERATOR_BINARY;};

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
	 * The left and right operands may be functions or
	 * constants. If the function is non-null it is used.
	 * Only if the function is null will the constants be
	 * accessed.
	 */
	MathFunction *m_Lhs;
	MathFunction *m_Rhs;
	double *m_LeftConstant;
	double *m_RightConstant;

};

#endif
