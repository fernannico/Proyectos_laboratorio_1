/*
 * input.c
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */

#include "input.h"

int esNumerica(char * cadena, int limite)
{
    int retorno = -1; //error
    int i;

    if(cadena != NULL && limite > 0)
    {
        retorno = 1; //verdadero
        for(i = 0; i<limite && cadena [i] != '\0'; i++)
        {
            if(i== 0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }
            if(cadena[i] > '9' || cadena[i] < '0')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int myGets(char * cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno  = 0;
			}
		}
	}
    return retorno;
}

int getInt(int * pResultado)
{
    int retorno = -1;
    char bufferString[50];
    if( pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
    {
       retorno = 0;
       *pResultado = atoi(bufferString); //atof para float
    }
    return retorno;
}

int utn_getNumero(int * pResultado, char* mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;

    do
    {
        reintentos--;
        printf("%s", mensaje);
        if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
        {
            *pResultado = bufferInt;
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

int getShort(short* pResultado)
{
    int retorno = -1;
    char bufferString[50];
    if( pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
    {
       retorno = 0;
       *pResultado = atoi(bufferString); //atof para float
    }
    return retorno;
}

int utn_getShort(short* pResultado, char* mensaje, char * mensajeError, short minimo, short maximo, short reintentos)
{
    int retorno = -1;
    short buffer;

    do
    {
        reintentos--;
        printf("%s", mensaje);
        if( getShort(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
        {
            *pResultado = buffer;
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

//entero
///-------------------------------------------------------------------------------------------------
//float

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

///-------------------------------------------------------------------------------------------------
/*
int PedirCadena(char cadena[],int len,char mensaje[])
{
	int retorno;
	char buffer[1024];
	int largoBuffer;

	retorno = 0;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",buffer);

	largoBuffer = (int)strlen(buffer);

	if(len > largoBuffer)
	{
		strcpy(cadena,buffer);
		retorno = 1;
	}


	return retorno;
}
*/
/*
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&buffer);
			buffer = toupper(buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}
*/
///------------------------------------------------------------------------------------------------

int esSoloLetras(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 && esSoloLetras(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud){
    		strcpy(pResultado,buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	do{
		reintentos--;
		printf("%s", mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strcpy(pResultado,bufferString);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}while(reintentos>=0);

	return retorno;
}

void ModularNombre(char nombre[]){
	int size;

	strlwr(nombre);
	nombre[0] = toupper(nombre[0]);

	size = strlen(nombre);

	for(int i = 0; i < size; i++){
		if(nombre[i] == ' '){
			nombre[i+1] = toupper(nombre[i+1]);
		}
	}
}

///------------------------------------------------------------------------------------------------

char ValidarSeguirNoSeguir(char * mensaje, char * mensajeError){
	char letra = 'S';
	char letraNoSeguir = 'N';
	char opcion;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &opcion);
		opcion = toupper(opcion);
		if(opcion != letra && opcion != letraNoSeguir){
			printf("%s", mensajeError);
		}
	}while(opcion != letra && opcion != letraNoSeguir);

	return opcion;
}

float CalcularPromedio(float acumulador, int contador){
	float promedio;

	if(contador != 0){
		promedio = (float)acumulador/ contador;
	}else{
		printf("\nError, no se puede dividir entre 0");
	}

	return promedio;
}
