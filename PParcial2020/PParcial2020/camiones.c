#include <stdio.h>
#include <string.h>
#include "camiones.h"
#define  ANIO   2010  //marca la cantidad de antiguedad en los camiones(en este caso 10 anios)


//***********INICIALIZAR, HARCODEOCAMIONES******************************

void inicialiazarCamiones(eCamiones listadoCamiones[],int tamC)
{
    int i;
    for(i=0; i<tamC; i++)
    {
        listadoCamiones[i].estadoCamiones=LIBRE;
    }
}

void HardcodeoCamiones(eCamiones listadoCamiones[], int tam)
{

    int idCamiones[10]= {10,20,30,40,50,60,70,80,90,100};
    int idChofer[10]= {133,133,134,134,135,136,136,137,137,137};
    char patente[10][20]= {"ACD756","ACB777","ACE756","ACF75912","ACH756","ACI756","ACQ757","ACZ156","ACM786","ACL756"};
    char tipo[10][20]= {"cortaDistancia","largaDistancia","cortaDistancia","largaDistancia","cortaDistancia","largaDistancia","cortaDistancia","largaDistancia","cortaDistancia","largaDistancia"};
    char marca[10][20]= {"ford","ford","fiat","fiat","WV","ford","ford","ford","ford","ford"};
    int anio[10]= {2000,2000,2001,2001,2010,2005,2015,2018,2018,2017};
    float peso[10]= {1,2,3,4,2,6,2,4,4,5};
    int cantRuedas[11]= {10,12,6,6,12,12,10,12,12};
    int estadoCamiones[11]= {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for(i=0; i<tam; i++)
    {
        listadoCamiones[i].idCamion= idCamiones[i];
        listadoCamiones[i].idChofer = idChofer[i];
        strcpy(listadoCamiones[i].patente,patente[i]);
        strcpy(listadoCamiones[i].tipo,tipo[i]);
        strcpy(listadoCamiones[i].marca,marca[i]);
        listadoCamiones[i].anio= anio[i];
        listadoCamiones[i].peso= peso[i];
        listadoCamiones[i].cantRuedas= cantRuedas[i];
        listadoCamiones[i].estadoCamiones=estadoCamiones[i];
    }
}


//**********************MOSTRAR CAMIONES************************************
void mostrarCamiones(eCamiones camion,eChofer listadoChofer[],int tamC)
{
    eChofer auxChofer;
    auxChofer=buscarChofer(listadoChofer,tamC,camion.idChofer);
    if(auxChofer.estadoChofer==LIBRE)
    {
        strcpy(auxChofer.nombre,"sin chofer");
    }
    printf("%d \t %10s\t%8s\t%8d\t%8.2f\t%8d\t%14s\t%12s \n",camion.idCamion,camion.patente,
           camion.marca, camion.anio,
           camion.peso,camion.cantRuedas,
           camion.tipo,auxChofer.nombre);

}

void MostrarListadoCamiones(eCamiones listadoCamiones[], int tamC,eChofer listadoChofer[],int tamCho)
{
    int i;


    for(i=0; i<tamC; i++)
    {
        if(listadoCamiones[i].estadoCamiones==OCUPADO)
        {
            mostrarCamiones(listadoCamiones[i],listadoChofer,tamCho);
        }
    }
}

//***********************BUSQUEDA: ESPACIO LIBRE- BUSCAR CAMION -BUSCAR CAMION POR ID*********
int buscarLibreCam(eCamiones camiones[],int tam)
{
    int i;
    int indice=-1;


    for(i=0; i<tam; i++)
    {
        if(camiones[i].estadoCamiones==LIBRE)
        {
            indice=i;
        }
    }
    return indice;
}

eCamiones buscarCamion(eCamiones listadocamiones[],int tam,int idCamiones)
{
    eCamiones auxCamion;
    auxCamion.idCamion=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listadocamiones[i].idCamion==idCamiones && listadocamiones[i].estadoCamiones==OCUPADO)
        {
            auxCamion=listadocamiones[i];
            break;
        }
    }
    return auxCamion;
}


