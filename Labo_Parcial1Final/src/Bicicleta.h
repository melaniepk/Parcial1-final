/*
 * Bicicleta.h
 *
 *  Created on: 20 may. 2021
 *      Author: mkale
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_

#define MARCA_LEN 26
#define COLOR_LEN 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Trabajo.h"
//#include "Servicio.h"
//#include "informes.h"
#include "utn1.h"

typedef struct
{
	char marca[MARCA_LEN];
	int idBicicleta;
	float rodado;
	char color[COLOR_LEN];
	int isEmpty;

}eBicicleta;

int inicializarBicicletas(eBicicleta *list, int len);
eBicicleta PedirDatosBicicleta();
int BuscarLibreB(eBicicleta *lista, int tam);
int IncrementarIdB (int *proximoId);

int agregarBicicletaHard(eBicicleta *lista, int tam,int indice, int idBicicleta,char *marca ,float rodado, char* color);
int ImprimirBicicletas(eBicicleta *lista,int tam);
int ModificarBicicleta(eBicicleta *lista, int tam);
int EncontrarBicicletaPorId(eBicicleta *lista, int len, int *id);
int bajaBicicleta(int id,eBicicleta *lista, int tam);
int agregarBicicleta(eBicicleta *lista, int len,int id);



#endif /* BICICLETA_H_ */
