/**
 * Title: MathSetting.h
 * Description: Object to provide optional epsilon and angleMode.
 * @author Mary Wyllie
 */

#ifndef MATHSETTING_H 
#define MATHSETTING_H 1

/**
 * Class for alternate epsilon and angleMode.
 * A pointer to this class can be passed as a parameter to any of the 
 * math classes to provide a local definition of the epsilon and 
 * angleMode. If not passed, these classes will use the static definitions
 * in Math class.
 */
class MathSetting
{

public:

	/**
 	 * Constructor.
 	 * @return None.
 	 */	
	MathSetting();

	/**
 	 * Constructor.
 	 * @param epsilon (input) How close is equal?
	 * @param isDegrees (input) Degrees (true) or Radians (false).
 	 * @return None.
 	 */	
	MathSetting(
		double epsilon, 
		bool isDegrees);

	/**
 	 * SetEpsilon
 	 * @param epsilon (input) How close is equal?
 	 * @return None.
 	 */	
	void 
	SetEpsilon(double epsilon) 
		{m_Epsilon = epsilon;};

	/**
 	 * GetEpsilon
 	 * @return epsilon How close is equal?
 	 */	
	double 
	GetEpsilon() 
		{return m_Epsilon;};

	/**
 	 * SetAngleMode 
 	 * @param isDegrees (input) Degrees (true) or radians (false).
 	 * @return None.
	 */
	void 
	SetAngleMode(bool isDegrees) 
		{m_IsDegrees = isDegrees;};

	/**
 	 * GetAngleMode 
 	 * @return isDegrees (input) Degrees (true) or radians (false).
	 */
	bool 
	GetAngleMode() 
		{return m_IsDegrees;};

private:

	/**
 	 * How close is equal?
 	 */	
	double m_Epsilon;

	/**
 	 * Degrees (true) or radians (false).
 	 */	
	bool m_IsDegrees;

} ; //end-class Math

#endif

