#ifndef CLSCELULAR_H
#define CLSCELULAR_H

#include <iostream>
#include "ClsFecha.h"

using namespace std;

class ClsCelular
{
public:
    ClsCelular();

    /// GETTERS
    int getIDCelular();
    int getIDMarca();
    char* getModelo();
    ClsFecha getFechaLanzamiento();
    int getAlmacenamiento();
    int getMemoriaRAM();
    float getPrecio();
    int getStock();

    /// SETTERS
    void setIDCelular(int idcelular);
    void setIDMarca(int idmarca);
    void setModelo(char* modelo);
    void setFechaLanzamiento(int dia,int mes,int anio);
    void setAlmacenamiento(int almacenamiento);
    void setMemoriaRAM(int memoriaRAM);
    void setPrecio(float precio);
    void setStock(int stock);

    /// MOSTRAR Y CARGAR
    void Mostrar();
    void Mostrar(ClsCelular Obj);
    void Mostrar(short x,short y);
    void Cargar();
    void Grabar(ClsCelular *Obj);
    void gotoxy(short x, short y);

protected:

private:
    int IDCelular;
    int IDMarca;
    char Modelo[50];
    ClsFecha FechaLanzamiento;
    int Almacenamiento;
    int MemoriaRAM;
    float Precio;
    int Stock;
};

#endif // CLSCELULAR_H
