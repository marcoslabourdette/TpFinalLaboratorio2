#ifndef CLSMARCA_H
#define CLSMARCA_H

#include <iostream>
#include "ClsFecha.h"

using namespace std;

class ClsMarca
{
public:
    /// CONSTRUCTOR POR DEFECTO
    ClsMarca();

    /// GETTERS
    int getIDMarca();
    char* getNombre();
    char* getPaisOrigen();
    ClsFecha getFechaFundacion();

    ///SETTERS
    void setIDMarca(int idmarca);
    void setNombre(char* nombre);
    void setPaisOrigen(char* paisorigen);
    void setFechaFundacion(int dia,int mes,int anio);

    /// MOSTRAR Y CARGAR
    void Mostrar();
    void Mostrar(ClsMarca Obj);
    void Mostrar(short x, short y);
    void Cargar();
    void Grabar(ClsMarca *Obj);
    void gotoxy(short x, short y);

protected:

private:
    int IDMarca;
    char Nombre[50];
    char PaisOrigen[50];
    ClsFecha FechaFundacion;
};

#endif // CLSMARCA_H
