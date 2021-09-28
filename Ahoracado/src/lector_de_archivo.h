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

/*
 * Abre el archivo recibido como parametro en solo lectura.
 * Inicia las variables del TDA.
 */
void archivo_inicio(lector_de_archivo *archivo,char *argumento_path_archivo);


/*
 * Lee la primer linea. Utilizamos "Getline" como sugerencia del enunciado.
 */
void leer_linea_archivo(lector_de_archivo *archivo);

/*
 * Retorna 1 en caso de que finalizamos de leer el archivo.
 * Retorna 0 en caso de que aun no llegamos al final del archivo.
 */
int linea_llego_al_final(lector_de_archivo *archivo);

/*
 * Libera los recursos del TDA lector_de_archivo fclose().
 */
void archivo_fin(lector_de_archivo *archivo);


#endif /* LECTOR_DE_ARCHIVO_H_ */
