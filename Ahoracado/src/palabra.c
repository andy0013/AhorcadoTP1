/*
 * palabra.c
 *
 *  Created on: 21 sep. 2021
 *      Author: andres
 */

#include "palabra.h"


void palabra_inicio(palabra *palabra_en_uso, int cantidad_letras, int longitud, char *palabra_leida){

	palabra_en_uso->cantidad_de_letras = cantidad_letras;

	palabra_en_uso->longitud = longitud;

	palabra_en_uso->palabra_en_juego = (char *)malloc(longitud*sizeof(char));

	for(int i = 0 ; i < (longitud) ; i++ ){

		palabra_en_uso->palabra_en_juego[i] = '_';

	}

	palabra_en_uso->palabra_leida = palabra_leida;


}