int buscarCamionPorId(eCamiones camiones[],int tam,int idCamion)
{
    int i;
    int indice=-1;


    for(i=0; i<tam; i++)
    {
        if(camiones[i].idCamion== idCamion &&  camiones[i].estadoCamiones==OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


//********************ALTA CAMION********************************************************
int altaCamiones(eCamiones camion[],int tamCam,eChofer chofer[],int cantCho, int idCamion)
{
    int i;
    int idChofer;
    int respuesta=0;
    eChofer auxChofer;

    i=buscarLibreCam(camion,tamCam);
    if(buscarLibreCam(camion,tamCam)!=-1)
    {

        printf("Ingrese Patente: ");
        fflush(stdin);
        gets(camion[i].patente);

        if( isValidPatente(camion[i].patente)== 1 &&
                getDatoString("Ingrese Marca: ","Error\n",2,10,3,camion[i].marca)==0 &&
                getFloat("Ingrese Peso(tonelada): ","Error\n",2,4,3,&camion[i].peso)==0 &&
                getUnsignedInt("Ingrese anio: ","Error\n",1,5,3,&camion[i].anio)==0 &&
                getUnsignedInt("Ingrese cantidad de Ruedas: ","Error\n",1,4,3,&camion[i].cantRuedas)==0 &&
                getDatoString("ingrese Tipo(Larga Distancia/Corta Distancia):","Error\n",1,25,3,camion[i].tipo)==0)
        {

            //PIDO UN ID AL USUARIO
            printf("\nElija id de chofer para el camion: ");
            MostrarListadoChofer(chofer,cantCho);
            getUnsignedInt("ID Chofer:","Error",1,10,3,&idChofer);
            //VALIDO ID DE CHOFER
            auxChofer=buscarChofer(chofer,cantCho,idChofer);
            if(auxChofer.idChofer!=-1)
            {
                camion[i].idChofer=idChofer;
                camion[i].idCamion=idCamion;
                camion[i].estadoCamiones=OCUPADO;
                respuesta=1;
            }
            else
            {
                printf("No Existe ID");

            }
        }
    }

    return respuesta;
}


//***********BAJA CAMION*************************************************
int bajaCamiones(eCamiones camion[],int tamCam,eChofer chofer[], int tanCho)
{
    int i;
    int respuesta=0;
    int idCamion;
    char respuestaBaja[4];
    eCamiones auxCamion;
    //PIDO UN ID AL USUARIO

    getUnsignedInt("\nID Camion para dar de baja:","\nError\n",1,10,3,&idCamion);
    printf("\n%d\n",idCamion);
    //VALIDO ID DE CHOFER
    auxCamion=buscarCamion(camion,tamCam,idCamion);

    if(auxCamion.idCamion!=-1)
    {
        mostrarCamiones(auxCamion,chofer,tanCho);
        getDatoString("esta seguro que desea dar de baja?si/no: ","Error",1,3,2,respuestaBaja);
        if(stricmp(respuestaBaja,"si")==0)
        {   i=buscarCamionPorId(camion,tamCam,idCamion);
            camion[i].estadoCamiones=LIBRE;
            respuesta=1;
        }
    }
    else
    {
        printf("\nNo Existe ID");

    }

    return respuesta;
}

//********MODIFICAR CAMIONES****************************************************************

int modificarCamiones(eCamiones camion[], int tamCamion,eChofer chofer[], int tamChofer)
{
    int i;
    int respuesta=0;
    int idCamion;
    int idChofer;
    char respuestaBaja;
    eCamiones auxCamion;
    eChofer auxChofer;
    //PIDO UN ID AL USUARIO

    getUnsignedInt("\nIngrese ID de Camion para modificar(Tipo/Chofer): ","\nError\n",1,10,3,&idCamion);

    //VALIDO ID DE CHOFER
    auxCamion=buscarCamion(camion,tamCamion,idCamion);

    if(auxCamion.idCamion!=-1)
    {
        i=buscarCamionPorId(camion,tamCamion,idCamion);
        mostrarCamiones(camion[i],chofer,tamChofer);
        getDatoString("esta seguro que desea Modificar?s/n: ","Error",1,2,2,&respuestaBaja);

        //---INICIA LA MODIFICACION-------------
        if(respuestaBaja =='s')
        {
            if(getDatoString("ingrese Tipo(Larga Distancia/Corta Distancia):","Error\n",1,25,3,camion[i].tipo)==0)
            {

                //PIDO UN IDCHOFER AL USUARIO PARA MODIFICAR
                printf("\nElija id de chofer para el camion: ");
                MostrarListadoChofer(chofer,tamChofer);
                getUnsignedInt("ID Chofer:","Error",1,10,3,&idChofer);
                //VALIDO ID DE CHOFER
                auxChofer=buscarChofer(chofer,tamChofer,idChofer);
                if(auxChofer.idChofer!=-1)
                {
                    camion[i].idChofer=idChofer;
                    respuesta=1;
                }
                else
                {
                    printf("No Existe ID");

                }
            }

        }
    }
    else
    {
        printf("\nNo Existe ID");

    }

    return respuesta;

}

//*****************************MOSTRAR CAMIONES POR TIPO Y SU CHOFER******************************


int MostrarListadoCamionesPorTipo(eCamiones listadoCamiones[], int tamC,eChofer listadoChofer[],int tamCho)
{
    int i;
    int j;
    eCamiones auxCamion;
    int retorno =0;


    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if(strcmp(listadoCamiones[i].tipo,listadoCamiones[j].tipo)>0)
            {
                auxCamion=listadoCamiones[i];
                listadoCamiones[i]=listadoCamiones[j];
                listadoCamiones[j]=auxCamion;
                retorno=1;
            }
        }
    }

    if(retorno==1)
    {
        MostrarListadoCamiones(listadoCamiones,tamC,listadoChofer,tamCho);
    }
    return retorno;
}

//**********************CONTAR CANTIDAD DE CAMIONES*************************
int contarCantidadDeCamiones(eCamiones camion[],int tamCamion,int idChofer)
{
    int i;
    int contador=0;
    for(i=0;i<tamCamion;i++)
        {
            if(camion[i].idChofer== idChofer)
            {
                contador++;
            }
        }
    return contador;
}

//*******************MOSTRAR CAMIONES CON MAS DE 10 AÑOS*********************
void MostrarListadoCamionesConMasDeAnio(eCamiones listadoCamiones[], int tamC,eChofer listadoChofer[],int tamCho)
{
    int i;


    for(i=0; i<tamC; i++)
    {
        if(listadoCamiones[i].estadoCamiones==OCUPADO && listadoCamiones[i].anio<ANIO)
        {
            mostrarCamiones(listadoCamiones[i],listadoChofer,tamCho);
        }
    }
}
