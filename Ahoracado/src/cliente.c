/*
 * cliente.c
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */
#
#include "cliente.h"

void cliente_inicio(cliente *instancia_de_cliente){

	instancia_de_cliente->input = NULL;

	instancia_de_cliente->se_cargo_input = 0;

	instancia_de_cliente->posicion_letra_leida = 0;

}

void cliente_obtener_input_user(cliente *instancia_de_cliente,char *char_user){

	//USO PRINT Y GETLINE, DEBE SER SOCKET

	if(!instancia_de_cliente->se_cargo_input){

		printf("%s\n","ingrese una letra:");

		size_t size_bytes;

		getline(&instancia_de_cliente->input,&size_bytes,stdin);

		*char_user = instancia_de_cliente->input[instancia_de_cliente->posicion_letra_leida];

		instancia_de_cliente->se_cargo_input = 1;

	} else {

		cliente_obtener_input_siguiente_user(instancia_de_cliente, char_user);

	}
}

void cliente_obtener_input_siguiente_user(cliente *instancia_de_cliente,char *char_user){

	instancia_de_cliente->posicion_letra_leida++;

	if(instancia_de_cliente->input[instancia_de_cliente->posicion_letra_leida] != '\n'){

		*char_user = instancia_de_cliente->input[instancia_de_cliente->posicion_letra_leida];

	}else{

		cliente_inicio(instancia_de_cliente);

		cliente_obtener_input_user(instancia_de_cliente, char_user);

	}

}

void cliente_mensaje_palabra_actual(char *palabra_actual){

	printf("%s\n\n\n", palabra_actual);

}

void cliente_mensaje_final_del_juego(int cantidad_ganadas, int cantidad_perdidas){

	printf("Resumen:\n");

	printf("\t Victorias: %d\n", cantidad_ganadas );

	printf("\t Derrotas: %d\n", cantidad_perdidas);

}



void cliente_user_adivino_la_palabra(){

	printf("Ganaste\n\n");

}

