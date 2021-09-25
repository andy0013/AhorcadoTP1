/*
 * cliente.h
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <string.h>
#include "socket.h"

typedef struct {

	char *input;

	int se_cargo_input;

	int posicion_letra_leida;

	socket_t *servidor_a_user;

} consola;


void consola_inicio(consola *instancia_de_consola, socket_t *servidor_a_user);

void consola_obtener_input_user(consola *instancia_de_consola, char *char_user);

void consola_obtener_input_siguiente_user(consola *instancia_de_consola,char *char_user);

void consola_mensaje_palabra_actual(consola *instancia_de_consola,char *palabra_actual);

void consola_mensaje_final_del_juego(int cantidad_ganadas, int cantidad_perdidas);

void consola_user_adivino_la_palabra(consola *instancia_de_consola);

#endif /* CLIENTE_H_ */
