/**
 * Title: MathFunction
 * Base class for a mathematical function.
 * @author Mary Wyllie
 */

#include "MathFunction.h"
#include "MathOperationFactory.h"
#include "MathOperation.h"

/**
 * Base class for a mathematical function.
 */

/**
 * Constructor.
 */
MathFunction::MathFunction()
{
	m_MathSetting = NULL;
	m_MathOperation = NULL;
}

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
MathFunction::MathFunction(
	TOperatorType type)
{
	m_MathOperation = CreateMathOperation(type, NULL, NULL, NULL, NULL, NULL);
}	

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
MathFunction::MathFunction(
	TOperatorType type,
	MathFunction* lhs,
	MathFunction* rhs)
{
	m_MathOperation = CreateMathOperation(type, lhs, rhs, NULL, NULL, NULL);
}	

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
MathFunction::MathFunction(
	TOperatorType type,
	double leftConstant,
	MathFunction* rhs)
{
	m_MathOperation = CreateMathOperation(type, NULL, rhs, 
		&leftConstant, 0, NULL);
}	
	

/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
MathFunction::MathFunction(
	TOperatorType type,
	MathFunction* lhs,
	double rightConstant)
{
	m_MathOperation = CreateMathOperation(type, lhs, NULL, 
		0, &rightConstant, NULL);
}	


/**
 * Constructor.
 * @param oper (input) What operator is used.
 */
MathFunction::MathFunction(
	TOperatorType type,
	std::vector<double> coeffs)
{
	m_MathOperation = CreateMathOperation(type, NULL, NULL, 
		0, 0, &coeffs);
}

/**
 * Copy Constructor.
 * @param rhs (input) What function is copied.
 */
MathFunction::MathFunction(
	const MathFunction& function)
{
	m_MathOperation = CreateMathOperation(function.m_MathOperation);

	if(function.m_MathSetting)
	{
		MathBase::SetEpsilon( function.GetEpsilon() );
		MathBase::SetAngleMode( function.GetAngleMode() );
		m_MathOperation->SetMathSetting(GetMathSetting());
	}
}

/**
 * Destructor.
 * Note that MathFunction and MathOperation share a setting.
 * MathFunction will be responsible for deleting it on destructor.
 */
MathFunction::~MathFunction()
{
	if(m_MathOperation) delete m_MathOperation;
	ClearSetting(true);
}

/**
 * Set Epsilon value for this object.
 * @param epsilon (input) Value which defines how close is equal.
 */
void 
MathFunction::SetEpsilon(double epsilon)
{
	bool setChild = false;
	if(!GetMathSetting())
	{
		setChild = true;
	}
	MathBase::SetEpsilon(epsilon);
	if(setChild && m_MathOperation)
	{
		m_MathOperation->SetMathSetting(GetMathSetting());
	}
}

/**
 * Set angle mode value for this object - radians (f)/degrees(t)).
 * @param angelMode (input) Angles are in degrees or radians.
 * Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.
 */
void 
MathFunction::SetAngleMode(
	bool angleMode)
{
	bool setChild = false;
	if(!GetMathSetting())
	{
		setChild = true;
	}
	MathBase::SetAngleMode(angleMode);
	if(setChild && m_MathOperation)
	{
		m_MathOperation->SetMathSetting(GetMathSetting());
	}
}

/**
 * Assignment operator.
 * @param rhs (input) A function from which to assign.
 * @return New function.
 */
MathFunction& 
MathFunction::operator=(const MathFunction& rhs)
{
	if(this == &rhs)
	{
		return (*this);
	}
	m_MathOperation = CreateMathOperation(rhs.m_MathOperation);

	if(rhs.m_MathSetting)
	{
		MathBase::SetEpsilon( rhs.GetEpsilon() );
		MathBase::SetAngleMode( rhs.GetAngleMode() );
		m_MathOperation->SetMathSetting(GetMathSetting());
	}
    return (*this);
}

/**
 * Allow operator to create added functions.
 * e.g. MathFunction newFunc = func1 + func2;
 * @param value (input) A constant to add to this function.
 * @return New function.
 */
MathFunction
MathFunction::operator+(MathFunction& rhs)
{
	MathFunction oper(MATH_ADD, this, &rhs);
	return oper;
}

/**
 * Allow operator to create added functions.
 * e.g. MathFunction newFunc = func1 + 10;
 * @param value (input) A constant to add to this value.
 * @return New function.
 */
MathFunction
MathFunction::operator+(const double value)
{
	MathFunction oper(MATH_ADD, this, value);
	return oper;
}

/**
 * Allow operator to create subtracted functions.
 * e.g. MathFunction newFunc = func1 - func2;
 * @param rhs (input) A function to subtract from this function.
 * @return New function.
 */
MathFunction 
MathFunction::operator-(MathFunction& rhs)
{
	MathFunction oper(MATH_SUBTRACT, this, &rhs);
	return oper;
}

