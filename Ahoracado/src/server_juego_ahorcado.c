/*
 * juego_ahorcado.c
 *
 *  Created on: 17 sep. 2021
 *      Author: andres
 */

#include "server_juego_ahorcado.h"
#include <string.h>

void juego_inicio(juego *instancia_de_juego, consola *user_servidor,
		int intentos_juego) {
	instancia_de_juego->intentos_juego = intentos_juego;
	instancia_de_juego->consola_user_servidor = user_servidor;
	instancia_de_juego->veces_que_gano = 0;
	instancia_de_juego->veces_que_perdio = 0;
}

void juego_levantar_dato(juego *instancia_de_juego,
		char *argumento_path_archivo) {
	lector_de_archivo palabras_por_descubrir;

	archivo_inicio(&palabras_por_descubrir, argumento_path_archivo);

	instancia_de_juego->archivo = palabras_por_descubrir;
}

void juego_preparar_ahorcado(juego *instancia_de_juego) {
	instancia_de_juego->intentos_disponibles =
			instancia_de_juego->intentos_juego;

	leer_linea_archivo(&instancia_de_juego->archivo);

	int longitudDePalabraPorAdivinarEnEsteIntento = (strlen(
			instancia_de_juego->archivo.line) - 1);

	palabra palabra_leida;

	palabra_inicio(&palabra_leida, longitudDePalabraPorAdivinarEnEsteIntento,
			instancia_de_juego->archivo.line);

	instancia_de_juego->palabra_leida = palabra_leida;
}

void juego_user_gano_partida(juego *instancia_de_juego) {
	consola_mensaje_palabra_actual(instancia_de_juego->consola_user_servidor,
			instancia_de_juego->palabra_leida.palabra_leida,
			&instancia_de_juego->intentos_disponibles, 1,
			instancia_de_juego->palabra_leida.longitud);

	palabra_fin(&instancia_de_juego->palabra_leida);

	juego_preparar_ahorcado((instancia_de_juego));

	consola_finalizar_partida_cliente_actual(
			instancia_de_juego->consola_user_servidor);

	instancia_de_juego->veces_que_gano = instancia_de_juego->veces_que_gano + 1;
}

void juego_user_perdio_partida(juego *instancia_de_juego) {
	consola_mensaje_palabra_actual(instancia_de_juego->consola_user_servidor,
			instancia_de_juego->palabra_leida.palabra_leida,
			&instancia_de_juego->intentos_disponibles, 1,
			instancia_de_juego->palabra_leida.longitud);

	palabra_fin(&instancia_de_juego->palabra_leida);

	juego_preparar_ahorcado((instancia_de_juego));

	consola_finalizar_partida_cliente_actual(
			instancia_de_juego->consola_user_servidor);

	instancia_de_juego->veces_que_perdio = instancia_de_juego->veces_que_perdio
			+ 1;
}

void imprimir_resultado_juegos(juego *instancia_de_juego) {
	printf("Resumen:\n");
	printf("\tVictorias: %i\n", instancia_de_juego->veces_que_gano);
	printf("\tDerrotas: %i\n", instancia_de_juego->veces_que_perdio);
}

void juego_ejecutar(juego *instancia_de_juego) {
	char input_user;

	while (!linea_llego_al_final(&instancia_de_juego->archivo)) {
		consola_conectar_usuario_de_ser_necesario(
				instancia_de_juego->consola_user_servidor);

		consola_mensaje_palabra_actual(
				instancia_de_juego->consola_user_servidor,
				instancia_de_juego->palabra_leida.palabra_en_juego,
				&instancia_de_juego->intentos_disponibles, 0,
				instancia_de_juego->palabra_leida.longitud);

		consola_obtener_input_user(instancia_de_juego->consola_user_servidor,
				&input_user);

		palabra_revisar_caracter_y_intentos(&instancia_de_juego->palabra_leida,
				input_user, &instancia_de_juego->intentos_disponibles);

		if (palabras_leidas_e_construidas_son_iguales(
				&instancia_de_juego->palabra_leida)) {
			juego_user_gano_partida(instancia_de_juego);
		}
		if (instancia_de_juego->intentos_disponibles == 0) {
			juego_user_perdio_partida(instancia_de_juego);
		}
	}
	imprimir_resultado_juegos(instancia_de_juego);
}

void juego_fin(juego *instancia_de_juego) {
	palabra_fin(&instancia_de_juego->palabra_leida);

	archivo_fin(&instancia_de_juego->archivo);

	consola_fin(instancia_de_juego->consola_user_servidor);
}

