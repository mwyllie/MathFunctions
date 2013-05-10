/**
 * Title: MathFunction
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#ifndef MATHFUNCTION_H
#define MATHFUNCTION_H

#include <string>
#include <vector>
#include "MathBase.h"
#include "Point.h"
#include "MathOperation.h"

class MathFunction;

/**
 * Interface class for a mathematical function.
 * Specific functions will be defined with MathOperation class
 * which is a member variable to this class.
 */
class
MathFunction :
	public MathBase
{
public:

	/**
	 * Constructor.
	 */
	MathFunction();

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	MathFunction(
		TOperatorType type);

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	MathFunction(
		TOperatorType type,
		MathFunction* lhs,
		MathFunction* rhs = NULL);

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	MathFunction(
		TOperatorType type,
		double leftConstant,
		MathFunction* rhs = NULL);

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	MathFunction(
		TOperatorType type,
		MathFunction* lhs,
		double rightConstant);

	/**
	 * Constructor.
	 * @param oper (input) What operator is used.
	 */
	MathFunction(
		TOperatorType type,
		std::vector<double> coeffs);

	/**
	 * Destructor.
	 */
	~MathFunction();

	/**
	 * Set the epsilon and angle mode data.
	 * @param setting (input) Epsilon and angle mode data.
	 */
	void
	SetMathSetting(
		MathSetting *setting)
		{m_MathSetting = setting;};

	/**
	 * Set the epsilon and angle mode data.
	 * @return Pointer to the math data.
	 */
	MathSetting*
	GetMathSetting()
		{return m_MathSetting;};

	/**
 	 * Set Epsilon value for this object.
	 * @param epsilon (input) Value which defines how close is equal.
 	 */
	virtual void 
	SetEpsilon(double epsilon);

	/**
 	 * Set angle mode value for this object - radians (f)/degrees(t)).
	 * @param angelMode (input) Angles are in degrees or radians.
	 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 	 */
	virtual void 
	SetAngleMode(
		bool angleMode);

	/**
	 * Allow operator to create added functions.
	 * e.g. MathFunction newFunc = func1 + 10;
	 * @param rhs (input) A function to add to this function.
	 * @return New function.
	 */
	MathFunction 
	operator+(MathFunction& rhs);

	/**
	 * Allow operator to create added functions.
	 * e.g. MathFunction newFunc = func1 + 10;
	 * @param value (input) A constant to add to this value.
	 * @return New function.
	 */
	MathFunction 
	operator+(const double value);

	/**
	 * Allow operator to create subtracted functions.
	 * e.g. MathFunction newFunc = func1 - func2;
	 * @param rhs (input) A function to subtract from this function.
	 * @return New function.
	 */
	MathFunction 
	operator-(MathFunction& rhs);

	/**
	 * Allow operator to create subtracted functions.
	 * e.g. MathFunction newFunc = func1 - 10;
	 * @param value (input) A constant to subtract from this value.
	 * @return New function.
	 */
	MathFunction 
	operator-(const double value);

	/**
	 * Allow operator to create multiplied functions.
	 * e.g. MathFunction newFunc = func1 * func2;
	 * @param rhs (input) A function to multiply by this function.
	 */
	MathFunction 
	operator*(MathFunction& rhs);

	/**
	 * Allow operator to create multiplied functions.
	 * e.g. MathFunction newFunc = func1 * 10;
	 * @param value (input) A constant to multiply by this value.
	 * @return New function.
	 */
	MathFunction 
	operator*(const double value);

	/**
	 * Allow operator to create divided functions.
	 * e.g. MathFunction newFunc = func1 / func2;
	 * @param rhs (input) A function to divide by this function.
	 * @return New function.
	 */
	MathFunction 
	operator/(MathFunction& rhs);

	/**
	 * Allow operator to create divided functions.
	 * e.g. MathFunction newFunc = func1 / 10;
	 * @param value (input) A constant to divide by this value.
	 * @return New function.
	 */
	MathFunction 
	operator/(const double value);

	/**
	 * Allow operator to create functions raised to powers.
	 * e.g. MathFunction newFunc = func1 ^ func2;
	 * @param rhs (input) A function to raise to this function.
	 * @return New function.
	 */
	MathFunction 
	operator^(MathFunction& rhs);

	/**
	 * Allow operator to create functions raised to powers.
	 * e.g. MathFunction newFunc = func1 ^ 22;
	 * @param value (input) A constant to raise to this value.
	 * @return New function.
	 */
	MathFunction 
	operator^(const double value);

	/**
	 * Interface function to calculate a point for this function.
	 * @param x (input) x input value for this function.
	 * @param y (output) y output value for this function.
	 * @return TMathResult for successful calculation (or not).
	 */
	virtual TMathResult
	CalculateY(
		double x, double *y);

	/**
	 * Interface function to calculate a point for this function.
	 * e.g. MathFunction newFunc = func1 + func2;
	 * @param pt (input/output) x input value for this function.
	 * y coordinate is output for this function.
	 * @return TMathResult for successful calculation (or not).
	 */
	virtual TMathResult
	CalculateY(
		Point *pt);


protected:

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
		double leftConstant,
		double rightConstant,
		std::vector<double> *coefficients);
	
protected:
	//----------------------------------
	// Math operation to be performed.
	//----------------------------------
	MathOperation *m_MathOperation;
};

#endif
