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

	size_t sizeBytes;

	int posicion_letra_leida;

	char *palabraParaUser;

} cliente;


void cliente_inicio(cliente *instancia_de_cliente);

void cliente_obtener_input_user(cliente *instancia_de_cliente, char *char_user);

void cliente_obtener_input_siguiente_user(cliente *instancia_de_cliente,char *char_user);

void cliente_preparar_palabra(cliente *instancia_de_cliente);

//	printf("%s\n","ingrese una letra:");
//
//	getline(&input,&sizeBytes,stdin);


#endif /* CLIENTE_H_ */
