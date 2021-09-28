/*
 * protocolo.h
 *
 *  Created on: 25 sep. 2021
 *      Author: andres
 */

#ifndef SRC_PROTOCOLO_H_
#define SRC_PROTOCOLO_H_

#define FLAG_DE_TERMINACION 127

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include "socket.h"




typedef struct{
	socket_t *skt_server;
	socket_t *skt_cliente;
}protocolo_t;

int protocolo_inicio_cliente(protocolo_t *instancia_de_protocolo,const char *host, const char *port);

void protocolo_inicio_servidor(protocolo_t *instancia_de_protocolo,const char *host, const char *port);

void protocolo_aceptar_cliente(protocolo_t *instancia_de_protocolo);

void protocolo_enviar_mensaje_a_cliente(protocolo_t *instancia_de_protocolo, int *intentos,char *palabra_actual, int flag_estado);

void protocolo_recibir_mensaje_de_cliente(protocolo_t *instancia_de_protocolo, char *input);

void protocolo_enviar_mensaje_a_servidor(protocolo_t *instancia_de_protocolo,size_t letras_a_recibir,char *buffer);

void protocolo_recibir_datos_partida_servidor(protocolo_t *instancia_de_protocolo,uint8_t *palabra_user, int *intentos);

void protocolo_recibir_datos_longitud_palabra_servidor(protocolo_t *instancia_de_protocolo,int *palabra_user);

void protocolo_recibir_datos_palabra_servidor(protocolo_t *instancia_de_protocolo,char *palabra_user, int *len_palabra);




#endif /* SRC_PROTOCOLO_H_ */
