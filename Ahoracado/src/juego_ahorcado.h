/*
 * game_ahorcado.h
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */

#include "lector_de_archivo.h"
#include "cliente.h"
#include "palabra.h"
#include <string.h>

#ifndef JUEGO_AHORCADO_H_
#define JUEGO_AHORCADO_H_

typedef struct {
	int intentosDisponibles;
	lector_de_archivo archivo;
	cliente cliente_user_servidor;
	palabra palabra_leida;
	int veces_que_gano;
	int veces_que_perdio;
} juego;


void juego_inicio(juego *instancia_de_juego);

void juego_levantar_dato(juego *instancia_de_juego);

void juego_preparar_ahorcado(juego *instancia_de_juego);

void elCharLeidoPertenece(char* line,char leido,int *intentos, char *palabraParaInterfaz, int *letras_adivinadas);

void juego_ejecutar(juego *instancia_de_juego);

void juego_fin();


#endif /* JUEGO_AHORCADO_H_ */
