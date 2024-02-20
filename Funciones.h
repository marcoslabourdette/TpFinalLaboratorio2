#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "ClsPersona.h"
#include "ClsCliente.h"
#include "ClsCelular.h"
#include "ClsMarca.h"
#include "ClsVenta.h"
#include <stdio.h>
#include <string.h>
#include "Archivos.h"
#include "Graficos.h"

using namespace std;

/// CARGA DE DATOS
void CargarClientes();
void CargarMarcas();
void CargarCelulares();
void CargarVentas();
/// LISTADOS
void ListadoClienteXapellido();
void ListadoClienteXedad();
void ListadoCelularesXmarca();
void ListadoCelularesXfechadelanzamiento();
void ListadoCelularesXprecio();
void ListadoCelularesXmodelo();
void ListadoMarcas();
void ListadoVentas();
/// CONSULTAS
void ConsultaCLientesXdni();
void ConsultaCLientesXrangodeEdad();
void ConsultaCelularesXmarca();
void ConsultaCelularesXfechadelanzamiento();
void ConsultaCelularesXrangodeprecio();
void ConsultaCelularesXalmacenamiento();
void ConsultaCelularesXmemoriaRAM();
void ConsultaVentasXrangodefecha();
void ConsultaVentasXmarca();
void ConsultaVentasXmodelo();
/// INFORMES
void RecuadacionAnual();
void RecaudacionXclientes();
int BuscarCliente(int IDActual);
void RecaudacionXmarca();
int BuscarMarca(int IDCel);
int BuscarVentas(int IDMarca);
void RecaudacionXmodelo();
float ContarLoRecaudado(int IDCel);
void CantidadCelularesAnual();
/// BACKUPS Y RESTAURACIONES
void BackupClientes();
void BackupCelulares();
void BackupMarcas();
void BackupVentas();
void BackupTodosLosArchivos();
void RestauracionClientes();
void RestauracionCelulares();
void RestauracionMarcas();
void RestauracionVentas();
void RestauracionTodosLosArchivos();
///------FUNCIONES ADICIONALES-------///
///-------Leer registros.
void leerClientes(ClsCliente *);
void leerCelulares(ClsCelular *);
void leerVentas (ClsVenta *);
void leerMarcas(ClsMarca *);
///-------Ordenamiento de vectores.
//Ordenar por apellido.
void ordenarPorApellido(ClsCliente *, int);
//Ordenar por edad.
void ordenarPorEdad(ClsCliente *, int);
//Ordenar por modelo.
void ordenarPorModelo(ClsCelular*,int);
//Ordenar por precio.
void ordenarPorPrecio(ClsCelular *,int);
//Ordenar marcas alfabeticamente.
void ordenarMarcas(ClsMarca *, int);
//Ordenar por fechas.
void ordenarPorFecha(ClsCelular *, int);
void ordenarPorFecha(ClsVenta *,int);
int compararFechas(ClsFecha , ClsFecha);
///---Validaciones para consultas.
bool validarMarca(char *);
bool validarAlmacenamiento(int);
bool validarMemoriaRam(int );
bool validarModelo(char*);
///------Contadores.
int contarClientes();
int contarCelulares();
int contarVentas();
int contarMarcas();
///------Interfaces.
void InterfazClientes(string titulo,int posicion);
void InterfazCelulares(string titulo,int posicion);
void InterfazMarcas(string titulo,int posicion);
void InterfazVentas(string titulo,int posicion);

