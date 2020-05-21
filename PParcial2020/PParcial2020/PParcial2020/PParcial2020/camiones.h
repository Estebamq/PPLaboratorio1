#define OCUPADO 0
#define LIBRE -1
#define ANIOANTIGUEDAD 2020//para el promedio de los anios de antiguedad de los camiones
#define  ANIO   2010  //marca la cantidad de antiguedad en los camiones(en este caso 10 anios)
#include "choferes.h"

typedef struct
{
    int idCamion;
    int idChofer;
    char patente[20];
    char marca[20];
    int anio;
    float peso;
    int cantRuedas;
    char tipo[25];
    int estadoCamiones;
} eCamiones;

//*******NORMALIZAR-HARCODEO*****************************************************************
void inicialiazarCamiones(eCamiones listadoCamiones[],int tamC);
void HardcodeoCamiones(eCamiones [], int);
//**********MOSTRAR**************************************************************************
void mostrarCamiones(eCamiones camion,eChofer listadoChofer[],int tamC);
void MostrarListadoCamiones(eCamiones listadoCamiones[], int tam,eChofer listadoChofer[],int tamChofer);
void MostrarListadoCamionesConMasDeAnio(eCamiones listadoCamiones[], int tamC,eChofer listadoChofer[],int tamCho);
int MostrarListadoCamionesPorMarca(eCamiones listadoCamiones[], int tamC,eChofer listadoChofer[],int tamCho);
//***********************BUSQUEDA: ESPACIO LIBRE- BUSCAR CAMION -BUSCAR CAMION POR ID*********
int buscarLibreCam(eCamiones camiones[],int tam);
int buscarOcupadoCam(eCamiones camiones[],int tam);
eCamiones buscarCamion(eCamiones listadocamiones[],int tam,int idCamiones);
//********************ALTA CAMION-BAJA CAMION-MODIFICACION************************************
int altaCamiones(eCamiones camion[],int tamCam,eChofer chofer[],int cantCho,int idCamion);
int bajaCamiones(eCamiones camion[],int tamCam,eChofer chofer[], int tanCho);
int modificarCamiones(eCamiones camion[], int tamCamion,eChofer chofer[], int tamChofer);
//*******************MOSTRAR CAMIONES POR TIPO Y SUS CHOFERES********************************
int ordenarListadoCamionesPorTipo(eCamiones listadoCamiones[], int tamC,eChofer listadoChofer[],int tamCho);
//*******************CONTAR CANTIDAD DE CAMIONES*********************************************
int contarCantidadDeCamiones(eCamiones camion[],int tamCamion,int idChofer);
//******************PROMEDIO ANTIGUEDAD DE CAMIONES*****************************************
float promedioAntiguedadCamiones(eCamiones Camiones[],int cantCamiones);