/**
 * Allow operator to create subtracted functions.
 * e.g. MathFunction newFunc = func1 - 10;
 * @param value (input) A constant to subtract from this value.
 * @return New function.
 */
MathFunction 
MathFunction::operator-(const double value)
{
	MathFunction oper(MATH_SUBTRACT, this, value);
	return oper;
}

/**
 * Allow operator to create multiplied functions.
 * e.g. MathFunction newFunc = func1 * func2;
 * @param rhs (input) A function to multiply by this function.
 */
MathFunction 
MathFunction::operator*(MathFunction& rhs)
{
	MathFunction oper(MATH_MULTIPLY, this, &rhs);
	return oper;
}

/**
 * Allow operator to create multiplied functions.
 * e.g. MathFunction newFunc = func1 * 10;
 * @param value (input) A constant to multiply by this value.
 * @return New function.
 */
MathFunction 
MathFunction::operator*(const double value)
{
	MathFunction oper(MATH_MULTIPLY, this, value);
	return oper;
}

/**
 * Allow operator to create divided functions.
 * e.g. MathFunction newFunc = func1 / func2;
 * @param rhs (input) A function to divide by this function.
 * @return New function.
 */
MathFunction 
MathFunction::operator/(MathFunction& rhs)
{
	MathFunction oper(MATH_DIVIDE, this, &rhs);
	return oper;
}

/**
 * Allow operator to create divided functions.
 * e.g. MathFunction newFunc = func1 / 10;
 * @param value (input) A constant to divide by this value.
 * @return New function.
 */
MathFunction 
MathFunction::operator/(const double value)
{
	MathFunction oper(MATH_DIVIDE, this, value);
	return oper;
}

/**
 * Allow operator to create functions raised to powers.
 * e.g. MathFunction newFunc = func1 ^ func2;
 * @param rhs (input) A function to raise to this function.
 * @return New function.
 */
MathFunction 
MathFunction::operator^(MathFunction& rhs)
{
	MathFunction oper(MATH_POWER, this, &rhs);
	return oper;
}

/**
 * Allow operator to create functions raised to powers.
 * e.g. MathFunction newFunc = func1 ^ 22;
 * @param value (input) A constant to raise to this value.
 * @return New function.
 */
MathFunction 
MathFunction::operator^(const double value)
{
	MathFunction oper(MATH_POWER, this, value);
	return oper;
}

/**
 * Allow operator to create composite functions.
 * e.g. MathFunction newFunc = outFunc(inFunc);
 * @param inside (input) The inside of the composite.
 * @return New function.
 */
MathFunction 
MathFunction::operator()(MathFunction& inside)
{
	MathFunction comp(MATH_COMPOSITE, this, &inside);
return comp;
}

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
MathFunction::CreateMathOperation(
	TOperatorType type,
	MathFunction *lhs,
	MathFunction *rhs,
	double *leftConstant,
	double *rightConstant,
	std::vector<double> *coefficients)
{
	MathOperationFactory factory;
	MathOperation* operation = factory.CreateMathOperation(
		type,
		lhs, rhs,
		leftConstant, rightConstant,
		coefficients);
	return operation;
}

/**
 * This method calls the factory for the various math
 * operations serving as a copy for the math operation.
 * @param mathOperation (input)
 */
MathOperation*
MathFunction::CreateMathOperation(
	MathOperation* mathOper)
{
	MathOperationFactory factory;
	MathOperation* operation = factory.CreateMathOperation(
		mathOper->GetOperatorType(),
		mathOper->GetLhs(), 
		mathOper->GetRhs(),
		mathOper->GetLeftConstant(),
		mathOper->GetRightConstant(),
		mathOper->GetCoefficients());
	return operation;
}


/**
 * Interface function to calculate a point for this function.
 * @param x (input) x input value for this function.
 * @param y (output) y output value for this function.
 * @return TMathResult for successful calculation (or not).
 */
TMathResult
MathFunction::CalculateY(
	double x, double *y)
{
	TMathResult status = MATH_UNDEFINED;
	if(m_MathOperation)
		status = m_MathOperation->CalculateY(x, y);
	return status;
}

/**
 * Interface function to calculate a point for this function.
 * e.g. MathFunction newFunc = func1 + func2;
 * @param pt (input/output) x input value for this function.
 * y coordinate is output for this function.
 * @return TMathResult for successful calculation (or not).
 */
TMathResult
MathFunction::CalculateY(
	Point *pt)
{
	TMathResult status = MATH_UNDEFINED;
	double y;
	
	if(m_MathOperation && pt)
	{
		status = m_MathOperation->CalculateY(pt->GetX(), &y);
		if(status == MATH_SUCCESS)
		{
			pt->SetY(y);
		}
	}
	return status;
}

