#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SettingsDialog)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

	connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::on_dialogAccepted);
	connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::close);
}

SettingsDialog::~SettingsDialog()
{
	delete ui;
}

void SettingsDialog::setValues(double x0, double y0, double rx, double ry)
{
	ui->editX0->setText(QString::number(x0, 'f', 2));
	ui->editY0->setText(QString::number(y0, 'f', 2));
	ui->editRx->setText(QString::number(rx, 'f', 2));
	ui->editRy->setText(QString::number(ry, 'f', 2));

	ui->editX0->setFocus();
}

void SettingsDialog::on_dialogAccepted()
{
	requestUpdate(ui->editX0->text().toDouble(), ui->editY0->text().toDouble(), ui->editRx->text().toDouble(), ui->editRy->text().toDouble());
	close();
}
