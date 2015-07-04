#include "AgregarDialog.h"
#include "ui_AgregarDialog.h"

AgregarDialog::AgregarDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AgregarDialog)
{
    ui->setupUi(this);
}

AgregarDialog::~AgregarDialog()
{
    delete ui;
}

Empleado AgregarDialog::getEmpleado() const
{
    return mEmpleado;
}

void AgregarDialog::on_buttonBox_accepted()
{
    mEmpleado.setId(ui->idLineEdit->text());
    mEmpleado.setNombre(ui->nombreLineEdit->text());
    mEmpleado.setEdad(ui->edadLineEdit->text());
    mEmpleado.setSalario(ui->salarioLineEdit->text());
    accept();
}

void AgregarDialog::on_buttonBox_rejected()
{
    reject();
}
