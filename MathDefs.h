/**
 * Title: MathDefs.h
 * Header file for definitions common to the MathFunction classes.
 * @author "Mary Wyllie"
 */

#ifndef MATHDEFS_H
#define MATHDEFS_H

//-----------------------
// Numerical definitions
//-----------------------
const double MATH_PI = 3.141592653589793;
const double MATH_2PI = (2.0 * MATH_PI);
const double MATH_PI_OVER_2 = MATH_2PI;
const double MATH_PI_OVER_180 = (MATH_PI / 180.0);
const double MATH_180_OVER_PI = (180.0 / MATH_PI);
const double MATH_E = 2.718281828459045;

/**
 * Some common trig values for performance.
 */
const double MATH_SIN_45 = 0.707106781186547524401;
const double MATH_COS_45 = 0.707106781186547524401;
const double MATH_SIN_135 = MATH_SIN_45;
const double MATH_COS_135 = - MATH_SIN_45;
const double MATH_SIN_225 = - MATH_SIN_45;
const double MATH_COS_225 = - MATH_SIN_45;
const double MATH_SIN_315 = - MATH_SIN_45;
const double MATH_COS_315 = MATH_SIN_45;

/**
 * Angles are specified in degrees or radians.
 */
const bool MATH_ANGLES_IN_DEGREES = true;
const bool MATH_ANGLES_IN_RADIANS = false;

typedef enum TMathResult
{
	MATH_UNDEFINED = -1,
	MATH_SUCCESS = 1
} TMathResult;

typedef enum TOperatorType
{
	MATH_ADD = 0,
	MATH_SUBTRACT,
	MATH_MULTIPLY,
	MATH_DIVIDE,
	MATH_POWER,
	MATH_POLYNOMIAL,
	MATH_COMPOSITE,
	MATH_SIN,
	MATH_COS,
	MATH_TAN,
	MATH_COT,
	MATH_SEC,
	MATH_CSC,
	MATH_LOG,
	MATH_LN
} TOperatorType;

#endif
