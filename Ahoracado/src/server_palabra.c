/*
 * palabra.c
 *
 *  Created on: 21 sep. 2021
 *      Author: andres
 */

#include "server_palabra.h"

void palabra_inicio(palabra *palabra_en_uso, int longitud
		, char *palabra_leida) {
	palabra_en_uso->longitud = longitud;

	palabra_en_uso->palabra_en_juego = (char*) malloc(longitud * sizeof(char));

	for (int i = 0; i < (longitud); i++) {
		palabra_en_uso->palabra_en_juego[i] = '_';
	}
	palabra_en_uso->palabra_leida = palabra_leida;
}

int palabras_leidas_e_construidas_son_iguales(palabra *palabra_en_uso) {
	int palabras_son_iguales = 1;

	for (int i = 0; i < (palabra_en_uso->longitud); i++) {
		if (palabra_en_uso->palabra_en_juego[i]
				!= palabra_en_uso->palabra_leida[i]) {
			palabras_son_iguales = 0;
		}
	}
	return palabras_son_iguales;
}

int el_caracter_propuesto_fue_propuesto_previamente(palabra *palabra_en_uso,
		char leido) {
	int fue_propuesto_previamente = 0;

	char caracter_leido;

	for (int i = 0; i < palabra_en_uso->longitud; i++) {
		caracter_leido = palabra_en_uso->palabra_en_juego[i];
		if ((caracter_leido == leido)) {
			fue_propuesto_previamente = 1;
		}
	}
	return fue_propuesto_previamente;
}

int modificar_palabra_en_uso(palabra *palabra_en_uso, char leido) {
	int modificamos_palabra_en_juego = 0;

	char caracter_leido;

	for (int i = 0; i < palabra_en_uso->longitud; i++) {
		caracter_leido = palabra_en_uso->palabra_leida[i];
		if ((caracter_leido == leido)) {
			palabra_en_uso->palabra_en_juego[i] = leido;

			modificamos_palabra_en_juego = 1;
		}
	}
	return modificamos_palabra_en_juego;
}

void palabra_revisar_caracter_y_intentos(palabra *palabra_en_uso,
		char caracter_propuesto, int *intentos) {
	int acerto_letra_propuesta = 0;

	if (el_caracter_propuesto_fue_propuesto_previamente(palabra_en_uso,
			caracter_propuesto)) {
		acerto_letra_propuesta = 0;
	} else {
		acerto_letra_propuesta = modificar_palabra_en_uso(palabra_en_uso,
				caracter_propuesto);
	}
	if (!acerto_letra_propuesta) {
		*intentos = *intentos - 1;
	}
}

void palabra_fin(palabra *palabra_en_uso) {
	free(palabra_en_uso->palabra_en_juego);
}

