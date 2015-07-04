#ifndef AGREGARDIALOG_H
#define AGREGARDIALOG_H

#include <QDialog>
#include "Empleado.h"

namespace Ui
{
class AgregarDialog;
}

class AgregarDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AgregarDialog(QWidget *parent = nullptr);
    ~AgregarDialog();
    Empleado getEmpleado() const;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::AgregarDialog *ui;
    Empleado mEmpleado;
};

#endif // AGREGARDIALOG_H
