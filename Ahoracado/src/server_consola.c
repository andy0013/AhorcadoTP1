/*
 * cliente.c
 *
 *  Created on: 18 sep. 2021
 *      Author: andres
 */

#include "server_consola.h"

void consola_inicio(consola *instancia_de_consola, protocolo_t *servidor_a_user) {

//	instancia_de_consola->input = NULL;

	instancia_de_consola->input = (char*) malloc(sizeof(char));

	instancia_de_consola->se_cargo_input = 0;

	instancia_de_consola->posicion_letra_leida = 0;

	instancia_de_consola->servidor_a_user = servidor_a_user;
}

void consola_conectar_usuario_de_ser_necesario(consola *instancia_de_consola) {

	if (instancia_de_consola->servidor_a_user->skt_cliente.fd == 0) {

		protocolo_aceptar_cliente(instancia_de_consola->servidor_a_user);

	}


}

void consola_finalizar_partida_cliente_actual(consola *instancia_de_consola) {

	socket_uninit(&instancia_de_consola->servidor_a_user->skt_cliente);

	instancia_de_consola->servidor_a_user->skt_cliente.fd = 0;

}

void consola_obtener_input_user(consola *instancia_de_consola, char *char_user) {

	if (!instancia_de_consola->se_cargo_input) {

//		instancia_de_consola->input = (char *)malloc(sizeof(char));

		protocolo_recibir_mensaje_de_cliente(
				instancia_de_consola->servidor_a_user,
				instancia_de_consola->input);

		*char_user =
				instancia_de_consola->input[instancia_de_consola->posicion_letra_leida];

		instancia_de_consola->se_cargo_input = 1;

	} else {

		consola_obtener_input_siguiente_user(instancia_de_consola, char_user);

	}
}

void consola_obtener_input_siguiente_user(consola *instancia_de_consola,
		char *char_user) {

//	instancia_de_consola->input = (char *)malloc(sizeof(char));

	protocolo_recibir_mensaje_de_cliente(instancia_de_consola->servidor_a_user,
			instancia_de_consola->input);

	*char_user =
			instancia_de_consola->input[instancia_de_consola->posicion_letra_leida];

	if (*char_user == '\n') {

		instancia_de_consola->se_cargo_input = 0;

		consola_obtener_input_user(instancia_de_consola, char_user);
	}
}

void consola_mensaje_palabra_actual(consola *instancia_de_consola,
		char *palabra_actual, int *intentos, int flag_estado) {

	protocolo_enviar_mensaje_a_cliente(instancia_de_consola->servidor_a_user,
			intentos, palabra_actual, flag_estado);

}

void consola_fin(consola *instancia_de_consola) {

	protocolo_fin_servicio(instancia_de_consola->servidor_a_user);

	free(instancia_de_consola->input);

}

