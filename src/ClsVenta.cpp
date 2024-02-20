#include "ClsVenta.h"
#include "ClsCelular.h"
#include "windows.h"
#include "string.h"

using namespace std;

    /// CONSTRUCTOR POR DEFECTO
ClsVenta::ClsVenta()
{

}
/// GETTERS
int ClsVenta::getID()
{
    return ID;
}
ClsFecha ClsVenta::getFechaVenta()
{
    return FechaVenta;
}
int ClsVenta::getIDCliente()
{
    return IDCliente;
}
int ClsVenta::getIDCelular()
{
    return IDCelular;
}
float ClsVenta::getPrecio()
{
    return Precio;
}
int ClsVenta::getCantidad()
{
    return Cantidad;
}
char ClsVenta::getFormaPago()
{
    return FormaPago;
}
float ClsVenta::getImporte()
{
    return Importe;
}

///SETTERS
void ClsVenta::setID(int id)
{
    ID = id;
}
void ClsVenta::setFechaVenta(int dia,int mes,int anio)
{
    FechaVenta.setDia(dia);
    FechaVenta.setMes(mes);
    FechaVenta.setAnio(anio);
}
void ClsVenta::setIDCliente(int idcliente)
{
    IDCliente = idcliente;
}
void ClsVenta::setIDCelular(int idcelular)
{
    IDCelular = idcelular;
}
void ClsVenta::setPrecio(int idcelular)
{
    ClsCelular reg;
    FILE *ArchivoCelulares;
    ArchivoCelulares = fopen("Celulares.dat","rb+");
    while (fread(&reg,sizeof(ClsCelular),1,ArchivoCelulares)==1)
    {
        if (reg.getIDCelular()==idcelular)
        {
            Precio=reg.getPrecio();
        }
    }
    fclose(ArchivoCelulares);
}
void ClsVenta::setCantidad(int cantidad)
{
    Cantidad = cantidad;
}
void ClsVenta::setFormaPago(char formapago)
{
    FormaPago = formapago;
}
void ClsVenta::setImporte(int cantidad)
{
    Importe = Precio*cantidad;
}

/// MOSTRAR Y CARGAR
void ClsVenta::Mostrar()
{
    cout << "ID: " << ID << endl;
    cout << "Fecha: " << FechaVenta.getDia() << "/" << FechaVenta.getMes() << "/" << FechaVenta.getAnio() << endl;
    cout << "ID del cliente: " << IDCliente << endl;
    cout << "ID de Celular: " << IDCelular << endl;
    cout << "Precio unitario: " << Precio << endl;
    cout << "Cantidad: " << Cantidad << endl;
    cout << "Forma de Pago: " << FormaPago << endl;
}
void ClsVenta::Mostrar(ClsVenta Obj)
{
    cout << "ID: " << Obj.getID() << endl;
    cout << "Fecha: " << Obj.getFechaVenta().getDia() << "/" << Obj.getFechaVenta().getMes() << "/" << Obj.getFechaVenta().getAnio() << endl;
    cout << "ID del cliente: " << Obj.getIDCliente() << endl;
    cout << "ID de Celular: " << Obj.getIDCelular() << endl;
    cout << "Precio unitario: " << Obj.getPrecio() << endl;
    cout << "Cantidad: " << Obj.getCantidad() << endl;
    cout << "Forma de Pago: " << Obj.getFormaPago() << endl;
}
void ClsVenta::Mostrar(short x,short y)
{
    gotoxy(5,y);
    cout << ID;
    gotoxy(9,y);
    cout << "| " << FechaVenta.getDia() << "/" << FechaVenta.getMes() << "/" << FechaVenta.getAnio();
    gotoxy(22,y);
    cout << "|    " << IDCliente;
    gotoxy(33,y);
    cout << "|    " << IDCelular;
    gotoxy(44,y);
    cout << "| $" << Precio;
    gotoxy(60,y);
    cout << "|   " << Cantidad;
    gotoxy(69,y);
    cout << "|      " << FormaPago;
    gotoxy(83,y);
    cout << "| $" << Importe;
}
void ClsVenta::Cargar()
{
    int id;
    int dia;
    int mes;
    int anio;
    int idcliente;
    int idcelular;
    int cantidad;
    char formapago;
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(15,3);
    cout << "- Cargar Ventas -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    gotoxy(3,5);
    cout << "Ingrese ID de la venta: ";
    cin >> id;
    setID(id);
    gotoxy(3,6);
    cout << "Ingrese dia de la venta: ";
    cin >> dia;
    gotoxy(3,7);
    cout << "Ingrese mes de la venta: ";
    cin >> mes;
    gotoxy(3,8);
    cout << "Ingrese anio de la venta: ";
    cin >> anio;
    setFechaVenta(dia,mes,anio);
    gotoxy(3,9);
    cout << "Ingrese ID del cliente: ";
    cin >> idcliente;
    setIDCliente(idcliente);
    gotoxy(3,10);
    cout << "Ingrese ID del celular: ";
    cin >> idcelular;
    setIDCelular(idcelular);
    setPrecio(idcelular);
    gotoxy(3,11);
    cout << "Ingrese Cantidad: ";
    cin >> cantidad;
    setCantidad(cantidad);
    gotoxy(3,12);
    cout << "Ingrese Forma de Pago: ";
    cin >> formapago;
    setFormaPago(formapago);
    setImporte(cantidad);
}
void ClsVenta::Grabar(ClsVenta *Obj)
{
    FILE *ArchivoVentas;
    ArchivoVentas = fopen("Ventas.dat","ab+");
    fwrite(Obj,sizeof(ClsVenta),1,ArchivoVentas);
    fclose(ArchivoVentas);
}
void ClsVenta::gotoxy(short x, short y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
