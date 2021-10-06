/*
 * protocolo.h
 *
 *  Created on: 25 sep. 2021
 *      Author: andres
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include "common_socket.h"

#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_

#define FLAG_DE_TERMINACION 128

typedef struct {
	socket_t skt_server;
	socket_t skt_cliente;
} protocolo_t;
/*
 *  Inicia la conexion con el servidor.
 *  En caso de error retorna 1, exito 0.
 */
int protocolo_inicio_cliente(protocolo_t *instancia_de_protocolo,
		const char *host, const char *port);

/*
 *  Inicia el servidor.
 *  En caso de error retorna 1, exito 0.
 */
int protocolo_inicio_servidor(protocolo_t *instancia_de_protocolo,
		const char *host, const char *port);

/*
 *  El servidor acepta nuevo cliente.
 */
void protocolo_aceptar_cliente(protocolo_t *instancia_de_protocolo);

/*
 * Envia al cliente, de forma ordenada, los datos recibidos.
 * La forma de enviar la informacion fue definida en el informe.
 */
void protocolo_enviar_mensaje_a_cliente(protocolo_t *instancia_de_protocolo,
		int *intentos, char *palabra_actual, int flag_estado);

/*
 * Recibe el input del cliente. la letra por probar en nuestra palabra.
 */
void protocolo_recibir_mensaje_de_cliente(protocolo_t *instancia_de_protocolo,
		char *input);

/*
 * Envia mensaje al servidor. la letra por probar en nuestra palabra.
 */
void protocolo_enviar_mensaje_a_servidor(protocolo_t *instancia_de_protocolo,
		size_t letras_a_recibir, char *buffer);

/*
 * Recibe el primer byte de informacion que envia el servidor.
 * Obtiene informacion sobre si la paritda sigue, y los intentos.
 */
void protocolo_recibir_datos_partida_servidor(
		protocolo_t *instancia_de_protocolo, uint8_t *palabra_user,
		int *intentos);

/*
 * Recibe los segundos 2 bytes del servidor.
 * Informacion del largo de la palabra.
 */
void protocolo_recibir_datos_longitud_palabra_servidor(
		protocolo_t *instancia_de_protocolo, int *palabra_user);

/*
 * Recibe la palabra del servidor. (largo depende de recv anterior)
 */
void protocolo_recibir_datos_palabra_servidor(
		protocolo_t *instancia_de_protocolo, char *palabra_user,
		int *len_palabra);

/*
 * Libera los recursos solicitados al iniciar el cliente.
 */
void protocolo_fin_cliente(protocolo_t *instancia_de_protocolo);

/*
 * Libera los recursos solicitados al inicial el servidor.
 */
void protocolo_fin_servicio(protocolo_t *instancia_de_protocolo);

#endif /* SRC_PROTOCOLO_H_ */
