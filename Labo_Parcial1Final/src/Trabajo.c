/*
 * Trabajo.c
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

int inicializarTrabajos(eTrabajo *list, int len)
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


eTrabajo PedirDatosTrabajo()
{
    eTrabajo miTrabajo;

	//utn_getString(miTrabajo.marcaBicicleta ,MARCA_LEN, "\nIngrese la marca de la bicicleta", "\nError!. ", 10);
	//utn_getNumeroFlotante(&miTrabajo.rodadoBicicleta,"Ingrese el rodado de la bicicleta:\n",
						  // "Error al ingresar el rodado.\n",1,50,10);
    miTrabajo.fecha = pedirFecha("Ingrese fecha");


    return miTrabajo;

}

int BuscarLibreT(eTrabajo *lista, int tam)
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

int IncrementarIdT (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	return nuevoId;
}

int agregarTrabajo(eTrabajo *lista, int len,int id, int idServicio, int idBicicleta)
{

	int i;
	int retorno = -1;

	if(lista != NULL && len > 0)
	{
		i = BuscarLibreT(lista, len);
		if (i != -1)
		{
			lista[i] = PedirDatosTrabajo();
			lista[i].id = id;
			lista[i].idServicio = idServicio;
			lista[i].idBicicleta = idBicicleta;
			lista[i].isEmpty = FALSE;

			retorno = 0;
		}

	}
	return retorno;
}


eFecha pedirFecha(char mensaje[])
{
	eFecha miFecha;
	utn_getNumero(&miFecha.dia,"Ingrese dia", "ERROR! no existe ese dia",1,31,5);
	utn_getNumero(&miFecha.mes,"Ingrese mes", "ERROR! no existe ese mes",1,12,5);
	utn_getNumero(&miFecha.anio,"Ingrese año", "ERROR! no existe ese año",2020,2100,5);

	return miFecha;
}



int ImprimirTrabajos(eTrabajo *lista, eServicio *listaServ,int tam, int tamServ, eBicicleta *listaBicicletas, int tamBici)
{

	int retorno = -1;
	int i;
	int j;
	int k;

	if(lista != NULL && tam > 0 && listaServ != NULL && tamServ >=0)
	{

		for(i=0;i<tam;i++)
		{

			for(j=0;j<tamServ;j++)
			{
				for(k=0;k<tamBici;k++)
				{
					if(lista[i].isEmpty == FALSE && lista[i].idServicio == listaServ[j].id && lista[i].idBicicleta == listaBicicletas[k].idBicicleta)
					{
						printf("  ID del trabajo    Marca       Rodado      Servicio        Fecha\n ");

						printf(" %d           %s         %.2f          %s          %d/%d/%d \n ", lista[i].id,
																   listaBicicletas[k].marca,
																   listaBicicletas[k].rodado,
																   listaServ[j].descripcion,
																   lista[i].fecha.dia,
																   lista[i].fecha.mes,
																   lista[i].fecha.anio);
					}
					retorno = 0;
				}


			}


		}
	}
	return retorno;
}


int ModificarTrabajo(eTrabajo *lista, int tam,eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici)
{

	int idIngresado;
	int i;
	int opcionMod;
	char seguir;
	int retorno = -1;


	printf("Ingrese el ID del trabajo a modificar: ");
	scanf("%d", &idIngresado);


	if(lista != NULL && tam >0)
	{
		for(i=0; i<tam; i++)
		{
			if(idIngresado == lista[i].id)
			{

				do
				{
					utn_getNumero(&opcionMod, "Ingrese el numero que corresponda a lo que quiera modificar:\n"
							"1. Marca de la bicicleta\n2. Servicio\n","Error, elija una opcion valida", 1,2,2);

					switch(opcionMod)
					{
					case 1:
						utn_getString(listaBicicletas[i].marca,MARCA_LEN,"Ingrese nueva marca\n",
								"Error al ingresar nueva marca\n", 2);
						break;
					case 2:
						ImprimirServicios(listaServicios,tamServ);
						utn_getNumero(&lista[i].idServicio, "Ingrese ID del nuevo servicio",
								"Error al ingresar nuevo ID", listaServicios[0].id,listaServicios[10].id, 10);
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



int EncontrarTrabajoPorId(eTrabajo *lista, int len, int *id)
{
	int retorno = -1;
	int i;
	if(lista != NULL && len > 0 && id >=0)
	{

		for(i=0; i< len;i++)
		{
			if(lista[i].id == *id)
			{
				retorno = i;
				break;
			}
		}
	}


	return retorno;
}

int BajaTrabajo(eTrabajo *lista, int len,int id,eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici)
{
	int retorno = -1;
	char opcion;

	if(lista != NULL && len > 0 )
	{
		printf("¿Seguro desea eliminar al trabajo de id %d  marca: %s, servicio: %s, del dia :%d/%d/%d ? (S/N)",
				id, listaBicicletas[id].marca,listaServicios[id].descripcion,
				lista[id].fecha.dia,lista[id].fecha.mes,lista[id].fecha.anio);
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



int OrdenarTrabajos(eTrabajo *lista, int len, int *orden, eBicicleta *listaBicicletas, int tamBici)
{
	int retorno = -1;
	int i;
	int j;
	int k;
	int l;
	eTrabajo auxTrabajo;
	eBicicleta auxBici;

	if (lista != NULL && len > 0)
	{
		switch (*orden)
		{
		case 0: //descendente
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (lista[i].isEmpty == FALSE && lista[j].isEmpty == FALSE)
					{
						if(lista[j].fecha.anio < lista[i].fecha.anio)
						{
							auxTrabajo = lista[j];
							lista[j] = lista[i];
							lista[i] = auxTrabajo;
						}
						else
						{
							if((lista[j].fecha.anio < lista[i].fecha.anio) == 0)
								for(k=0;k<tamBici-1;k++)
								{
									for(l=k+1;i<tamBici;l++)
									{
										if(strncmp(listaBicicletas[k].marca , listaBicicletas[l].marca,sizeof(listaBicicletas->marca)))
										{
											auxBici = listaBicicletas[k];
											listaBicicletas[k] = listaBicicletas[l];
											listaBicicletas[l] = auxBici;
										}
									}

								}

						}

					}

				}
			}
			retorno = 0;
			break;
		case 1://ascendente
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (lista[i].isEmpty == FALSE && lista[j].isEmpty == FALSE)
					{
						if(lista[j].fecha.anio > lista[i].fecha.anio)
						{
							auxTrabajo = lista[j];
							lista[j] = lista[i];
							lista[i] = auxTrabajo;
						}
						else
						{
							if((lista[j].fecha.anio > lista[i].fecha.anio) == 0)
							for(k=0;k<tamBici-1;k++)
							{
								for(l=k+1;i<tamBici;l++)
								{
									if(strncmp(listaBicicletas[l].marca , listaBicicletas[k].marca,sizeof(listaBicicletas->marca)))
									{
										auxBici = listaBicicletas[l];
										listaBicicletas[l] = listaBicicletas[k];
										listaBicicletas[k] = auxBici;
									}
								}

							}
						}
					}
				}
			}
			retorno = 0;
			break;
		default:
			printf("Criterio de ordenamiento mal ingresado.\n");
			retorno = -1;
			break;
		}
	}
	return retorno;
}

