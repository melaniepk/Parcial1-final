/*
 * Informes.c
 *
 *  Created on: 20 may. 2021
 *      Author: mkale
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "utn1.h"
#include "Trabajo.h"
#include "Servicio.h"
#define FALSE 1
#define TRUE 0

void totalServiciosPrestados(eTrabajo *listaTrabajos, eServicio *listaServicios, int tamTra, int tamServ)
{
	int i;
	int j;
	float acumulador = 0;
	for(i=0;i<tamTra;i++)
	{
		for(j=0;j<tamServ;j++)
		{
			if(listaTrabajos[i].isEmpty == FALSE && (listaTrabajos[i].idServicio == listaServicios[j].id))
			{
				acumulador = listaServicios[i].precio + acumulador;
			}
		}

	}

	printf("El precio por los servicios acumulados es de: %.2f\n", acumulador);

}

void listaTrabajosOrdenadosPorMarcas(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici)
{

	int i;
	int j;
	int k;
	if(listaTrabajos != NULL && listaServicios != NULL && listaBicicletas != NULL && tamTra >= 0 && tamServ >= 0 && tamBici >=0)
	{
		for(k=0;k<tamTra;k++)
		{
			for(i=0;i<tamBici;i++)
			{

				for(j=0;j<tamServ;j++)
				{
					if(listaTrabajos[i].idServicio == listaServicios[j].id && listaTrabajos[i].isEmpty == FALSE && listaServicios[j].isEmpty==FALSE && listaBicicletas[i].isEmpty == FALSE)
					{
						printf("Marca: %s\n", listaBicicletas[i].marca);
						printf("Servicio prestado: %s\n", listaServicios[j].descripcion);
						break;
					}

				}
			}
		}

	}
}

void serviciosConMasTrabajos(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ)
{

	int i;
	int j;
	int contadorTrabajos=0;

	if(listaTrabajos != NULL && listaServicios != NULL && tamTra >= 0 && tamServ >= 0)
	{
		for(i=0;i<tamServ;i++)
		{
			if(listaServicios[i].isEmpty == FALSE)
			{
				printf("Servicio: %s\n", listaServicios[i].descripcion);
				 for(j=0;j<tamTra;j++)
				 {
					 if(listaServicios[i].id == listaTrabajos[j].idServicio && listaServicios[i].isEmpty == FALSE && listaTrabajos[j].isEmpty==FALSE)
					 {
						 contadorTrabajos++;
					 }
				 }
			     printf("Cantidad de trabajos :%d\n ", contadorTrabajos);

			}

		}
	}




}




void listaServiciosConDatosDeSusBicis(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici)
{
	int i;
	int j;
	int k;

	if(listaTrabajos != NULL && listaServicios != NULL && tamTra >= 0 && tamServ >= 0)
	{
		for(i=0;i<tamServ;i++)
		{
			printf("Servicio: %s\n", listaServicios[i].descripcion);
			for(j=0;j<tamTra;j++)
			{
				for(k=0;k<tamBici;k++)
				{
					if(listaServicios[i].id == listaTrabajos[j].idServicio && listaTrabajos[j].idBicicleta == listaBicicletas[k].idBicicleta)
					{
						printf("Bicicletas que se realizaron el servicio:");
						printf("ID:%d        Marca: %s       Rodado: %d       Color: %s\n", listaBicicletas[k].idBicicleta,
																							listaBicicletas[k].marca,
																							listaBicicletas[k].rodado,
																							listaBicicletas[k].color);
					}
				}

			}
		}

	}
}

void cantidadBicicletasRojasConServicio(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici)
{
	int i;
	int j;
	int k;
	int contadorDeRojo;

	for(k=0;k<tamTra; k++)
	{
		for(i=0;i<tamServ;i++)
		{
			for(j=0;j<tamBici;j++)
			{
				if(listaTrabajos[i].idServicio == listaServicios[j].id && listaTrabajos[i].idBicicleta == listaBicicletas[k].idBicicleta)
				{
					if(strncmp(listaBicicletas[k].color, "rojo", COLOR_LEN))
					{
						contadorDeRojo++;
					}
				}
			}
		}
	}

	printf("La cantidad de bicicletas rojas que se realizaron un servicio son: %d", contadorDeRojo);
}

