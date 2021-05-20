/*
 ============================================================================
 Name        : Labo_Parcial1Final.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"
#include "Servicio.h"
#include "Bicicleta.h"
#include "Informes.h"
#include "utn1.h"
#define TAM_SERV 10
#define TAM_TRABAJO 15
#define TAM_BICI 10

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	int idServElegido;
	int IdIncremental;
	int idBicicleta;
	int id = 0;
	int banderaDeCompletado=0;
	int idTrabajo;
	int retorno;
	int criterio;
	//int idEncontrado;

	eServicio arrayServicios[TAM_SERV];
	eTrabajo arrayTrabajos[TAM_TRABAJO];
	eBicicleta arrayBicicletas[TAM_BICI];
	inicializarTrabajos(arrayTrabajos,TAM_TRABAJO);
	inicializarServicios(arrayServicios,TAM_SERV);
	inicializarBicicletas(arrayBicicletas,TAM_BICI);

	agregarServicio(arrayServicios,4,0, 20000, "Limpieza",250);
	agregarServicio(arrayServicios,4,1, 20001, "Parche",300);
	agregarServicio(arrayServicios,4,2, 20002, "Centrado",400);
	agregarServicio(arrayServicios,4,3, 20003, "Cadena",350);

	agregarBicicletaHard(arrayBicicletas,TAM_BICI,0,25,"marca1", 29,"rojo");
	agregarBicicletaHard(arrayBicicletas,TAM_BICI,1,26,"marca2", 26,"verde");
	agregarBicicletaHard(arrayBicicletas,TAM_BICI,2,27,"marca3", 26.5,"rojo");
	agregarBicicletaHard(arrayBicicletas,TAM_BICI,3,28,"marca4", 27,"azul");
	agregarBicicletaHard(arrayBicicletas,TAM_BICI,4,29,"marca5", 26,"amarillo");

	do
	{
		if(utn_getNumero(&opcion,"Ingrese una opcion del menú entre las siguientes:\n"
				"1. ALTA TRABAJO\n2. MODIFICAR TRABAJO\n3. BAJA TRABAJO\n4. LISTAR TRABAJOS\n"
				"5. LISTAR SERVICIOS\n6. TOTAL en pesos por los servicios prestados\n"
				"7. Listado de trabajos ordenados por marca de bicicleta\n8. El/los servicios con mas trabajos realizados\n"
				"9. Listado de servicios con los de las bicicletas a las que se le realizó tal servicio\n"
				"10. Cantidad de bicciletas de color rojo que se realizado un sevicio\n11. Salir","ERROR. Opcion no valida\n",1,11,10)==0)
		{
			switch(opcion)
			{
			case 1:
				IdIncremental = IncrementarIdT(&id);
				ImprimirServicios(arrayServicios,TAM_SERV);
				if(utn_getNumero(&idServElegido,"Ingrese el ID del servicio que desea contratar", "ERROR!", 20000,20003,10)==0)
				{
					ImprimirBicicletas(arrayBicicletas,TAM_BICI);
					if(utn_getNumero(&idBicicleta,"Ingrese el id de la bicicleta", "Error, id inexistente", 25,29,5)==0)
					agregarTrabajo(arrayTrabajos, TAM_TRABAJO, IdIncremental,idServElegido,idBicicleta);
				}
				banderaDeCompletado = 1;
				break;
			case 2:
				if(banderaDeCompletado != 0)
				{	printf("Trabajos que puede modificar:\n");
					ImprimirTrabajos(arrayTrabajos,arrayServicios,TAM_TRABAJO,TAM_SERV,arrayBicicletas, TAM_BICI);
					retorno = ModificarTrabajo(arrayTrabajos, TAM_TRABAJO,arrayServicios, TAM_SERV,arrayBicicletas, TAM_BICI);
					if(retorno == -1)
					{
						printf("No se pudo modificar al trabajo o el ID no existe\n");
					}
					else
					{
						printf("Trabajo modificado\n");
					}
				}
				else
				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 3:
				if(banderaDeCompletado != 0)
				{
					printf("Trabajos que puede dar de baja:\n");
					ImprimirTrabajos(arrayTrabajos,arrayServicios,TAM_TRABAJO,TAM_SERV,arrayBicicletas,TAM_BICI);
					utn_getNumero(&idTrabajo,"Ingrese el id del trabajo a dar de baja", "ERROR, id inexistente", 1,1000,2);
					idTrabajo = EncontrarTrabajoPorId(arrayTrabajos,TAM_TRABAJO,&idTrabajo);
					if(idTrabajo == -1)
					{
						printf("No se pudo encontrar a un trabajo con ese ID\n");
					}
					else
					{
						retorno = BajaTrabajo(arrayTrabajos, TAM_TRABAJO,idTrabajo,arrayServicios,TAM_SERV,arrayBicicletas, TAM_BICI);
						if(retorno != -1)
						{
							printf("Baja completada!\n");
						}
						else
						{
							printf("No se completó la baja del producto");
						}
					}

				}
				else

				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 4:
				if(banderaDeCompletado != 0)
				{
					utn_getNumero(&criterio, "Ingrese un criterio de ordenamiento descendente (0) o ascendente (1)", "ERROR. Fuera de rango", 0, 1,2);

					retorno = OrdenarTrabajos(arrayTrabajos, TAM_TRABAJO, &criterio, arrayBicicletas, TAM_BICI);
					if(retorno != -1)
					{
						ImprimirTrabajos(arrayTrabajos,arrayServicios,TAM_TRABAJO, TAM_SERV, arrayBicicletas,TAM_BICI);
					}
					else
					{
						printf("No se pudo ordenar\n");
					}
				}
				else
				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 5:
				if(banderaDeCompletado != 0)
				{
					ImprimirServicios(arrayServicios, TAM_SERV);
				}
				else
				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 6:
				totalServiciosPrestados(arrayTrabajos,arrayServicios,TAM_TRABAJO,TAM_SERV);
				break;
			case 7:
				listaTrabajosOrdenadosPorMarcas(arrayTrabajos, TAM_TRABAJO, arrayServicios, TAM_SERV, arrayBicicletas, TAM_BICI);
				break;
			case 8:
				serviciosConMasTrabajos(arrayTrabajos, TAM_TRABAJO,arrayServicios,TAM_SERV);

				break;
			case 9:
				listaServiciosConDatosDeSusBicis(arrayTrabajos,TAM_TRABAJO, arrayServicios,TAM_SERV,arrayBicicletas,TAM_BICI);
				break;
			case 10:
				cantidadBicicletasRojasConServicio(arrayTrabajos,TAM_TRABAJO,arrayServicios,TAM_SERV,arrayBicicletas, TAM_BICI);
				break;
			case 11:
				ImprimirTrabajos(arrayTrabajos,arrayServicios,TAM_TRABAJO, TAM_SERV, arrayBicicletas,TAM_BICI);

				break;
			case 12:
				printf("Cerrando sistema");

				break;
			}
		}

	}while(opcion != 12);

	return EXIT_SUCCESS;
}
