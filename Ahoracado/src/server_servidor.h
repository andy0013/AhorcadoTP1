/*
 * servidor.h
 *
 *  Created on: 22 sep. 2021
 *      Author: andres
 */

#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "server_consola.h"
#include "server_juego_ahorcado.h"
#include "common_socket.h"
#include "common_protocolo.h"

#define HOST "localhost"
#define EXITO 0
#define ERROR 1

typedef struct {
	protocolo_t procolo;
} servidor;

/*
 * Ejecuta el flujo de iniciar el servidor.
 * una vez bindeado, queda escuchando a sockets.
 * Ejecuta la comunicacion, donde esta el flujo del juego.
 * Finalizar la comunicacion.
 * Retorna: 1 en caso de ERROR, 0 en caso de EXITO.
 */
int servidor_ejecutar(int argc, char *argv[]);

/*
 * Inicia el protocolo de nuestro TDA.
 * Retorna: 0 en caso de EXITO, 1 en caso de error.
 */
int servidor_inicio(servidor *servidor_creado, char *port);

/*
 * Se ocupa de comunicarse con el usuario, en el juego.
 * Inicia el TDA Juego ahorcado, que se ocupa del flujo de la partida, y
 * Consola que se ocupa de la comunicacion con el cliente.
 * Y de solicitar valores al usuario.
 */
void servidor_comunicacion(servidor *servidor_creado, int *intentos,
		char *argumento_path_archivo);

/*
 * Libera los recursos solicitados en el TDA.
 */
void servidor_fin(servidor *servidor_creado);

#endif /* SRC_SERVIDOR_H_ */
