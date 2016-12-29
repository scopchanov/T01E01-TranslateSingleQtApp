#include "EllipseCalculator.h"
#include "ui_EllipseCalculator.h"

EllipseCalculator::EllipseCalculator(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::EllipseCalculator)
{
	ui->setupUi(this);

	m_calculator = new ValueCalculator(this);
	ui->horizontalSlider->setValue(10);
}

EllipseCalculator::~EllipseCalculator()
{
	delete ui;
}

void EllipseCalculator::refreshTable()
{
	QTableWidgetItem *item;
	float angle = m_calculator->valueToAngle(ui->horizontalSlider->value());

	ui->tableWidget->clearContents();

	item = new QTableWidgetItem(m_calculator->firstRowName());
	item->setFlags(Qt::NoItemFlags);
	ui->tableWidget->setItem(0, 0, item);

	item = new QTableWidgetItem(QString::number(m_calculator->calculateX(angle), 'f', 2));
	item->setTextAlignment(Qt::AlignCenter);
	item->setFlags(Qt::NoItemFlags);
	ui->tableWidget->setItem(0, 1, item);

	item = new QTableWidgetItem(m_calculator->secondRowName());
	item->setFlags(Qt::NoItemFlags);
	ui->tableWidget->setItem(1, 0, item);

	item = new QTableWidgetItem(QString::number(m_calculator->calculateY(angle), 'f', 2));
	item->setTextAlignment(Qt::AlignCenter);
	item->setFlags(Qt::NoItemFlags);
	ui->tableWidget->setItem(1, 1, item);
}

void EllipseCalculator::on_btnSettings_clicked()
{
	SettingsDialog *dialog = new SettingsDialog(this);

	dialog->setValues(m_calculator->x0(), m_calculator->y0(), m_calculator->rx(), m_calculator->ry());
	connect(dialog, &SettingsDialog::requestUpdate, this, &EllipseCalculator::on_updateRequested);
	dialog->exec();
}

void EllipseCalculator::on_updateRequested(double x0, double y0, double rx, double ry)
{
	m_calculator->setX0(x0);
	m_calculator->setY0(y0);
	m_calculator->setRx(rx);
	m_calculator->setRy(ry);

	refreshTable();
}

void EllipseCalculator::on_horizontalSlider_valueChanged(int)
{
	refreshTable();
}
