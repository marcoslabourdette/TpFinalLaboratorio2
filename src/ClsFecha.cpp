#include "ClsFecha.h"

/// CONSTRUCTOR POR DEFECTO
ClsFecha::ClsFecha()  /// OBLIGATORIO CREARLO
{
    Dia = 0;
    Mes = 0;
    Anio = 0000;
}

/// CONSTRUCTOR CON PARAMETROS
ClsFecha::ClsFecha(int dia, int mes, int anio)
{
    Dia = dia;
    Mes = mes;
    Anio = anio;
}

/// GETTERS
int ClsFecha::getDia()
{
    return Dia;
}
int ClsFecha::getMes()
{
    return Mes;
}
int ClsFecha::getAnio()
{
    return Anio;
}

/// SETTERS
void ClsFecha::setDia(int dia)
{
    Dia = dia;
}
void ClsFecha::setMes(int mes)
{
    Mes = mes;
}
void ClsFecha::setAnio(int anio)
{
    Anio = anio;
}
///METODO TOSTRING
std::string ClsFecha::toString(){
    return std::to_string(Dia) + "/" + std::to_string(Mes) + "/" + std::to_string(Anio);
}
