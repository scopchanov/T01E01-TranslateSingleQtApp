#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SettingsDialog(QWidget *parent = 0);
	~SettingsDialog();

	void setValues(double x0, double y0, double rx, double ry);

private:
	Ui::SettingsDialog *ui;

private slots:
	void on_dialogAccepted();

signals:
	void requestUpdate(double, double, double, double);
};

#endif // SETTINGSDIALOG_H
