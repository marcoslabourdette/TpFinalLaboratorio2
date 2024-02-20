#ifndef CLSVENTA_H
#define CLSVENTA_H

#include <iostream>
#include "ClsFecha.h"

using namespace std;

class ClsVenta
{
public:
    /// CONSTRUCTOR POR DEFECTO
    ClsVenta();

    /// GETTERS
    int getID();
    ClsFecha getFechaVenta();
    int getIDCliente();
    int getIDCelular();
    float getPrecio();
    int getCantidad();
    char getFormaPago();
    float getImporte();

    ///SETTERS
    void setID(int id);
    void setFechaVenta(int dia,int mes,int anio);
    void setIDCliente(int idcliente);
    void setIDCelular(int idcelular);
    void setPrecio(int idcelular);
    void setCantidad(int cantidad);
    void setFormaPago(char formapago);
    void setImporte(int cantidad);

    /// MOSTRAR Y CARGAR
    void Mostrar();
    void Mostrar(ClsVenta Obj);
    void Mostrar(short x,short y);
    void Cargar();
    void Grabar(ClsVenta *Obj);
    void gotoxy(short x, short y);

protected:

private:
    int ID;
    ClsFecha FechaVenta;
    int IDCliente;
    int IDCelular;
    float Precio;
    int Cantidad;
    char FormaPago;
    float Importe;
};

#endif // CLSVENTA_H
