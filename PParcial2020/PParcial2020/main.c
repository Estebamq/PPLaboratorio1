#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferesCamiones.h"
#define TCAMIONES 25
#define TCHOFERES 10

int main()
{
    eChofer listadoChofer[TCHOFERES];
    eCamiones listadoCamiones[TCAMIONES];
    int opcion;
    int idCamion=100;
    int idChofer=1000;

    inicialiazarCamiones(listadoCamiones,TCAMIONES);
    inicializarChoferes(listadoChofer,TCHOFERES);
    HardcodeoChoferes(listadoChofer, 6);
    HardcodeoCamiones(listadoCamiones, 10);

    do
    {

        //************PRIMERA PARTE***********************************************
        //**********LISTADOS******************************************************

        printf("***************Choferes************\n");
        MostrarListadoChofer(listadoChofer, TCHOFERES);
        /*printf("\n***************Camiones Con Choferes************\n");
        MostrarListadoCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);*/

        printf("\n***************Choferes con Camiones************\n");
        printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
        MostrarChoferCamiones(listadoChofer, TCHOFERES, listadoCamiones, TCAMIONES);
        //-------------------------------------------------------------------------

        //************SEGUNDA PARTE***********************************************
        // ************ABM CAMIONES***********"

        //system("cls");
        printf("\n*******Alta Camiones*******\n");
        printf("\n1-Alta Camiones: \n2-Baja Camiones: \n3-Modificar Camiones\n4-Mostrar Camiones con Chofer\n5-Alta de Chofer\n6-Baja de chofer\n7-Mostrar Camiones Por Tipo\n8-Modificar Chofer\n9-Mostrar choferes con mas de un camion\n10-Camiones con mas de 10 anios\n20-Salir.\nIngrese opcion: ");
        scanf("%d",&opcion);
        //system("pause");
        switch(opcion)
        {
        case 1:
            //system("cls");
            printf("\n*******Alta Camiones*******\n\n");
            if(altaCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES,idCamion))
            {
                idCamion++;
                printf("\nse realizo el alta con exito!!\n");
            }
            else
            {
                printf("\n Error, no se realizo el alta\n");
            }
            //system("pause");
            break;
        case 2:
            //system("cls");
            printf("******Baja Camiones******");
            printf("\nID: \t Patente: \t Marca: \t  Anio: \t   Peso: \t  Cant Ruedas: \t  Tipo: \t   Nombre Chofer: \n");
            MostrarListadoCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);
            if( bajaCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES))
            {
                printf("\nse realizo la baja con exito!!\n");
            }
            else
            {
                printf("\n Error, no se realizo la baja\n");
            }

            //system("pause");
            break;
        case 3:
            //system("cls");
            printf("*******Modificar Camiones******");
            MostrarListadoCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);
            if( modificarCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES))
            {
                printf("\nse realizo la Modificacion con exito!!\n");
            }
            else
            {
                printf("\n Error, no se realizo la Modificacion\n");
            }
            //system("pause");
            break;
        case 4:
            //system("cls");
            printf("\n******Mostrar Camiones con Chofer******\n");
            printf("\nID: \t Patente: \t Marca: \t  Anio: \t   Peso: \t  Cant Ruedas: \t  Tipo: \t   Nombre Chofer: \n");
            MostrarListadoCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);
            printf("\n");
            //system("pause");
            break;

        //*******************TERCERA PARTE****************************************************
        //*****************CHOFER:ALTA-BAJA-ORDENAR ********************************************************
        case 5:
            //system("cls");
            printf("\n*******Alta Chofer*******\n\n");
            if(altaChofer(listadoChofer,TCHOFERES,idChofer))
            {
                idChofer++;
                printf("\nse realizo el alta con exito!!\n");
            }
            else
            {
                printf("\n Error, no se realizo el alta\n");
            }
            //system("pause");
            break;
        case 6:
            //system("cls");
            printf("\n*******BAJA CHOFER*******\n\n");
            if(bajaChoferCascada(listadoChofer,TCHOFERES,listadoCamiones,TCAMIONES))
            {
                printf("\nse realizo el Baja con exito!!\n");
            }
            else
            {
                printf("\n Error, no se realizo la Baja\n");
            }
            //system("pause");
            break;
        case 7:
            //system("cls");
            printf("\n*******ORDENAR CAMIONES POR TIPO Y MOSTRAR CHOFER*******\n\n");
            if(MostrarListadoCamionesPorTipo(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES)==0)
            {
                printf("\n Error, no se puede mostrar\n");
            }
            //system("pause");
            break;


        //*******************CUARTA PARTE*****************************************************
        //**************MODIFICAR CHOFER-LISTAR CHOFER CON MAS DE UN CAMION-LISTAR CAMIONES CON MAS DE 10 ANIOS****
        case 8:
            //system("cls");
            printf("\n*******MODIFICAR CHOFER*******\n\n");
            MostrarListadoChofer(listadoChofer, TCHOFERES);
            if( modificarChofer(listadoChofer,TCHOFERES))
            {
                printf("\nse realizo la Modificacion con exito!!\n");
            }
            else
            {
                printf("\n Error, no se realizo la Modificacion\n");
            }
            //system("pause");
            break;
        case 9:
            //system("cls");
            printf("\n*******LISTAR CHOFER CON MAS DE UN CAMION*******\n\n");
            printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
            MostrarChoferMasDeUnCamion(listadoChofer,TCHOFERES,listadoCamiones,TCAMIONES);
            //system("pause");
            break;
        case 10:
            //system("cls");
            printf("\n*******LISTAR CAMIONES CON MAS DE 10 ANIOS*******\n\n");
            MostrarListadoCamionesConMasDeAnio(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);
            //system("pause");
            break;

        default:
            if(opcion !=20)
            {
                printf("Opcion incorrecta");
            }
        }
    }
    while(opcion!=20);




    //------------------------------------------------------------------------------------

    //*******************QUINTA PARTE*****************************************************
    //-----------------------------------------------------------------------------------
    return 0;
}
