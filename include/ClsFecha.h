#ifndef CLSFECHA_H
#define CLSFECHA_H

#include <iostream>

using namespace std;

class ClsFecha
{
public:
    /// CONSTRUCTOR POR DEFECTO
    ClsFecha();

    /// CONSTRUCTOR CON PARAMETROS
    ClsFecha(int dia, int mes, int anio);

    /// GETTERS
    int getDia();
    int getMes();
    int getAnio();

    /// SETTERS
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    ///METODO TOSTRING
    std::string toString();

protected:

private:
    int Dia;
    int Mes;
    int Anio;
};

#endif // CLSFECHA_H
