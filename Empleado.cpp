#include "Empleado.h"

Empleado::Empleado(const QString &id, const QString &nombre,
                   const QString &edad, const QString &salario)
{
    mId = id;
    mNombre = nombre;
    mEdad = edad;
    mSalario = salario;
}

void Empleado::setId(const QString &id)
{
    mId = id;
}

void Empleado::setNombre(const QString &nombre)
{
    mNombre = nombre;
}

void Empleado::setEdad(const QString &edad)
{
    mEdad = edad;
}

void Empleado::setSalario(const QString &salario)
{
    mSalario = salario;
}

QString Empleado::getId() const
{
    return mId;
}

QString Empleado::getNombre() const
{
    return mNombre;
}

QString Empleado::getEdad() const
{
    return mEdad;
}

QString Empleado::getSalario() const
{
    return mSalario;
}

