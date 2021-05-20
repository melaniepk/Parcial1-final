/*
 * Bicicleta.c
 *
 *  Created on: 20 may. 2021
 *      Author: mkale
 */


#include "utn1.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Bicicleta.h"
#define FALSE 1
#define TRUE 0

int inicializarBicicletas(eBicicleta *list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}


eBicicleta PedirDatosBicicleta()
{
    eBicicleta miBicicleta;

	utn_getString(miBicicleta.marca ,MARCA_LEN, "\nIngrese la marca de la bicicleta", "\nError!. ", 10);
	utn_getNumeroFlotante(&miBicicleta.rodado,"Ingrese el rodado de la bicicleta:\n",
						   "Error al ingresar el rodado.\n",1,50,10);
	utn_getString(miBicicleta.color,COLOR_LEN,"\nIngrese el color de la bicicleta", "Error!",10);

    return miBicicleta;

}

int BuscarLibreB(eBicicleta *lista, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty== TRUE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int IncrementarIdB (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	return nuevoId;
}



int agregarBicicleta(eBicicleta *lista, int len,int id)
{

	int i;
	int retorno = -1;

	if(lista != NULL && len > 0)
	{
		i = BuscarLibreB(lista, len);
		if (i != -1)
		{
			lista[i] = PedirDatosBicicleta();
			lista[i].idBicicleta = id;
			lista[i].isEmpty = FALSE;

			retorno = 0;
		}

	}
	return retorno;
}

int agregarBicicletaHard(eBicicleta *lista, int tam,int indice, int idBicicleta,char *marca ,float rodado, char* color)
{

	int retorno = -1;
	eBicicleta bufferBicicleta;

	if(lista != NULL && tam > 0 && indice >=0  && marca != NULL)
	{

		strncpy(bufferBicicleta.marca, marca, sizeof(bufferBicicleta.marca));
		bufferBicicleta.idBicicleta = idBicicleta;
		bufferBicicleta.rodado = rodado;
		strncpy(bufferBicicleta.color, color, sizeof(bufferBicicleta.color));
		bufferBicicleta.isEmpty = FALSE;
		lista[indice] = bufferBicicleta;

			retorno = 0;


	}
	return retorno;

}



int ImprimirBicicletas(eBicicleta *lista,int tam)
{

	int retorno = -1;
	int i;
	if(lista != NULL && tam > 0)
	{
			   printf("  ID     Marca     Rodado\n ");

		for(i=0;i<tam;i++)
		{
			if(lista[i].isEmpty != TRUE)
			{
				retorno = 0;

				printf(" %d      %s         %.2f     %s\n ",  lista[i].idBicicleta,
													   lista[i].marca,
													   lista[i].rodado,
													   lista[i].color);
			}

		}
	}
	return retorno;
}


int ModificarBicicleta(eBicicleta *lista, int tam)
{

	int idIngresado;
	int i;
	int opcionMod;
	char seguir;
	int retorno = -1;


	printf("Ingrese el ID de la bicicleta a modificar: ");
	scanf("%d", &idIngresado);


	if(lista != NULL && tam >0)
	{
		for(i=0; i<tam; i++)
		{
			if(idIngresado == lista[i].idBicicleta )
			{

				do
				{
					utn_getNumero(&opcionMod, "Ingrese el numero que corresponda a lo que quiera modificar:\n"
							"1. Marca de la bicicleta\n2. Rodado de la bicileta\n3. Color de la bicicleta","Error, elija una opcion valida", 1,2,10);

					switch(opcionMod)
					{
					case 1:
						utn_getString(lista[i].marca,MARCA_LEN,"Ingrese nueva marca\n",
								"Error al ingresar la marca\n", 10);
						break;
					case 2:
						utn_getNumeroFlotante(&lista[i].rodado, "Ingrese nuevo rodado",
								"Error al ingresar nuevo rodado",10,40, 10);
						break;
					case 3:
						utn_getPalabra(lista[i].color,COLOR_LEN ,"Ingrese nuevo color", "Error al ingresar color",5);
						break;
					}

					retorno = 0;

					printf("Modificacion realizada con exito!.\nDesea realizar alguna otra modificacion? (S/N).");
					scanf("%c", &seguir);

				}while(seguir == 's');

			}

		}
	}

	return retorno;
}



int EncontrarBicicletaPorId(eBicicleta *lista, int len, int *id)
{
	int retorno = -1;
	int i;
	if(lista != NULL && len > 0 && id >=0)
	{

		for(i=0; i< len;i++)
		{
			if(lista[i].idBicicleta == *id)
			{
				retorno = i;
				break;
			}
		}
	}


	return retorno;
}
int bajaBicicleta(int id,eBicicleta *lista, int tam)
{
	int retorno = -1;
		char opcion;

		if(lista != NULL && tam > 0 )
		{
			printf("¿Seguro desea eliminar el servicio de %s id: %d ? (S/N)",
					lista->marca,lista->idBicicleta);
			scanf("%c", &opcion);
			if(opcion == 's')
			{
				lista[id].isEmpty = TRUE;
				retorno = 0;
			}
			else
			{
				retorno = -1;

			}

		}
	return retorno;
}
