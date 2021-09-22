/*
 * palabra.h
 *
 *  Created on: 21 sep. 2021
 *      Author: andres
 */

#ifndef PALABRA_H_
#define PALABRA_H_

typedef struct {
	int cantidad_de_letras;
	int longitud;
	char *palabra_leida;
	char *palabra_en_juego
} palabra;

void palabra_inicio(palabra *palabra_en_uso,  int cantidad_letras, int longitud, char *palabra_leida);

#endif /* PALABRA_H_ */
