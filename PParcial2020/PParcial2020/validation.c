#include "validation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************
    getString
    getName
    getNumero
    getNumeroConDecimales

**************************/

/** \brief Solicita el ingreso de un string y valida su tamaño
* \param msg char* Mensaje a mostrar
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño minimo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            gets(bufferStr);

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strcpy(resultado,bufferStr);
                retorno=0;
                break;
            }
            printf("%s",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}
//-------------------------------------------------------------------------------------------------
/** \brief Solicita el ingreso de un string y valida su tamaño y su contenido (solo letras)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getDatoString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strcpy(resultado,bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidName(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if((stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')&& stringRecibido[i]!=' ')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//-----------------------------------------------------------------------------------------------
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero sin signo)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input int* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)     //podrìa necesitar parametros para validar max y min
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//*******************************************************
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero con decimales)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input float* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr); // atof array to float
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s", msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//------------------------------------------------------------------------------------------------------------

/** \brief ingresa un string de tres letras y tres numeros y lo valida como patente
 *
 * \param stringPatente char*
 * \return int un entero como respuesta si pudo hacer o no la validacion
 *
 */
int isValidPatente(char* stringPatente)
{
    char numPatente[3];
    char LetraPatente[3];
    int retorno=1;
    int i;
    int j=0;

    if(strlen(stringPatente)==6)
    {
        for(i=0; i<6; i++)
        {
            if(i<3)
            {
                LetraPatente[i]=stringPatente[i];
                if(stringPatente[i]==' ')
                {
                    break;
                }
            }
            else
            {
                numPatente[j]=stringPatente[i];
                if(stringPatente[i]==' ')
                {
                    break;
                }
                j++;
            }

        }

        for(i=0; i<3; i++)
        {
            if((LetraPatente[i]<'A' || (LetraPatente[i]>'Z' && LetraPatente[i]<'a') || LetraPatente[i]>'z'))
            {
                retorno=0;
            }
        }




        for(j=0; j<3; j++)
        {
            if(numPatente[j]<'0' || numPatente[j]>'9')
            {
                retorno=0;

            }
        }

    }
    else
    {
        retorno=0;
    }

    return retorno;
}

/** \brief Solicita el ingreso de un string y valida su tamaño y su contenido (solo letras)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int getDatoSexo(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strcpy(resultado,bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidSexo(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if((stringRecibido[0]!='F' && stringRecibido[0]!='M' && stringRecibido[0]!='f' && stringRecibido[0]!='m')&& stringRecibido[0]!=' ')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
