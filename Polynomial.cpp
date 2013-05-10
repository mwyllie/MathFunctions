/**
 * Title: Polynomial
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#include "Polynomial.h"
#include "MathFunction.h"
#include <math.h>

/**
 * Class to represent a polynomial function.
 * This is a convenience function to provide access to
 * a polynomial with a vector of coefficient to each power
 * of x.
 */

/**
 * Constructor.
 */
Polynomial::Polynomial()
{
}

/**
 * Constructor.
 * @param coefficients (input) List of coefficients.
 */
Polynomial::Polynomial(
	std::vector<double>& coefficients)
{
	m_Coefficients = coefficients;
}


/**
 * Constructor.
 */
Polynomial::~Polynomial()
{
}

/**
 * Virtual function to calculate a point for this fucntion.
 * @param x (input) x input value for this function.
 * @return Y value corresponding to the x input.
 */
TMathResult
Polynomial::CalculateY(
	double x,
	double *y)
{
	TMathResult status = MATH_SUCCESS;
	double result = 0;

	for(int i = 0; i < m_Coefficients.size(); i++)
	{
		if(! m_Coefficients[i]) continue;

		double power = 1;
		if(i == 1) power = x;
		if(i > 1) power = pow(x, i);
		result += m_Coefficients[i] * power;
	}
	*y = result;
	return status;
}

