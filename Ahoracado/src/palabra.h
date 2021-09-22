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

void palabra_inicio(palabra *palabra_en_uso,int longitud, char *palabra_leida);

int palabras_leidas_e_construidas_son_iguales(palabra *palabra_en_uso);


#endif /* PALABRA_H_ */
