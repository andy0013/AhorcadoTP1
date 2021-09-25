/*
 * lector_de_archivo.c
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */
#include "lector_de_archivo.h"

void archivo_inicio(lector_de_archivo *archivo,char *argumento_path_archivo){
	archivo->file = fopen("words.txt", "r");
	archivo->line = NULL;
	archivo->lenLineaLeida = 0;

}

void leer_linea_archivo(lector_de_archivo *archivo){

	getline(&archivo->line,&archivo->lenLineaLeida,archivo->file);

}

int linea_llego_al_final(lector_de_archivo *archivo){

	return feof(archivo->file);

}



void archivo_fin(){

}

