#include "PIDRegulator.h"

PIDRegulator::PIDRegulator(float pK, float iK, float dK)
{
	m_pK = pK;
	m_dK = dK;
	m_iK = iK;
	m_timer.start();
}

int PIDRegulator::apply(float to_set, float current)
{
	if (is_first)
	{
		m_timer.start();
		is_first = false;
	}
	float result;
	float integral_part;
	float proportional_part;
	float differential_part;
	float time_elaplsed = (m_timer.elapsed() / 1000.00) < 0.0000001 ?  0.000001 : m_timer.elapsed() / 1000.00;

	m_timer.stop();

	float error = to_set - current;

	m_integral = constrain(error * time_elaplsed + m_integral, -100, 100);

	proportional_part = m_pK * error;

	integral_part = m_iK * m_integral;

	differential_part = m_dK * (error - m_error_old) / time_elaplsed;

	result = proportional_part + integral_part + differential_part;

	m_error_old = error;

	m_timer.start();
	result = constrain(result, -100, 100);
	return result;
}

void PIDRegulator::set_k(float pK, float iK, float dK)
{

	m_pK = pK;
	m_dK = iK;
	m_iK = dK;
}

void PIDRegulator::set_pk(float pK)
{
	m_pK = pK;
}

void PIDRegulator::set_ik(float iK)
{
	m_iK = iK;
}

void PIDRegulator::set_dk(float dK)
{
	m_dK = dK;
}