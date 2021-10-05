/*
 * protocolo.c
 *
 *  Created on: 25 sep. 2021
 *      Author: andres
 */

#ifndef SRC_PROTOCOLO_C_
#define SRC_PROTOCOLO_C_
#include "common_protocolo.h"

int protocolo_inicio_cliente(protocolo_t *instancia_de_protocolo,
		const char *host, const char *port) {
	socket_t skt;

	socket_init(&skt);

	instancia_de_protocolo->skt_cliente = skt;

	return socket_connect(&instancia_de_protocolo->skt_cliente, host, port);
}

int protocolo_inicio_servidor(protocolo_t *instancia_de_protocolo,
		const char *host, const char *port) {
	socket_t skt;

	socket_init(&skt);

	instancia_de_protocolo->skt_server = skt;

	socket_t skt_cliente;

	socket_init(&skt_cliente);

	instancia_de_protocolo->skt_cliente = skt_cliente;

	return socket_bind_and_listen(&instancia_de_protocolo->skt_server, NULL,
			port);
}

void protocolo_aceptar_cliente(protocolo_t *instancia_de_protocolo) {
	if (instancia_de_protocolo->skt_cliente.fd == 0) {
		socket_t skt_cliente_conectado;

		socket_accept(&instancia_de_protocolo->skt_server,
				&skt_cliente_conectado);

		instancia_de_protocolo->skt_cliente = skt_cliente_conectado;

	} else {
		socket_uninit(&instancia_de_protocolo->skt_cliente);

		instancia_de_protocolo->skt_cliente.fd = 0;

		protocolo_aceptar_cliente(instancia_de_protocolo);
	}
}

void protocolo_recibir_datos_partida_servidor(
		protocolo_t *instancia_de_protocolo, uint8_t *termino_la_partida,
		int *intentos) {
	uint8_t informacion_juego;

	*termino_la_partida = 0;

	socket_receive(&instancia_de_protocolo->skt_cliente, (char*)&informacion_juego,
			sizeof(uint8_t));

	if (informacion_juego >= FLAG_DE_TERMINACION) {
		*termino_la_partida = 1;

		*intentos = informacion_juego - FLAG_DE_TERMINACION;

	} else {
		*intentos = informacion_juego;
	}
}

void protocolo_recibir_datos_longitud_palabra_servidor(
		protocolo_t *instancia_de_protocolo, int *palabra_user) {
	uint16_t len_palabra;

	socket_receive(&instancia_de_protocolo->skt_cliente, (char*)&len_palabra,
			sizeof(uint16_t));

	*palabra_user = ntohs(len_palabra);
}

void protocolo_recibir_datos_palabra_servidor(
		protocolo_t *instancia_de_protocolo, char *palabra_user,
		int *len_palabra) {
	socket_receive(&instancia_de_protocolo->skt_cliente, palabra_user,
			*len_palabra);
}

void protocolo_enviar_mensaje_a_cliente(protocolo_t *instancia_de_protocolo,
		int *intentos, char *palabra_actual, int flag_estado) {
	uint8_t estado_juego = *intentos;
	uint8_t flag = 127;
	uint16_t len = strlen(palabra_actual);
	if (flag_estado) {
		estado_juego = estado_juego + flag;
		len = len - 1;
	}
	uint16_t len_buf = htons(len);
	socket_send(&instancia_de_protocolo->skt_cliente,(char*)&estado_juego,
			sizeof(uint8_t));
	socket_send(&instancia_de_protocolo->skt_cliente, (char*)&len_buf,
			sizeof(uint16_t));
	socket_send(&instancia_de_protocolo->skt_cliente, palabra_actual, len);
}

void protocolo_recibir_mensaje_de_cliente(protocolo_t *instancia_de_protocolo,
		char *input) {
	socket_receive(&instancia_de_protocolo->skt_cliente, input, 1);
}

void protocolo_enviar_mensaje_a_servidor(protocolo_t *instancia_de_protocolo,
		size_t letras_enviadas, char *buffer) {
	socket_send(&instancia_de_protocolo->skt_cliente, buffer,
			1/*strlen(letras_enviadas)*/);
}

void protocolo_fin_cliente(protocolo_t *instancia_de_protocolo) {
	socket_uninit(&instancia_de_protocolo->skt_cliente);
	free(&instancia_de_protocolo->skt_cliente);
}

void protocolo_fin_servicio(protocolo_t *instancia_de_protocolo) {
	socket_uninit(&instancia_de_protocolo->skt_server);
	socket_uninit(&instancia_de_protocolo->skt_cliente);
}

#endif /* SRC_PROTOCOLO_C_ */
