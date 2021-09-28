/*
 * palabra.h
 *
 *  Created on: 21 sep. 2021
 *      Author: andres
 */

#ifndef PALABRA_H_
#define PALABRA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	int longitud;
	char *palabra_leida;
	char *palabra_en_juego;
} palabra;

/*
 * Iniciamos las variables del TDA palabra. En este TDA guardamos
 * los datos necesarios para la partida en el juego del ahorcado.
 */
void palabra_inicio(palabra *palabra_en_uso,int longitud, char *palabra_leida);

/*
 * Con los datos disponibles en el TDA, retorna 1 si se adivino la palabra.
 * retorna 0 si no se adivino la palabra.
 */
int palabras_leidas_e_construidas_son_iguales(palabra *palabra_en_uso);

/*
 * Modificamos las varibles de nuestro TDA en funcion del input del usuario.
 * Tambien en caso de error o acierto, modificamos el puntero a int de los intentos disponibles.
 */
void palabra_revisar_caracter_y_intentos(palabra *palabra_en_uso,char leido,int *intentos);

/*
 * Liberamos la memoria allocada.
 */
void palabra_fin(palabra *palabra_en_uso);



#endif /* PALABRA_H_ */
