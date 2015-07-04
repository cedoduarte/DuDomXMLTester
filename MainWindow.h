#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Empleado.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionAbrir_triggered();
    void on_actionGuardar_como_triggered();
    void on_actionQuitar_triggered();
    void on_actionAgregar_triggered();
    void on_actionEliminar_triggered();
private:
    enum
    {
        ID,
        NOMBRE,
        EDAD,
        SALARIO
    };

    void agregaEmpleado(const Empleado &empleado);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
