#ifndef CLSPERSONA_H
#define CLSPERSONA_H

#include <iostream>
#include "ClsFecha.h"
#include "windows.h"

using namespace std;

class ClsPersona
{
public:
    /// CONSTRUCTOR POR DEFECTO
    ClsPersona();

    /// GETTERS
    char* getNombres();
    char* getApellidos();
    const char* getDNI();
    int getEdad();
    ClsFecha getFechaNacimiento();

    /// SETTERS
    void setDNI(const char* dni);
    void setNombres(char* nombres);
    void setApellidos(char* apellidos);
    void setEdad(int anio);
    void setFechaNacimiento(int dia,int mes, int anio);

    /// MOSTRAR Y CARGAR
    void Mostrar();
    void Mostrar(ClsPersona obj);
    void Mostrar(short x, short y);
    void MostrarUno(short x,short y);
    void Cargar();
    void gotoxy(short x, short y);

protected:

private:
    char Nombres[50];
    char Apellidos[50];
    char DNI[9];
    int Edad;
    ClsFecha FechaNacimiento;
};

#endif // CLSPERSONA_H
