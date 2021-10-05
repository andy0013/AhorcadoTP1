/*
 * cliente.c
 *
 *  Created on: 24 sep. 2021
 *      Author: andres
 */

#include "client_cliente.h"

int cliente_ejectuar(int argc, char *argv[]) {

	cliente servidor_conectado;

	if (cliente_inicio(&servidor_conectado, argv[1], argv[2]) != EXITO)
		return ERROR;

	cliente_comunicacion(&servidor_conectado);

	cliente_fin(&servidor_conectado);

	return EXITO;
}

int cliente_inicio(cliente *servidor_conectado, char *host, char *port) {

	protocolo_t protocolo;

	int cliente_desconectado = protocolo_inicio_cliente(&protocolo, host, port);

	servidor_conectado->protocolo = protocolo;

	return cliente_desconectado;
}

void cliente_comunicacion(cliente *servidor_conectado) {

	locutor locutor_de_la_partida;

	locutor_inicio(&locutor_de_la_partida);

	int juego_en_curso = 1;

	while (juego_en_curso) {

		locutor_preparar_atributos_de_partida(&locutor_de_la_partida);

		locutor_recibir_y_actualizar(&locutor_de_la_partida,
				&servidor_conectado->protocolo);

		if (locutor_termino_el_juego_ganamos(&locutor_de_la_partida))
			break;

		if (locutor_termino_el_juego_perdimos(&locutor_de_la_partida))
			break;

		locutor_imprimir_informacon_recibida(&locutor_de_la_partida);

		locutor_solicitar_y_enviar_letra_del_input_user(&locutor_de_la_partida,
				&servidor_conectado->protocolo);

	}

	locutor_fin(&locutor_de_la_partida);
}

void cliente_fin(cliente *servidor_creado) {

//	protocolo_fin_cliente(&servidor_creado->protocolo);

//	free(servidor_creado->protocolo);

}

