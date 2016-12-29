#include "EllipseCalculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EllipseCalculator w;
	w.show();

	return a.exec();
}
