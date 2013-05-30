MathFunctions
=============

C++ classes to implement complex mathematical functions.

Function definitions are created with MathFunction as an interface class.
The following functions are available through MathFunction:

	MATH_ADD              (Also available with "+" operator)
	MATH_SUBTRACT         (Also available with "-" operator)
	MATH_MULTIPLY         (Also available with "*" operator)
	MATH_DIVIDE           (Also available with "/" operator)
	MATH_POWER            (Also available with "^" operator)
	MATH_POLYNOMIAL
	MATH_COMPOSITE        (Also available with "()" operator)
	MATH_SIN
	MATH_COS
	MATH_TAN
	MATH_COT
	MATH_SEC
	MATH_CSC
	MATH_LOG
	MATH_LN

These operations may be applied to to a single mathematical operation or
combined by using MathFunction classes as operands, or combine functions
with MATH_COMPOSITE.  Details of function creation are outlined below
in CREATING FUNCTIONS.

For details on how to use the functions, see section USING FUNCTIONS following
the create descriptions.


CREATING FUNCTIONS
------------------

	MATH_ADD | MATH_SUBTRACT | MATH_MULTIPLY | MATH_DIVIDE
	---------------------------------------------------------------
	MathFunction
	MathFunction(
		MATH_ADD | MATH_SUBTRACT | MATH_MULTIPLY | MATH_DIVIDE
		MathFunction* lhs,          /* Left hand function */
		MathFunction* rhs);         /* Right hand function */

	MathFunction
	MathFunction(
		MATH_ADD | MATH_SUBTRACT | MATH_MULTIPLY | MATH_DIVIDE
		double leftConstant,         /* Left hand value */
		MathFunction* rhs);          /* Right hand function */


	MathFunction
	MathFunction(
		MATH_ADD | MATH_SUBTRACT | MATH_MULTIPLY | MATH_DIVIDE
		MathFunction* lhs,           /* Left hand function */
		double rightConstant);       /* Right hand value */


	Examples:
	---------
	// Create some functions to operate on.
	MathFunction sinX(MATH_SIN);
	MathFunction cosX(MATH_COS);

	// Add with a call.
	MathFunction addTrig(MATH_ADD, &sinX, &cosX);

	// Subtract with an operator
	MathFunction subtractTrig = sinX - cosX;

	// Mutiply with a call.
	MathFunction multTrig(MATH_MULTIPLY, 2, &sinX);

	// Divide with an operator.
	MathFunction divTrig = sinX / 2;



	MATH_POWER
	---------------------------------------------------------------
	MathFunction
	MathFunction(
		MATH_POWER, 
		MathFunction* baseFunction,          /* Base function */
		MathFunction* expFunction);          /* Exponent function */


	MathFunction
	MathFunction(
		MATH_POWER, 
		double baseValue,                    /* Base value */
		MathFunction* expFunction);          /* Exponent function */


	MathFunction
	MathFunction(
		MATH_POWER, 
		MathFunction* baseFunction,           /* Base function */
		double expValue);                     /* Exponent value */


	Examples:
	---------
	// Create some functions to operate on.
	MathFunction sinX(MATH_SIN);
	MathFunction cosX(MATH_SIN);

	MathFunction sinXraisedToCosX(MATH_POWER, &sinX, &cosX);
	MathFunction twoToSinX(MATH_POWER, 2, &sinX);
	MathFunction sinSquared = sinX^2;



	MATH_POLYNOMIAL
	---------------------------------------------------------------
	MathFunction
	MathFunction(
		MATH_POLYNOMIAL,
		std::vector<double> coeffs);   /* Vector of coefficents to x^i term */


	Examples:
	---------
	// Create a polynomial 3x^2 + 2x + 1
	std::vector<double> coeffs;
	coeffs.push_back(1);
	coeffs.push_back(2);
	coeffs.push_back(3);
	MathFunction poly(MATH_POLYNOMIAL, coeffs);

	// Now create a polynomial 3x^2 + 1
	coeffs[1] = 0;
	MathFunction poly2(MATH_POLYNOMIAL, coeffs);



	MATH_COMPOSITE
	---------------------------------------------------------------
	MathFunction
	MathFunction(
		MATH_COMPOSITE, 
		MathFunction* outsideFunction, 
		MathFunction* insideFunction);

	Examples:
	---------
	// Create a polynomial 2(pi)x - (pi)/2
	std::vector<double> coeffs;
	coeffs.push_back(MATH_PI_OVER_2);
	coeffs.push_back(MATH_2PI);
	MathFunction poly(MATH_POLYNOMIAL, coeffs);
	MathFunction sin(MATH_SIN);
	sin.SetAngleMode(MATH_ANGLES_IN_RADIANS);

	// Now create the composite function sin(2(pi)x - (pi)/2).
	MathFunction comp(MATH_COMPOSITE, &sin, &poly);
	// Or
	MathFunction comp = sin(poly);



	MATH_SIN | MATH_COS | MATH_TAN | MATH_COT | MATH_SEC | MATH_CSC
	---------------------------------------------------------------
	MathFunction
	MathFunction(
		MATH_SIN | MATH_COS | MATH_TAN | 
		MATH_COT | MATH_SEC | MATH_CSC)

	Examples:
	---------
	// Create a polynomial 2(pi)x - (pi)/2
	std::vector<double> coeffs;
	coeffs.push_back(MATH_PI_OVER_2);
	coeffs.push_back(MATH_2PI);
	MathFunction poly(MATH_POLYNOMIAL, coeffs);
	MathFunction sin(MATH_SIN);
	
	// Now create the composite function sin(2(pi)x - (pi)/2).
	MathFunction comp(MATH_COMPOSITE, &sin, &poly);
	comp.SetAngleMode(MATH_ANGLES_IN_RADIANS);



	MATH_LOG
	---------------------------------------------------------------
	MathFunction
	MathFunction(
		MATH_LOG, 
		double base = 10.0);


	Examples:
	---------
	// Create a log base 10 of x function.
	MathFunction log10(MATH_LOG);
	// Create a log base 2 of x function.
	MathFunction log2(MATH_LOG, 2.0);



	MATH_LN
	---------------------------------------------------------------
	MathFunction
	MathFunction(MATH_LN);

	Examples:
	---------
	// Create a ln function.
	MathFunction ln(MATH_LN);



