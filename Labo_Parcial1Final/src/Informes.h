/*
 * Informes.h
 *
 *  Created on: 20 may. 2021
 *      Author: mkale
 */

#ifndef INFORMES_H_
#define INFORMES_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"
#include "Servicio.h"
#include "Bicicleta.h"
#include "utn1.h"

#define FALSE 1
#define TRUE 0


typedef struct
{
	int id;
	int contador;
}eAuxiliar;


/**
 * @fn void totalServiciosPrestados(eTrabajo*, eServicio*, int, int)
 * @brief
 * recibe las listas de trabajos y servicios con sus tamaños, y calcula
 * el precio total (suma) de los servicios prestados en los trabajos
 * @param listaTrabajos array de trabajos
 * @param listaServicios array de servicios
 * @param tamTra tamaño del array de trabajos
 * @param tamServ tamaño del array del servicios
 */
void totalServiciosPrestados(eTrabajo *listaTrabajos, eServicio *listaServicios, int tamTra, int tamServ);

/**
 * @fn void listaTrabajosOrdenadosPorMarcas(eTrabajo*, int, eServicio*, int, eBicicleta*, int)
 * @brief
 * ordena los trabajos hechos segun la marca de la bicicleta
 * @param listaTrabajos array de trabajos
 * @param tamTra tamaño del array de trabajos
 * @param listaServicios array de servicios
 * @param tamServ tamaño del array de servicios
 * @param listaBicicletas array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 */
void listaTrabajosOrdenadosPorMarcas(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici);

void serviciosConMasTrabajos(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ);

void listaServiciosConDatosDeSusBicis(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici);
void cantidadBicicletasRojasConServicio(eTrabajo *listaTrabajos, int tamTra, eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici);


#endif /* INFORMES_H_ */
