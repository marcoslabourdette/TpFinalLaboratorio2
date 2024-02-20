#include "ClsCliente.h"
#include "string.h"
#include <iostream>

using namespace std;

ClsCliente::ClsCliente() : ClsPersona()
{
    //ctor
}

/// GETTERS
int ClsCliente::getID()
{
    return ID;
}
char* ClsCliente::getDomicilio()
{
    return Domicilio;
}
char* ClsCliente::getTelefono()
{
    return Telefono;
}
char* ClsCliente::getMail()
{
    return Mail;
}

/// SETTERS
void ClsCliente::setID(int id)
{
    ID = id;
}
void ClsCliente::setDomicilio(char* domicilio)
{
    strcpy(Domicilio,domicilio);
}
void ClsCliente::setTelefono(char* telefono)
{
    strcpy(Telefono,telefono);
}
void ClsCliente::setMail(char* mail)
{
    strcpy(Mail,mail);
}

/// MOSTRAR Y CARGAR
void ClsCliente::Mostrar()
{
    ClsPersona::Mostrar();
    cout << "ID del cliente: " << ID << endl;
    cout << "Domicilio: " << Domicilio << endl;
    cout << "Telefono: " << Telefono << endl;
    cout << "Mail: " << Mail << endl;
}
void ClsCliente::Mostrar(ClsCliente Obj)
{
    ClsPersona::Mostrar(Obj);
    cout << "ID del cliente: " << Obj.getID() << endl;
    cout << "Domicilio: " << Obj.getDomicilio() << endl;
    cout << "Telefono: " << Obj.getTelefono() << endl;
    cout << "Mail: " << Obj.getMail() << endl;
}
void ClsCliente::Mostrar(short x,short y)
{
    ClsPersona::Mostrar(x,y);
    gotoxy(65,y);
    cout << "| " << ID;
    gotoxy(71,y);
    cout << "| " << Domicilio;
    gotoxy(83,y);
    cout << "| " << Telefono;
    gotoxy(95,y);
    cout << "| " << Mail;
}
void ClsCliente::MostrarUno(short x,short y)
{
    ClsPersona::MostrarUno(x,y);
    gotoxy(x,y+5);
    cout << "ID del cliente: " << ID << endl;
    gotoxy(x,y+6);
    cout << "Domicilio: " << Domicilio << endl;
    gotoxy(x,y+7);
    cout << "Telefono: " << Telefono << endl;
    gotoxy(x,y+8);
    cout << "Mail: " << Mail << endl;

}
void ClsCliente::Cargar()
{
    int id;
    char domicilio[50];
    char telefono[15];
    char mail[100];
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(15,3);
    cout << "- Cargar Cliente -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    ClsPersona::Cargar();
    gotoxy(3,11);
    cout << "Ingrese ID del cliente: ";
    cin >> id;
    setID(id);
    gotoxy(3,12);
    cout << "Ingrese Domicilio: ";
    cin.ignore();
    cin.getline(domicilio,50);
    setDomicilio(domicilio);
    gotoxy(3,13);
    cout << "Ingrese Telefono: ";
    cin.getline(telefono,15);
    setTelefono(telefono);
    gotoxy(3,14);
    cout << "Ingrese Mail: ";
    cin.getline(mail,100);
    setMail(mail);
}
void ClsCliente::Grabar(ClsCliente *Obj)
{
    FILE *ArchivoClientes;
    ArchivoClientes = fopen("Clientes.dat","ab+");
    fwrite(Obj,sizeof(ClsCliente),1,ArchivoClientes);
    fclose(ArchivoClientes);
}