USING FUNCTIONS
---------------

Calculating functional values
-----------------------------

	CalculateY
	-----------
	Calculate the Y value for a given X for this function.
	param x (input) x input value for this function.
	param y (output) y output value for this function.
	return TMathResult - One of MATH_SUCCESS or MATH_UNDEFINED (such as /0)

	TMathResult
	MathFunction::CalculateY(
		double x
		double *y)

	CalculateY
	-----------
	Calculate the Y value for a given X for this function.
	pt (input/output) x input value for this function.
	y coordinate is output for this function.
	return TMathResult - One of MATH_SUCCESS or MATH_UNDEFINED (such as /0)

	TMathResult
	MathFunction::CalculateY(
		Point *pt);


Controlling Computational Parameters
-------------------------------------
A MathSetting class is used to indicate an Epsilon and AngleMode parameter
described as follows:

- Epsilon
This value is used to manage computed floating point values that will not 
match exactly after computations have been done. The epsilon value indicates 
that two parameters within this epsilon value will be judged to be equal. 
Internally checks for 0 values will actually be values within epsilon of zero.

- AngleMode
Indicates that angles will be represented as degrees (true) or radians (false).
Use MATH_ANGLES_IN_DEGREES and MATH_ANGLES_IN_RADIANS for calls.

Each of the parameters above can be set globally, or on the individual 
MathFunction object. To set globally, use:


Global Settings
---------------
	Set global Epsilon value.
	epsilon (input) Value which defines how close is equal.

	static void 
	SetGlobalEpsilon(double epsilon);


	Set global angle mode value - radians (f)/degrees(t)).
	angelMode (input) Angles are in degrees or radians.
	Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.

	static void 
	SetGlobalAngleMode(bool angleMode);


MathFunction Object Settings
----------------------------
	Set Epsilon value for this object.
	epsilon (input) Value which defines how close is equal.

	void 
	MathFunction::SetEpsilon(double epsilon);


	Set angle mode value for this object - radians (f)/degrees(t)).
	angelMode (input) Angles are in degrees or radians.
	Use MATH_ANGLES_IN_DEGREES | MATH_ANGLES_IN_RADIANS.

	void 
	MathFunction::SetGlobalAngleMode(bool angleMode);




---------------------------------------------------------------
To Do: 
- Add ddx for derivative to each MathOperation.
- Add method for convenience to produce an entire set of points.
- Transformations applied to functions.
- Make calls more robust with parameter checks.

