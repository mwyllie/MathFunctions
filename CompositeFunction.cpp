/**
 * Title: CompositeFunction
 * Class for a Composite mathematical function.
 * @author Mary Wyllie
 */

#include "CompositeFunction.h"

/**
 * Constructor.
 */
CompositeFunction::CompositeFunction()
{
	m_Outside = NULL;
	m_Inside = NULL;
}

/**
 * Constructor.
 * @param outsideFunction (input) Outside of CompositeFunction.
 * @param insideFunction (input) Inside of CompositeFunction.
 */
CompositeFunction::CompositeFunction(
	MathFunction *outsideFunction,
	MathFunction *insideFunction) : 
	m_Outside(outsideFunction),
	m_Inside(insideFunction)
{
}

/**
 * Destructor.
 */
CompositeFunction::~CompositeFunction()
{
}

/**
 * Set the functions.
 * @param outsideFunction (input) Outside of CompositeFunction.
 * @param insideFunction (input) Inside of CompositeFunction.
 */
void
CompositeFunction::SetFunctions(
	MathFunction *outsideFunction,
	MathFunction *insideFunction)
{
	if(outsideFunction)
		m_Outside = outsideFunction;
	if(insideFunction)
		m_Inside = insideFunction;
}

/**
 * Virtual function to calculate a point for this fucntion.
 * @param x (input) x input value for this function.
 * @return Y value corresponding to the x input.
 */
TMathResult
CompositeFunction::CalculateY(
	double x,
	double *y)
{
	TMathResult status;
	double result = 0;

	if(m_Inside)
		status = m_Inside->CalculateY(x, &result);
	if(m_Outside && status)
		status = m_Outside->CalculateY(result, y);

	return status;
}

