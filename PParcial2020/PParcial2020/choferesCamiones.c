#include "choferesCamiones.h"
#include <stdio.h>
#include <string.h>
//*********************MUESTRO CHOFERES CON SUS CAMIONES*************************************************
void MostrarChoferCamiones(eChofer listadoChofer[], int cantChofer, eCamiones listadoCamiones[], int cantCamiones)
{
    int i;
    int j;
    char banderaTieneCamiones;


    for(i=0; i<cantChofer; i++)
    {
        if(listadoChofer[i].estadoChofer==OCUPADO)
        {
            MostrarChofer(listadoChofer[i]);
            banderaTieneCamiones = 'n';

            for(j=0; j<cantCamiones; j++)
            {
                if(listadoChofer[i].idChofer == listadoCamiones[j].idChofer && listadoCamiones[j].estadoCamiones==OCUPADO )
                {
                    banderaTieneCamiones = 's';
                    mostrarCamiones(listadoCamiones[j],listadoChofer,cantChofer);
                }
            }

            if(banderaTieneCamiones == 'n')
            {
                printf("\nNo tiene Camiones");
            }
        }
    }
}
//*******************BAJA DE CHOFER POR CASCADA***********************************
int bajaChoferCascada(eChofer chofer[],int tamCho,eCamiones camion[], int tamCam)
{
    int i;
    int respuesta=0;
    int idChofer;
    char respuestaBaja[4];
    eChofer auxChofer;

    //MUESTRO TODOS LOS CHOFERES CON LOS CAMIONES
    printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
    MostrarChoferCamiones(chofer,tamCho,camion,tamCam);

    //PIDO UN ID AL USUARIO
    getUnsignedInt("\ningrese ID para dar de baja el Chofer: ","\nError\n",1,10,3,&idChofer);

    //VALIDO ID DE CHOFER
    auxChofer=buscarChofer(chofer,tamCho,idChofer);

    if(auxChofer.idChofer!=-1)
    {
        //******************MUESTRO EL CHOFER QUE SE VA A DAR DE BAJA*******************************
        printf("\nID: \t Apellido: \t Nombre:\t DNI:   \t Legajo: \t Nacionalidad: \t  Telefono: \t Edad: \t Sexo: \n");
        MostrarChofer(auxChofer);
        //******************MUESTRO LOS CAMIONES DE ESE CHOFER**************************************
        for(i=0; i<tamCam; i++)
        {
            if(camion[i].idChofer==idChofer && camion[i].estadoCamiones==OCUPADO)
            {
                mostrarCamiones(camion[i],chofer,tamCho);
            }
        }
        //*****************VALIDO SI EL USUARIO QUIERE DAR DE BAJA***********************************
        getDatoString("esta seguro que desea dar de baja?si/no: ","Error",1,3,2,respuestaBaja);

        if(strcmpi(respuestaBaja,"si")==0)
        {
            i=buscarChoferPorId(chofer,tamCho,idChofer);// Busco ID para saber en que posicion esta el chofer
            chofer[i].estadoChofer=LIBRE;//baja chofer
            for(i=0; i<tamCam; i++)
            {
                if(camion[i].idChofer==idChofer && camion[i].estadoCamiones==OCUPADO)
                {
                    camion[i].estadoCamiones=LIBRE;//baja camion del chofer
                    respuesta=1;// RESPUESTA QUE SE PUDO HACER LA BAJA
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

//**************************Mostrar Choferes con mas de un camion*****************************

void MostrarChoferMasDeUnCamion(eChofer listadoChofer[], int cantChofer, eCamiones listadoCamiones[], int cantCamiones)
{
    int i;
    int j;


    for(i=0; i<cantChofer; i++)
    {
        listadoChofer[i].cantCamiones=contarCantidadDeCamiones(listadoCamiones,cantCamiones,listadoChofer[i].idChofer);
        if(listadoChofer[i].estadoChofer==OCUPADO && listadoChofer[i].cantCamiones>1)
        {
            MostrarChofer(listadoChofer[i]);

            for(j=0; j<cantCamiones; j++)
            {
                if(listadoChofer[i].idChofer == listadoCamiones[j].idChofer && listadoCamiones[j].estadoCamiones==OCUPADO )
                {

                    mostrarCamiones(listadoCamiones[j],listadoChofer,cantChofer);
                }
            }


        }
    }
}
//**************************Mostrar Choferes ordenados por cantidad de camion*****************************

void MostrarChoferCamionOrdenados(eChofer listadoChofer[], int cantChofer, eCamiones listadoCamiones[], int cantCamiones)
{
    int i;
    int j;
    eChofer auxChofer;

    for(i=0; i<cantChofer;i++)
    {
        if(listadoChofer[i].estadoChofer==OCUPADO)
        {
            listadoChofer[i].cantCamiones=contarCantidadDeCamiones(listadoCamiones,cantCamiones,listadoChofer[i].idChofer);
        }
    }

    for(i=0; i<cantChofer-1; i++)
    {
        for(j=i+1; j<cantChofer; j++)
        {
            if(listadoChofer[i].cantCamiones>listadoChofer[j].cantCamiones)//CAMBIAR PARA HACERLO ASCENDENTE O DESCENDENTE
            {
                auxChofer=listadoChofer[i];
                listadoChofer[i]=listadoChofer[j];
                listadoChofer[j]=auxChofer;
            }
        }
    }

    MostrarChoferCamiones(listadoChofer,cantChofer,listadoCamiones,cantCamiones);

}

//**************************Mostrar Choferes ordenados por cantidad de camion Y ALFABETICAMENTE*****************************

void MostrarChoferCamionOrdenadosAlfa(eChofer listadoChofer[], int cantChofer, eCamiones listadoCamiones[], int cantCamiones)
{
    int i;
    int j;
    eChofer auxChofer;

    for(i=0; i<cantChofer;i++)
    {
        if(listadoChofer[i].estadoChofer==OCUPADO)
        {
            listadoChofer[i].cantCamiones=contarCantidadDeCamiones(listadoCamiones,cantCamiones,listadoChofer[i].idChofer);
        }
    }

    for(i=0; i<cantChofer-1; i++)
    {
        for(j=i+1; j<cantChofer; j++)
        {
            if(listadoChofer[i].cantCamiones>listadoChofer[j].cantCamiones)//CAMBIAR PARA HACERLO ASCENDENTE O DESCENDENTE
            {
                auxChofer=listadoChofer[i];
                listadoChofer[i]=listadoChofer[j];
                listadoChofer[j]=auxChofer;

            }else if(listadoChofer[i].cantCamiones==listadoChofer[j].cantCamiones)
            {
                if(strcmpi(listadoChofer[i].apellido,listadoChofer[j].apellido)>0)//Cambiar el sentido de el orden del apellido
                {
                    auxChofer=listadoChofer[i];
                    listadoChofer[i]=listadoChofer[j];
                    listadoChofer[j]=auxChofer;
                }
            }
        }
    }

    MostrarChoferCamiones(listadoChofer,cantChofer,listadoCamiones,cantCamiones);

}

