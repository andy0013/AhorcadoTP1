/*
 * cliente.c
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */
#
#include "cliente.h"

void cliente_inicio(cliente *instancia_de_cliente){

	instancia_de_cliente->palabraParaUser = NULL;

	instancia_de_cliente->input = NULL;

	instancia_de_cliente->sizeBytes = 0;

	instancia_de_cliente->posicion_letra_leida = 0;

}

void cliente_obtener_input_user(cliente *instancia_de_cliente,char *char_user){

	//USO PRINT Y GETLINE, DEBE SER SOCKET

	printf("%s\n","ingrese una letra:");

	getline(&instancia_de_cliente->input,&instancia_de_cliente->input,stdin);

	*char_user = instancia_de_cliente->input[instancia_de_cliente->posicion_letra_leida];

}

void cliente_obtener_input_siguiente_user(cliente *instancia_de_cliente,char *char_user){

	instancia_de_cliente->posicion_letra_leida++;

	if(instancia_de_cliente->input[instancia_de_cliente->posicion_letra_leida] != '\n'){

		*char_user = instancia_de_cliente->input[instancia_de_cliente->posicion_letra_leida];

	}else{

		cliente_inicio(&(*instancia_de_cliente));

		cliente_obtener_input_user(&(*instancia_de_cliente), &(*char_user));

	}



}
