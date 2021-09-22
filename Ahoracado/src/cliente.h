/*
 * cliente.h
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>


typedef struct {

	char *input;

	int se_cargo_input;

	int posicion_letra_leida;

} cliente;


void cliente_inicio(cliente *instancia_de_cliente);

void cliente_obtener_input_user(cliente *instancia_de_cliente, char *char_user);

void cliente_obtener_input_siguiente_user(cliente *instancia_de_cliente,char *char_user);

void cliente_mensaje_palabra_actual(char *palabra_actual);

void cliente_mensaje_final_del_juego(int cantidad_ganadas, int cantidad_perdidas);

void cliente_user_adivino_la_palabra();

#endif /* CLIENTE_H_ */
