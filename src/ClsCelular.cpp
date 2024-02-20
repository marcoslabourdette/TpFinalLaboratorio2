#include "ClsCelular.h"
#include "string.h"
#include "windows.h"
#include <stdio.h>

using namespace std;

ClsCelular::ClsCelular()
{
    //ctor
}

/// GETTERS
int ClsCelular::getIDCelular()
{
    return IDCelular;
}
int ClsCelular::getIDMarca()
{
    return IDMarca;
}
char* ClsCelular::getModelo()
{
    return Modelo;
}
ClsFecha ClsCelular::getFechaLanzamiento()
{
    return FechaLanzamiento;
}
int ClsCelular::getAlmacenamiento()
{
    return Almacenamiento;
}
int ClsCelular::getMemoriaRAM()
{
    return MemoriaRAM;
}
float ClsCelular::getPrecio()
{
    return Precio;
}
int ClsCelular::getStock()
{
    return Stock;
}

/// SETTERS
void ClsCelular::setIDCelular(int idcelular)
{
    IDCelular = idcelular;
}
void ClsCelular::setIDMarca(int idmarca)
{
    IDMarca = idmarca;
}
void ClsCelular::setModelo(char* modelo)
{
    strcpy(Modelo,modelo);
}
void ClsCelular::setFechaLanzamiento(int dia,int mes,int anio)
{
    FechaLanzamiento.setDia(dia);
    FechaLanzamiento.setMes(mes);
    FechaLanzamiento.setAnio(anio);
}
void ClsCelular::setAlmacenamiento(int almacenamiento)
{
    Almacenamiento = almacenamiento;
}
void ClsCelular::setMemoriaRAM(int memoriaRAM)
{
    MemoriaRAM = memoriaRAM;
}
void ClsCelular::setPrecio(float precio)
{
    Precio = precio;
}
void ClsCelular::setStock(int stock)
{
    Stock = stock;
}

/// MOSTRAR Y CARGAR
void ClsCelular::Mostrar()
{
    cout << "ID del celular: " << IDCelular << endl;
    cout << "ID de la marca: " << IDMarca << endl;
    cout << "Modelo: " << Modelo << endl;
    cout << "Fecha de lanzamiento: " << FechaLanzamiento.getDia() << "/" << FechaLanzamiento.getMes() << "/" << FechaLanzamiento.getAnio() << endl;
    cout << "Capacidad de almacenamiento: " << Almacenamiento << endl;
    cout << "Cantidad de memoria RAM: " << MemoriaRAM << endl;
    cout << "Precio: " << Precio << endl;
    cout << "Stock: " << Stock << endl;
}
void ClsCelular::Mostrar(ClsCelular Obj)
{
    cout << "ID del celular: " << Obj.getIDCelular() << endl;
    cout << "ID de la marca: " << Obj.getIDMarca() << endl;
    cout << "Modelo: " << Obj.getModelo() << endl;
    cout << "Fecha de lanzamiento: " << Obj.getFechaLanzamiento().getDia() << "/" << Obj.getFechaLanzamiento().getMes() << "/" << Obj.getFechaLanzamiento().getAnio() << endl;
    cout << "Capacidad de almacenamiento: " << Obj.getAlmacenamiento() << endl;
    cout << "Cantidad de memoria RAM: " << Obj.getMemoriaRAM() << endl;
    cout << "Precio: " << Obj.getPrecio() << endl;
    cout << "Stock: " << Obj.getStock() << endl;
}
void ClsCelular::Mostrar(short x,short y)
{
    gotoxy(3,y);
    cout << IDCelular;
    gotoxy(9,y);
    cout << "| " << IDMarca;
    gotoxy(17,y);
    cout << "| " << Modelo;
    gotoxy(34,y);
    cout << "| " << FechaLanzamiento.getDia() << "/" << FechaLanzamiento.getMes() << "/" << FechaLanzamiento.getAnio();
    gotoxy(46,y);
    cout << "| " << Almacenamiento << "GB";
    gotoxy(54,y);
    cout << "| " << MemoriaRAM << "GB";
    gotoxy(60,y);
    cout << "| $" << Precio;
    gotoxy(70,y);
    cout << "| " << Stock;
}
void ClsCelular::Cargar()
{
    int idcelular;
    int idmarca;
    char modelo[50];
    int dia;
    int mes;
    int anio;
    int almacenamiento;
    int memoriaRAM;
    float precio;
    int stock;
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(15,3);
    cout << "- Cargar Celular -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    gotoxy(3,5);
    cout << "Ingrese ID del celular: ";
    cin >> idcelular;
    setIDCelular(idcelular);
    gotoxy(3,6);
    cout << "Ingrese ID de la marca: ";
    cin >> idmarca;
    setIDMarca(idmarca);
    gotoxy(3,7);
    cout << "Ingrese modelo: ";
    cin.ignore();
    cin.getline(modelo,50);
    setModelo(modelo);
    gotoxy(3,8);
    cout << "Ingrese dia del lanzamiento: ";
    cin >> dia;
    gotoxy(3,9);
    cout << "Ingrese mes del lanzamiento: ";
    cin >> mes;
    gotoxy(3,10);
    cout << "Ingrese anio del lanzamiento: ";
    cin >> anio;
    setFechaLanzamiento(dia,mes,anio);
    gotoxy(3,11);
    cout << "Ingrese capacidad de almacenamiento: ";
    cin >> almacenamiento;
    setAlmacenamiento(almacenamiento);
    gotoxy(3,12);
    cout << "Ingrese cantidad de memoria RAM: ";
    cin >> memoriaRAM;
    setMemoriaRAM(memoriaRAM);
    gotoxy(3,13);
    cout << "Ingrese precio: ";
    cin >> precio;
    setPrecio(precio);
    gotoxy(3,14);
    cout << "Ingrese Stock: ";
    cin >> stock;
    setStock(stock);
}
void ClsCelular::Grabar(ClsCelular *Obj)
{
    FILE *ArchivoCelulares;
    ArchivoCelulares = fopen("Celulares.dat","ab+");
    fwrite(Obj,sizeof(ClsCelular),1,ArchivoCelulares);
    fclose(ArchivoCelulares);
}
void ClsCelular::gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
