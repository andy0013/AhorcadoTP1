/*
 * servidor.c
 *
 *  Created on: 22 sep. 2021
 *      Author: andres
 */
#include "server_servidor.h"

#ifndef SERVIDOR_C_
#define SERVIDOR_C_

int servidor_ejecutar(int argc, char *argv[]) {
	servidor servidor_levantado;
	int intentos = strtol(argv[2], NULL, 10);
	if(intentos <= 0)
		return ERROR;

	if (servidor_inicio(&servidor_levantado, argv[1]) != EXITO)
		return ERROR;

	servidor_comunicacion(&servidor_levantado, &intentos, argv[3]);

	servidor_fin(&servidor_levantado);

	return EXITO;
}

int servidor_inicio(servidor *servidor_creado, char *port) {
	protocolo_t protocolo;

	int escuchando_sockets = protocolo_inicio_servidor(&protocolo, HOST,
			port);

	servidor_creado->procolo = protocolo;

	return escuchando_sockets;
}

void servidor_comunicacion(servidor *servidor_creado, int *intentos,
		char *argumento_path_archivo) {
	juego juego_ahorcado;

	consola jugador;

	consola_inicio(&jugador, &servidor_creado->procolo);

	juego_inicio(&juego_ahorcado, &jugador, *intentos);

	juego_levantar_dato(&juego_ahorcado, argumento_path_archivo);

	juego_preparar_ahorcado(&juego_ahorcado);

	juego_ejecutar(&juego_ahorcado);

	juego_fin(&juego_ahorcado);
}

void servidor_fin(servidor *servidor_creado) {
	protocolo_fin_servicio(&servidor_creado->procolo);
}

#endif /* SRC_SERVIDOR_C_ */
