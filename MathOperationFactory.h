/**
 * Title: MathOperationFactory.h
 * Description: Math operation factory for creation of various math functions.
 * @author Mary Wyllie
 */

#ifndef MATHOPERATIONFACTORY_H
#define MATHOPERATIONFACTORY_H

#include <vector>
#include "MathDefs.h"

class MathOperation;
class MathFunction;

/**
 * Base class for a mathematical operation.
 */
class
MathOperationFactory
{
public:
	/**
	 * Constructor
	 */
	MathOperationFactory() {};

	/**
	 * This method serves as a factory for the various math
	 * operations. All possible parameters are included to
	 * provide a single signature.
	 * @param type (input) Which math operation.
	 * @param lhs (input) Left side function.
	 * @param rhs (input) Right side function.
	 * @param leftConstant (input) Left value.
	 * @param rightValue (input) Right value.
	 * @param coefficients (input) Coefficients for polynomial.
	 */
	MathOperation*
	CreateMathOperation(
		TOperatorType type,
		MathFunction *lhs,
		MathFunction *rhs,
		double *leftConstant,
		double *rightConstant,
		std::vector<double> *coefficients);


protected:

};

#endif

