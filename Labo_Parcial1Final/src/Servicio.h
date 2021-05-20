/*
 * Servicio.h
 *
 *  Created on: 20 may. 2021
 *      Author: mkale
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn1.h"

#define ID_SERV 20000
#define FALSE 1
#define TRUE 0
#define DESC_LEN 25


typedef struct
{
	int id;// (comienza en 20000, autoincremental)
	char descripcion[DESC_LEN];// (máximo 25 caracteres)
	float precio;
	int isEmpty;
}eServicio;

/**
 * @fn int agregarServicio(eServicio*, int, int, int, char*, float)
 * @brief
 * recibe una array de servicios, su tamaño y el indice donde se cargaran los datos,
 * luego carga los datos en la lista
 * @param lista array de servicios
 * @param tam tamaño del array
 * @param indice posicion del array
 * @param idServicio id para el servicio que se quiere cargar
 * @param descripcion descripcion del servicio
 * @param precio precio del servicio
 * @return retorna 0 si funcionó, -1 si no
 */
int agregarServicio(eServicio *lista, int tam,int indice, int idServicio,char *descripcion ,float precio);

/**
 * @fn int IncrementarId(int*)
 * @brief
 * Incrementa automaticamente el id
 * @param proximoId id a convertir
 * @return id convertido
 */
int IncrementarId (int *proximoId);

/**
 * @fn int BuscarLibre(eServicio*, int)
 * @brief
 * busca una posicion libre en el array revisando el campo isEmpty
 * @param lista array de servicios
 * @param tam tamaño del array
 * @return posicion libre o -1 si no hay
 */
int BuscarLibre(eServicio *lista, int tam);

/**
 * @fn int ImprimirServicios(eServicio*, int)
 * @brief
 * muestra una lista de los servicios y sus caracteristicas
 * @param lista array de servicios
 * @param len tamaño del array
 * @return 0 si salio bien, -1 si no
 */
int ImprimirServicios(eServicio *lista, int len);

/**
 * @fn int inicializarServicios(eServicio*, int)
 * @brief
 * inicializa el campo isEmpty en 0 o TRUE
 * @param lista array de servicios
 * @param tam tamaño del array
 * @return 0 si salio bien, -1 si no
 */
int inicializarServicios(eServicio *lista, int tam);

/***
 * @fn eServicio PedirDatosServicio()
 * @brief
 * carga los datos del servicio
 * @return devuelve el servicio con sus datos
 */
eServicio PedirDatosServicio();

/**
 * @fn int ModificarServicio(eServicio*, int)
 * @brief
 * segun el array del servicio a modificar, permite elegir y modificar alguno de sus campos
 * @param listaServicios array de servicios
 * @param tam tamaño del array
 * @return 0 si modificó, -1 si no
 */
int ModificarServicio(eServicio *listaServicios, int tam);

/**
 * @fn int bajaservicio(int, eServicio*, int)
 * @brief
 * da de baja un servicio cambiando su campo isEmpty a TRUE
 * @param id id del servicio a dar de baja
 * @param listaServicios array de servicios
 * @param tam tamaño del array
 * @return 0 si dio de baja, -1 si no
 */
int bajaservicio(int id,eServicio *listaServicios, int tam);

/**
 * @fn int EncontrarServicioPorId(eServicio*, int, int*)
 * @brief
 * recibe un id y lo busca para verificar su existencia
 * @param lista array de servicios
 * @param len tamaño del array
 * @param id id del servicio
 * @return devuelve la posicion(i) si lo encontró, -1 si no
 */
int EncontrarServicioPorId(eServicio *lista, int len, int *id);



#endif /* SERVICIO_H_ */
