#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AgregarDialog.h"
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList titles { "ID", "Nombre", "Edad", "Salario" };
    ui->tableWidget->setColumnCount(titles.size());
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    auto filename = QFileDialog::getOpenFileName(this, "Abrir datos",
                                                 QDir::rootPath(),
                                                 "XML file (*.xml)");
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root = doc.firstChild().toElement();
    auto ix = root.firstChild().toElement();
    while (!ix.isNull()) {
        auto id = ix.attribute("id");
        auto nombre = ix.firstChild().toElement().text();
        auto edad = ix.firstChild().nextSibling().toElement().text();
        auto salario = ix.firstChild().nextSibling().nextSibling().toElement()
                .text();
        agregaEmpleado(Empleado(id, nombre, edad, salario));
        ix = ix.nextSibling().toElement();
    }
}

void MainWindow::on_actionGuardar_como_triggered()
{
    auto filename = QFileDialog::getSaveFileName(this, "Guardar datos",
                                                 QDir::rootPath(),
                                                 "XML file (*.xml)");
    if (filename.isEmpty()) {
        return;
    }
    QDomDocument doc;
    auto root = doc.createElement("empleados");
    doc.appendChild(root);
    const int rowCount = ui->tableWidget->rowCount();
    for (int ix = 0; ix < rowCount; ++ix) {
        Empleado empleado(ui->tableWidget->item(ix, ID)->text(),
                ui->tableWidget->item(ix, NOMBRE)->text(),
                ui->tableWidget->item(ix, EDAD)->text(),
                ui->tableWidget->item(ix, SALARIO)->text());
        auto eEmpleado = doc.createElement("empleado");
        eEmpleado.setAttribute("id", empleado.getId());
        auto eNombre = doc.createElement("nombre");
        auto eEdad = doc.createElement("edad");
        auto eSalario = doc.createElement("salario");
        eNombre.appendChild(doc.createTextNode(empleado.getNombre()));
        eEdad.appendChild(doc.createTextNode(empleado.getEdad()));
        eSalario.appendChild(doc.createTextNode(empleado.getSalario()));
        eEmpleado.appendChild(eNombre);
        eEmpleado.appendChild(eEdad);
        eEmpleado.appendChild(eSalario);
        root.appendChild(eEmpleado);
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    QTextStream xout(&file);
    xout << doc.toString();
    file.flush();
    file.close();
}

void MainWindow::on_actionQuitar_triggered()
{
    close();
}

void MainWindow::on_actionAgregar_triggered()
{
    AgregarDialog d(this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    agregaEmpleado(d.getEmpleado());
}

void MainWindow::on_actionEliminar_triggered()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void MainWindow::agregaEmpleado(const Empleado &empleado)
{
    const int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, ID,
                    new QTableWidgetItem(empleado.getId()));
    ui->tableWidget->setItem(row, NOMBRE,
                    new QTableWidgetItem(empleado.getNombre()));
    ui->tableWidget->setItem(row, EDAD,
                    new QTableWidgetItem(empleado.getEdad()));
    ui->tableWidget->setItem(row, SALARIO,
                    new QTableWidgetItem(empleado.getSalario()));
}
