#include "ClsPersona.h"
#include "string.h"

using namespace std;

/// CONSTRUCTOR POR DEFECTO
ClsPersona::ClsPersona()
{
    strcpy(DNI,"00000000");
    strcpy(Nombres,"Sin Nombre");
    strcpy(Apellidos,"Sin Apellido");
    FechaNacimiento = ClsFecha();
    Edad=0;
}
/// GETTERS
char* ClsPersona::getNombres()
{
    return Nombres;
}
char* ClsPersona::getApellidos()
{
    return Apellidos;
}
const char* ClsPersona::getDNI()
{
    return DNI;
}
int ClsPersona::getEdad()
{
    return Edad;
}
ClsFecha ClsPersona::getFechaNacimiento()
{
    return FechaNacimiento;
}

/// SETTERS
void ClsPersona::setDNI(const char* dni)
{
    strcpy(DNI,dni);
}
void ClsPersona::setNombres(char* nombres)
{
    strcpy(Nombres,nombres);
}
void ClsPersona::setApellidos(char* apellidos)
{
    strcpy(Apellidos,apellidos);
}
void ClsPersona::setEdad(int anio)
{
    Edad = 2023-anio;
}
void ClsPersona::setFechaNacimiento(int dia,int mes, int anio)
{
    FechaNacimiento.setDia(dia);
    FechaNacimiento.setMes(mes);
    FechaNacimiento.setAnio(anio);
}
/// MOSTRAR Y CARGAR
void ClsPersona::Mostrar()
{
    cout << "DNI: " << DNI << endl;
    cout << "Nombres: " << Nombres << endl;
    cout << "Apellidos: " << Apellidos << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Fecha de Nacimiento: " << FechaNacimiento.getDia() << "/" << FechaNacimiento.getMes() << "/" << FechaNacimiento.getAnio() << endl;
}
void ClsPersona::Mostrar(short x, short y)
{
    gotoxy(3,y);
    cout << DNI;
    gotoxy(32,y);
    cout << "| " << Nombres;
    gotoxy(12,y);
    cout << "| " << Apellidos;
    gotoxy(48,y);
    cout << "| " << Edad;
    gotoxy(53,y);
    cout << "| " << FechaNacimiento.getDia() << "/" << FechaNacimiento.getMes() << "/" << FechaNacimiento.getAnio();
}
void ClsPersona::MostrarUno(short x,short y)
{
    gotoxy(x,y);
    cout << "DNI: " << DNI << endl;
    gotoxy(x,y+1);
    cout << "Nombres: " << Nombres << endl;
    gotoxy(x,y+2);
    cout << "Apellidos: " << Apellidos << endl;
    gotoxy(x,y+3);
    cout << "Edad: " << Edad << endl;
    gotoxy(x,y+4);
    cout << "Fecha de Nacimiento: " << FechaNacimiento.getDia() << "/" << FechaNacimiento.getMes() << "/" << FechaNacimiento.getAnio() << endl;
}
void ClsPersona::Mostrar(ClsPersona Obj)
{
    cout << "DNI: " << Obj.getDNI() << endl;
    cout << "Nombres: " << Obj.getNombres() << endl;
    cout << "Apellidos: " << Obj.getApellidos() << endl;
    cout << "Edad: " << Obj.getEdad() << endl;
    cout << "Fecha de Nacimiento: " << Obj.getFechaNacimiento().getDia() << "/" << Obj.getFechaNacimiento().getMes() << "/" << Obj.getFechaNacimiento().getAnio() << endl;
}
void ClsPersona::Cargar()
{
    char nombres[50];
    char apellidos[50];
    char dni[9];
    int dia;
    int mes;
    int anio;
    gotoxy(3,5);
    cout << "Ingrese DNI: ";
    cin.ignore();
    cin.getline(dni,9);
    setDNI(dni);
    gotoxy(3,6);
    cout << "Ingrese Nombres: ";
    cin.getline(nombres,50);
    setNombres(nombres);
    gotoxy(3,7);
    cout << "Ingrese Apellidos: ";
    cin.getline(apellidos,50);
    setApellidos(apellidos);
    gotoxy(3,8);
    cout << "Ingrese Dia de Nacimiento: ";
    cin >> dia;
    gotoxy(3,9);
    cout << "Ingrese Mes de Nacimiento: ";
    cin >> mes;
    gotoxy(3,10);
    cout << "Ingrese Anio de Nacimiento: ";
    cin >> anio;
    setEdad(anio);
    setFechaNacimiento(dia,mes,anio);
}
void ClsPersona::gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