void CargarClientes()
{
    ClsCliente Obj;
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,16,cBLANCO,cAZUL);
    Obj.Cargar();
    Obj.Grabar(&Obj);
    pause();
}
void CargarMarcas()
{
    ClsMarca Obj;
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,14,cBLANCO,cAZUL);
    Obj.Cargar();
    Obj.Grabar(&Obj);
    pause();
}
void CargarCelulares()
{
    ClsCelular Obj;
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,15,cBLANCO,cAZUL);
    Obj.Cargar();
    Obj.Grabar(&Obj);
    pause();
}
void CargarVentas()
{
    ClsVenta Obj;
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,14,cBLANCO,cAZUL);
    Obj.Cargar();
    Obj.Grabar(&Obj);
    pause();
}
///------------------LISTADOS--------------------------------------
void ListadoClienteXapellido(){
    int c = contarClientes();
    ClsCliente *vectorClientes = new ClsCliente[c];
    leerClientes(vectorClientes);
    ordenarPorApellido(vectorClientes,c);
    string titulo="- Clientes ordenados por apellido -";
    int posicion=40;
    InterfazClientes(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        vectorClientes[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            cont=0;
            y=6;
            InterfazClientes(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorClientes;
}
void ListadoClienteXedad(){
    int c = contarClientes();
    ClsCliente *vectorClientes = new ClsCliente[c];
    leerClientes(vectorClientes);
    ordenarPorEdad(vectorClientes,c);
    string titulo="- Clientes ordenados por edad (Menor a Mayor.) -";
    int posicion=40;
    InterfazClientes(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        vectorClientes[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            cont=0;
            y=6;
            InterfazClientes(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorClientes;
}
void ListadoCelularesXmarca()
{
    int c = contarCelulares();
    int cantMarcas = contarMarcas();
    ClsCelular *vectorCelulares = new ClsCelular[c];
    ClsMarca *vectorMarcas = new ClsMarca[cantMarcas];
    leerCelulares(vectorCelulares);
    leerMarcas(vectorMarcas);
    ordenarMarcas(vectorMarcas,cantMarcas);
    for(int i = 0; i < cantMarcas; i++)
    {
        string titulo="- Celulares ordenados por marca -  Marca: ";
        int posicion=15;
        InterfazCelulares(titulo,posicion);
        gotoxy(57,3);
        cout << vectorMarcas[i].getNombre();
        int x=3;
        int y=6;
        int cont=0;
        for(int j = 0; j < c; j++)
        if(vectorMarcas[i].getIDMarca() == vectorCelulares[j].getIDMarca())
        {
            vectorCelulares[j].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                y=6;
                cont=0;
                InterfazCelulares(titulo,posicion);
                gotoxy(57,3);
                cout << vectorMarcas[i].getNombre();
            }
        }
        gotoxy(x,y);
        system("pause");
        system("cls");
    }
    delete[] vectorMarcas;
    delete[] vectorCelulares;
}
void ListadoCelularesXfechadelanzamiento(){
    int c = contarCelulares();
    ClsCelular *vectorCelulares = new ClsCelular[c];
    leerCelulares(vectorCelulares);
    ordenarPorFecha(vectorCelulares,c);
    string titulo="- Celulares ordenados por fecha de lanzamiento (Mas reciente a mas antiguo). -";
    int posicion=3;
    InterfazCelulares(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++)
    {
        vectorCelulares[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            y=6;
            cont=0;
            InterfazCelulares(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;
}
void ListadoCelularesXprecio(){
    int c = contarCelulares();
    ClsCelular *vectorCelulares = new ClsCelular[c];
    leerCelulares(vectorCelulares);
    ordenarPorPrecio(vectorCelulares,c);
    string titulo="- Celulares ordenados por precio (Mayor a menor). -";
    int posicion=15;
    InterfazCelulares(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++)
    {
        vectorCelulares[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            y=6;
            cont=0;
            InterfazCelulares(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;
}
void ListadoCelularesXmodelo(){
    int c = contarCelulares();
    ClsCelular *vectorCelulares = new ClsCelular[c];
    leerCelulares(vectorCelulares);
    ordenarPorModelo(vectorCelulares,c);
    string titulo="- Celulares ordenados por modelo -";
    int posicion=25;
    InterfazCelulares(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c;i++)
    {
        vectorCelulares[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            y=6;
            cont=0;
            InterfazCelulares(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;
}
void ListadoMarcas(){
    int c = contarMarcas();
    ClsMarca *vectorMarcas = new ClsMarca[c];
    leerMarcas(vectorMarcas);
    ordenarMarcas(vectorMarcas,c);
    string titulo="- Marcas -";
    int posicion=25;
    InterfazMarcas(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        vectorMarcas[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            y=6;
            cont=0;
            InterfazMarcas(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorMarcas;
}
void ListadoVentas(){
    int c = contarVentas();
    ClsVenta *vectorVentas = new ClsVenta[c];
    leerVentas(vectorVentas);
    ordenarPorFecha(vectorVentas,c);
    string titulo="- Ventas ordenas por fecha (Mas reciente a mas antigua). -";
    int posicion=15;
    InterfazVentas(titulo,posicion);
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++)
    {
        vectorVentas[i].Mostrar(x,y);
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(x,y);
            system("pause");
            y=6;
            cont=0;
            InterfazVentas(titulo,posicion);
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorVentas;
}
///--------------------------CONSULTAS------------------------------
void ConsultaCLientesXrangodeEdad(){
    bool validarEdad = true, validar, hayClientes = false;
    int c = contarClientes();
    ClsCliente *vectorClientes =  new ClsCliente[c];
    leerClientes(vectorClientes);
    ordenarPorEdad(vectorClientes,c);
    int edad1,edad2;
    do{
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,65,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "----------------------------------------------------------------" << endl;
        gotoxy(15,3);
        cout << "- Consulta de clientes por rango de edad -" << endl;
        gotoxy(3,4);
        cout << "----------------------------------------------------------------" << endl;
        gotoxy(3,5);
        cout << "Ingrese la edad minima: ";
        cin >> edad1;
        if(edad1 < 0 || edad1 == 0 || edad1 > 120){
            gotoxy(3,7);
            cout << "Error valor ingresado incorrecto, Intente de nuevo. " << endl;
            validarEdad = false;
            pause();
        }
        else{
            validarEdad = true;
        }
    }while(!validarEdad);
    do{
        gotoxy(3,7);
        cout << "Ingrese la edad maxima: ";
        cin >> edad2;
        if(edad2 <= edad1){
            gotoxy(3,9);
            cout << "Error, la edad debe ser mayor a la inicial, Intente de nuevo." << endl;
            validar = false;
            pause();
            clrscr();
            system("COLOR 0F");
            recuadro(2,1,65,13,cBLANCO,cAZUL);
            gotoxy(3,2);
            cout << "----------------------------------------------------------------" << endl;
            gotoxy(15,3);
            cout << "- Consulta de clientes por rango de edad -" << endl;
            gotoxy(3,4);
            cout << "----------------------------------------------------------------" << endl;
            gotoxy(3,5);
            cout << "Ingrese la edad minima: " << edad1;
        }
        else{
            validar = true;
        }
    }while(!validar);
    string titulo="- Clientes de    a     anios -";
    int posicion=40;
    InterfazClientes(titulo,posicion);
    gotoxy(54,3);
    cout << edad1;
    gotoxy(59,3);
    cout << edad2;
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        if(vectorClientes[i].getEdad() >= edad1 && vectorClientes[i].getEdad() <= edad2){
            vectorClientes[i].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                y=6;
                cont=0;
                InterfazClientes(titulo,posicion);
                gotoxy(54,3);
                cout << edad1;
                gotoxy(59,3);
                cout << edad2;
            }
            hayClientes = true;
        }
    }
    if(!hayClientes){
        gotoxy(40,7);
        y=8;
        cout << "No hay clientes en este rango de edad." << endl;
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorClientes;
}
void ConsultaCLientesXdni(){
    bool existe = false;
    int c = contarClientes();
    ClsCliente *vectorClientes =  new ClsCliente[c];
    leerClientes(vectorClientes);
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,14,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(6,3);
    cout << "- Consulta de clientes por DNI -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    cin.ignore();
    char dni[9];
    gotoxy(3,5);
    cout << "Ingrese el DNI del cliente a buscar:" << endl;
    gotoxy(3,6);
    cin.getline(dni,9);
    for(int i = 0; i < c; i++){
        if(strcmp(dni,vectorClientes[i].getDNI()) == 0){
            clrscr();
            system("COLOR 0F");
            recuadro(2,1,40,14,cBLANCO,cAZUL);
            gotoxy(3,2);
            cout << "---------------------------------------" << endl;
            gotoxy(10,3);
            cout << "- Cliente encontrado -" << endl;
            gotoxy(3,4);
            cout << "---------------------------------------" << endl;
            int x=3;
            int y=5;
            vectorClientes[i].MostrarUno(x,y);
            existe = true;
        }
    }
    if(!existe){
        gotoxy(3,7);
        cout << "No se encuentra un cliente con ese DNI." << endl;
    }
    gotoxy(3,14);
    system("pause");
    delete[] vectorClientes;
}
void ConsultaCelularesXmarca(){
     bool validar;
    int c = contarMarcas();
    int cant = contarCelulares();
    ClsMarca *vectorMarcas = new ClsMarca[c];
    ClsCelular *vectorCelulares = new ClsCelular[cant];
    leerMarcas(vectorMarcas);
    leerCelulares(vectorCelulares);
    char nombreMarca[50];
    cin.ignore();
    do{
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,55,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "------------------------------------------------------" << endl;
        gotoxy(10,3);
        cout << "- Consulta de celulares por marca -" << endl;
        gotoxy(3,4);
        cout << "------------------------------------------------------" << endl;
        gotoxy(3,6);
        cout << "Ingrese el nombre de la marca: ";
        cin.getline(nombreMarca,50);
        validar = validarMarca(nombreMarca);
        if(!validar){
            gotoxy(3,8);
            cout << "No se encuentra la marca ingresada, Intente de nuevo." << endl;
            gotoxy(3,10);
            system("pause");
        }
    }while(!validar);
    string titulo="Celulares de la marca: ";
    int posicion=25;
    InterfazCelulares(titulo,posicion);
    gotoxy(48,3);
    cout << nombreMarca;
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
            for(int j = 0; j < cant; j++){
                if(strcmp(nombreMarca,vectorMarcas[i].getNombre())==0){
                    if(vectorMarcas[i].getIDMarca() == vectorCelulares[j].getIDMarca()){
                        vectorCelulares[j].Mostrar(x,y);
                        y+=1;
                        cont+=1;
                        if(cont==17)
                        {
                            gotoxy(x,y);
                            system("pause");
                            x=3;
                            y=6;
                            cont=0;
                            InterfazCelulares(titulo,posicion);
                            gotoxy(48,3);
                            cout << nombreMarca;
                        }
                    }
                }
            }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorMarcas;
    delete[] vectorCelulares;
}
void ConsultaCelularesXfechadelanzamiento(){
    bool validarDia = true, validarMes = true, validarAnio = true;
    bool existe = false;
    int c = contarCelulares();
    ClsFecha fecha;
    ClsCelular *vectorCelulares = new ClsCelular[c];
    leerCelulares(vectorCelulares);
    int dia,mes,anio;
    do{
     clrscr();
     system("COLOR 0F");
     recuadro(2,1,51,23,cBLANCO,cAZUL);
     gotoxy(3,2);
     cout << "--------------------------------------------------" << endl;
     gotoxy(3,3);
     cout << "- Consulta de celulares por fecha de lanzamiento -" << endl;
     gotoxy(3,4);
     cout << "--------------------------------------------------" << endl;
     gotoxy(3,6);
     cout << "Ingrese el dia de lanzamiento: ";
     cin >> dia;
     fecha.setDia(dia);
     gotoxy(3,7);
     if(dia > 31 || dia < 0 || dia == 0){
        cout << "Error el dia ingresado no es valido. Intente de nuevo." << endl;
        validarDia = false;
        pause();
     }
     else{
        validarDia = true;
    }
    }while(!validarDia);
    do{
       gotoxy(3,7);
       cout << "Ingrese el mes de lanzamiento: ";
       cin >> mes;
       fecha.setMes(mes);
       if(mes > 12 || mes < 0 || mes == 0){
        gotoxy(3,8);
        cout << "Mes ingresado incorrecto. Intente de nuevo." << endl;
        validarMes = false;
        pause();
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,51,23,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "--------------------------------------------------" << endl;
        gotoxy(3,3);
        cout << "- Consulta de celulares por fecha de lanzamiento -" << endl;
        gotoxy(3,4);
        cout << "--------------------------------------------------" << endl;
        gotoxy(3,6);
        cout << "Ingrese el dia de lanzamiento: " << dia;
     }
     else{
        validarMes = true;
    }
    }while(!validarMes);
     do{
        gotoxy(3,8);
        cout << "Ingrese el anio de lanzamiento: ";
        cin >> anio;
        fecha.setAnio(anio);
        if(anio < 1965 || anio > 2023 || anio == 0){
          gotoxy(3,9);
          cout << "Anio ingresado incorrecto. Intente de nuevo." << endl;
          validarAnio = false;
          pause();
          clrscr();
          system("COLOR 0F");
          recuadro(2,1,51,23,cBLANCO,cAZUL);
          gotoxy(3,2);
          cout << "--------------------------------------------------" << endl;
          gotoxy(3,3);
          cout << "- Consulta de celulares por fecha de lanzamiento -" << endl;
          gotoxy(3,4);
          cout << "--------------------------------------------------" << endl;
          gotoxy(3,6);
          cout << "Ingrese el dia de lanzamiento: " << dia;
          gotoxy(3,7);
          cout << "Ingrese el mes de lanzamiento: " << mes;
        }
        else{
            validarAnio = true;
        }
    }while(!validarAnio);
    string titulo="Celulares lanzados en la fecha: ";
    int posicion=20;
    InterfazCelulares(titulo,posicion);
    gotoxy(52,3);
    cout << fecha.toString();
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        if(compararFechas(fecha,vectorCelulares[i].getFechaLanzamiento()) == 0){
            existe = true;
            vectorCelulares[i].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                x=3;
                y=6;
                cont=0;
                InterfazCelulares(titulo,posicion);
                gotoxy(52,3);
                cout << fecha.toString();
            }
        }
    }
    if(!existe){
        gotoxy(20,7);
        y+=3;
        cout << "No hay celulares estrenados en la fecha ingresada." << endl;
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;
}
void ConsultaCelularesXrangodeprecio(){
    bool validar, validarPrecio = true, hayCelulares = false;
    int c = contarCelulares();
    ClsCelular *vectorCelulares =  new ClsCelular[c];
    leerCelulares(vectorCelulares);
    ordenarPorPrecio(vectorCelulares,c);
    float precio1,precio2;
    do{
       clrscr();
       system("COLOR 0F");
       recuadro(2,1,63,13,cBLANCO,cAZUL);
       gotoxy(3,2);
       cout << "--------------------------------------------------------------" << endl;
       gotoxy(20,3);
       cout << "- Consulta por rango de precio -" << endl;
       gotoxy(3,4);
       cout << "--------------------------------------------------------------" << endl;
       gotoxy(3,6);
       cout << "Ingrese el precio minimo: ";
       cin >> precio1;
       if(precio1 < 0 || precio1 == 0){
        gotoxy(3,7);
        cout << "Precio ingresado incorrecto. Intente de nuevo. " << endl;
        validarPrecio = false;
        pause();
       }
       else{
        validarPrecio = true;
       }
    }while(!validarPrecio);
    do{
        gotoxy(3,8);
        cout << "Ingrese el precio maximo: ";
        cin >> precio2;
        if(precio2 <= precio1){
            gotoxy(3,10);
            cout << "Error, el precio debe ser mayor al inicial. Intente de nuevo." << endl;
            validar = false;
            gotoxy(3,13);
            system("pause");
            clrscr();
            system("COLOR 0F");
            recuadro(2,1,63,13,cBLANCO,cAZUL);
            gotoxy(3,2);
            cout << "--------------------------------------------------------------" << endl;
            gotoxy(20,3);
            cout << "- Consulta por rango de precio -" << endl;
            gotoxy(3,4);
            cout << "--------------------------------------------------------------" << endl;
            gotoxy(3,6);
            cout << "Ingrese el precio minimo: " << precio1;
        }
        else{
            validar = true;
        }
    }while(!validar);
    string titulo="- Celulares de $       a $       -";
    int posicion=20;
    InterfazCelulares(titulo,posicion);
    gotoxy(36,3);
    cout << precio1;
    gotoxy(46,3);
    cout << precio2;
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        if(vectorCelulares[i].getPrecio() >= precio1 && vectorCelulares[i].getPrecio() <= precio2){
            vectorCelulares[i].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                x=3;
                y=6;
                cont=0;
                InterfazCelulares(titulo,posicion);
                gotoxy(36,3);
                cout << precio1;
                gotoxy(46,3);
                cout << precio2;
            }
            hayCelulares = true;
        }
    }
    if(!hayCelulares){
        gotoxy(20,7);
        y+=3;
        cout << "No hay celulares en este rango de precio." << endl;
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;

}
void ConsultaCelularesXalmacenamiento(){
    int almacenamiento, c = contarCelulares();
    bool validar=true;
    ClsCelular *vectorCelulares = new ClsCelular[c];
    leerCelulares(vectorCelulares);
    do{
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,63,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "--------------------------------------------------------------" << endl;
        gotoxy(10,3);
        cout << "- Consulta de celulares por almacenamiento -" << endl;
        gotoxy(3,4);
        cout << "--------------------------------------------------------------" << endl;
        gotoxy(3,6);
        cout << "Ingrese capacidad de almacenamiento: ";
        cin >> almacenamiento;
        validar = validarAlmacenamiento(almacenamiento);
        if(almacenamiento < 0 || almacenamiento == 0){
            gotoxy(3,8);
            cout << "El valor ingresado es incorrecto, Intente de nuevo." << endl;
            gotoxy(3,10);
            system("pause");
        }
        else if(!validar){
            gotoxy(3,8);
            cout << "El almacenamiento ingresado no se encuentra. Intente de nuevo" << endl;
            gotoxy(3,10);
            system("pause");
        }
    }while(!validar);
    string titulo="- Celulares con capacidad de almacenamiento de:     GB -";
    int posicion=10;
    InterfazCelulares(titulo,posicion);
    gotoxy(58,3);
    cout << almacenamiento;
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        if(almacenamiento == vectorCelulares[i].getAlmacenamiento()){
            vectorCelulares[i].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                x=3;
                y=6;
                cont=0;
                InterfazCelulares(titulo,posicion);
                gotoxy(58,3);
                cout << almacenamiento;
            }
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;
}
void ConsultaCelularesXmemoriaRAM(){
    int memoriaRam,c = contarCelulares();
    ClsCelular *vectorCelulares = new ClsCelular[c];
    bool validar=true;
    leerCelulares(vectorCelulares);
    do{
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,63,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "--------------------------------------------------------------" << endl;
        gotoxy(10,3);
        cout << "- Consulta de celulares por memoria ram -" << endl;
        gotoxy(3,4);
        cout << "--------------------------------------------------------------" << endl;
        gotoxy(3,6);
        cout << "Ingrese capacidad de memoria ram: ";
        cin >> memoriaRam;
        validar = validarMemoriaRam(memoriaRam);
        if(memoriaRam < 0 || memoriaRam == 0){
            gotoxy(3,8);
            cout << "El valor ingresado es incorrecto, Intente de nuevo." << endl;
            gotoxy(3,10);
            system("pause");
        }
        else if(!validar){
            gotoxy(3,8);
            cout << "El valor de memoria RAM ingresado no se encuentra, Intente de nuevo." << endl;
            gotoxy(3,10);
            system("pause");
        }
    }while(!validar);
    string titulo="- Celulares con    GB de memoria RAM -";
    int posicion=20;
    InterfazCelulares(titulo,posicion);
    gotoxy(36,3);
    cout << memoriaRam;
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        if(memoriaRam == vectorCelulares[i].getMemoriaRAM()){
            vectorCelulares[i].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                x=3;
                y=6;
                cont=0;
                InterfazCelulares(titulo,posicion);
                gotoxy(36,3);
                cout << memoriaRam;
            }
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorCelulares;
}
void ConsultaVentasXrangodefecha(){
    bool validarDia = true, validarMes = true, validarAnio = true;
    bool validar;
    ClsFecha fecha1, fecha2;
    int diaInicial,mesInicial,anioInicial,diaFecha2,mesFecha2,anioFecha2;
    int c = contarVentas();
    ClsVenta *vectorVentas = new ClsVenta[c];
    leerVentas(vectorVentas);
    ordenarPorFecha(vectorVentas,c);
    do{
     clrscr();
     system("COLOR 0F");
     recuadro(2,1,51,23,cBLANCO,cAZUL);
     gotoxy(3,2);
     cout << "--------------------------------------------------" << endl;
     gotoxy(3,3);
     cout << "- Consulta de celulares por fecha de lanzamiento -" << endl;
     gotoxy(3,4);
     cout << "--------------------------------------------------" << endl;
     gotoxy(3,6);
     cout << "Ingrese el dia de lanzamiento: ";
     cin >> diaInicial;
     fecha1.setDia(diaInicial);
     gotoxy(3,7);
     if(diaInicial > 31 || diaInicial < 0 || diaInicial == 0){
        cout << "Error el dia ingresado no es valido. Intente de nuevo." << endl;
        validarDia = false;
        pause();
     }
     else{
        validarDia = true;
    }
    }while(!validarDia);
    do{
       gotoxy(3,7);
       cout << "Ingrese el mes de lanzamiento: ";
       cin >> mesInicial;
       fecha1.setMes(mesInicial);
       if(mesInicial > 12 || mesInicial < 0 || mesInicial == 0){
        gotoxy(3,8);
        cout << "Mes ingresado incorrecto. Intente de nuevo." << endl;
        validarMes = false;
        pause();
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,51,23,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "--------------------------------------------------" << endl;
        gotoxy(3,3);
        cout << "- Consulta de celulares por fecha de lanzamiento -" << endl;
        gotoxy(3,4);
        cout << "--------------------------------------------------" << endl;
        gotoxy(3,6);
        cout << "Ingrese el dia de lanzamiento: " << diaInicial;
     }
     else{
        validarMes = true;
    }
    }while(!validarMes);
     do{
        gotoxy(3,8);
        cout << "Ingrese el anio de lanzamiento: ";
        cin >> anioInicial;
        fecha1.setAnio(anioInicial);
        if(anioInicial < 1965 || anioInicial > 2023 || anioInicial == 0){
          gotoxy(3,9);
          cout << "Anio ingresado incorrecto. Intente de nuevo." << endl;
          validarAnio = false;
          pause();
          clrscr();
          system("COLOR 0F");
          recuadro(2,1,51,23,cBLANCO,cAZUL);
          gotoxy(3,2);
          cout << "--------------------------------------------------" << endl;
          gotoxy(3,3);
          cout << "- Consulta de celulares por fecha de lanzamiento -" << endl;
          gotoxy(3,4);
          cout << "--------------------------------------------------" << endl;
          gotoxy(3,6);
          cout << "Ingrese el dia de lanzamiento: " << diaInicial;
          gotoxy(3,7);
          cout << "Ingrese el mes de lanzamiento: " << mesInicial;
        }
        else{
            validarAnio = true;
        }
    }while(!validarAnio);
    fecha1.setDia(diaInicial);
    fecha1.setMes(mesInicial);
    fecha1.setAnio(anioInicial);
    do{
    gotoxy(3,9);
    cout << "Ingrese dia de la segunda fecha: ";
    cin >> diaFecha2;
    gotoxy(3,10);
    cout << "Ingrese mes de la segunda fecha: ";
    cin >> mesFecha2;
    gotoxy(3,11);
    cout << "Ingrese anio de la segunda fecha: ";
    cin >> anioFecha2;
    fecha2.setDia(diaFecha2);
    fecha2.setMes(mesFecha2);
    fecha2.setAnio(anioFecha2);
    if(compararFechas(fecha1,fecha2)>0 || compararFechas(fecha1,fecha2)==0){
        gotoxy(3,13);
        cout << "Error la segunda fecha debe ser posterior a la inicial. Intente de nuevo" << endl;
        validar = false;
        gotoxy(3,14);
        system("pause");
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,73,14,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "------------------------------------------------------------------------" << endl;
        gotoxy(20,3);
        cout << "- Consulta por rango de fechas -" << endl;
        gotoxy(3,4);
        cout << "------------------------------------------------------------------------" << endl;
        gotoxy(3,5);
        cout << "Ingrese dia de la fecha inicial: " << diaInicial;
        gotoxy(3,6);
        cout << "Ingrese mes de la fecha inicial: " << mesInicial;
        gotoxy(3,7);
        cout << "Ingrese anio de la fecha inicial: " << anioInicial;
    }
    else{
        validar = true;
    }
    }while(!validar);
    string titulo="- Ventas realizadas de            a            -";
    int posicion=15;
    InterfazVentas(titulo,posicion);
    gotoxy(38,3);
    cout << fecha1.toString();
    gotoxy(51,3);
    cout << fecha2.toString();
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c; i++){
        if (compararFechas(vectorVentas[i].getFechaVenta(), fecha1) >= 0 && compararFechas(vectorVentas[i].getFechaVenta(), fecha2) <= 0) {
            vectorVentas[i].Mostrar(x,y);
            y+=1;
            cont+=1;
            if(cont==17)
            {
                gotoxy(x,y);
                system("pause");
                y=6;
                cont=0;
                InterfazVentas(titulo,posicion);
                gotoxy(38,3);
                cout << fecha1.toString();
                gotoxy(51,3);
                cout << fecha2.toString();
            }
        }
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorVentas;
}
void ConsultaVentasXmarca(){
    bool validar, hayVentas = false;
    char nombreMarca[50];
    int cant = contarMarcas();
    int c = contarVentas();
    int cantCel = contarCelulares();
    ClsVenta *vectorVentas = new ClsVenta[c];
    ClsMarca *vectorMarcas = new ClsMarca[cant];
    ClsCelular *vectorCelulares = new ClsCelular[cantCel];
    leerVentas(vectorVentas);
    leerMarcas(vectorMarcas);
    leerCelulares(vectorCelulares);
    cin.ignore();
    do{
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,63,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "--------------------------------------------------------------" << endl;
        gotoxy(15,3);
        cout << "- Consulta ventas por marcas -" << endl;
        gotoxy(3,4);
        cout << "--------------------------------------------------------------" << endl;
        gotoxy(3,6);
        cout << "Ingrese el nombre de la marca: ";
        cin.getline(nombreMarca,50);
        validar = validarMarca(nombreMarca);
        if(!validar){
            gotoxy(3,8);
            cout << "Error marca ingresada incorrecta. Intente de  nuevo." << endl;
            gotoxy(3,10);
            system("pause");
        }
    }while(!validar);
    string titulo="- Ventas por la Marca: ";
    int posicion=20;
    InterfazVentas(titulo,posicion);
    gotoxy(43,3);
    cout << nombreMarca;
    int x=3;
    int z=6;
    int cont=0;
    for(int i = 0; i < cant;i++){
        for(int j = 0; j < cantCel; j++){
            if(strcmp(nombreMarca,vectorMarcas[i].getNombre()) == 0){
                if(vectorMarcas[i].getIDMarca() == vectorCelulares[j].getIDMarca()){
                    for(int y = 0; y < c; y++){ // x_x   x_x
                        if(vectorVentas[y].getIDCelular() == vectorCelulares[j].getIDCelular()){
                            hayVentas = true;
                            vectorVentas[y].Mostrar(x,z);
                            z+=1;
                            cont+=1;
                            if(cont==17)
                            {
                                gotoxy(x,z);
                                system("pause");
                                z=6;
                                cont=0;
                                InterfazVentas(titulo,posicion);
                                gotoxy(43,3);
                                cout << nombreMarca;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!hayVentas){
        gotoxy(20,6);
        z+=3;
        cout << "No hay ventas para esta marca. " << endl;
    }
    gotoxy(x,z);
    system("pause");
    delete[] vectorMarcas;
    delete[] vectorVentas;
    delete[] vectorCelulares;
}
void ConsultaVentasXmodelo(){
    bool validar, hayVentas = false;
    char nombreModelo[50];
    int c = contarCelulares();
    int cant = contarVentas();
    ClsCelular *vectorCelulares = new ClsCelular[c];
    ClsVenta *vectorVentas = new ClsVenta[cant];
    leerCelulares(vectorCelulares);
    leerVentas(vectorVentas);
    cin.ignore();
    cout << "-------------------------------" << endl;
    cout << "- Consulta ventas por modelos -" << endl;
    cout << "-------------------------------" << endl;
    do{
        cout << "Ingrese el nombre del modelo: ";
        cin.getline(nombreModelo,50);
        validar = validarModelo(nombreModelo);
        if(!validar){
            cout << "Error modelo ingresado incorrecto. Intente de  nuevo." << endl;
            system("pause");
            system("cls");
        }
    }while(!validar);
    string titulo="- Ventas por el modelo: ";
    int posicion=20;
    InterfazVentas(titulo,posicion);
    gotoxy(44,3);
    cout << nombreModelo << " -";
    int x=3;
    int y=6;
    int cont=0;
    for(int i = 0; i < c;i++){
        if(strcmp(nombreModelo,vectorCelulares[i].getModelo())== 0){
            for(int j = 0; j < cant; j++){
                if(vectorCelulares[i].getIDCelular() == vectorVentas[j].getIDCelular()){
                    hayVentas = true;
                    vectorVentas[j].Mostrar(x,y);
                    y+=1;
                    cont+=1;
                    if(cont==17)
                    {
                        gotoxy(x,y);
                        system("pause");
                        y=6;
                        cont=0;
                        InterfazVentas(titulo,posicion);
                        gotoxy(44,3);
                        cout << nombreModelo << " -";
                    }
                }
            }
        }
    }
    if(!hayVentas){
        gotoxy(20,6);
        y+=3;
        cout << "No hay ventas por este modelo" << endl;
    }
    gotoxy(x,y);
    system("pause");
    delete[] vectorVentas;
    delete[] vectorCelulares;
}
void RecuadacionAnual()
{
    float RecaudacionMes[12];
    for(int z=0;z<12;z++)
    {
        RecaudacionMes[z]=0;
    }
    ClsVenta Ventas;
    FILE *aVentas;
    aVentas=fopen(ARCHIVO_VENTAS,"rb");
    int anioBuscado;
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,16,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(6,3);
    cout << "-  Recaudacion Anual  -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    gotoxy(3,5);
    cout << "Ingrese anio a buscar: ";
    cin >> anioBuscado;
    while(fread(&Ventas,sizeof(ClsVenta),1,aVentas)==1)
    {
        if(anioBuscado==Ventas.getFechaVenta().getAnio())
        {
            for(int x=0;x<12;x++)
            {
                if(x+1==Ventas.getFechaVenta().getMes())
                {
                    RecaudacionMes[x] += Ventas.getImporte();
                }
            }
        }
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,16,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(6,3);
    cout << "-  Recaudacion de " << anioBuscado << " -" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    int y=5;
    for(int i=0;i<12;i++)
    {
        gotoxy(6,y);
        cout << "Mes " << i+1 << ": " << RecaudacionMes[i] << endl;
        y+=1;
    }
    pause();
    fclose(aVentas);
}
void RecaudacionXclientes()
{
    int IDActual;
    float RecaudacionDelCliente;
    ClsCliente Clientes;
    ClsVenta Ventas;
    FILE *aCliente;
    aCliente=fopen(ARCHIVO_CLIENTES,"rb");
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,55,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "------------------------------------------------------";
    gotoxy(10,3);
    cout << "    -  Recaudacion por clientes  -";
    gotoxy(3,4);
    cout << "------------------------------------------------------";
    gotoxy(5,5);
    cout << "ID";
    gotoxy(9,5);
    cout << "|";
    gotoxy(12,5);
    cout << "Apellidos";
    gotoxy(29,5);
    cout << "|";
    gotoxy(34,5);
    cout << "Nombres";
    gotoxy(45,5);
    cout << "|";
    gotoxy(46,5);
    cout << "Recaudacion";
    int y=6;
    int cont=0;
    while(fread(&Clientes,sizeof(ClsCliente),1,aCliente)==1)
    {
        IDActual=Clientes.getID();
        RecaudacionDelCliente=0;
        RecaudacionDelCliente=BuscarCliente(IDActual);
        gotoxy(5,y);
        cout << Clientes.getID();
        gotoxy(9,y);
        cout << "| " << Clientes.getApellidos();
        gotoxy(29,y);
        cout << "| " << Clientes.getNombres();
        gotoxy(45,y);
        cout << "| $" << RecaudacionDelCliente;
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(3,y);
            system("pause");
            y=6;
            cont=0;
            clrscr();
            system("COLOR 0F");
            recuadro(2,1,55,23,cBLANCO,cAZUL);
            gotoxy(3,2);
            cout << "------------------------------------------------------";
            gotoxy(10,3);
            cout << "    -  Recaudacion por clientes  -";
            gotoxy(3,4);
            cout << "------------------------------------------------------";
            gotoxy(5,5);
            cout << "ID";
            gotoxy(9,5);
            cout << "|";
            gotoxy(12,5);
            cout << "Apellidos";
            gotoxy(29,5);
            cout << "|";
            gotoxy(34,5);
            cout << "Nombres";
            gotoxy(45,5);
            cout << "|";
            gotoxy(46,5);
            cout << "Recaudacion";
        }
    }
    gotoxy(3,y);
    system("pause");
    fclose(aCliente);
}
int BuscarCliente(int IDActual)
{
    ClsVenta Ventas;
    FILE *aVenta;
    aVenta=fopen(ARCHIVO_VENTAS,"rb");
    float RecaudacionDelCliente=0;
    while(fread(&Ventas,sizeof(ClsVenta),1,aVenta)==1)
    {
        if(Ventas.getIDCliente()== IDActual)
        {
            RecaudacionDelCliente+=Ventas.getImporte();
        }
    }
    return RecaudacionDelCliente;
    fclose(aVenta);
}
void RecaudacionXmarca()
{
    int IDMarca;
    float RecaudacionDeLaMarca;
    ClsMarca Marcas;
    FILE *aMarca;
    aMarca=fopen(ARCHIVO_MARCAS,"rb");
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------";
    gotoxy(6,3);
    cout << "    -  Recaudacion por marcas  -";
    gotoxy(3,4);
    cout << "---------------------------------------";
    gotoxy(5,5);
    cout << "ID";
    gotoxy(9,5);
    cout << "|";
    gotoxy(12,5);
    cout << "Nombre";
    gotoxy(25,5);
    cout << "|";
    gotoxy(27,5);
    cout << "Recaudacion";
    int y=6;
    int cont=0;
    while(fread(&Marcas,sizeof(ClsMarca),1,aMarca)==1)
    {
        IDMarca=Marcas.getIDMarca();
        RecaudacionDeLaMarca=BuscarVentas(IDMarca);
        gotoxy(5,y);
        cout << Marcas.getIDMarca();
        gotoxy(9,y);
        cout << "| " << Marcas.getNombre();
        gotoxy(25,y);
        cout << "| " << RecaudacionDeLaMarca;
        y+=1;
        cont+=1;
        if(cont==17)
        {
            gotoxy(3,y);
            system("pause");
            y=6;
            cont=0;
            clrscr();
            system("COLOR 0F");
            recuadro(2,1,40,23,cBLANCO,cAZUL);
            gotoxy(3,2);
            cout << "------------------------------------------------------";
            gotoxy(6,3);
            cout << "    -  Recaudacion por marcas  -";
            gotoxy(3,4);
            cout << "------------------------------------------------------";
            gotoxy(5,5);
            cout << "ID";
            gotoxy(9,5);
            cout << "|";
            gotoxy(12,5);
            cout << "Nombre";
            gotoxy(25,5);
            cout << "|";
            gotoxy(27,5);
            cout << "Recaudacion";
        }
    }
    gotoxy(3,y);
    system("pause");
    fclose(aMarca);
}
int BuscarVentas(int IDMarca)
{
    int RecaudacionDeLaMarca=0;
    int IDCel;
    int MarcaVenta=0;
    ClsVenta Ventas;
    FILE *aVenta;
    aVenta=fopen(ARCHIVO_VENTAS,"rb");
    while(fread(&Ventas,sizeof(ClsVenta),1,aVenta)==1)
    {
        IDCel=Ventas.getIDCelular();
        MarcaVenta=BuscarMarca(IDCel);
        if(MarcaVenta == IDMarca)
        {
            RecaudacionDeLaMarca+=Ventas.getImporte();
        }
    }
    return RecaudacionDeLaMarca;
    fclose(aVenta);
}
int BuscarMarca(int IDCel)
{
    int MarcaVenta=0;
    ClsCelular Celulares;
    FILE *aCelular;
    aCelular=fopen(ARCHIVO_CELULARES,"rb");
    while(fread(&Celulares,sizeof(ClsCelular),1,aCelular)==1)
    {
        if(IDCel==Celulares.getIDCelular())
        {
            MarcaVenta=Celulares.getIDMarca();
            return MarcaVenta;
        }
    }
    fclose(aCelular);
}
void RecaudacionXmodelo()
{
    int IDCel;
    float RecaudacionDelModelo;
    ClsCelular Celulares;
    FILE *aCelular;
    aCelular=fopen(ARCHIVO_CELULARES,"rb");
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------";
    gotoxy(6,3);
    cout << "    -  Recaudacion por modelo  -";
    gotoxy(3,4);
    cout << "---------------------------------------";
    gotoxy(5,5);
    cout << "ID";
    gotoxy(9,5);
    cout << "|";
    gotoxy(12,5);
    cout << "Modelo";
    gotoxy(25,5);
    cout << "|";
    gotoxy(27,5);
    cout << "Recaudacion";
    int y=6;
    int cont=0;
    while(fread(&Celulares,sizeof(ClsCelular),1,aCelular)==1)
    {
        if(cont==17)
        {
            gotoxy(3,y);
            system("pause");
            y=6;
            cont=0;
            clrscr();
            system("COLOR 0F");
            recuadro(2,1,40,23,cBLANCO,cAZUL);
            gotoxy(3,2);
            cout << "---------------------------------------";
            gotoxy(6,3);
            cout << "    -  Recaudacion por modelo  -";
            gotoxy(3,4);
            cout << "---------------------------------------";
            gotoxy(5,5);
            cout << "ID";
            gotoxy(9,5);
            cout << "|";
            gotoxy(12,5);
            cout << "Modelo";
            gotoxy(25,5);
            cout << "|";
            gotoxy(27,5);
            cout << "Recaudacion";
        }
        IDCel=Celulares.getIDCelular();
        RecaudacionDelModelo=0;
        RecaudacionDelModelo=ContarLoRecaudado(IDCel);
        gotoxy(5,y);
        cout << Celulares.getIDCelular();
        gotoxy(9,y);
        cout << "| " << Celulares.getModelo();
        gotoxy(25,y);
        cout << "| " << RecaudacionDelModelo;
        y+=1;
        cont+=1;
    }
    gotoxy(3,y);
    system("pause");
    fclose(aCelular);
}
float ContarLoRecaudado(int IDCel)
{
    float RecaudacionDelModelo;
    ClsVenta Ventas;
    FILE *aVenta;
    aVenta=fopen(ARCHIVO_VENTAS,"rb");
    while(fread(&Ventas,sizeof(ClsVenta),1,aVenta)==1)
    {
        if(Ventas.getIDCelular()== IDCel)
        {
            RecaudacionDelModelo+=Ventas.getImporte();
        }
    }
    fclose(aVenta);
    return RecaudacionDelModelo;
}
void CantidadCelularesAnual()
{
    int CantidadMes[12];
    for(int z=0;z<12;z++)
    {
        CantidadMes[z]=0;
    }
    ClsVenta Ventas;
    FILE *aVentas;
    aVentas=fopen(ARCHIVO_VENTAS,"rb");
    int anioBuscado;
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,40,16,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------" << endl;
    gotoxy(3,3);
    cout << "-Cantidad de Celulares vendidos Anual-" << endl;
    gotoxy(3,4);
    cout << "---------------------------------------" << endl;
    gotoxy(3,5);
    cout << "Ingrese anio a buscar: ";
    cin >> anioBuscado;
    while(fread(&Ventas,sizeof(ClsVenta),1,aVentas)==1)
    {
        if(anioBuscado==Ventas.getFechaVenta().getAnio())
        {
            for(int x=0;x<12;x++)
            {
                if(x+1==Ventas.getFechaVenta().getMes())
                {
                    CantidadMes[x] += Ventas.getCantidad();
                }
            }
        }

    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,42,16,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "-----------------------------------------" << endl;
    gotoxy(3,3);
    cout << "-Cantidad de Celulares vendidos en " << anioBuscado << " -" << endl;
    gotoxy(3,4);
    cout << "-----------------------------------------" << endl;
    int y=5;
    for(int i=0;i<12;i++)
    {
        gotoxy(6,y);
        cout << "Mes " << i+1 << ": " << CantidadMes[i] << endl;
        y+=1;
    }
    pause();
    fclose(aVentas);
}
void BackupClientes()
{
    ClsCliente Clientes;
    FILE *aClientes, *BACKUP;
    aClientes=fopen(ARCHIVO_CLIENTES,"rb");
    if(aClientes==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("CLientes.bak","wb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Clientes, sizeof(ClsCliente), 1, aClientes)==1)
    {
        fwrite(&Clientes, sizeof(ClsCliente),1, BACKUP);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  BACKUP ARCHIVO CLIENTES  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Backup creado";
    pause();
    fclose(aClientes);
    fclose(BACKUP);
}
void BackupCelulares()
{
    ClsCelular Celulares;
    FILE *aCelulares, *BACKUP;
    aCelulares=fopen(ARCHIVO_CELULARES,"rb");
    if(aCelulares==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("Celulares.bak","wb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Celulares, sizeof(ClsCelular), 1, aCelulares)==1)
    {
        fwrite(&Celulares, sizeof(ClsCelular),1, BACKUP);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  BACKUP ARCHIVO CELULARES  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Backup creado";
    pause();
    fclose(aCelulares);
    fclose(BACKUP);
}
void BackupMarcas()
{
    ClsMarca Marcas;
    FILE *aMarcas, *BACKUP;
    aMarcas=fopen(ARCHIVO_MARCAS,"rb");
    if(aMarcas==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("Marcas.bak","wb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Marcas, sizeof(ClsMarca), 1, aMarcas)==1)
    {
        fwrite(&Marcas, sizeof(ClsMarca),1, BACKUP);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  BACKUP ARCHIVO MARCAS  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Backup creado";
    pause();
    fclose(aMarcas);
    fclose(BACKUP);
}
void BackupVentas()
{
    ClsVenta Ventas;
    FILE *aVentas, *BACKUP;
    aVentas=fopen(ARCHIVO_VENTAS,"rb");
    if(aVentas==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("Ventas.bak","wb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Ventas, sizeof(ClsVenta), 1, aVentas)==1)
    {
        fwrite(&Ventas, sizeof(ClsVenta),1, BACKUP);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  BACKUP ARCHIVO VENTAS  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Backup creado";
    pause();
    fclose(aVentas);
    fclose(BACKUP);
}
void BackupTodosLosArchivos()
{
    BackupCelulares();
    BackupClientes();
    BackupMarcas();
    BackupVentas();
}
void RestauracionClientes()
{
    ClsCliente Clientes;
    FILE *aClientes, *BACKUP;
    aClientes=fopen(ARCHIVO_CLIENTES,"wb");
    if(aClientes==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("CLientes.bak","rb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Clientes, sizeof(ClsCliente), 1, BACKUP)==1)
    {
        fwrite(&Clientes, sizeof(ClsCliente),1, aClientes);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  RESTAURACION ARCHIVO CLIENTES  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Restauracion creada";
    pause();
    fclose(aClientes);
    fclose(BACKUP);
}
void RestauracionCelulares()
{
    ClsCelular Celualres;
    FILE *aCelulares, *BACKUP;
    aCelulares=fopen(ARCHIVO_CELULARES,"wb");
    if(aCelulares==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("Celulares.bak","rb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Celualres, sizeof(ClsCelular), 1, BACKUP)==1)
    {
        fwrite(&Celualres, sizeof(ClsCelular),1, aCelulares);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  RESTAURACION ARCHIVO CELULARES  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Restauracion creada";
    pause();
    fclose(aCelulares);
    fclose(BACKUP);
}
void RestauracionMarcas()
{
    ClsMarca Marcas;
    FILE *aMarca, *BACKUP;
    aMarca=fopen(ARCHIVO_MARCAS,"wb");
    if(aMarca==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("Marcas.bak","rb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Marcas, sizeof(ClsMarca), 1, BACKUP)==1)
    {
        fwrite(&Marcas, sizeof(ClsMarca),1, aMarca);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  RESTAURACION ARCHIVO MARCAS  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Restauracion creada";
    pause();
    fclose(aMarca);
    fclose(BACKUP);
}
void RestauracionVentas()
{
    ClsVenta Ventas;
    FILE *aVentas, *BACKUP;
    aVentas=fopen(ARCHIVO_VENTAS,"wb");
    if(aVentas==NULL)
    {
        exit(1);
    }
    BACKUP=fopen("Ventas.bak","rb");
    if(BACKUP==NULL)
    {
        exit(1);
    }
    while(fread(&Ventas, sizeof(ClsVenta), 1, BACKUP)==1)
    {
        fwrite(&Ventas, sizeof(ClsVenta),1, aVentas);
    }
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,41,15,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "----------------------------------------" << endl;
    gotoxy(7,3);
    cout << "-  RESTAURACION ARCHIVO VENTAS  -" << endl;
    gotoxy(3,4);
    cout << "----------------------------------------" << endl;
    gotoxy(14,8);
    cout << "Restauracion creada";
    pause();
    fclose(aVentas);
    fclose(BACKUP);
}
void RestauracionTodosLosArchivos()
{
    RestauracionCelulares();
    RestauracionClientes();
    RestauracionMarcas();
    RestauracionVentas();
}
///-----------------------FUNCIONES ADICIONALES----------------------
///Leer registros.
void leerClientes(ClsCliente *vectorClientes){
    FILE *aClientes = fopen(ARCHIVO_CLIENTES,"rb");
    if(aClientes == NULL){
        exit(1);
    }
    int i = 0;
    while(fread(&vectorClientes[i],sizeof(ClsCliente),1,aClientes)){
        i++;
    }
    fclose(aClientes);
}
void leerCelulares(ClsCelular *vectorCelulares){
    FILE *aCelulares = fopen(ARCHIVO_CELULARES,"rb");
    if(aCelulares == NULL){
        exit(1);
    }
    int i = 0;
    while(fread(&vectorCelulares[i],sizeof(ClsCelular),1,aCelulares)){
        i++;
    }
    fclose(aCelulares);
}
void leerVentas (ClsVenta *vectorVentas){
    FILE* aVentas = fopen(ARCHIVO_VENTAS,"rb");
    if(aVentas == NULL){
        exit(1);
    }
    int i = 0;
    while(fread(&vectorVentas[i],sizeof(ClsVenta),1,aVentas)){
        i++;
    }
    fclose(aVentas);
}
void leerMarcas(ClsMarca *vectorMarcas){
    FILE *aMarcas = fopen(ARCHIVO_MARCAS,"rb");
    if(aMarcas == NULL){
        exit(1);
    }
    int i = 0;
    while(fread(&vectorMarcas[i],sizeof(ClsMarca),1,aMarcas)){
        i++;
    }
    fclose(aMarcas);
}
///-----Ordenamiento de vectores.
//Ordenar por apellido.
void ordenarPorApellido(ClsCliente *vectorClientes, int tam){
    for(int i = 0; i < tam; i++){
        for(int j=0 ; j< tam-1 ;j++){
            if(strcmp(vectorClientes[j].getApellidos(), vectorClientes[j+1].getApellidos())> 0){
                ClsCliente aux = vectorClientes[j];
                vectorClientes[j] = vectorClientes[j+1];
                vectorClientes[j+1] = aux;
            }
        }
    }
}
//Ordenar por edad
void ordenarPorEdad(ClsCliente *vectorClientes, int tam){
    for(int i = 0; i < tam; i++){
        for(int j=0 ; j < tam-1 ;j++){
            if(vectorClientes[j].getEdad() > vectorClientes[j+1].getEdad()){
                ClsCliente aux = vectorClientes[j];
                vectorClientes[j] = vectorClientes[j+1];
                vectorClientes[j+1] = aux;
            }
        }
    }
}
//Ordenar por modelo.
void ordenarPorModelo(ClsCelular *vectorCelulares,int tam){
      for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam-1; j++){
            if(strcmp(vectorCelulares[j].getModelo(),vectorCelulares[j+1].getModelo()) > 0){
                ClsCelular aux = vectorCelulares[j];
                vectorCelulares[j] = vectorCelulares[j+1];
                vectorCelulares[j+1] = aux;
            }
        }
    }
}
//Ordenar por precio.
void ordenarPorPrecio(ClsCelular *vectorCelulares, int tam){
      for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam-1; j++){
            if(vectorCelulares[j].getPrecio() < vectorCelulares[j+1].getPrecio()){
                ClsCelular aux = vectorCelulares[j];
                vectorCelulares[j] = vectorCelulares[j+1];
                vectorCelulares[j+1] = aux;
            }
        }
    }
}
//Ordenar marcas alfabeticamente.
void ordenarMarcas(ClsMarca *vectorMarcas, int tam){
      for(int i = 0; i < tam; i++){
          for(int j = 0; j < tam-1; j++){
            if(strcmp(vectorMarcas[j].getNombre(),vectorMarcas[j+1].getNombre())> 0){
                ClsMarca aux = vectorMarcas[j];
                vectorMarcas[j] = vectorMarcas[j+1];
                vectorMarcas[j+1] = aux;
            }
          }
      }
}
//Ordenar por fechas.
void ordenarPorFecha(ClsCelular *vectorCelulares, int tam){
     for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam-1; j++){
            if(compararFechas(vectorCelulares[j].getFechaLanzamiento(), vectorCelulares[j+1].getFechaLanzamiento()) < 0){
                ClsCelular aux = vectorCelulares[j];
                vectorCelulares[j] = vectorCelulares[j+1];
                vectorCelulares[j+1] = aux;
            }
        }
     }
}
void ordenarPorFecha(ClsVenta *vectorVentas, int tam){
     for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam-1; j++){
            if(compararFechas(vectorVentas[j].getFechaVenta(), vectorVentas[j+1].getFechaVenta()) < 0){
                ClsVenta aux = vectorVentas[j];
                vectorVentas[j] = vectorVentas[j+1];
                vectorVentas[j+1] = aux;
            }
        }
     }
}
int compararFechas(ClsFecha fecha1, ClsFecha fecha2){
    if(fecha1.getAnio() < fecha2.getAnio()){
        return -1;
    }
    else if(fecha1.getAnio() > fecha2.getAnio()){
        return 1;
    }
    if(fecha1.getMes() < fecha2.getMes()){
        return -1;
    }
    else if(fecha1.getMes() > fecha2.getMes()){
        return 1;
    }
    if(fecha1.getDia() < fecha2.getDia()){
        return -1;
    }
    else if(fecha1.getDia() > fecha2.getDia()){
        return 1;
    }
    return 0;
}
///Validaciones para consultas.
bool validarMarca(char *nombre){
    FILE *aMarcas = fopen(ARCHIVO_MARCAS,"rb");
    if(aMarcas == NULL){exit(1);}
    ClsMarca m;
    while(fread(&m,sizeof(ClsMarca),1,aMarcas)){
        if(strcmp(nombre,m.getNombre()) == 0){
            fclose(aMarcas);
            return true;
        }
    }
    fclose(aMarcas);
    return false;
}
bool validarAlmacenamiento(int almacenamiento){
    FILE *aCelulares = fopen(ARCHIVO_CELULARES,"rb");
    if(aCelulares == NULL){exit(1);}
    ClsCelular c1;
    while(fread(&c1,sizeof(ClsCelular),1,aCelulares)){
        if(c1.getAlmacenamiento()== almacenamiento){
            fclose(aCelulares);
            return true;
        }
    }
    fclose(aCelulares);
    return false;
}
bool validarMemoriaRam(int memoria){
    FILE *aCelulares = fopen(ARCHIVO_CELULARES,"rb");
    if(aCelulares == NULL){exit(1);}
    ClsCelular c1;
    while(fread(&c1,sizeof(ClsCelular),1,aCelulares)){
        if(c1.getMemoriaRAM()== memoria){
            fclose(aCelulares);
            return true;
        }
    }
    fclose(aCelulares);
    return false;
}
bool validarModelo(char *modelo){
    FILE *aCelulares = fopen(ARCHIVO_CELULARES,"rb");
    if(aCelulares == NULL){exit(1);}
    ClsCelular c1;
    while(fread(&c1,sizeof(ClsCelular),1,aCelulares)){
        if(strcmp(modelo,c1.getModelo())== 0){
            fclose(aCelulares);
            return true;
        }
    }
    fclose(aCelulares);
    return false;
}
///Contadores.
int contarClientes(){
    int contador = 0;
    FILE *aClientes = fopen(ARCHIVO_CLIENTES,"rb");
    if(aClientes == NULL){
        exit(1);
    }
    ClsCliente c1;
    while(fread(&c1,sizeof(ClsCliente),1,aClientes)){
        contador++;
    }
    fclose(aClientes);
    return contador;
}
int contarCelulares(){
    int contador = 0;
    FILE *aCelulares = fopen(ARCHIVO_CELULARES,"rb");
    if(aCelulares == NULL){
        exit(1);
    }
    ClsCelular c1;
    while(fread(&c1,sizeof(ClsCelular),1,aCelulares)){
        contador++;
    }
    fclose(aCelulares);
    return contador;
}
int contarMarcas(){
    int contador = 0;
    FILE *aMarcas = fopen(ARCHIVO_MARCAS,"rb");
    if(aMarcas == NULL){
        exit(1);
    }
    ClsMarca c1;
    while(fread(&c1,sizeof(ClsMarca),1,aMarcas)){
        contador++;
    }
    fclose(aMarcas);
    return contador;
}
int contarVentas(){
    int contador = 0;
    FILE *aVentas = fopen(ARCHIVO_VENTAS,"rb");
    if(aVentas == NULL){
        exit(1);
    }
    ClsVenta v1;
    while(fread(&v1,sizeof(ClsVenta),1,aVentas)){
        contador++;
    }
    fclose(aVentas);
    return contador;
}
void InterfazClientes(string titulo,int posicion)
{
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,115,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    gotoxy(posicion,3);
    cout << titulo << endl;
    gotoxy(3,4);
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    gotoxy(6,5);
    cout << "DNI";
    gotoxy(12,5);
    cout << "|";
    gotoxy(15,5);
    cout << "Apellidos";
    gotoxy(32,5);
    cout << "|";
    gotoxy(37,5);
    cout << "Nombres";
    gotoxy(48,5);
    cout << "|";
    gotoxy(49,5);
    cout << "Edad";
    gotoxy(53,5);
    cout << "|";
    gotoxy(57,5);
    cout << "Fecha";
    gotoxy(65,5);
    cout << "|";
    gotoxy(67,5);
    cout << "ID";
    gotoxy(71,5);
    cout << "|";
    gotoxy(73,5);
    cout << "Domicilio";
    gotoxy(83,5);
    cout << "|";
    gotoxy(85,5);
    cout << "Telefono";
    gotoxy(95,5);
    cout << "|";
    gotoxy(98,5);
    cout << "Correo";
}
void InterfazCelulares(string titulo,int posicion)
{
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,79,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "------------------------------------------------------------------------------" << endl;
    gotoxy(posicion,3);
    cout << titulo << endl;
    gotoxy(3,4);
    cout << "------------------------------------------------------------------------------" << endl;
    gotoxy(5,5);
    cout << "ID";
    gotoxy(9,5);
    cout << "|";
    gotoxy(11,5);
    cout << "Marca";
    gotoxy(17,5);
    cout << "|";
    gotoxy(23,5);
    cout << "Modelo";
    gotoxy(34,5);
    cout << "|";
    gotoxy(38,5);
    cout << "Fecha";
    gotoxy(46,5);
    cout << "|";
    gotoxy(47,5);
    cout << "Espacio";
    gotoxy(54,5);
    cout << "|";
    gotoxy(56,5);
    cout << "RAM";
    gotoxy(60,5);
    cout << "|";
    gotoxy(63,5);
    cout << "Precio";
    gotoxy(70,5);
    cout << "|";
    gotoxy(71,5);
    cout << "Stock";
}
void InterfazMarcas(string titulo,int posicion)
{
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,58,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "---------------------------------------------------------" << endl;
    gotoxy(posicion,3);
    cout << titulo << endl;
    gotoxy(3,4);
    cout << "---------------------------------------------------------" << endl;
    gotoxy(5,5);
    cout << "ID";
    gotoxy(9,5);
    cout << "|";
    gotoxy(11,5);
    cout << "Nombre";
    gotoxy(20,5);
    cout << "|";
    gotoxy(23,5);
    cout << "Pais de origen";
    gotoxy(40,5);
    cout << "|";
    gotoxy(42,5);
    cout << "Fecha de fundacion";
}
void InterfazVentas(string titulo,int posicion)
{
    clrscr();
    system("COLOR 0F");
    recuadro(2,1,90,23,cBLANCO,cAZUL);
    gotoxy(3,2);
    cout << "-----------------------------------------------------------------------------------------" << endl;
    gotoxy(posicion,3);
    cout << titulo << endl;
    gotoxy(3,4);
    cout << "-----------------------------------------------------------------------------------------" << endl;
    gotoxy(5,5);
    cout << "ID";
    gotoxy(9,5);
    cout << "|";
    gotoxy(11,5);
    cout << "Fecha";
    gotoxy(22,5);
    cout << "|";
    gotoxy(23,5);
    cout << "ID cliente";
    gotoxy(33,5);
    cout << "|";
    gotoxy(34,5);
    cout << "ID Celular";
    gotoxy(44,5);
    cout << "|";
    gotoxy(45,5);
    cout << "Precio unitario";
    gotoxy(60,5);
    cout << "|";
    gotoxy(61,5);
    cout << "Cantidad";
    gotoxy(69,5);
    cout << "|";
    gotoxy(70,5);
    cout << "Forma de Pago";
    gotoxy(83,5);
    cout << "|";
    gotoxy(84,5);
    cout << "Importe";
}
#endif // FUNCIONES_H_INCLUDED
