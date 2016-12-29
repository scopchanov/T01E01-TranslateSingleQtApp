#include "ValueCalculator.h"

ValueCalculator::ValueCalculator(QObject *parent) : QObject(parent)
{

}

double ValueCalculator::x0() const
{
	return m_x0;
}

void ValueCalculator::setX0(double x0)
{
	m_x0 = x0;
}

double ValueCalculator::y0() const
{
	return m_y0;
}

void ValueCalculator::setY0(double y0)
{
	m_y0 = y0;
}

double ValueCalculator::rx() const
{
	return m_rx;
}

void ValueCalculator::setRx(double rx)
{
	m_rx = rx;
}

double ValueCalculator::ry() const
{
	return m_ry;
}

void ValueCalculator::setRy(double ry)
{
	m_ry = ry;
}

double ValueCalculator::calculateX(double angle) const
{
	return m_x0 + m_rx*cos(angle);
}

double ValueCalculator::calculateY(double angle) const
{
	return m_y0 + m_ry*sin(angle);
}

double ValueCalculator::valueToAngle(int value) const
{
	return value*2*m_pi/100;
}

QString ValueCalculator::firstRowName() const
{
	return "X coordinate";
}

QString ValueCalculator::secondRowName() const
{
	return "Y coordinate";
}
