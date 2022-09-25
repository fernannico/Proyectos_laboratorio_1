/*
 * input.c
 *
 *  Created on: 19 sep. 2022
 *      Author: User
 */
#include "input.h"
#include "output.h"
#include "operaciones.h"

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

int utn_getNumero(int * pResultado, char* mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;

    do
    {
        reintentos--;
        printf("%s", mensaje);
        if( getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
        {
            *pResultado = bufferInt;
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

//---------------------------------------------------------------------------------------------------
///flotante

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

void CargarUnJugador(int* numeroCamiseta, int* pUefa, int* pConmebol, int* pConcacaf, int* pAfc, int* pOfc, int* pCaf){
	int subopcionConfederacion;

	if(utn_getNumero(numeroCamiseta, "\nIngresar número de camiseta de 1 a 99: ", "Error,  ingresar una camiseta valida de 1 a 99", 1, 99,1)==0){
		printf("Se ingreso la camiseta numero %d\n", *numeroCamiseta);

		ImprimirSubmenuConfederaciones(*pUefa, *pConmebol, *pConcacaf, *pAfc, *pOfc, *pCaf);

		if(utn_getNumero(&subopcionConfederacion, "\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF, 1)==0){
			if(ContarConfederaciones(subopcionConfederacion, pUefa, pConmebol, pConcacaf, pAfc, pOfc, pCaf)){
				printf("\nSe ingreso correctamente al jugador");
			}else{
				printf("\nerror");
			}
		}
	}
}
