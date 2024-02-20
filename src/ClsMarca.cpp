#include "ClsMarca.h"
#include "string.h"
#include "windows.h"

using namespace std;

/// CONSTRUCTOR POR DEFECTO
ClsMarca::ClsMarca()
{
    IDMarca = 0;
    strcpy(Nombre,"Sin Nombre");
    strcpy(PaisOrigen,"Sin Pais");
    FechaFundacion = ClsFecha();
}
/// GETTERS
int ClsMarca::getIDMarca()
{
    return IDMarca;
}
char* ClsMarca::getNombre()
{
    return Nombre;
}
char* ClsMarca::getPaisOrigen()
{
    return PaisOrigen;
}
ClsFecha ClsMarca::getFechaFundacion()
{
    return FechaFundacion;
}

///SETTERS
void ClsMarca::setIDMarca(int idmarca)
{
    IDMarca = idmarca;
}
void ClsMarca::setNombre(char* nombre)
{
    strcpy(Nombre,nombre);
}
void ClsMarca::setPaisOrigen(char* paisorigen)
{
    strcpy(PaisOrigen,paisorigen);
}
void ClsMarca::setFechaFundacion(int dia,int mes,int anio)
{
    FechaFundacion.setDia(dia);
    FechaFundacion.setMes(mes);
    FechaFundacion.setAnio(anio);
}

/// MOSTRAR Y CARGAR
void ClsMarca::Mostrar()
{
    cout << "ID de la Marca: " << IDMarca << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Pais de Origen: " << PaisOrigen << endl;
    cout << "Fecha de Fundacion: " << FechaFundacion.getDia() << "/" << FechaFundacion.getMes() << "/" << FechaFundacion.getAnio() << endl;
}
void ClsMarca::Mostrar(ClsMarca Obj)
{
    cout << "ID de la Marca: " << Obj.getIDMarca() << endl;
    cout << "Nombre: " << Obj.getNombre() << endl;
    cout << "Pais de Origen: " << Obj.getPaisOrigen() << endl;
    cout << "Fecha de Fundacion: " << Obj.getFechaFundacion().getDia() << "/" << Obj.getFechaFundacion().getMes() << "/" << Obj.getFechaFundacion().getAnio() << endl;
}
void ClsMarca::Mostrar(short x, short y)
{
    gotoxy(3,y);
    cout << IDMarca;
    gotoxy(9,y);
    cout << "| " << Nombre;
    gotoxy(20,y);
    cout << "| " << PaisOrigen;
    gotoxy(40,y);
    cout << "| " << FechaFundacion.getDia() << "/" << FechaFundacion.getMes() << "/" << FechaFundacion.getAnio() << endl;
}
void ClsMarca::Cargar()
{
    int idmarca;
    char nombre[50];
    char paisorigen[50];
    int dia;
    int mes;
    int anio;
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(15,3);
    cout << "- Cargar Marca -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    gotoxy(3,5);
    cout << "Ingrese ID de la Marca: ";
    cin >> idmarca;
    setIDMarca(idmarca);
    gotoxy(3,6);
    cout << "Ingrese Nombre: ";
    cin.ignore();
    cin.getline(nombre,50);
    setNombre(nombre);
    gotoxy(3,7);
    cout << "Ingrese Pais de Origen: ";
    cin.getline(paisorigen,50);
    setPaisOrigen(paisorigen);
    gotoxy(3,8);
    cout << "Ingrese Dia de Fundacion: ";
    cin >> dia;
    gotoxy(3,9);
    cout << "Ingrese Mes de Fundacion: ";
    cin >> mes;
    gotoxy(3,10);
    cout << "Ingrese Anio de Fundacion: ";
    cin >> anio;
    setFechaFundacion(dia,mes,anio);
}
void ClsMarca::Grabar(ClsMarca *Obj)
{
    FILE *ArchivoMarcas;
    ArchivoMarcas = fopen("Marcas.dat","ab+");
    fwrite(Obj,sizeof(ClsMarca),1,ArchivoMarcas);
    fclose(ArchivoMarcas);
}
void ClsMarca::gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
