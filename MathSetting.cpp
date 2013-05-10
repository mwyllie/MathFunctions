/**
 * Title: MathSetting.h 
 * Description: Object to provide optional epsilon and angleMode.
 * @author Mary Wyllie
 */

#include "MathSetting.h"

/**
 * Class for alternate epsilon and angleMode.
 * A pointer to this class can be passed as a parameter to any of the 3d 
 * math classes to provide a local definition of the epsilon and 
 * angleMode. If not passed, these classes will use the static definitions
 * in Math class.
*/

/**
 * Constructor.
 * @return None.
 */	
MathSetting::MathSetting() 
{
}

/**
 * Constructor.
 * @param epsilon (input) How close is equal?
 * @param isDegrees (input) Degrees (true) or Radians (false).
 * @return None.
 */	
MathSetting::MathSetting(
	double epsilon, 
	bool isDegrees) :
	m_Epsilon(epsilon),
	m_IsDegrees(isDegrees)
{
}
