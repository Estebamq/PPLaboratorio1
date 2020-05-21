#define OCUPADO 0
#define LIBRE -1
#include <stdio.h>
#include <string.h>
#include "choferes.h"

void inicializarChoferes(eChofer listadoChoferes[],int tamChofer)
{
    int i;
    for(i=0; i<tamChofer; i++)
    {
        listadoChoferes[i].estadoChofer=LIBRE;
    }
}
void HardcodeoChoferes(eChofer listadochofer[], int tam)
{
    int legajo[6]= {1330,1340,1350,1360,1370,1380};
    int id[6]= {133,134,135,136,137,138};
    char apellido[6][20]= {"Luc","Jor","Nat","Mat","Jer","Jos"};
    char nombre[6][20]= {"Lucrecia","Jorge","Natalia","Matias","Jeremias","Jose"};
    int dni[6]= {35068998,35067899,36068978,35068920,31035669,34068777};
    char nacionalidad[6][20]= {"Argentino","Chileno","Uruguayo","Argentino","Paraguayo","Argentino"};
    char sexo[6]= {'f','m','f','m','m','m'};
    int telefono[6]= {42451515,2121548,3216511,32321321,123515,1235456};
    int edad[6]= {20,21,20,26,30,25};
    int estadoChofer[6]= {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for(i=0; i<tam; i++)
    {
        listadochofer[i].Legajo=legajo[i];
        listadochofer[i].idChofer= id[i];
        strcpy(listadochofer[i].apellido,apellido[i]);
        strcpy(listadochofer[i].nombre,nombre[i]);
        listadochofer[i].dni=dni[i];
        strcpy(listadochofer[i].nacionalidad,nacionalidad[i]);
        listadochofer[i].sexo=sexo[i];
        listadochofer[i].telefono=telefono[i];
        listadochofer[i].edad=edad[i];
        listadochofer[i].estadoChofer=estadoChofer[i];
    }
}




void MostrarChofer(eChofer chofer)
{
    printf("\n%d %10s %20s %13d %13d %18s %14d %10d %8c\n",chofer.idChofer,chofer.apellido,
           chofer.nombre,chofer.dni,
           chofer.Legajo,chofer.nacionalidad,
           chofer.telefono,chofer.edad,
           chofer.sexo);
}

void MostrarListadoChofer(eChofer listadoChofer[], int tam)
{
    int i;

    printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
    for(i=0; i<tam; i++)
    {
        if(listadoChofer[i].estadoChofer==OCUPADO)
        {
            MostrarChofer(listadoChofer[i]);
        }
    }
}
//*********BUSQUEDA:---****************************************
eChofer buscarChofer(eChofer listadoChoferes[],int tam,int id)
{
    eChofer auxChofer;
    auxChofer.idChofer=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listadoChoferes[i].idChofer==id && listadoChoferes[i].estadoChofer==OCUPADO)
        {
            auxChofer=listadoChoferes[i];
        }
    }
    return auxChofer;
}

int buscarLibreChofer(eChofer chofer[],int tamChofer)
{
    int i;
    int indice=-1;


    for(i=0; i<tamChofer; i++)
    {
        if(chofer[i].estadoChofer==LIBRE)
        {
            indice=i;
        }
    }
    return indice;
}

