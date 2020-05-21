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
    float promedioEdad;
    float promedioAntiguedad;

    inicialiazarCamiones(listadoCamiones,TCAMIONES);
    inicializarChoferes(listadoChofer,TCHOFERES);
    //HardcodeoChoferes(listadoChofer, 6);
    //HardcodeoCamiones(listadoCamiones, 10);


    do
    {
        system("cls");
        printf("\n*******MENU PARCIAL*******\n");
        printf("\n------PRIMERA PARTE--------\n1-Listar:");
        printf("\n------SEGUNDA PARTE--------\n2-Alta Camiones: \n3-Baja Camiones: \n4-Modificar Camiones\n");
        printf("\n------TERCERA PARTE--------\n5-Alta de Chofer:\n6-Baja de chofer:\n7-Mostrar Camiones Por Tipo\n");
        printf("\n------CUARTA PARTE---------\n8-Modificar Chofer\n9-Mostrar choferes con mas de un camion\n10-Camiones con mas de 10 anios\n");
        printf("\n------QUINTA PARTE---------\n11-Mostrar camiones por marca\n12-Mostrar Choferes ordenados por cantidad de camion:\n13-Mostrar choferes ordenados por cantidad de camion y alfabeticamente\n14-Mostrar el promedio de las edades de los choferes\n15-Mostrar el promedio de antiguedad de camiones:\n16-El promedio que tengo entre varones y mujeres: \n");
        printf("\n20-Salir.\nIngrese opcion: ");
        scanf("%d",&opcion);
        system("pause");

        switch(opcion)
        {
        case 1:
            //************PRIMERA PARTE***********************************************
            //**********LISTADOS******************************************************
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("***************Choferes*********************************************\n");
                MostrarListadoChofer(listadoChofer, TCHOFERES);
                printf("\n***************Camiones Con Choferes******************************\n");
                MostrarListadoCamiones(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);
                printf("\n***************Choferes con Camiones******************************\n");
                printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
                MostrarChoferCamiones(listadoChofer, TCHOFERES, listadoCamiones, TCAMIONES);
            }
            else
            {
                printf("\n\t\t NO HAY INFORMACION PARA MOSTRAR\n");
            }


            system("pause");

            break;

        //**********SEGUNDA PARTE*************************************************
        //**********ALTA/BAJA/MODIFICACION CAMION*********************************

        case 2:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
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
            }
            else
            {
                printf("\n\t\t ERROR:PRIMERO INGRESE DATOS CHOFER  \n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
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
            }
            else
            {
                printf("\n\t\t ERROR:PRIMERO INGRESE DATOS CHOFER, LUEGO DATOS DE CAMION \n");
            }

            system("pause");
            break;
        case 4:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
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
            }
            else
            {
                printf("\n\t\t ERROR:PRIMERO INGRESE DATOS CHOFER, LUEGO DATO DE CAMION\n");
            }
            system("pause");
            break;


        //*******************TERCERA PARTE****************************************************
        //*****************CHOFER:ALTA-BAJA-ORDENAR ********************************************************
        case 5:
            system("cls");
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
            system("pause");
            break;
        case 6:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("\n*******BAJA CHOFER*******\n\n");
                if(bajaChoferCascada(listadoChofer,TCHOFERES,listadoCamiones,TCAMIONES))
                {
                    printf("\nse realizo el Baja con exito!!\n");
                }
                else
                {
                    printf("\n Error, no se realizo la Baja\n");
                }
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CHOFER \n");
            }

            system("pause");
            break;
        case 7:
            system("cls");

            if(buscarOcupadoCam(listadoCamiones,TCAMIONES))
            {
                printf("\n*******ORDENAR CAMIONES POR TIPO Y MOSTRAR CON CHOFER*******\n\n");
                if(ordenarListadoCamionesPorTipo(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES)==0)
                {
                    printf("\n Error, no se puede mostrar\n");
                }
            }
            else
            {
                printf("\n\t\t ERROR: PRIMERO INGRESE UN CHOFER, LUEGO INGRESE DATOS CAMION \n");
            }
            system("pause");
            break;



        //*******************CUARTA PARTE*****************************************************
        //**************MODIFICAR CHOFER-LISTAR CHOFER CON MAS DE UN CAMION
        //**************-LISTAR CAMIONES CON MAS DE 10 ANIOS*********************************
        case 8:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
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
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CHOFER \n");
            }

            system("pause");
            break;
        case 9:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("\n*******LISTAR CHOFER CON MAS DE UN CAMION*******\n\n");
                printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
                MostrarChoferMasDeUnCamion(listadoChofer,TCHOFERES,listadoCamiones,TCAMIONES);
            }
            else
            {
                printf("\n\t\t ERROR:PRIMERO INGRESE DATOS CHOFER /SEGUNDO DATOS DE CAMIONES \n");
            }
            system("pause");
            break;
        case 10:
            system("cls");
            if(buscarOcupadoCam(listadoCamiones,TCAMIONES))
            {
                printf("\n*******LISTAR CAMIONES CON MAS DE 10 ANIOS*******\n\n");
                MostrarListadoCamionesConMasDeAnio(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES);
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CAMION \n");
            }
            system("pause");
            break;



        //*******************QUINTA PARTE*****************************************************

        case 11:
            system("cls");
            if(buscarOcupadoCam(listadoCamiones,TCAMIONES))
            {
                printf("\n*******LISTAR CAMION POR MARCA *******\n\n");
                if(MostrarListadoCamionesPorMarca(listadoCamiones,TCAMIONES,listadoChofer,TCHOFERES)==0)
                {
                    printf("\nMarca no registrada\n");
                }
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CAMION \n");
            }
            system("pause");
            break;
        case 12:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("\n*******LISTAR CHOFERES CON CAMIONES ORDENADOS POR CANTIDAD DE CAMION *******\n\n");
                printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
                MostrarChoferCamionOrdenados(listadoChofer, TCHOFERES, listadoCamiones, TCAMIONES);
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CHOFER \n");
            }
            system("pause");
            break;
        case 13:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("\n*******LISTAR CHOFERES CON CAMIONES ORDENADOS POR CANTIDAD DE CAMION/ALFABETICAMENTE *******\n\n");
                printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
                MostrarChoferCamionOrdenadosAlfa(listadoChofer, TCHOFERES, listadoCamiones, TCAMIONES);
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CHOFER \n");
            }
            system("pause");
            break;
        case 14:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("\n*******PROMEDIO DE EDAD ENTRE LOS CHOFERES*******\n\n");
                promedioEdad=promedioEdadChoferes(listadoChofer,TCHOFERES);
                if(promedioEdad!=0)
                {
                    printf("\nEl Promedio de edad de los choferes es: %.2f\n",promedioEdad);
                }
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CHOFER \n");
            }
            system("pause");
            break;
        case 15:
            system("cls");
            if(buscarOcupadoCam(listadoCamiones,TCAMIONES))
            {
                printf("\n*******PROMEDIO DE ANTIGUEDAD DE CAMIONES*******\n\n");
                promedioAntiguedad=promedioAntiguedadCamiones(listadoCamiones,TCAMIONES);
                if(promedioAntiguedad!=0)
                {
                    printf("\nEl Promedio de Antiguedad de los camiones es: %.2f\n",promedioAntiguedad);
                }
            }
            else
            {
                printf("\n\t\t ERROR:PRIMERO INGRESE DATOS DE CHOFER(SI NO EXISTE) LUEGO INGRESE DATOS CAMION \n");
            }
            system("pause");
            break;
        case 16:
            system("cls");
            if(buscarOcupadoChofer(listadoChofer,TCHOFERES))
            {
                printf("\n*******PROMEDIO CANTIDAD DE MUJERES Y HOMBRES ENTRE EL TOTAL DE CHOFERES*******\n\n");

                if(promedioCantidadChoferesMF(listadoChofer,TCHOFERES))
                {
                    printf("\nError\n");
                }
            }
            else
            {
                printf("\n\t\t ERROR:INGRESE DATOS CHOFER \n");
            }
            system("pause");
            break;
        default:
            if(opcion !=20)
            {
                printf("Opcion incorrecta");
            }
        }
    }
    while(opcion!=20);


    return 0;
}
