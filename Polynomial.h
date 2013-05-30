/**
 * Title: Polynomial
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "MathOperation.h"
#include <vector>

/**
 * Class to represent a polynomial function.
 * This is a convenience function to provide access to
 * a polynomial with a vector of coefficient to each power
 * of x.
 */
class
Polynomial :
	public MathOperation
{
public:

	/**
	 * Constructor.
	 */
	Polynomial();

	/**
	 * Constructor.
	 * @param coefficients (input) List of coefficients.
	 */
	Polynomial(
		std::vector<double>& coefficients);

	/**
	 * Destructor.
	 */
	~Polynomial();

	/**
	 * Gets the operator type.
	 * @return Operator type 
	 */
	virtual TOperatorClass
	GetOperatorClass()
		{return MATH_OPERATOR_COEFFICIENTS;};

	/**
	 * Set the coefficients.
	 * @param coefficients (input) List of coefficients.
	 */
	void
	SetCoefficients(
		std::vector<double> coefficients)
		{m_Coefficients = coefficients;};

	/**
	 * Get the coefficients.
	 * @return List of coefficients.
	 */
	virtual std::vector<double>*
	GetCoefficients()
		{return &m_Coefficients;};

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
	/**
	 * The vector of coefficents represents the coefficient
	 * for each power of x. For example, the 0th term represents the 
	 * constant, the 1st term represents the coefficient to x, etc.
	 * There is some waste here, as zeros are needed when there is
	 * no term.
	 */
	std::vector<double> m_Coefficients;

};

#endif

