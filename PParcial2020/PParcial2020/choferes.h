#define OCUPADO 0
#define LIBRE -1
#include "validation.h"
typedef struct
{
    int Legajo;
    int idChofer;
    char apellido[20];
    char nombre[20];
    int dni;
    char nacionalidad[20];
    char sexo;
    int telefono;
    int edad;
    int estadoChofer;
    int cantCamiones;
} eChofer;

//*******NORMALIZAR-HARCODEO**********************************
void HardcodeoChoferes(eChofer [], int);
void inicializarChoferes(eChofer listadoChoferes[],int tamChofer);
//**********MOSTRAR********************************************
void MostrarChofer(eChofer chofer);
void MostrarListadoChofer(eChofer [], int );

//*********BUSQUEDA:---****************************************
eChofer buscarChofer(eChofer listadoChoferes[],int tam,int id);
int buscarLibreChofer(eChofer chofer[],int tamChofer);
int buscarChoferPorId(eChofer chofer[],int tamChofer,int idChofer);

//*********ALTA-MODIFICAR************************************************
int altaChofer(eChofer chofer[],int cantCho, int idChofer);
int modificarChofer(eChofer chofer[], int tamChofer);

