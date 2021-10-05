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

	char *palabra_de_partuda = (char *)calloc(1,sizeof(char)*locutor->longitud_palabra);

	protocolo_recibir_datos_palabra_servidor(protocolo, palabra_de_partuda,
			&locutor->longitud_palabra);

	locutor->palabra = palabra_de_partuda;
}

int locutor_termino_el_juego_ganamos(locutor *locutor) {
	if ((strstr(locutor->palabra, "_") == NULL)
			& (locutor->intentos_usuario > 0)) {
		printf("Ganaste!");
		locutor->termino_la_partida = 1;
		return locutor->termino_la_partida;
	} else {
		return 0;
	}
}

int locutor_termino_el_juego_perdimos(locutor *locutor) {
	if ((locutor->termino_la_partida)
			& (locutor->intentos_usuario == 0)) {
		printf("Perdiste! La palabra secreta era: %s", locutor->palabra);
	}
	return locutor->termino_la_partida;
}

void locutor_imprimir_informacon_recibida(locutor *locutor) {
	printf("Palabra secreta: %s\n", locutor->palabra);

	printf("Te quedan %i intentos\n", locutor->intentos_usuario);
}

void locutor_solicitar_letra_del_input_user(locutor *locutor,
		char *letra_a_enviar) {
	if (locutor->input_user == NULL) {
		size_t size_bytes = 0;

		printf("%s", "Ingrese una letra:\n");
		if(getline(&locutor->input_user, &size_bytes, stdin) == -1){
		}
		*letra_a_enviar =
				locutor->input_user[locutor->posicion_de_letra_enviada];
	} else {
		locutor_obtener_letra_del_input_user(locutor, letra_a_enviar);
	}
}

void locutor_obtener_letra_del_input_user(locutor *locutor, char *letra) {
	locutor->posicion_de_letra_enviada++;

	*letra = locutor->input_user[locutor->posicion_de_letra_enviada];

	if (*letra == '\n') {
		locutor_inicio(locutor);

		locutor_solicitar_letra_del_input_user(locutor, letra);
	}
}

void locutor_solicitar_y_enviar_letra_del_input_user(locutor *locutor,
		protocolo_t *protocolo) {
	char letra_input;

	locutor_solicitar_letra_del_input_user(locutor, &letra_input);

	protocolo_enviar_mensaje_a_servidor(protocolo, 1, &letra_input);
}

void locutor_fin(locutor *locutor) {
	free(locutor->palabra);
}

