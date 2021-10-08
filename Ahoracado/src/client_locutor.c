/*
 * locutor.c
 *
 *  Created on: 27 sep. 2021
 *      Author: andres
 */

#include "client_locutor.h"

void locutor_inicio(locutor *locutor) {
	locutor->input_user = NULL;

	locutor->posicion_de_letra_enviada = 0;
}

void locutor_preparar_atributos_de_partida(locutor *locutor) {
	locutor->intentos_usuario = 0;

	locutor->palabra = NULL;

	locutor->longitud_palabra = 0;

	locutor->termino_la_partida = 0;
}

void locutor_recibir_y_actualizar(locutor *locutor, protocolo_t *protocolo) {
	protocolo_recibir_datos_partida_servidor(protocolo,
			(uint8_t*)&locutor->termino_la_partida, &locutor->intentos_usuario);

	protocolo_recibir_datos_longitud_palabra_servidor(protocolo,
			&locutor->longitud_palabra);

	locutor->palabra = (char *)calloc(locutor->longitud_palabra+1,sizeof(char));
	//MEMSET SOLUCIONA ERROR VALGRIND PARA MANIPULAR STRING RECIBIDO
	memset(locutor->palabra,'\0',locutor->longitud_palabra+1);

	protocolo_recibir_datos_palabra_servidor(protocolo, locutor->palabra,
			&locutor->longitud_palabra);
}

int locutor_termino_el_juego_ganamos(locutor *locutor) {
	if ((strstr(locutor->palabra, "_") == NULL)
			& (locutor->intentos_usuario > 0)) {
		printf("Ganaste!!\n");
		locutor->termino_la_partida = 1;
		return locutor->termino_la_partida;
	} else {
		return 0;
	}
}

int locutor_termino_el_juego_perdimos(locutor *locutor) {
	if ((locutor->termino_la_partida)
			& (locutor->intentos_usuario == 0)) {
		printf("Perdiste! La palabra secreta era: '%s'\n", locutor->palabra);
	}
	return locutor->termino_la_partida;
}

void locutor_imprimir_informacon_recibida(locutor *locutor) {
	printf("Palabra secreta: %s\n", locutor->palabra);

	printf("Te quedan %i intentos\n", locutor->intentos_usuario);
}

int locutor_letra_invalida(char *letra_a_enviar){
	int valor_invalido = 0;
	if(*letra_a_enviar == '\n')
		valor_invalido = 1;
	return valor_invalido;
}

void locutor_solicitar_letra_del_input_user(locutor *locutor,
		char *letra_a_enviar) {
	if (locutor->input_user == NULL) {
		size_t size_bytes = 0;

		int valor_invalido;

		do{
			valor_invalido = 0;
			printf("%s", "Ingrese letra: \n");

			size_t read = getline(&locutor->input_user, &size_bytes, stdin);

			*letra_a_enviar =
				locutor->input_user[locutor->posicion_de_letra_enviada];

			if((read == -1) ||(locutor_letra_invalida(letra_a_enviar)))
				valor_invalido = 1;
		}while(valor_invalido);
	} else {
		locutor_obtener_letra_del_input_user(locutor, letra_a_enviar);
	}
}

void locutor_obtener_letra_del_input_user(locutor *locutor, char *letra) {
	locutor->posicion_de_letra_enviada++;

	if (locutor->posicion_de_letra_enviada
			== (strlen(locutor->input_user)-1)){
		locutor_fin(locutor);

		locutor_inicio(locutor);

		locutor_solicitar_letra_del_input_user(locutor, letra);
	}else{
		printf("%s", "Ingrese letra: \n");
		*letra = locutor->input_user[locutor->posicion_de_letra_enviada];
	}
}

void locutor_solicitar_y_enviar_letra_del_input_user(locutor *locutor,
		protocolo_t *protocolo) {
	char letra_input;

	locutor_solicitar_letra_del_input_user(locutor, &letra_input);

	protocolo_enviar_mensaje_a_servidor(protocolo, 1, &letra_input);
}

void locutor_liberar_memoria(locutor *locutor){
	free(locutor->palabra);
}

void locutor_fin(locutor *locutor) {
	free(locutor->input_user);
}

