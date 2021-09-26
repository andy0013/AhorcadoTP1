/*
 * cliente.c
 *
 *  Created on: 24 sep. 2021
 *      Author: andres
 */

#include "cliente.h"


int cliente_execute(int argc, char *argv[]){
	cliente servidor_conectado;
	if (cliente_inicio(&servidor_conectado, argv[1])==1)return ERROR;
	cliente_comunicacion(&servidor_conectado,/*argv[2]*/"7777");
	return EXITO;
}


int cliente_inicio(cliente *servidor_creado, char *port){

	protocolo_t *protocolo  = malloc(sizeof(protocolo_t));

	protocolo_inicio_cliente(protocolo,"0.0.0.0", "7777");

	servidor_creado->protocolo = protocolo;

	return EXITO;
}



void cliente_comunicacion(cliente *servidor_creado, char *argumento_path_archivo){
	int enviar_datos = 1;
	char *input;
	size_t size_bytes = 0;
	while(enviar_datos){
		printf("%s","Ingrese una letra:");
		getline(&input,&size_bytes,stdin);
		for(int i = 0 ; i < (strlen(input)) ; i++ ){
			char letra;
			letra = input[i];
			protocolo_enviar_mensaje_a_servidor(servidor_creado->protocolo,1,&letra);
			if(letra == '\n') break;
			char datos_partida;
			int datos_partida_longitud;
			protocolo_recibir_datos_partida_servidor(servidor_creado->protocolo,&datos_partida);
			protocolo_recibir_datos_longitud_palabra_servidor(servidor_creado->protocolo,&datos_partida_longitud);
			char palabra_user[datos_partida_longitud];
			protocolo_recibir_datos_palabra_servidor(servidor_creado->protocolo,&palabra_user,&datos_partida_longitud);
			printf("%s\n",palabra_user);
		}
	}
}



void cliente_fin(cliente *servidor_creado){

}