int buscarChoferPorId(eChofer chofer[],int tamChofer,int idChofer)
{
    int i;
    int indice=-1;


    for(i=0; i<tamChofer; i++)
    {
        if(chofer[i].idChofer== idChofer &&  chofer[i].estadoChofer==OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

//******************ALTA CHOFER*************************************

int altaChofer(eChofer chofer[],int tamChofer, int idChofer)
{
    int i;
    int respuesta=0;

    i=buscarLibreChofer(chofer,tamChofer);
    if(i!=-1)
    {

        if( getUnsignedInt("Ingrese Legajo: ","Error\n",1,5,3,&chofer[i].Legajo)==0 &&
                getDatoString("Ingrese Apellido: ","Error\n",4,10,3,chofer[i].apellido)==0 &&
                getDatoString("Ingrese Nombre: ","Error\n",4,10,3,chofer[i].nombre)==0 &&
                getUnsignedInt("Ingrese D.N.I: ","Error\n",8,9,3,&chofer[i].dni)==0 &&
                getDatoString("Ingrese Nacionalidad: ","Error\n",4,10,3,chofer[i].nacionalidad)==0 &&
                getDatoSexo("Ingrese sexo(f,m): ","Error",1,2,3,&chofer[i].sexo)==0 &&
                getUnsignedInt("Ingrese Telefono: ","Error\n",5,9,3,&chofer[i].telefono)==0 &&
                getUnsignedInt("Ingrese edad: ","Error\n",2,3,3,&chofer[i].edad)==0)
        {
            chofer[i].idChofer=idChofer;
            chofer[i].estadoChofer=OCUPADO;
            respuesta=1;
        }
        else
        {
            printf("No Existe Hay Lugar Libre");

        }
    }

    return respuesta;
}

//********MODIFICAR CHOFER****************************************************************

int modificarChofer(eChofer chofer[], int tamChofer)
{
    int i;
    int respuesta=0;
    int opcion;
    int idChofer;
    char respuestaBaja;
    eChofer auxChofer;
    //PIDO UN ID AL USUARIO

    getUnsignedInt("\nIngrese ID de Chofer: ","\nError\n",1,10,3,&idChofer);

    //BUSCO CHOFER
    auxChofer=buscarChofer(chofer,tamChofer,idChofer);

    if(auxChofer.idChofer!=-1)
    {
        //BUSCO ID CHOFER
        i=buscarChoferPorId(chofer,tamChofer,idChofer);
        //MUESTRO LOS DATOS A MODIFICAR
        printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
        MostrarChofer(chofer[i]);
        getDatoString("esta seguro que desea Modificar?s/n: ","Error",1,2,2,&respuestaBaja);

        //---INICIA LA MODIFICACION-------------
        if(respuestaBaja =='s')
        {
            do
            {
                printf("\nIngrese que desea modificar: \n1-Legajo:\n2-Apellido:\n3-Nombre:\n4-DNI:\n5-Nacionalida:\n6-Sexo:\n7-Telefono: \n8-Edad: \n9-salir de modificar:\n");
                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1:
                    getUnsignedInt("Ingrese Legajo: ","Error\n",1,5,3,&chofer[i].Legajo);
                    break;
                case 2:
                    getDatoString("Ingrese Apellido: ","Error\n",4,10,3,chofer[i].nombre);
                    break;
                case 3:
                    getDatoString("Ingrese Nombre: ","Error\n",4,10,3,chofer[i].nombre);
                    break;
                case 4:
                    getUnsignedInt("Ingrese D.N.I: ","Error\n",8,9,3,&chofer[i].dni);
                    break;
                case 5:
                    getDatoString("Ingrese Nacionalidad: ","Error\n",4,10,3,chofer[i].nacionalidad);
                    break;
                case 6:
                    getDatoSexo("Ingrese sexo(f,m): ","Error",1,2,3,&chofer[i].sexo);
                    break;
                case 7:
                    getUnsignedInt("Ingrese Telefono: ","Error\n",5,9,3,&chofer[i].telefono);
                    break;
                case 8:
                    getUnsignedInt("Ingrese edad: ","Error\n",2,3,3,&chofer[i].edad);
                    break;
                default:
                    if(opcion!=9)
                    {
                        printf("Opcion incorrecta");
                    }

                }
            }
            while(opcion!=9);

            respuesta=1;

        }

    }

    else
    {
        printf("\nNo Existe ID");

    }

    return respuesta;

}


//********************PROMEDIO DE EDAD DE CHOFERES*************************************

float promedioEdadChoferes(eChofer chofer[],int cantChofer)
{
    float promedio=0;
    int edadSuma=0;
    int choferSuma=0;
    int i;

    for( i=0; i<cantChofer; i++)
    {
        if(chofer[i].estadoChofer==OCUPADO)
        {
            edadSuma+=chofer[i].edad;
            choferSuma++;
        }
    }

    if(choferSuma!=0)
    {
        promedio=(float)edadSuma/choferSuma;
    }

    return promedio;

}
//****************PROMEDIO CANTIDAD MUJERES Y VARONES*******************
int promedioCantidadChoferesMF(eChofer chofer[],int cantChofer)
{
    float promedioFemenino=0;
    float promedioMasculino=0;
    int respuesta=1;
    int sumatotal=0;
    int choferMSuma=0;
    int choferFSuma=0;
    int i;

    for( i=0; i<cantChofer; i++)
    {
        if(chofer[i].estadoChofer==OCUPADO)
        {
            if(chofer[i].sexo=='f'||chofer[i].sexo=='F')
            {

                choferFSuma++;

            }

            if(chofer[i].sexo=='m'||chofer[i].sexo=='M')
            {
                choferMSuma++;
                respuesta=0;
            }
            sumatotal++;
        }
    }

    if(choferFSuma!=0)
    {
        promedioFemenino=(float)choferFSuma/sumatotal;
    }

    printf("\nEl promedio de Mujeres es: %.2f\n",promedioFemenino);

    if(choferMSuma!=0)
    {
        promedioMasculino=(float)choferMSuma/sumatotal;
    }
     printf("\nEl promedio de Mujeres es: %.2f\n",promedioMasculino);



    return respuesta;

}
