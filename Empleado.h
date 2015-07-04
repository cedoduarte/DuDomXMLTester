#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <QString>

class Empleado
{
public:
    Empleado(const QString &id = "", const QString &nombre = "",
             const QString &edad = "", const QString &salario = "");
    void setId(const QString &id);
    void setNombre(const QString &nombre);
    void setEdad(const QString &edad);
    void setSalario(const QString &salario);
    QString getId() const;
    QString getNombre() const;
    QString getEdad() const;
    QString getSalario() const;
private:
    QString mId;
    QString mNombre;
    QString mEdad;
    QString mSalario;
};

#endif // EMPLEADO_H
