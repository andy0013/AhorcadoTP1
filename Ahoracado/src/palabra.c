/*
 * palabra.c
 *
 *  Created on: 21 sep. 2021
 *      Author: andres
 */

#include "palabra.h"


void palabra_inicio(palabra *palabra_en_uso, int longitud, char *palabra_leida){

	palabra_en_uso->longitud = longitud;

	palabra_en_uso->palabra_en_juego = (char *)malloc(longitud*sizeof(char));

	for(int i = 0 ; i < (longitud) ; i++ ){

		palabra_en_uso->palabra_en_juego[i] = '_';

	}

	palabra_en_uso->palabra_leida = palabra_leida;


}

int palabras_leidas_e_construidas_son_iguales(palabra *palabra_en_uso){

	int palabras_son_iguales = 1;

	for(int i = 0 ; i < (palabra_en_uso->longitud) ; i++ ){

		if(palabra_en_uso->palabra_en_juego[i] != palabra_en_uso->palabra_leida[i] ){

			palabras_son_iguales = 0;

		}

	}

	return palabras_son_iguales;

}


void palabra_detectar_char_y_modificar_datos(palabra *palabra_en_uso,char leido,int *intentos){

	char caracter_leido;

	int user_fallo = 1;

	for(int i = 0 ; i < palabra_en_uso->longitud ; i++ ){

		caracter_leido = palabra_en_uso->palabra_leida[i];

		if(caracter_leido == leido){

			palabra_en_uso->palabra_en_juego[i] = leido;

			user_fallo = 0;

		}

	}

	if(user_fallo){

		*intentos = *intentos - 1;

	}

}



