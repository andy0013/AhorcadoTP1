/*
 * cliente.c
 *
 *  Created on: 24 sep. 2021
 *      Author: andres
 */

#include "cliente.h"


int cliente_ejecuar(int argc, char *argv[]){
	cliente servidor_conectado;
	if (cliente_inicio(&servidor_conectado, argv[1])==1)return ERROR;
	cliente_comunicacion(&servidor_conectado,/*argv[2]*/"7777");
	return EXITO;
}


int cliente_inicio(cliente *servidor_creado, char *port){

	socket_t skt;

	servidor_creado->skt;

	socket_init(&servidor_creado->skt);

	socket_connect(&servidor_creado->skt, "0.0.0.0", "7777");

	return EXITO;
}


void cliente_comunicacion(cliente *servidor_creado, char *argumento_path_archivo){
	int enviar_datos = 1;
	char buffer[18] = {};
	char *input;
	size_t size_bytes = 0;
	while (enviar_datos) {
		char *buffer = (char *) malloc (18*sizeof(char));
		socket_receive(&servidor_creado->skt, buffer, 18);
		printf("%s\n",buffer);
		if(getline(&input,&size_bytes,stdin)== (-1))break;
		for(int i = 0 ; i < (strlen(input)) ; i++ ){
			char letra;
			letra = input[i];
			socket_send(&servidor_creado->skt,&letra , 1);
			if(letra == '\n') break;
			char word[4] = {};
			socket_receive(&servidor_creado->skt, word, 4);
			printf("%s\n",word);
		}
	}
}



void cliente_fin(cliente *servidor_creado){

}



