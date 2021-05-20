/*
 * Trabajo.h
 *
 *  Created on: 20 may. 2021
 *      Author: mkale
 */


#ifndef TRABAJO_H_
#define TRABAJO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#include "Bicicleta.h"
#include "utn1.h"

//#define MARCA_LEN 26
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct
{
	int id;// (autoincremental)
	//char marcaBicicleta[MARCA_LEN]; //(Cadena) Validar
	//float rodadoBicicleta;
	int idServicio; //(debe existir) Validar
	eFecha fecha;// (Validar día, mes y año
	int idBicicleta;
	int isEmpty;

}eTrabajo;

//void totalServiciosPrestados(eTrabajo *listaTrabajos, eServicio *listaServicios, int tamTra, int tamServ);
//void listaTrabajosOrdenadosPorMarcas(eTrabajo listaTrabajos[], int tamTra, eServicio listaServicios[], int tamServ, eBicicleta listaBicicletas, int tamBici);
/**
 * @fn int IncrementarIdT(int*)
 * @brief
 * Incrementa automaticamente el id
 * @param proximoId id a incrementar
 * @return id incrementado
 */
int IncrementarIdT (int *proximoId);

/**
 * @fn int agregarTrabajo(eTrabajo*, int, int, int)
 * @brief
 * completa los datos del trabajo si hay lugar en la lista
 * @param lista array de trabajos
 * @param len tamaño del array
 * @param id id del trabajo
 * @param idServicio id del servicio que tendra el trabajo
 * @return retorna 0 si funcionó, -1 si no
 */
int agregarTrabajo(eTrabajo *lista, int len,int id, int idServicio, int idBicicleta);

/**
 * @fn int BuscarLibreT(eTrabajo*, int)
 * @brief
 * busca un lugar libre en el array fijandose en el campo isEmpty
 * @param lista array de trabajos
 * @param tam tamaño del array
 * @return la posicion libre del array si existe, -1 si no
 */
int BuscarLibreT(eTrabajo *lista, int tam);

/**
 * @fn eTrabajo PedirDatosTrabajo()
 * @brief
 * completa los datos del trabajo
 * @return el trabajo con los datos cargados
 */
eTrabajo PedirDatosTrabajo();

/**
 * @fn eFecha pedirFecha(char[])
 * @brief
 * pide una fecha
 * @param mensaje mensaje para el usuario
 * @return retorna la fecha con los datos cargados
 */
eFecha pedirFecha(char mensaje[]);

/**
 * @fn int ImprimirTrabajos(eTrabajo*, eServicio*, int, int, eBicicleta*, int)
 * @brief
 * imprime una lista de los trabajos con sus datos,
 *  recorriendo la lista de los trabajos y sus posibles servicios
 * @param lista array de trabajos
 * @param listaServ array de servicios
 * @param tam tamaño del array de trabajos
 * @param tamServ tamaño del array de servicios
 * @param listaBicicletas array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 * @return  0 si logra imprimir, -1 si no
 */
int ImprimirTrabajos(eTrabajo *lista, eServicio *listaServ,int tam, int tamServ, eBicicleta *listaBicicletas, int tamBici);

/**
 * @fn int inicializarTrabajos(eTrabajo*, int)
 * @brief
 * inicializa en 0 o TRUE el campo isEmpty del array en cada posicion
 * @param list array de trabajos
 * @param len tamaño del array

 * @return 0 si inicializo, -1 si no
 */
int inicializarTrabajos(eTrabajo *list, int len);

/**
 * @fn int ModificarTrabajo(eTrabajo*, int, eServicio*, int)
 * @brief
 * permite modificar alguno de los campos del trabajo ingresando su id
 * @param lista array de trabajos
 * @param tam tamaño del array
 * @param listaServicios array de servicios
 * @param tamServ tamaño del array de servicios
 * @param listaBicicletas array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 * @return 0 si modificó, -1 si no
 */
int ModificarTrabajo(eTrabajo *lista, int tam,eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici);

/**
 * @fn int bajaTrabajo(eTrabajo*, int, int, eServicio*, int)
 * @brief
 * recibe un id y cambia su campo isEmpty a TRUE si este estaba previamente en FALSE
 * @param lista array de trabajos
 * @param len tamaño del array
 * @param id id del trabajo a eliminar
 * @param listaServicios array de servicios
 * @param tamServ tamaño del array de servicios
 * @param listaBicicletas array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 * @return 0 si dio de baja, -1 si no
 */
int BajaTrabajo(eTrabajo *lista, int len,int id,eServicio *listaServicios, int tamServ, eBicicleta *listaBicicletas, int tamBici);

/**
 * @fn int OrdenarTrabajos(eTrabajo*, int, int*)
 * @brief
 * ordena de forma ascendente o descendente a los trabajos por año y marca de la bicileta
 * @param lista array de trabajos
 * @param len tamaño del array
 * @param orden criterio de ordenamiento
 * @param listaBicicletas array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 * @return 0 si ordenó, -1 si no
 */
int OrdenarTrabajos(eTrabajo *lista, int len, int *orden, eBicicleta *listaBicicletas, int tamBici);

/**
 * @fn int EncontrarTrabajoPorId(eTrabajo*, int, int*)
 * @brief
 * comprueba la existencia de un determinado id
 * @param lista array de trabajos
 * @param len tamaño del array de trabajos
 * @param id id a encontrar
 * @return el id encontrado, o -1 si no lo encontró
 */
int EncontrarTrabajoPorId(eTrabajo *lista, int len, int *id);





#endif /* TRABAJO_H_ */
