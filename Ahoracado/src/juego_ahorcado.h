/*
 * game_ahorcado.h
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */

#include "lector_de_archivo.h"
#include "cliente.h"
#include <string.h>

#ifndef JUEGO_AHORCADO_H_
#define JUEGO_AHORCADO_H_


typedef struct {
	int intentosDisponibles;
	lector_de_archivo archivo;
	cliente cliente_user_servidor;
} juego;

void juego_inicio(juego *instancia_de_juego);

void juego_preparar_ahorcado(juego *instancia_de_juego);

void juego_inicializar_palabra_actual_para_usuario(char *palabraParaInterfaz, int longitudDePalabraPorAdivinarEnEsteIntento);

void juego_modificar_palabra_actual_para_usuario(char *palabraParaInterfaz);

void elCharLeidoPertenece(char* line,char leido,int *intentos, char *palabraParaInterfaz);

void juego_ejecutar(juego *instancia_de_juego);

void juego_fin();


#endif /* JUEGO_AHORCADO_H_ */
