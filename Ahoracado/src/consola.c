/*
 * cliente.c
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#include "consola.h"

void consola_inicio(consola *instancia_de_consola, protocolo_t *servidor_a_user){

	instancia_de_consola->input = NULL;

	instancia_de_consola->se_cargo_input = 0;

	instancia_de_consola->posicion_letra_leida = 0;

	instancia_de_consola->servidor_a_user = servidor_a_user;
}

void consola_obtener_input_user(consola *instancia_de_consola,char *char_user){

	if(!instancia_de_consola->se_cargo_input){

		instancia_de_consola->input = (char *)malloc(sizeof(char));

		protocolo_recibir_mensaje_de_cliente(instancia_de_consola->servidor_a_user, instancia_de_consola->input);

		*char_user = instancia_de_consola->input[instancia_de_consola->posicion_letra_leida];

		instancia_de_consola->se_cargo_input = 1;

	} else {

		consola_obtener_input_siguiente_user(instancia_de_consola, char_user);

	}
}

void consola_obtener_input_siguiente_user(consola *instancia_de_consola,char *char_user){

	instancia_de_consola->input = (char *)malloc(sizeof(char));

	protocolo_recibir_mensaje_de_cliente(instancia_de_consola->servidor_a_user,instancia_de_consola->input);

	*char_user = instancia_de_consola->input[instancia_de_consola->posicion_letra_leida];

	if(*char_user == '\n'){

		instancia_de_consola->se_cargo_input = 0;

		consola_obtener_input_user(instancia_de_consola, char_user);
	}
}

void consola_mensaje_palabra_actual(consola *instancia_de_consola,char *palabra_actual, int *intentos){

	protocolo_enviar_mensaje_a_cliente(instancia_de_consola->servidor_a_user, intentos, palabra_actual);


}

void consola_mensaje_final_del_juego(int cantidad_ganadas, int cantidad_perdidas){

	printf("Resumen:\n");

	printf("\t Victorias: %d\n", cantidad_ganadas );

	printf("\t Derrotas: %d\n", cantidad_perdidas);

}



void consola_user_adivino_la_palabra(consola *instancia_de_consola){

	socket_send(instancia_de_consola->servidor_a_user, 'Ganaste!!', 10);
	socket_send(instancia_de_consola->servidor_a_user, '\n', 10);

}

