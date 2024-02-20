#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <windows.h>
#include <iostream>
#include "graficos.h"
#include "Funciones.h"


using namespace std;

void MenuCargaDeDatos();
void MenuListados();
void MenuConsultas();
void MenuReportes();
void MenuConfiguraciones();
void MenuBackups();
void MenuRestauraciones();
void SubMenuListadoClientes();
void SubMenuListadoCelulares();
void SubMenuConsultaClientes();
void SubMenuConsultaCelulares();
void SubMenuConsultaVentas();

int MenuPrincipal()
{
    int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU PRINCIPAL  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(10,5);
        cout << "   1 - CARGA DE DATOS" << endl;
        gotoxy(10,6);
        cout << "   2 - LISTADOS" << endl;
        gotoxy(10,7);
        cout << "   3 - CONSULTAS" << endl;
        gotoxy(10,8);
        cout << "   4 - REPORTES" << endl;
        gotoxy(10,9);
        cout << "   5 - CONFIGURACIONES" << endl;
        gotoxy(3,10);
        cout << "---------------------------------------" << endl;
        gotoxy(13,11);
        cout << "   0 - SALIR" << endl;
        cout << endl;
        gotoxy(3,13);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 0:
            cout << endl << endl;
            return false;
            break;
        case 1:
            clrscr();
            MenuCargaDeDatos();
            break;
        case 2:
            clrscr();
            MenuListados();
            break;
        case 3:
            clrscr();
            MenuConsultas();
            break;
        case 4:
            clrscr();
            MenuReportes();
            break;
        case 5:
            clrscr();
            MenuConfiguraciones();
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void MenuCargaDeDatos()
{
        int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU CARGA DE DATOS  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(10,5);
        cout << "   1 - CARGAR CLIENTES" << endl;
        gotoxy(10,6);
        cout << "   2 - CARGAR CELULARES" << endl;
        gotoxy(10,7);
        cout << "   3 - CARGAR MARCAS" << endl;
        gotoxy(10,8);
        cout << "   4 - CARGAR VENTAS" << endl;
        gotoxy(3,9);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - SALIR" << endl;
        cout << endl;
        gotoxy(3,13);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            CargarClientes();
            break;
        case 2:
            clrscr();
            CargarCelulares();
            break;
        case 3:
            clrscr();
            CargarMarcas();
            break;
        case 4:
            clrscr();
            CargarVentas();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void MenuListados(){
    int opc;

    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU LISTADOS  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(8,5);
        cout << "   1 - Listado de Clientes" << endl;
        gotoxy(8,6);
        cout << "   2 - Listado de Celulares" << endl;
        gotoxy(8,7);
        cout << "   3 - Listado de Marcas" << endl;
        gotoxy(8,8);
        cout << "   4 - Listado de Ventas" << endl;
        gotoxy(3,9);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
            case 1:
                clrscr();
                SubMenuListadoClientes();
            break;
            case 2:
                clrscr();
                SubMenuListadoCelulares();
            break;
            case 3:
                clrscr();
                ListadoMarcas();
            break;
            case 4:
                clrscr();
                ListadoVentas();
            break;
            case 0:
                cout << endl << endl;
                return;
            break;
            default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}

void MenuConsultas(){
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU CONSULTAS  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(8,5);
        cout << "   1 - Consulta de Clientes" << endl;
        gotoxy(8,6);
        cout << "   2 - Consulta de Celulares" << endl;
        gotoxy(8,7);
        cout << "   3 - Consulta de Ventas"      << endl;
        gotoxy(3,8);
        cout << "---------------------------------------" << endl;
        gotoxy(13,9);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            SubMenuConsultaClientes();
            break;
        case 2:
            clrscr();
            SubMenuConsultaCelulares();
            break;
        case 3:
            clrscr();
            SubMenuConsultaVentas();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}

void MenuReportes(){
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,46,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------------" << endl;
        gotoxy(13,3);
        cout << "-  MENU REPORTES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------------" << endl;
        gotoxy(5,5);
        cout << "   1 - Recaudacion Anual" << endl;
        gotoxy(5,6);
        cout << "   2 - Recaudacion por Cliente" << endl;
        gotoxy(5,7);
        cout << "   3 - Recaudacion por Marca" << endl;
        gotoxy(5,8);
        cout << "   4 - Recaudacion por Modelo" << endl;
        gotoxy(5,9);
        cout << "   5 - Cantidad de celulares vendidos anual" << endl;
        gotoxy(3,10);
        cout << "---------------------------------------------" << endl;
        gotoxy(13,11);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            RecuadacionAnual();
            break;
        case 2:
            clrscr();
            RecaudacionXclientes();
            break;
        case 3:
            clrscr();
            RecaudacionXmarca();
            break;
        case 4:
            clrscr();
            RecaudacionXmodelo();
            break;
        case 5:
            clrscr();
            CantidadCelularesAnual();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void MenuConfiguraciones(){
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU CONFIGURACIONES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "   1 - Crear Backups" << endl;
        gotoxy(6,6);
        cout << "   2 - Restaurar Archivos" << endl;
        gotoxy(3,7);
        cout << "---------------------------------------" << endl;
        gotoxy(13,9);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,11);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            MenuBackups();
            break;
        case 2:
            clrscr();
            MenuRestauraciones();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}

void MenuBackups(){
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(11,3);
        cout << "-  MENU BACKUPS  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(3,5);
        cout << "1 - Crear Backup del archivo Clientes" << endl;
        gotoxy(3,6);
        cout << "2 - Crear Backup del archivo Celulares" << endl;
        gotoxy(3,7);
        cout << "3 - Crear Backup del archivo Marcas" << endl;
        gotoxy(3,8);
        cout << "4 - Crear Backup del archivo Ventas" << endl;
        gotoxy(3,9);
        cout << "5 - Crear Backup de todos los archivos" << endl;
        gotoxy(3,10);
        cout << "---------------------------------------" << endl;
        gotoxy(13,11);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            BackupClientes();
            break;
        case 2:
            clrscr();
            BackupCelulares();
            break;
        case 3:
            clrscr();
            BackupMarcas();
            break;
        case 4:
            clrscr();
            BackupVentas();
            break;
        case 5:
            clrscr();
            BackupTodosLosArchivos();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}

void MenuRestauraciones(){
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(12,3);
        cout << "-  MENU RESTAURACIONES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "1 - Restaurar el archivo Clientes" << endl;
        gotoxy(6,6);
        cout << "2 - Restaurar el archivo Celulares" << endl;
        gotoxy(3,7);
        cout << "3 - Restaurar el archivo Marcas" << endl;
        gotoxy(3,8);
        cout << "4 - Restaurar el archivo Ventas" << endl;
        gotoxy(3,9);
        cout << "5 - Restaurar todos los archivos" << endl;
        gotoxy(3,10);
        cout << "---------------------------------------" << endl;
        gotoxy(13,11);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            RestauracionClientes();
            break;
        case 2:
            clrscr();
            RestauracionCelulares();
            break;
        case 3:
            clrscr();
            RestauracionMarcas();
            break;
        case 4:
            clrscr();
            RestauracionVentas();
            break;
        case 5:
            clrscr();
            RestauracionTodosLosArchivos();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void SubMenuListadoClientes()
{
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(6,3);
        cout << "-  SUBMENU LISTADOS DE CLIENTES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "1 - Ordenados por Apellido" << endl;
        gotoxy(6,6);
        cout << "2 - Ordenados por Edad" << endl;
        gotoxy(3,7);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            ListadoClienteXapellido();
            break;
        case 2:
            clrscr();
            ListadoClienteXedad();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void SubMenuListadoCelulares()
{
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,44,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "-------------------------------------------" << endl;
        gotoxy(6,3);
        cout << "-  SUBMENU LISTADOS DE CELULARES  -" << endl;
        gotoxy(3,4);
        cout << "-------------------------------------------" << endl;
        gotoxy(6,5);
        cout << "1 - Ordenados por marca" << endl;
        gotoxy(6,6);
        cout << "2 - Ordenados por fecha de lanzamiento" << endl;
        gotoxy(6,7);
        cout << "3 - Ordenados por precio" << endl;
        gotoxy(6,8);
        cout << "4 - Ordenados por modelo" << endl;
        gotoxy(3,9);
        cout << "-------------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            ListadoCelularesXmarca();
            break;
        case 2:
            clrscr();
            ListadoCelularesXfechadelanzamiento();
            break;
        case 3:
            clrscr();
            ListadoCelularesXprecio();
            break;
        case 4:
            clrscr();
            ListadoCelularesXmodelo();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void SubMenuConsultaClientes()
{
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(6,3);
        cout << "-  SUBMENU CONSULTAS DE CLIENTES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "1 - Consulta por DNI" << endl;
        gotoxy(6,6);
        cout << "2 - Consultas por rango de Edad" << endl;
        gotoxy(3,7);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            ConsultaCLientesXdni();
            break;
        case 2:
            clrscr();
            ConsultaCLientesXrangodeEdad();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void SubMenuConsultaCelulares()
{
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(6,3);
        cout << "-  SUBMENU CONSULTAS DE CELULARES  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(4,5);
        cout << "1 - Consultas por marca" << endl;
        gotoxy(4,6);
        cout << "2 - Consultas por fecha de lanzamiento" << endl;
        gotoxy(4,7);
        cout << "3 - Consultas por rango de precio" << endl;
        gotoxy(4,8);
        cout << "4 - Consultas por almacenamiento" << endl;
        gotoxy(4,9);
        cout << "5 - Consultas por memoria RAM" << endl;
        gotoxy(3,10);
        cout << "---------------------------------------" << endl;
        gotoxy(13,11);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            ConsultaCelularesXmarca();
            break;
        case 2:
            clrscr();
            ConsultaCelularesXfechadelanzamiento();
            break;
        case 3:
            clrscr();
            ConsultaCelularesXrangodeprecio();
            break;
        case 4:
            clrscr();
            ConsultaCelularesXalmacenamiento();
            break;
        case 5:
            clrscr();
            ConsultaCelularesXmemoriaRAM();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
void SubMenuConsultaVentas()
{
    int opc;
    while(true){
        clrscr();
        system("COLOR 0F");
        recuadro(2,1,40,13,cBLANCO,cAZUL);
        gotoxy(3,2);
        cout << "---------------------------------------" << endl;
        gotoxy(6,3);
        cout << "-  SUBMENU CONSULTAS DE VENTAS  -" << endl;
        gotoxy(3,4);
        cout << "---------------------------------------" << endl;
        gotoxy(6,5);
        cout << "   1 - Consultas por rango de fecha" << endl;
        gotoxy(6,6);
        cout << "   2 - Consultas por marca" << endl;
        gotoxy(6,7);
        cout << "   3 - Consultas por modelo" << endl;
        gotoxy(3,8);
        cout << "---------------------------------------" << endl;
        gotoxy(13,10);
        cout << "   0 - REGRESAR" << endl;
        cout << endl;
        gotoxy(3,12);
        cout << "OPCION: ";
        cin >> opc;

        switch(opc){
        case 1:
            clrscr();
            ConsultaVentasXrangodefecha();
            break;
        case 2:
            clrscr();
            ConsultaVentasXmarca();
            break;
        case 3:
            clrscr();
            ConsultaVentasXmodelo();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            int color = 7 | (12 << 4);
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(13,13);
            cout << "OPCION INCORRECTA" << endl;
            pause();
            recuadro(2,1,40,13,cBLANCO,cAZUL);
            break;
        }
    }
}
#endif // MENU_H_INCLUDED
