/**
 * Title: CompositeFunction
 * A function which is a CompositeFunction of two functions.
 * @author Mary Wyllie
 */

#ifndef COMPOSITEFUNCTION_H
#define COMPOSITEFUNCTION_H

#include "MathFunction.h"
#include "MathOperation.h"

/**
 * Class for a composite mathematical function.
 */
class
CompositeFunction :
	public MathOperation
{
public:

	/**
	 * Constructor.
	 */
	CompositeFunction();

	/**
	 * Constructor.
	 * @param outsideFunction (input) Outside of CompositeFunction.
	 * @param insideFunction (input) Inside of CompositeFunction.
	 */
	CompositeFunction(
		MathFunction *outsideFunction,
		MathFunction *insideFunction);

	/**
	 * Destructor.
	 */
	virtual
	~CompositeFunction();

	/**
	 * Set the functions.
	 * @param outsideFunction (input) Outside of CompositeFunction.
	 * @param insideFunction (input) Inside of CompositeFunction.
	 */
	void
	SetFunctions(
		MathFunction *outsideFunction,
		MathFunction *insideFunction);

	/**
	 * Get Left hand side function.
	 * @return MathFunction*
	 */
	virtual MathFunction*
	GetLhs()
		{return m_Outside;};

	/**
	 * Get Right hand side function.
	 * @return MathFunction*
	 */
	virtual MathFunction*
	GetRhs()
		{return m_Inside;};

	/**
	 * Get the outside function.
	 * @return Pointer to MathFunction.
	 */
	MathFunction*
	GetOutsideFunction()
		{return m_Outside;};

	/**
	 * Get the inside function.
	 * @return Pointer to MathFunction.
	 */
	MathFunction*
	GetInsideFunction()
		{return m_Inside;};

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
	 * Functions to be combined, as m_Outside( m_inside );
	 * Like f(g(x)).
	 */
	MathFunction *m_Outside;
	MathFunction *m_Inside;

};

#endif


