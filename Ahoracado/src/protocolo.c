/*
 * protocolo.c
 *
 *  Created on: 25 sep. 2021
 *      Author: andres
 */

#ifndef SRC_PROTOCOLO_C_
#define SRC_PROTOCOLO_C_
#include "protocolo.h"

void protocolo_inicio_cliente(protocolo_t *instancia_de_protocolo,const char *host, const char *port){

	socket_t *skt = malloc(sizeof(socket_t));

	instancia_de_protocolo->skt_cliente = skt;

	socket_init(instancia_de_protocolo->skt_cliente);

	socket_connect(instancia_de_protocolo->skt_cliente, host, port);

//	instancia_de_protocolo
}


void protocolo_inicio_servidor(protocolo_t *instancia_de_protocolo,const char *host, const char *port){

	socket_t *skt = malloc(sizeof(socket_t));

	instancia_de_protocolo->skt_cliente = NULL;

	instancia_de_protocolo->skt_server = skt;

	socket_init(instancia_de_protocolo->skt_server);

	socket_bind_and_listen(instancia_de_protocolo->skt_server, NULL, port );

}


void protocolo_aceptar_cliente(protocolo_t *instancia_de_protocolo){

	if(instancia_de_protocolo->skt_cliente == NULL){

		socket_t *skt_cliente_conectado = malloc(sizeof(socket_t));

		instancia_de_protocolo->skt_cliente = skt_cliente_conectado;

		socket_accept(instancia_de_protocolo->skt_server, instancia_de_protocolo->skt_cliente);

	} else {

		socket_uninit(instancia_de_protocolo->skt_cliente);

		instancia_de_protocolo->skt_cliente = NULL;

		protocolo_aceptar_cliente(instancia_de_protocolo);

	}
}



void parseo_ascii_a_char(char *buffer, size_t cantidad_letras){

	for(int i = 0 ; i < cantidad_letras ; i++ ){

		buffer[i] = (char) buffer[i];

	}

}

void parseo_char_a_ascii(char *buffer, size_t cantidad_letras){

	for(int i = 0 ; i < cantidad_letras ; i++ ){

		buffer[i] = (long) buffer[i];

	}

}

void mensaje_a_user(char *mensaje, char *output){



}




void protocolo_recibir_datos_partida_servidor(protocolo_t *instancia_de_protocolo,char *palabra_user){

	uint8_t informacion_juego = malloc(sizeof(uint8_t));

	socket_receive(instancia_de_protocolo->skt_cliente, &informacion_juego, sizeof(uint8_t));

}

void protocolo_recibir_datos_longitud_palabra_servidor(protocolo_t *instancia_de_protocolo,int *palabra_user){

	uint16_t len_palabra = malloc(sizeof(uint16_t));

	socket_receive(instancia_de_protocolo->skt_cliente, &len_palabra, sizeof(uint16_t));

	len_palabra = ntohs(len_palabra);

	memcpy(palabra_user,&len_palabra,2);
}

void protocolo_recibir_datos_palabra_servidor(protocolo_t *instancia_de_protocolo,char *palabra_user, int *len_palabra){

	socket_receive(instancia_de_protocolo->skt_cliente, palabra_user, *len_palabra);

}






void protocolo_enviar_mensaje_a_cliente(protocolo_t *instancia_de_protocolo, int *intentos,  char *palabra_actual,int flag_estado){
	uint8_t estado_juego = *intentos;
	uint8_t flag = 128;
	if(flag_estado){
		estado_juego = estado_juego + flag;
	}
	uint16_t len = strlen(palabra_actual);
	uint16_t len_buf = htons(len);
    socket_send(instancia_de_protocolo->skt_cliente, &estado_juego, sizeof(uint8_t));
	socket_send(instancia_de_protocolo->skt_cliente, &len_buf, sizeof(uint16_t));
    socket_send(instancia_de_protocolo->skt_cliente, palabra_actual, len);

}

void protocolo_recibir_mensaje_de_cliente(protocolo_t *instancia_de_protocolo, char *input){

	socket_receive(instancia_de_protocolo->skt_cliente,input, 1);

	parseo_ascii_a_char(input, 1);

}


void protocolo_enviar_mensaje_a_servidor(protocolo_t *instancia_de_protocolo,size_t letras_enviadas,char *buffer){

	socket_send(instancia_de_protocolo->skt_cliente, buffer, 1/*strlen(letras_enviadas)*/);

}




#endif /* SRC_PROTOCOLO_C_ */
