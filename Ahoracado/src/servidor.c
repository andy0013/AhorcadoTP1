/*
 * servidor.c
 *
 *  Created on: 22 sep. 2021
 *      Author: andres
 */
#include "servidor.h"

#ifndef SERVIDOR_C_
#define SERVIDOR_C_

int servidor_ejecutar(int argc, char *argv[]){
	servidor servidor_levantado;
	servidor_inicio(&servidor_levantado, argv[1]);
	servidor_comunicacion(&servidor_levantado,/*argv[3]*/"words.txt");
	return EXITO;
}


int servidor_inicio(servidor *servidor_creado, char *port){

	socket_t skt;

	servidor_creado->skt;

	socket_init(&servidor_creado->skt);

	socket_bind_and_listen(&servidor_creado->skt, NULL, /*port*/ "7777");

	return EXITO;
}



void servidor_comunicacion(servidor *servidor_creado, char *argumento_path_archivo){

	socket_t skt_cliente_conectado;

	juego juego_ahorcado;

	consola jugador;

	socket_accept(&servidor_creado->skt,&skt_cliente_conectado);

	consola_inicio(&jugador, &skt_cliente_conectado);

	juego_inicio(&juego_ahorcado,&jugador);

	juego_levantar_dato(&juego_ahorcado,/*argumento_path_archivo*/ "words.txt");

	juego_preparar_ahorcado(&juego_ahorcado);

	while(1){

		juego_ejecutar(&juego_ahorcado);

	}

}

void servidor_fin(servidor *servidor_creado){

}



#endif /* SRC_SERVIDOR_C_ */
