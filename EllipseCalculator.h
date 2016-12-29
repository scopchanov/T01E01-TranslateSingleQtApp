#ifndef ELLIPSECALCULATOR_H
#define ELLIPSECALCULATOR_H

#include <QMainWindow>
#include "SettingsDialog.h"
#include "ValueCalculator.h"

namespace Ui {
class EllipseCalculator;
}

class EllipseCalculator : public QMainWindow
{
	Q_OBJECT
public:
	explicit EllipseCalculator(QWidget *parent = 0);
	~EllipseCalculator();

private:
	void refreshTable();

	Ui::EllipseCalculator *ui;

	ValueCalculator *m_calculator;

private slots:
	void on_btnSettings_clicked();
	void on_updateRequested(double x0, double y0, double rx, double ry);

	void on_horizontalSlider_valueChanged(int);
};

#endif // ELLIPSECALCULATOR_H
