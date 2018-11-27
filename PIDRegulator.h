#include "Arduino.h"
#include "Timer.h"

using namespace std;

class PIDRegulator
{

public:
	PIDRegulator(float pK, float dK, float iK);
	void set_k(float pK, float dK, float iK);
	int apply(float to_set, float current);
	void set_pk(float pk);
	void set_ik(float ik);
	void set_dk(float dk);
private:
	float m_error_old = 0;
	float m_integral = 0;
	float m_pK = 0;
	float m_dK = 0;
	float m_iK = 0;
	Timer m_timer;
};
