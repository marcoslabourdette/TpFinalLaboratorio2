#ifndef CLSCLIENTE_H
#define CLSCLIENTE_H
#include <iostream>
#include "ClsPersona.h"

using namespace std;

class ClsCliente : public ClsPersona
{
public:
    ClsCliente();

    /// GETTERS
    int getID();
    char* getDomicilio();
    char* getTelefono();
    char* getMail();

    /// SETTERS
    void setID(int id);
    void setDomicilio(char* domicilio);
    void setTelefono(char* telefono);
    void setMail(char* mail);

    /// MOSTRAR Y CARGAR
    void Mostrar();
    void Mostrar(ClsCliente Obj);
    void Mostrar(short x,short y);
    void MostrarUno(short x,short y);
    void Cargar();
    void Grabar(ClsCliente *Obj);

protected:

private:
    int ID;
    char Domicilio[50];
    char Telefono[15];
    char Mail[100];
};

#endif // CLSCLIENTE_H
