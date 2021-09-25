/*
 * lector_de_archivo.h
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <string.h>
#include <wchar.h>


#ifndef LECTOR_DE_ARCHIVO_H_
#define LECTOR_DE_ARCHIVO_H_

typedef struct {
	FILE *file;
	char *line;
	size_t lenLineaLeida;
} lector_de_archivo;


void archivo_inicio(lector_de_archivo *archivo,char *argumento_path_archivo);

void leer_linea_archivo(lector_de_archivo *archivo);

int linea_llego_al_final(lector_de_archivo *archivo);

void archivo_fin();


#endif /* LECTOR_DE_ARCHIVO_H_ */
