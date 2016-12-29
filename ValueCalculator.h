#ifndef VALUECALCULATOR_H
#define VALUECALCULATOR_H

#include <QObject>

class ValueCalculator : public QObject
{
	Q_OBJECT
public:
	explicit ValueCalculator(QObject *parent = 0);

	double x0() const;
	void setX0(double x0);
	double y0() const;
	void setY0(double y0);
	double rx() const;
	void setRx(double rx);
	double ry() const;
	void setRy(double ry);

	double calculateX(double angle) const;
	double calculateY(double angle) const;
	double valueToAngle(int value) const;

	QString firstRowName() const;
	QString secondRowName() const;

private:
	const double m_pi = 3.141592;
	double m_x0 = 0, m_y0 = 0, m_rx = 20, m_ry = 20;
};

#endif // VALUECALCULATOR_H
